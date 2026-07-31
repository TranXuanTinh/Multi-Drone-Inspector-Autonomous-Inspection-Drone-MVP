"""
ROS 2 Flight Commands — replaces MAVSDK FlightCommands for ROS 2.

Implements the FlightController interface by publishing
MissionCommand messages to the C++ offboard_controller node.

Command constants match multi_drone_msgs/msg/MissionCommand.
"""
from __future__ import annotations

import logging
import math
from typing import Optional

from src.core.interfaces import FlightController
from src.core.types import Waypoint, VehicleId

logger = logging.getLogger(__name__)

# MissionCommand constants (from multi_drone_msgs/msg/MissionCommand.msg)
CMD_TAKEOFF_ALL = 0
CMD_LAND_ALL = 1
CMD_RTL_ALL = 2
CMD_ARM_ALL = 3
CMD_DISARM_ALL = 4
CMD_OFFBOARD_START = 5
CMD_OFFBOARD_STOP = 6
CMD_GOTO = 7
CMD_HOLD_ALL = 8
CMD_ABORT_ALL = 9
CMD_SINGLE_VEHICLE = 10


class ROS2FlightCommands(FlightController):
    """ROS 2-based flight commands.

    Publishes MissionCommand messages to control a single vehicle
    via the C++ offboard_controller node.

    Implements the same FlightController interface as the MAVSDK-based
    FlightCommands class for backward compatibility.
    """

    def __init__(
        self,
        bridge,    # ROS2VehicleBridge
        vehicle_id: Optional[VehicleId] = None,
    ) -> None:
        self._bridge = bridge
        self._vehicle_id = vehicle_id or bridge.vehicle_id
        self._offboard_active = False

        logger.info(
            f"ROS2FlightCommands created for {self._vehicle_id.name}"
        )

    # ── FlightController interface ───────────────────────────

    async def arm(self) -> None:
        """Arm the vehicle."""
        logger.info(f"[{self._vehicle_id.name}] Arming...")
        await self._bridge.send_mission_command(CMD_ARM_ALL)

    async def disarm(self) -> None:
        """Disarm the vehicle."""
        logger.info(f"[{self._vehicle_id.name}] Disarming...")
        await self._bridge.send_mission_command(CMD_DISARM_ALL)

    async def takeoff(self, altitude_m: float = 15.0) -> None:
        """Take off to the specified altitude."""
        logger.info(
            f"[{self._vehicle_id.name}] Taking off to {altitude_m}m"
        )
        await self._bridge.send_mission_command(
            CMD_TAKEOFF_ALL, param1=altitude_m,
        )

    async def land(self) -> None:
        """Land at the current position."""
        logger.info(f"[{self._vehicle_id.name}] Landing...")
        await self._bridge.send_mission_command(CMD_LAND_ALL)

    async def rtl(self) -> None:
        """Return to the launch position (FlightController ABC)."""
        logger.info(
            f"[{self._vehicle_id.name}] Returning to launch..."
        )
        await self._bridge.send_mission_command(CMD_RTL_ALL)

    # Keep legacy alias for backward compatibility
    async def return_to_launch(self) -> None:
        """Alias for rtl() — backward compatibility."""
        await self.rtl()

    async def hold(self) -> None:
        """Hold current position."""
        logger.info(f"[{self._vehicle_id.name}] Holding position...")
        await self._bridge.send_mission_command(CMD_HOLD_ALL)

    async def goto(
        self,
        latitude_deg: float,
        longitude_deg: float,
        altitude_m: float,
        yaw_deg: float = float("nan"),
    ) -> None:
        """Navigate to a GPS position (FlightController ABC).

        Note: The C++ controller handles the actual GPS→NED conversion.
        """
        logger.info(
            f"[{self._vehicle_id.name}] Going to "
            f"({latitude_deg:.6f}, {longitude_deg:.6f}) at {altitude_m:.1f}m"
        )
        await self._bridge.send_mission_command(
            CMD_GOTO,
            param1=latitude_deg,
            param2=longitude_deg,
            param3=altitude_m,
            param4=yaw_deg if not math.isnan(yaw_deg) else 0.0,
        )

    # Keep legacy alias for backward compatibility
    async def goto_waypoint(self, waypoint: Waypoint) -> None:
        """Navigate to a Waypoint object — backward compatibility."""
        await self.goto(waypoint.latitude, waypoint.longitude, waypoint.altitude)

    async def wait_for_altitude(
        self, target_m: float, tolerance_m: float = 1.0,
        timeout_s: float = 30.0,
    ) -> bool:
        """Wait for the vehicle to reach target altitude.

        In ROS 2 mode, polls the bridge telemetry.
        """
        logger.info(
            f"[{self._vehicle_id.name}] Waiting for altitude "
            f"{target_m}m (±{tolerance_m}m, timeout {timeout_s}s)..."
        )
        import asyncio
        deadline = asyncio.get_running_loop().time() + timeout_s
        while asyncio.get_running_loop().time() < deadline:
            telem = self._bridge.latest_telemetry
            if telem and abs(telem.position.relative_altitude_m - target_m) <= tolerance_m:
                logger.info(
                    f"[{self._vehicle_id.name}] Altitude reached: "
                    f"{telem.position.relative_altitude_m:.1f}m"
                )
                return True
            await asyncio.sleep(0.5)
        logger.warning(
            f"[{self._vehicle_id.name}] Altitude wait timed out after {timeout_s}s"
        )
        return False

    async def wait_for_landed(self, timeout_s: float = 60.0) -> bool:
        """Wait for the vehicle to land.

        In ROS 2 mode, polls the bridge telemetry for low altitude.
        """
        logger.info(f"[{self._vehicle_id.name}] Waiting for landing...")
        import asyncio
        deadline = asyncio.get_running_loop().time() + timeout_s
        while asyncio.get_running_loop().time() < deadline:
            telem = self._bridge.latest_telemetry
            if telem and telem.position.relative_altitude_m < 0.5:
                logger.info(f"[{self._vehicle_id.name}] Vehicle has landed")
                return True
            await asyncio.sleep(0.5)
        logger.warning(
            f"[{self._vehicle_id.name}] Landing wait timed out after {timeout_s}s"
        )
        return False

    async def wait_for_disarmed(self, timeout_s: float = 60.0) -> bool:
        """Wait for the vehicle to disarm.

        In ROS 2 mode, polls the bridge telemetry.
        """
        logger.info(f"[{self._vehicle_id.name}] Waiting for disarm...")
        import asyncio
        deadline = asyncio.get_running_loop().time() + timeout_s
        while asyncio.get_running_loop().time() < deadline:
            telem = self._bridge.latest_telemetry
            if telem and not telem.armed:
                logger.info(f"[{self._vehicle_id.name}] Vehicle is disarmed")
                return True
            await asyncio.sleep(0.5)
        logger.warning(
            f"[{self._vehicle_id.name}] Disarm wait timed out after {timeout_s}s"
        )
        return False

    @property
    def is_offboard_active(self) -> bool:
        """Whether offboard control mode is currently active."""
        return self._offboard_active

    async def start_offboard(self) -> None:
        """Start offboard control mode."""
        logger.info(
            f"[{self._vehicle_id.name}] Starting offboard mode..."
        )
        await self._bridge.send_mission_command(CMD_OFFBOARD_START)
        self._offboard_active = True

    async def stop_offboard(self) -> None:
        """Stop offboard control mode."""
        logger.info(
            f"[{self._vehicle_id.name}] Stopping offboard mode..."
        )
        await self._bridge.send_mission_command(CMD_OFFBOARD_STOP)
        self._offboard_active = False

    async def send_position_setpoint(
        self, x: float, y: float, z: float, yaw: float = 0.0,
    ) -> None:
        """Send a position setpoint in NED frame."""
        await self._bridge.send_mission_command(
            CMD_GOTO,
            param1=x,
            param2=y,
            param3=z,
            param4=yaw,
        )

    async def abort(self) -> None:
        """Emergency abort — RTL immediately."""
        logger.warning(
            f"[{self._vehicle_id.name}] ABORT — emergency RTL"
        )
        await self._bridge.send_mission_command(CMD_ABORT_ALL)
