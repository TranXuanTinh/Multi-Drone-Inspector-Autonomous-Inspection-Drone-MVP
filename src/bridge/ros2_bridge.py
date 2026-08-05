"""
ROS 2 Vehicle Bridge — replaces MAVLinkBridge for ROS 2 / XRCE-DDS.

Implements the existing DroneConnector interface using ROS 2 topics
published by the C++ vehicle_controller node. This allows the
Python-side MissionStateMachine to work unchanged.

Topic mapping (per vehicle namespace /px4_{i}):
  Subscribe: /fleet/vehicle_status  → VehicleStatus from C++ controller
  Publish:   /fleet/mission_command → MissionCommand to C++ controller
"""
from __future__ import annotations

import asyncio
import logging
from typing import Callable, Optional

from src.core.interfaces import DroneConnector
from src.core.types import (
    Position, Attitude, TelemetryFrame, VehicleId,
)

logger = logging.getLogger(__name__)


class ROS2VehicleBridge(DroneConnector):
    """ROS 2-based vehicle connector.

    Implements the same DroneConnector interface as MAVLinkBridge,
    enabling backward compatibility with the existing state machine
    and mission logic.

    In ROS 2 mode, this bridge:
      - Subscribes to VehicleStatus from the C++ offboard_controller
      - Translates VehicleStatus → TelemetryFrame for Python consumers
      - Publishes MissionCommand for vehicle control

    Note: Requires rclpy and multi_drone_msgs to be importable.
    Falls back to a stub if ROS 2 is not available (for testing).
    """

    def __init__(
        self,
        vehicle_id: VehicleId,
        ros_node=None,
    ) -> None:
        self._vehicle_id = vehicle_id
        self._namespace = vehicle_id.namespace
        self._ros_node = ros_node

        self._connected = False
        self._latest_telemetry = TelemetryFrame()
        self._telemetry_callback: Optional[Callable] = None
        self._telemetry_rate_hz: float = 10.0

        # ROS 2 subscriptions (set up on connect)
        self._status_sub = None
        self._command_pub = None

        logger.info(
            f"ROS2VehicleBridge created for {vehicle_id.name} "
            f"(namespace={self._namespace})"
        )

    # ── DroneConnector interface ─────────────────────────────

    async def connect(self, timeout_s: float = 30.0) -> None:
        """Connect to the ROS 2 vehicle controller.

        Sets up subscriptions to the C++ controller's published topics.
        """
        logger.info(
            f"[{self._vehicle_id.name}] Connecting via ROS 2..."
        )

        if self._ros_node is not None:
            self._setup_ros2_subscriptions()
        else:
            logger.warning(
                f"[{self._vehicle_id.name}] No ROS node provided — "
                f"running in stub mode"
            )
            import time
            self._latest_telemetry = TelemetryFrame(
                timestamp=time.time(),
                position=Position(47.397742, 8.545594, 488.0, 0.0),
                attitude=Attitude(0.0, 0.0, 0.0),
                heading_deg=0.0,
                groundspeed_ms=0.0,
                battery_percent=100.0,
                battery_voltage=16.8,
                flight_mode="HOLD",
                armed=False,
                is_connected=True,
                gps_num_satellites=10,
                gps_fix_type=3,
            )

        self._connected = True
        logger.info(
            f"[{self._vehicle_id.name}] Connected (ROS 2 bridge)"
        )

    async def disconnect(self) -> None:
        """Disconnect from the ROS 2 vehicle."""
        self._connected = False
        logger.info(f"[{self._vehicle_id.name}] Disconnected")

    async def wait_for_ready(self, timeout_s: float = 30.0) -> None:
        """Wait until the vehicle controller is publishing status."""
        logger.info(f"[{self._vehicle_id.name}] Waiting for ready...")

        loop = asyncio.get_running_loop()
        deadline = loop.time() + timeout_s
        while loop.time() < deadline:
            if self._latest_telemetry.is_connected:
                logger.info(
                    f"[{self._vehicle_id.name}] Vehicle ready "
                    f"(GPS fix: {self._latest_telemetry.gps_fix_type})"
                )
                return
            await asyncio.sleep(0.5)

        logger.warning(
            f"[{self._vehicle_id.name}] Ready timeout after {timeout_s}s"
        )

    @property
    def is_connected(self) -> bool:
        return self._connected

    @property
    def latest_telemetry(self) -> TelemetryFrame:
        return self._latest_telemetry

    async def start_telemetry_stream(
        self,
        rate_hz: float = 10.0,
        callback: Optional[Callable] = None,
    ) -> None:
        """Start receiving telemetry from the C++ controller.

        In ROS 2 mode, telemetry arrives via subscription callbacks.
        The rate is determined by the C++ controller's publish rate.
        """
        self._telemetry_rate_hz = rate_hz
        self._telemetry_callback = callback
        logger.info(
            f"[{self._vehicle_id.name}] Telemetry stream started"
        )
        if callback and self._ros_node is None:
            try:
                loop = asyncio.get_running_loop()
                loop.create_task(callback(self._latest_telemetry))
            except Exception as e:
                logger.error(f"Failed to trigger initial stub telemetry callback: {e}")

    async def stop_telemetry_stream(self) -> None:
        """Stop telemetry stream."""
        self._telemetry_callback = None
        logger.info(
            f"[{self._vehicle_id.name}] Telemetry stream stopped"
        )

    # ── ROS 2 Integration ────────────────────────────────────

    def _setup_ros2_subscriptions(self) -> None:
        """Set up ROS 2 subscriptions to C++ controller topics."""
        try:
            from multi_drone_msgs.msg import VehicleStatus, MissionCommand
            from rclpy.qos import QoSProfile, ReliabilityPolicy

            qos = QoSProfile(depth=10)
            qos.reliability = ReliabilityPolicy.RELIABLE

            # Subscribe to vehicle status
            self._status_sub = self._ros_node.create_subscription(
                VehicleStatus,
                "/fleet/vehicle_status",
                self._on_vehicle_status,
                qos,
            )

            # Publisher for mission commands
            self._command_pub = self._ros_node.create_publisher(
                MissionCommand,
                "/fleet/mission_command",
                qos,
            )

            logger.info(
                f"[{self._vehicle_id.name}] ROS 2 subscriptions ready"
            )

        except ImportError:
            logger.warning(
                "ROS 2 packages not available — "
                "running in offline/test mode"
            )

    def _on_vehicle_status(self, msg) -> None:
        """Callback for VehicleStatus from C++ controller."""
        # Only process messages for our vehicle
        if msg.vehicle_id != self._vehicle_id.instance_id:
            return

        # Translate VehicleStatus → TelemetryFrame
        self._latest_telemetry = TelemetryFrame(
            timestamp=msg.stamp.sec + msg.stamp.nanosec * 1e-9,
            position=Position(
                latitude_deg=msg.latitude_deg,
                longitude_deg=msg.longitude_deg,
                absolute_altitude_m=msg.absolute_altitude_m,
                relative_altitude_m=msg.relative_altitude_m,
            ),
            attitude=Attitude(
                roll_deg=msg.roll_deg,
                pitch_deg=msg.pitch_deg,
                yaw_deg=msg.yaw_deg,
            ),
            heading_deg=msg.heading_deg,
            groundspeed_ms=msg.groundspeed_ms,
            battery_percent=msg.battery_percent,
            battery_voltage=msg.battery_voltage,
            flight_mode=msg.flight_mode,
            armed=msg.armed,
            is_connected=msg.connected,
            gps_num_satellites=msg.gps_num_satellites,
            gps_fix_type=msg.gps_fix_type,
        )

        # Invoke callback if registered (thread-safe: this callback
        # runs in the ROS 2 executor thread, not the asyncio loop)
        if self._telemetry_callback:
            try:
                loop = asyncio.get_running_loop()
                # Already in an asyncio context (SingleThreadedExecutor
                # running inside asyncio) — use create_task directly
                loop.create_task(
                    self._telemetry_callback(self._latest_telemetry)
                )
            except RuntimeError:
                # Called from a non-asyncio thread (MultiThreadedExecutor)
                # — schedule onto the asyncio event loop safely
                try:
                    loop = asyncio.get_event_loop()
                    asyncio.run_coroutine_threadsafe(
                        self._telemetry_callback(self._latest_telemetry),
                        loop,
                    )
                except RuntimeError:
                    pass  # No event loop available; drop callback

    # ── Command Methods ──────────────────────────────────────

    async def send_mission_command(
        self,
        command: int,
        param1: float = 0.0,
        param2: float = 0.0,
        param3: float = 0.0,
        param4: float = 0.0,
    ) -> None:
        """Send a mission command via ROS 2 topic."""
        if self._command_pub is None:
            logger.warning(
                f"[{self._vehicle_id.name}] No command publisher — "
                f"command {command} ignored"
            )
            # Update simulated telemetry in stub mode
            try:
                CMD_TAKEOFF_ALL = 0
                CMD_LAND_ALL = 1
                CMD_RTL_ALL = 2
                CMD_ARM_ALL = 3
                CMD_DISARM_ALL = 4
                CMD_GOTO = 7

                if command == CMD_ARM_ALL:
                    self._latest_telemetry.armed = True
                elif command == CMD_DISARM_ALL:
                    self._latest_telemetry.armed = False
                elif command == CMD_TAKEOFF_ALL:
                    self._latest_telemetry.armed = True
                    self._latest_telemetry.position = Position(
                        latitude_deg=self._latest_telemetry.position.latitude_deg,
                        longitude_deg=self._latest_telemetry.position.longitude_deg,
                        absolute_altitude_m=param1 + 488.0,
                        relative_altitude_m=param1
                    )
                elif command in (CMD_LAND_ALL, CMD_RTL_ALL):
                    self._latest_telemetry.position = Position(
                        latitude_deg=self._latest_telemetry.position.latitude_deg,
                        longitude_deg=self._latest_telemetry.position.longitude_deg,
                        absolute_altitude_m=488.0,
                        relative_altitude_m=0.0
                    )
                    self._latest_telemetry.armed = False
                elif command == CMD_GOTO:
                    # In NED local goto, param3 is z (negative = up)
                    self._latest_telemetry.position = Position(
                        latitude_deg=param1,
                        longitude_deg=param2,
                        absolute_altitude_m=abs(param3) + 488.0,
                        relative_altitude_m=abs(param3)
                    )

                if self._telemetry_callback:
                    try:
                        loop = asyncio.get_running_loop()
                        loop.create_task(self._telemetry_callback(self._latest_telemetry))
                    except Exception as callback_err:
                        logger.error(f"Failed to trigger telemetry callback: {callback_err}")
            except Exception as e:
                logger.error(f"Failed to update simulated telemetry: {e}")
            return

        try:
            from multi_drone_msgs.msg import MissionCommand

            msg = MissionCommand()
            msg.command = command
            msg.target_vehicle_id = self._vehicle_id.instance_id
            msg.param1 = param1
            msg.param2 = param2
            msg.param3 = param3
            msg.param4 = param4
            msg.stamp = self._ros_node.get_clock().now().to_msg()

            self._command_pub.publish(msg)
            logger.debug(
                f"[{self._vehicle_id.name}] Sent command {command}"
            )

        except Exception as e:
            logger.error(
                f"[{self._vehicle_id.name}] Command publish failed: {e}"
            )

    @property
    def vehicle_id(self) -> VehicleId:
        return self._vehicle_id
