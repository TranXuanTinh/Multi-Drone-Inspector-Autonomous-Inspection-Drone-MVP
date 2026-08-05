"""
SITL test fixtures — connection, lifecycle, auto-skip.

Supports both legacy MAVSDK bridge and new ROS 2 bridge.
Tests are automatically skipped when the simulator is not available.

Mock-based fixtures are provided for deterministic testing without
a live SITL instance.
"""
import asyncio
import time
import pytest
from unittest.mock import AsyncMock, MagicMock, PropertyMock

# Try importing MAVSDK bridge (optional — may not be installed)
try:
    from src.bridge.mavlink_bridge import MAVLinkBridge
    from src.bridge.commands import FlightCommands
    MAVSDK_AVAILABLE = True
except ImportError:
    MAVSDK_AVAILABLE = False

# ROS 2 bridge is always available (uses stub mode if no ROS)
from src.bridge.ros2_bridge import ROS2VehicleBridge
from src.bridge.ros2_flight_commands import ROS2FlightCommands
from src.core.types import (
    VehicleId, TelemetryFrame, Position, Attitude, SafetyAction,
)


# ── Legacy MAVSDK Fixtures ───────────────────────────────────

@pytest.fixture
async def sitl_bridge():
    """Connect to PX4 SITL via MAVSDK, yield bridge, disconnect on teardown.

    Auto-skips if SITL is not running or MAVSDK is not installed.
    """
    if not MAVSDK_AVAILABLE:
        pytest.skip("MAVSDK not installed")

    bridge = MAVLinkBridge()
    try:
        await asyncio.wait_for(bridge.connect(), timeout=60.0)
    except (ConnectionError, TimeoutError, asyncio.TimeoutError):
        pytest.skip("PX4 SITL not available")

    yield bridge

    await bridge.disconnect()


@pytest.fixture
async def sitl_flight(sitl_bridge):
    """FlightCommands connected to live SITL."""
    return FlightCommands(sitl_bridge)


@pytest.fixture
async def sitl_ready(sitl_bridge):
    """Ensure SITL has GPS fix and home position set."""
    try:
        await asyncio.wait_for(sitl_bridge.wait_for_ready(), timeout=30.0)
    except (TimeoutError, asyncio.TimeoutError):
        pytest.skip("SITL did not become ready (no GPS fix)")

    return sitl_bridge


# ── Mock-Based MAVSDK Fixtures ──────────────────────────────
# These provide deterministic testing without a live PX4 SITL.

def _make_telemetry_frame(**kwargs):
    """Create a realistic TelemetryFrame with sensible defaults."""
    defaults = dict(
        timestamp=time.time(),
        position=Position(47.397742, 8.545594, 488.0, 15.0),
        attitude=Attitude(0.5, -0.3, 90.0),
        heading_deg=90.0,
        groundspeed_ms=2.5,
        battery_percent=85.0,
        battery_voltage=16.4,
        flight_mode="HOLD",
        armed=True,
        is_connected=True,
        gps_num_satellites=12,
        gps_fix_type=3,
    )
    defaults.update(kwargs)
    return TelemetryFrame(**defaults)


@pytest.fixture
def mock_bridge():
    """Mock MAVLinkBridge that simulates a connected, ready PX4 SITL.

    Provides all DroneConnector interface methods as mocks with
    realistic return values, usable for any test that previously
    required `sitl_bridge` or `sitl_ready`.
    """
    bridge = MagicMock()

    # Connection state
    bridge.is_connected = True
    bridge.connect = AsyncMock()
    bridge.disconnect = AsyncMock()
    bridge.wait_for_ready = AsyncMock()
    bridge.reconnect = AsyncMock(return_value=True)

    # Telemetry
    telem = _make_telemetry_frame()
    type(bridge).latest_telemetry = PropertyMock(return_value=telem)
    bridge.start_telemetry_stream = AsyncMock()
    bridge.stop_telemetry_stream = AsyncMock()

    # Health
    bridge.is_healthy = AsyncMock(return_value=True)

    return bridge


@pytest.fixture
def mock_flight(mock_bridge):
    """Mock FlightCommands that simulates successful flight operations.

    All flight commands succeed immediately. `wait_for_altitude`,
    `wait_for_landed`, and `wait_for_disarmed` return True.
    """
    flight = MagicMock()

    flight.arm = AsyncMock()
    flight.disarm = AsyncMock()
    flight.takeoff = AsyncMock()
    flight.land = AsyncMock()
    flight.rtl = AsyncMock()
    flight.hold = AsyncMock()
    flight.goto = AsyncMock()

    flight.wait_for_altitude = AsyncMock(return_value=True)
    flight.wait_for_landed = AsyncMock(return_value=True)
    flight.wait_for_disarmed = AsyncMock(return_value=True)

    flight.is_offboard_active = False
    flight.stop_offboard = AsyncMock()

    return flight


# ── ROS 2 Bridge Fixtures ───────────────────────────────────

@pytest.fixture
def vehicle_id_0():
    """Vehicle ID for the first vehicle."""
    return VehicleId(
        instance_id=0,
        namespace="/px4_0",
        name="UAV-Alpha",
        mavlink_sys_id=1,
        role="leader",
    )


@pytest.fixture
def vehicle_id_1():
    """Vehicle ID for the second vehicle."""
    return VehicleId(
        instance_id=1,
        namespace="/px4_1",
        name="UAV-Bravo",
        mavlink_sys_id=2,
        role="follower",
    )


@pytest.fixture
async def ros2_bridge(vehicle_id_0):
    """ROS 2 vehicle bridge in stub mode (no ROS node needed)."""
    bridge = ROS2VehicleBridge(vehicle_id=vehicle_id_0, ros_node=None)
    await bridge.connect()
    yield bridge
    await bridge.disconnect()


@pytest.fixture
async def ros2_flight(ros2_bridge):
    """ROS 2 flight commands in stub mode."""
    return ROS2FlightCommands(ros2_bridge)
