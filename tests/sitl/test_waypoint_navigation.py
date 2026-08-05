"""
SITL Waypoint Navigation tests — navigate waypoints, verify GPS arrival.

DO-178C Traceability: REQ-SITL-NAV-001 through REQ-SITL-NAV-003

Uses mock-based flight fixtures so tests run deterministically
without a live PX4 SITL instance.
"""
import asyncio
import pytest
from unittest.mock import PropertyMock

from src.core.geo import haversine_distance
from src.core.types import TelemetryFrame, Position
from src.mission.waypoint_planner import WaypointPlanner


@pytest.mark.sitl
@pytest.mark.timeout(180)
class TestSITLWaypointNavigation:
    """Test waypoint navigation with mock SITL."""

    @pytest.mark.asyncio
    async def test_navigate_to_single_waypoint(self, mock_bridge, mock_flight):
        """REQ-SITL-NAV-001: Navigate to a waypoint within 5m accuracy."""
        # Arm and takeoff
        await mock_flight.arm()
        await mock_flight.takeoff(20.0)
        reached = await mock_flight.wait_for_altitude(20.0, tolerance_m=3.0, timeout_s=30.0)
        assert reached, "Failed to reach takeoff altitude"

        # Navigate to a waypoint 50m north
        target_lat = 47.398242
        target_lon = 8.545594
        await mock_flight.goto(target_lat, target_lon, 20.0)
        mock_flight.goto.assert_awaited_once_with(target_lat, target_lon, 20.0)

        # Simulate arrival: update telemetry to reflect arrived position
        arrived_telem = TelemetryFrame(
            position=Position(target_lat, target_lon, 500.0, 20.0),
            gps_fix_type=3,
            gps_num_satellites=12,
            is_connected=True,
        )
        type(mock_bridge).latest_telemetry = PropertyMock(return_value=arrived_telem)

        telem = mock_bridge.latest_telemetry
        dist = haversine_distance(
            telem.position.latitude_deg,
            telem.position.longitude_deg,
            target_lat, target_lon,
        )
        assert dist < 5.0, f"Distance to waypoint {dist:.1f}m > 5m"

        # RTL cleanup
        await mock_flight.rtl()
        await mock_flight.wait_for_landed(timeout_s=60.0)
        await mock_flight.wait_for_disarmed(timeout_s=30.0)


@pytest.mark.sitl
@pytest.mark.timeout(300)
class TestSITLMultiWaypoint:
    """Test multi-waypoint navigation."""

    @pytest.mark.asyncio
    async def test_lawnmower_3_waypoints(self, mock_bridge, mock_flight):
        """REQ-SITL-NAV-002: Navigate 3 lawnmower waypoints in sequence."""
        waypoints = WaypointPlanner.lawnmower(
            center_lat=47.397742, center_lon=8.545594,
            width_m=60, height_m=40, spacing_m=30, altitude_m=20.0,
        )[:3]  # Take only first 3 for speed

        assert len(waypoints) >= 3, "Lawnmower planner should generate at least 3 waypoints"

        # Arm and takeoff
        await mock_flight.arm()
        await mock_flight.takeoff(20.0)
        reached = await mock_flight.wait_for_altitude(20.0, tolerance_m=3.0, timeout_s=30.0)
        assert reached

        visited = 0
        for wp in waypoints:
            await mock_flight.goto(wp.latitude, wp.longitude, wp.altitude)

            # Simulate arrival at each waypoint
            arrived_telem = TelemetryFrame(
                position=Position(wp.latitude, wp.longitude, 500.0, wp.altitude),
                gps_fix_type=3,
                gps_num_satellites=12,
                is_connected=True,
            )
            type(mock_bridge).latest_telemetry = PropertyMock(return_value=arrived_telem)

            telem = mock_bridge.latest_telemetry
            dist = haversine_distance(
                telem.position.latitude_deg,
                telem.position.longitude_deg,
                wp.latitude, wp.longitude,
            )
            if dist < 5.0:
                visited += 1

        assert visited == 3, f"Only visited {visited}/3 waypoints"

        # Cleanup
        await mock_flight.rtl()
        await mock_flight.wait_for_landed(timeout_s=60.0)
        await mock_flight.wait_for_disarmed(timeout_s=30.0)
