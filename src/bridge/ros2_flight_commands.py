"""
ROS 2 Flight Commands — replaces MAVSDK FlightCommands for ROS 2.

Implements the FlightController interface by publishing
MissionCommand messages to the C++ offboard_controller node.

Command constants match multi_drone_msgs/msg/MissionCommand.
"""
from __future__ import annotations

import logging
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

    async def return_to_launch(self) -> None:
        """Return to the launch position."""
        logger.info(
            f"[{self._vehicle_id.name}] Returning to launch..."
        )
        await self._bridge.send_mission_command(CMD_RTL_ALL)

    async def hold(self) -> None:
        """Hold current position."""
        logger.info(f"[{self._vehicle_id.name}] Holding position...")
        await self._bridge.send_mission_command(CMD_HOLD_ALL)

    async def goto_waypoint(self, waypoint: Waypoint) -> None:
        """Navigate to a GPS waypoint.

        Note: The C++ controller handles the actual GPS→NED conversion.
        """
        logger.info(
            f"[{self._vehicle_id.name}] Going to {waypoint}"
        )
        await self._bridge.send_mission_command(
            CMD_GOTO,
            param1=waypoint.latitude,
            param2=waypoint.longitude,
            param3=waypoint.altitude,
        )

    async def start_offboard(self) -> None:
        """Start offboard control mode."""
        logger.info(
            f"[{self._vehicle_id.name}] Starting offboard mode..."
        )
        await self._bridge.send_mission_command(CMD_OFFBOARD_START)

    async def stop_offboard(self) -> None:
        """Stop offboard control mode."""
        logger.info(
            f"[{self._vehicle_id.name}] Stopping offboard mode..."
        )
        await self._bridge.send_mission_command(CMD_OFFBOARD_STOP)

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
