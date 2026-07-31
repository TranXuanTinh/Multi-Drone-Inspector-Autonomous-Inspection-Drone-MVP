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

import asyncio
import argparse
import logging
import signal
import sys
from pathlib import Path

# Add project root to path
sys.path.insert(0, str(Path(__file__).parent.parent))

from src.utils.logger import setup_logging
from src.utils.config_loader import load_config
from src.core.events import EventBus
from src.core.types import (
    VehicleId, FleetState, FormationConfig,
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

        # Create bridge (stub mode — no ROS node in standalone Python)
        bridge = ROS2VehicleBridge(vehicle_id=vid, ros_node=None)
        await bridge.connect()

        # Create flight commands
        cmd = ROS2FlightCommands(bridge)

        bridges[i] = bridge
        commands[i] = cmd

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
    await asyncio.sleep(3)

    logger.info("\n--- Phase 2: Form Line Formation ---")
    await fleet.set_formation(
        FormationConfig(
            pattern=fleet_config.get("default_formation", "line"),
            spacing_m=fleet_config.get("default_spacing_m", 10.0),
        )
    )
    await asyncio.sleep(5)

    logger.info("\n--- Phase 3: Execute Coordinated Mission ---")
    await fleet.execute_coordinated_mission(waypoints_per_vehicle)

    logger.info("\n--- Phase 4: RTL All ---")
    await fleet.rtl_all()
    await asyncio.sleep(3)

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
