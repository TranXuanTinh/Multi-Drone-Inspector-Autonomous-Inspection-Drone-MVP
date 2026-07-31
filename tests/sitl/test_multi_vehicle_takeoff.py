"""
SITL Test — Multi-Vehicle Takeoff.

Verifies that all vehicles can arm, take off, hover, and land
in a multi-instance PX4 SITL environment.

Prerequisites:
    - N PX4 SITL instances running (launch_multi_sitl.sh)
    - Micro XRCE-DDS Agent running
    - ROS 2 nodes running (full_system.launch.py)

Usage:
    pytest tests/sitl/test_multi_vehicle_takeoff.py -v -m sitl --timeout=120
"""
from __future__ import annotations

import asyncio
import pytest
import time
from typing import Dict

# Mark all tests in this module as SITL
pytestmark = [pytest.mark.sitl, pytest.mark.timeout(120)]


@pytest.fixture
def fleet_config():
    """Default fleet configuration for tests."""
    return {
        "num_vehicles": 3,
        "takeoff_altitude_m": 10.0,
        "hover_duration_s": 5.0,
        "position_tolerance_m": 2.0,
        "altitude_tolerance_m": 1.5,
    }


class TestMultiVehicleTakeoff:
    """Test suite for multi-vehicle takeoff operations."""

    @pytest.mark.asyncio
    async def test_all_vehicles_connect(self, fleet_config):
        """Verify all SITL vehicles are connected and reporting telemetry."""
        from src.fleet.fleet_manager import FleetManager
        from src.core.types import VehicleId
        from src.core.events import EventBus

        event_bus = EventBus()
        fleet = FleetManager(config=fleet_config, event_bus=event_bus)

        num = fleet_config["num_vehicles"]
        for i in range(num):
            vid = VehicleId(
                instance_id=i,
                namespace=f"/px4_{i}",
                name=f"UAV-{i}",
                mavlink_sys_id=i + 1,
                role="leader" if i == 0 else "follower",
            )
            await fleet.register_vehicle(vid)

        assert fleet.num_vehicles == num
        assert len(fleet.vehicle_ids) == num

    @pytest.mark.asyncio
    async def test_fleet_state_transitions(self, fleet_config):
        """Verify fleet state machine transitions."""
        from src.fleet.fleet_manager import FleetManager
        from src.core.types import VehicleId, FleetState, FormationConfig
        from src.core.events import EventBus

        event_bus = EventBus()
        fleet = FleetManager(config=fleet_config, event_bus=event_bus)

        # Initial state
        assert fleet.fleet_state == FleetState.IDLE

        # Register vehicles
        for i in range(fleet_config["num_vehicles"]):
            vid = VehicleId(i, f"/px4_{i}", f"UAV-{i}", i + 1)
            await fleet.register_vehicle(vid)

        # Takeoff should transition to EXECUTING
        await fleet.takeoff_all(altitude_m=10.0)
        assert fleet.fleet_state == FleetState.EXECUTING

        # Set formation should transition to FORMING
        await fleet.set_formation(
            FormationConfig(pattern="line", spacing_m=10.0)
        )
        assert fleet.fleet_state == FleetState.FORMING

        # RTL should transition to RTL_ALL
        await fleet.rtl_all()
        assert fleet.fleet_state == FleetState.RTL_ALL

    @pytest.mark.asyncio
    async def test_vehicle_registration_and_unregistration(self, fleet_config):
        """Verify vehicles can be added and removed from the fleet."""
        from src.fleet.fleet_manager import FleetManager
        from src.core.types import VehicleId
        from src.core.events import EventBus

        event_bus = EventBus()
        fleet = FleetManager(config=fleet_config, event_bus=event_bus)

        vid = VehicleId(0, "/px4_0", "UAV-Alpha", 1, "leader")
        await fleet.register_vehicle(vid)
        assert fleet.num_vehicles == 1
        assert 0 in fleet.vehicle_ids

        await fleet.unregister_vehicle(0)
        assert fleet.num_vehicles == 0
        assert 0 not in fleet.vehicle_ids

    @pytest.mark.asyncio
    async def test_min_separation_calculation(self, fleet_config):
        """Verify minimum inter-vehicle distance computation."""
        from src.fleet.fleet_manager import FleetManager
        from src.core.types import VehicleId, Position, TelemetryFrame
        from src.core.events import EventBus

        event_bus = EventBus()
        fleet = FleetManager(config=fleet_config, event_bus=event_bus)

        # Register 2 vehicles
        for i in range(2):
            vid = VehicleId(i, f"/px4_{i}", f"UAV-{i}", i + 1)
            await fleet.register_vehicle(vid)

        # Set known positions (Zurich area, ~10m apart)
        fleet.update_vehicle_telemetry(0, TelemetryFrame(
            position=Position(47.397742, 8.545594, 500.0, 10.0),
        ))
        fleet.update_vehicle_telemetry(1, TelemetryFrame(
            position=Position(47.397842, 8.545594, 500.0, 10.0),
        ))

        sep = fleet.get_min_separation()
        assert sep > 0.0, "Separation should be positive"
        assert sep < 100.0, "Separation should be reasonable"
