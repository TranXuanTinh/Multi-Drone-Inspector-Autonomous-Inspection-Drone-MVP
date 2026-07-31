"""
SITL test fixtures — connection, lifecycle, auto-skip.

Supports both legacy MAVSDK bridge and new ROS 2 bridge.
Tests are automatically skipped when the simulator is not available.
"""
import asyncio
import pytest

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
from src.core.types import VehicleId


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
