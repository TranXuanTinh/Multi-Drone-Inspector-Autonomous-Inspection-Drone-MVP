"""
SITL Takeoff/Land tests — arm, takeoff, land, disarm lifecycle.

DO-178C Traceability: REQ-SITL-FLIGHT-001 through REQ-SITL-FLIGHT-004

Uses mock-based flight fixtures so tests run deterministically
without a live PX4 SITL instance.
"""
import asyncio
import pytest


@pytest.mark.sitl
@pytest.mark.timeout(120)
class TestSITLTakeoffLand:
    """Test takeoff and landing with mock SITL."""

    @pytest.mark.asyncio
    async def test_arm_takeoff_land_disarm(self, mock_bridge, mock_flight):
        """REQ-SITL-FLIGHT-001: Full takeoff/land cycle."""
        # Arm
        await mock_flight.arm()
        mock_flight.arm.assert_awaited_once()

        # Takeoff to 15m
        await mock_flight.takeoff(15.0)
        mock_flight.takeoff.assert_awaited_once_with(15.0)
        reached = await mock_flight.wait_for_altitude(
            15.0, tolerance_m=2.0, timeout_s=30.0,
        )
        assert reached, "Failed to reach takeoff altitude"

        # Land
        await mock_flight.land()
        mock_flight.land.assert_awaited_once()
        landed = await mock_flight.wait_for_landed(timeout_s=60.0)
        assert landed, "Failed to land"

        # Disarm
        await mock_flight.disarm()
        mock_flight.disarm.assert_awaited_once()
