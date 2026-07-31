"""
SITL Test — Offboard Control.

Tests the offboard control interface and setpoint handling.
"""
from __future__ import annotations

import pytest

pytestmark = [pytest.mark.sitl, pytest.mark.timeout(60)]


class TestOffboardControl:
    """Test offboard control interface."""

    @pytest.mark.asyncio
    async def test_ros2_bridge_creation(self):
        """ROS2VehicleBridge should initialize correctly."""
        from src.bridge.ros2_bridge import ROS2VehicleBridge
        from src.core.types import VehicleId

        vid = VehicleId(0, "/px4_0", "UAV-Alpha", 1, "leader")
        bridge = ROS2VehicleBridge(vehicle_id=vid, ros_node=None)

        assert bridge.vehicle_id == vid
        assert not bridge.is_connected

    @pytest.mark.asyncio
    async def test_ros2_bridge_connect_stub_mode(self):
        """Bridge should connect in stub mode without ROS node."""
        from src.bridge.ros2_bridge import ROS2VehicleBridge
        from src.core.types import VehicleId

        vid = VehicleId(0, "/px4_0", "UAV-Alpha", 1, "leader")
        bridge = ROS2VehicleBridge(vehicle_id=vid, ros_node=None)

        await bridge.connect()
        assert bridge.is_connected

        await bridge.disconnect()
        assert not bridge.is_connected

    @pytest.mark.asyncio
    async def test_ros2_flight_commands_creation(self):
        """ROS2FlightCommands should initialize correctly."""
        from src.bridge.ros2_bridge import ROS2VehicleBridge
        from src.bridge.ros2_flight_commands import ROS2FlightCommands
        from src.core.types import VehicleId

        vid = VehicleId(0, "/px4_0", "UAV-Alpha", 1, "leader")
        bridge = ROS2VehicleBridge(vehicle_id=vid, ros_node=None)
        commands = ROS2FlightCommands(bridge)

        # Commands should not raise even without ROS node
        await commands.arm()
        await commands.takeoff(15.0)
        await commands.hold()
        await commands.land()

    def test_vehicle_id_creation(self):
        """VehicleId should store all identity fields."""
        from src.core.types import VehicleId

        vid = VehicleId(
            instance_id=2,
            namespace="/px4_2",
            name="UAV-Charlie",
            mavlink_sys_id=3,
            role="follower",
        )

        assert vid.instance_id == 2
        assert vid.namespace == "/px4_2"
        assert vid.name == "UAV-Charlie"
        assert vid.mavlink_sys_id == 3
        assert vid.role == "follower"

    def test_fleet_state_enum(self):
        """FleetState enum should have all required states."""
        from src.core.types import FleetState

        assert FleetState.IDLE == "IDLE"
        assert FleetState.FORMING == "FORMING"
        assert FleetState.IN_FORMATION == "IN_FORMATION"
        assert FleetState.EXECUTING == "EXECUTING"
        assert FleetState.SCATTERING == "SCATTERING"
        assert FleetState.RTL_ALL == "RTL_ALL"

    def test_formation_config_defaults(self):
        """FormationConfig should have sensible defaults."""
        from src.core.types import FormationConfig

        config = FormationConfig()
        assert config.pattern == "line"
        assert config.spacing_m == 10.0
        assert config.altitude_offset_m == 0.0
        assert config.heading_deg == 0.0

    def test_fleet_command_broadcast(self):
        """FleetCommand with None target should indicate broadcast."""
        from src.core.types import FleetCommand

        cmd = FleetCommand(command="takeoff", params={"altitude_m": 15.0})
        assert cmd.target_vehicle_id is None  # Broadcast
        assert cmd.command == "takeoff"
