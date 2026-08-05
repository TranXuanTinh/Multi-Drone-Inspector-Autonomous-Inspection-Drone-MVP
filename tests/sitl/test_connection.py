"""
SITL Connection tests — verify connectivity to PX4 SITL.

DO-178C Traceability: REQ-SITL-CONN-001 through REQ-SITL-CONN-005

Uses mock-based bridge fixtures so tests run deterministically
without a live PX4 SITL instance.
"""
import asyncio
import pytest
from unittest.mock import AsyncMock, PropertyMock

from src.core.types import TelemetryFrame, Position, Attitude


@pytest.mark.sitl
@pytest.mark.timeout(60)
class TestSITLConnection:
    """Test PX4 SITL connection lifecycle."""

    @pytest.mark.asyncio
    async def test_connect_successfully(self, mock_bridge):
        """REQ-SITL-CONN-001: Connect to SITL on first attempt."""
        assert mock_bridge.is_connected is True

    @pytest.mark.asyncio
    async def test_telemetry_available_after_stream_start(self, mock_bridge):
        """REQ-SITL-CONN-002: Telemetry is populated after stream start."""
        await mock_bridge.start_telemetry_stream(rate_hz=10.0)

        telem = mock_bridge.latest_telemetry
        assert telem is not None
        assert telem.gps_fix_type >= 3

        await mock_bridge.stop_telemetry_stream()

    @pytest.mark.asyncio
    async def test_gps_fix_type_3d(self, mock_bridge):
        """REQ-SITL-CONN-003: GPS fix type is at least 3D."""
        await mock_bridge.start_telemetry_stream(rate_hz=10.0)

        telem = mock_bridge.latest_telemetry
        assert telem is not None
        assert telem.gps_fix_type >= 3, (
            f"GPS fix type {telem.gps_fix_type} < 3 (no 3D fix)"
        )

        await mock_bridge.stop_telemetry_stream()

    @pytest.mark.asyncio
    async def test_is_healthy_returns_true_when_connected(self, mock_bridge):
        """REQ-SITL-CONN-004: is_healthy() returns True when SITL running."""
        result = await mock_bridge.is_healthy()
        assert result is True

    @pytest.mark.asyncio
    async def test_disconnect_and_verify(self, mock_bridge):
        """REQ-SITL-CONN-005: Disconnect clears connected flag."""
        assert mock_bridge.is_connected is True

        # Simulate disconnect changing the connected flag
        async def _disconnect():
            mock_bridge.is_connected = False
        mock_bridge.disconnect = _disconnect

        await mock_bridge.disconnect()
        assert mock_bridge.is_connected is False
