#!/usr/bin/env python3
"""
run_multi_mission.py — Multi-vehicle mission entry point.

Orchestrates a coordinated multi-vehicle inspection mission using
the FleetManager and multiple ROS2VehicleBridge instances.

Usage:
    # 1. Start SITL:    ./scripts/launch_multi_sitl.sh --num 3 --xrce
    # 2. Launch nodes:  ros2 launch multi_drone_bringup full_system.launch.py
    # 3. Run mission:   python scripts/run_multi_mission.py
"""
from __future__ import annotations

import os
import sys
import asyncio
import argparse
import logging
import signal
from pathlib import Path

# --- Bootstrap LD_LIBRARY_PATH for ROS 2 & multi_drone_msgs ---
_project_root = Path(__file__).parent.parent.resolve()
_ros_distro = os.environ.get("ROS_DISTRO", "jazzy")
_required_ld_paths = [
    f"/opt/ros/{_ros_distro}/lib",
    str(_project_root / "ros2_ws" / "install" / "multi_drone_msgs" / "lib"),
    str(_project_root / "ros2_ws" / "install" / "px4_msgs" / "lib"),
]

# Check which required paths are currently missing from LD_LIBRARY_PATH
_current_ld_path = os.environ.get("LD_LIBRARY_PATH", "")
_current_ld_paths = [p for p in _current_ld_path.split(":") if p]
_missing_paths = [p for p in _required_ld_paths if p not in _current_ld_paths and os.path.isdir(p)]

if _missing_paths and not os.environ.get("_RESTARTED_WITH_LD_LIBRARY_PATH"):
    # Prepend missing paths to preserve precedence
    _new_ld_path = ":".join(_missing_paths + _current_ld_paths)
    os.environ["LD_LIBRARY_PATH"] = _new_ld_path
    os.environ["_RESTARTED_WITH_LD_LIBRARY_PATH"] = "1"
    
    # Re-execute Python with the corrected LD_LIBRARY_PATH
    try:
        os.execv(sys.executable, [sys.executable] + sys.argv)
    except Exception as e:
        sys.stderr.write(f"Failed to auto-restart with updated LD_LIBRARY_PATH: {e}\n")

# Add project root to path
sys.path.insert(0, str(_project_root))

from src.utils.logger import setup_logging
from src.utils.config_loader import load_config
from src.core.events import EventBus
from src.core.types import (
    VehicleId, FleetState, FormationConfig, FleetCommand,
)
from src.fleet.fleet_manager import FleetManager
from src.fleet.formation_patterns import FormationPatternGenerator
from src.bridge.ros2_bridge import ROS2VehicleBridge
from src.bridge.ros2_flight_commands import ROS2FlightCommands
from src.mission.waypoint_planner import PatternRegistry

logger = logging.getLogger(__name__)


async def main(config_path: str = None):
    """Main multi-vehicle mission execution."""

    # Load config
    config = load_config(config_path or "config/vehicle/fleet_config.yaml")
    setup_logging(
        level=config.get("logging", {}).get("level", "INFO"),
        log_dir=config.get("logging", {}).get("log_dir", "data/logs"),
    )

    logger.info("=" * 60)
    logger.info("  Multi-UAV Inspector — Coordinated Mission (SITL)")
    logger.info("=" * 60)

    fleet_config = config.get("fleet", {})
    vehicle_configs = config.get("vehicles", [])
    num_vehicles = fleet_config.get("num_vehicles", 3)

    event_bus = EventBus()

    # === Initialize ROS 2 if available ===
    ros_node = None
    try:
        # Auto-add ROS 2 Jazzy Python paths if not already on sys.path.
        # This allows the script to work from conda without requiring the
        # user to manually `source /opt/ros/jazzy/setup.bash` first.
        import os
        _ros_distro = os.environ.get("ROS_DISTRO", "jazzy")
        _ros_python_path = f"/opt/ros/{_ros_distro}/lib/python3.12/site-packages"
        if os.path.isdir(_ros_python_path) and _ros_python_path not in sys.path:
            sys.path.insert(0, _ros_python_path)
        # Also add the workspace install path for multi_drone_msgs
        _ws_install = os.path.join(
            str(Path(__file__).parent.parent), "ros2_ws", "install"
        )
        if os.path.isdir(_ws_install):
            # Walk install/<pkg>/lib/python3.12/site-packages
            for pkg_dir in Path(_ws_install).iterdir():
                sp = pkg_dir / "lib" / "python3.12" / "site-packages"
                if sp.is_dir() and str(sp) not in sys.path:
                    sys.path.insert(0, str(sp))

        # Also ensure ROS 2 shared libraries are findable
        _ros_lib = f"/opt/ros/{_ros_distro}/lib"
        _ld_path = os.environ.get("LD_LIBRARY_PATH", "")
        if _ros_lib not in _ld_path:
            os.environ["LD_LIBRARY_PATH"] = f"{_ros_lib}:{_ld_path}"

        import rclpy
        from rclpy.node import Node
        rclpy.init()
        ros_node = Node("mission_client")
        logger.info("ROS 2 initialized, running in REAL mode")

        # Spin ROS 2 node in background
        async def spin_node():
            while rclpy.ok():
                rclpy.spin_once(ros_node, timeout_sec=0.05)
                await asyncio.sleep(0.05)
        asyncio.create_task(spin_node())
    except ImportError as e:
        logger.info(f"ROS 2 not available ({e}), running in STUB/offline mode")
        logger.info("Hint: Ensure Python version matches ROS 2 Jazzy (3.12)")

    # === Initialize Fleet Manager ===
    fleet = FleetManager(config=config, event_bus=event_bus)

    # === Register Vehicles ===
    bridges = {}
    commands = {}

    for i in range(num_vehicles):
        v_cfg = vehicle_configs[i] if i < len(vehicle_configs) else {}

        vid = VehicleId(
            instance_id=v_cfg.get("id", i),
            namespace=f"/px4_{i}",
            name=v_cfg.get("name", f"UAV-{i}"),
            mavlink_sys_id=v_cfg.get("mavlink_sys_id", i + 1),
            role=v_cfg.get("role", "follower" if i > 0 else "leader"),
        )

        # Create bridge
        bridge = ROS2VehicleBridge(vehicle_id=vid, ros_node=ros_node)
        await bridge.connect()

        # Create flight commands
        cmd = ROS2FlightCommands(bridge)

        bridges[i] = bridge
        commands[i] = cmd

        # Register callback to update FleetManager telemetry
        def make_telemetry_callback(instance_id):
            async def cb(frame):
                fleet.update_vehicle_telemetry(instance_id, frame)
            return cb
        await bridge.start_telemetry_stream(callback=make_telemetry_callback(vid.instance_id))

        # Register command handler to map fleet commands to flight controller commands
        def make_command_handler(flight_cmd):
            async def handler(fleet_cmd):
                c = fleet_cmd.command
                params = fleet_cmd.params or {}
                if c == "takeoff":
                    alt = params.get("altitude_m", 15.0)
                    await flight_cmd.takeoff(alt)
                elif c == "land":
                    await flight_cmd.land()
                elif c == "rtl":
                    await flight_cmd.rtl()
                elif c == "hold":
                    await flight_cmd.hold()
                elif c == "goto":
                    lat = params.get("latitude_deg")
                    lon = params.get("longitude_deg")
                    alt = params.get("altitude_m")
                    yaw = params.get("yaw_deg", float("nan"))
                    await flight_cmd.goto(lat, lon, alt, yaw)
            return handler
        fleet.register_command_handler(vid.instance_id, make_command_handler(cmd))

        # Register with fleet manager
        await fleet.register_vehicle(vid)
        logger.info(f"Registered: {vid}")

    logger.info(f"Fleet ready: {fleet.num_vehicles} vehicles")

    # === Generate Per-Vehicle Waypoints ===
    mission_config = config.get("mission", {})
    search_area = mission_config.get("search_area", {})
    pattern_name = mission_config.get("search_pattern", "lawnmower")

    pattern_config = {
        "center_lat": search_area.get("center_lat", 47.397742),
        "center_lon": search_area.get("center_lon", 8.545594),
        "width_m": search_area.get("width_m", 200),
        "height_m": search_area.get("height_m", 150),
        "spacing_m": search_area.get("spacing_m", 30),
        "altitude_m": mission_config.get("search_altitude_m", 20.0),
    }

    # Generate waypoints and split among vehicles
    try:
        all_waypoints = PatternRegistry.generate(pattern_name, pattern_config)
    except ValueError:
        logger.warning(f"Unknown pattern '{pattern_name}', using lawnmower")
        all_waypoints = PatternRegistry.generate("lawnmower", pattern_config)

    # Split waypoints evenly among vehicles
    waypoints_per_vehicle = {}
    chunk_size = max(1, len(all_waypoints) // num_vehicles)
    for i in range(num_vehicles):
        start = i * chunk_size
        end = start + chunk_size if i < num_vehicles - 1 else len(all_waypoints)
        waypoints_per_vehicle[i] = all_waypoints[start:end]
        logger.info(
            f"Vehicle {i}: {len(waypoints_per_vehicle[i])} waypoints "
            f"(WP{start} → WP{end - 1})"
        )

    logger.info(f"Total waypoints: {len(all_waypoints)} ({pattern_name} pattern)")

    # === Mission Execution ===
    logger.info("\n--- Phase 1: Takeoff All ---")
    await fleet.takeoff_all(
        altitude_m=mission_config.get("takeoff_altitude_m", 15.0),
    )
    # Wait for all vehicles to reach altitude
    await asyncio.gather(*(
        cmd.wait_for_altitude(
            mission_config.get("takeoff_altitude_m", 15.0),
            tolerance_m=1.5,
            timeout_s=30.0,
        )
        for cmd in commands.values()
    ))

    logger.info("\n--- Phase 2: Form Line Formation ---")
    await fleet.set_formation(
        FormationConfig(
            pattern=fleet_config.get("default_formation", "line"),
            spacing_m=fleet_config.get("default_spacing_m", 10.0),
        )
    )
    await fleet.execute_formation()
    # Wait a few seconds for vehicles to stabilize formation positions
    await asyncio.sleep(5)

    logger.info("\n--- Phase 3: Execute Coordinated Mission ---")
    await fleet.execute_coordinated_mission(waypoints_per_vehicle)

    logger.info("\n--- Phase 4: RTL All ---")
    await fleet.rtl_all()
    # Wait for all vehicles to land and disarm
    await asyncio.gather(*(
        cmd.wait_for_landed(timeout_s=60.0)
        for cmd in commands.values()
    ))
    await asyncio.gather(*(
        cmd.wait_for_disarmed(timeout_s=30.0)
        for cmd in commands.values()
    ))

    # === Report ===
    logger.info("=" * 60)
    logger.info("  Multi-Vehicle Mission Complete!")
    logger.info(f"  Vehicles:  {num_vehicles}")
    logger.info(f"  Waypoints: {len(all_waypoints)} total")
    logger.info(f"  Formation: {fleet_config.get('default_formation', 'line')}")
    logger.info("=" * 60)

    # Cleanup
    for bridge in bridges.values():
        await bridge.disconnect()

    if ros_node:
        try:
            import rclpy
            ros_node.destroy_node()
            rclpy.shutdown()
        except Exception:
            pass


if __name__ == "__main__":
    parser = argparse.ArgumentParser(
        description="Run coordinated multi-vehicle inspection mission",
    )
    parser.add_argument(
        "--config", "-c",
        default=None,
        help="Path to fleet config YAML (default: config/vehicle/fleet_config.yaml)",
    )
    args = parser.parse_args()

    asyncio.run(main(config_path=args.config))
