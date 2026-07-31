"""
SITL Test — Formation Flight.

Tests formation pattern generation and fleet formation control.
"""
from __future__ import annotations

import math
import pytest

pytestmark = [pytest.mark.sitl, pytest.mark.timeout(60)]


class TestFormationPatterns:
    """Test formation geometry computation."""

    def test_line_formation_positions(self):
        """Line formation should spread vehicles perpendicular to heading."""
        from src.fleet.formation_patterns import FormationPatternGenerator

        leader_pos = (47.397742, 8.545594, 20.0)
        positions = FormationPatternGenerator.line(
            leader_pos=leader_pos,
            num_vehicles=3,
            spacing_m=10.0,
            heading_deg=0.0,
        )

        assert len(positions) == 3
        # Leader should be at center (original position)
        assert positions[0] == leader_pos

        # Followers should be offset from leader
        for i in range(1, 3):
            lat, lon, alt = positions[i]
            assert alt == 20.0, "Altitude should match leader"
            assert lat != leader_pos[0] or lon != leader_pos[1], \
                f"Vehicle {i} should not be at leader position"

    def test_v_formation_positions(self):
        """V-formation should create a V shape behind leader."""
        from src.fleet.formation_patterns import FormationPatternGenerator

        leader_pos = (47.397742, 8.545594, 20.0)
        positions = FormationPatternGenerator.v_formation(
            leader_pos=leader_pos,
            num_vehicles=3,
            spacing_m=10.0,
            heading_deg=0.0,
            angle_deg=30.0,
        )

        assert len(positions) == 3
        assert positions[0] == leader_pos  # Leader at apex

    def test_circle_formation_positions(self):
        """Circle formation should distribute vehicles evenly."""
        from src.fleet.formation_patterns import FormationPatternGenerator

        center = (47.397742, 8.545594, 20.0)
        positions = FormationPatternGenerator.circle(
            leader_pos=center,
            num_vehicles=4,
            spacing_m=15.0,  # Used as radius
        )

        assert len(positions) == 4
        # All should be at the same altitude
        for lat, lon, alt in positions:
            assert alt == 20.0

    def test_diamond_formation_positions(self):
        """Diamond formation should create a diamond shape."""
        from src.fleet.formation_patterns import FormationPatternGenerator

        leader_pos = (47.397742, 8.545594, 20.0)
        positions = FormationPatternGenerator.diamond(
            leader_pos=leader_pos,
            num_vehicles=4,
            spacing_m=10.0,
        )

        assert len(positions) == 4
        assert positions[0] == leader_pos  # Leader at front

    def test_available_patterns(self):
        """Should list all available pattern names."""
        from src.fleet.formation_patterns import FormationPatternGenerator

        patterns = FormationPatternGenerator.available_patterns()
        assert "line" in patterns
        assert "v_formation" in patterns
        assert "circle" in patterns
        assert "diamond" in patterns

    def test_generate_dispatcher(self):
        """Static generate() should dispatch to correct pattern."""
        from src.fleet.formation_patterns import FormationPatternGenerator

        leader_pos = (47.397742, 8.545594, 20.0)

        for pattern in ["line", "v_formation", "circle", "diamond"]:
            positions = FormationPatternGenerator.generate(
                pattern=pattern,
                leader_pos=leader_pos,
                num_vehicles=3,
                spacing_m=10.0,
            )
            assert len(positions) == 3, f"Pattern {pattern} should produce 3 positions"

    def test_unknown_pattern_falls_back_to_line(self):
        """Unknown pattern should fall back to line formation."""
        from src.fleet.formation_patterns import FormationPatternGenerator

        leader_pos = (47.397742, 8.545594, 20.0)
        positions = FormationPatternGenerator.generate(
            pattern="nonexistent_pattern",
            leader_pos=leader_pos,
            num_vehicles=3,
            spacing_m=10.0,
        )
        assert len(positions) == 3


class TestFormationFlight:
    """Test fleet formation control integration."""

    @pytest.mark.asyncio
    async def test_set_formation_updates_config(self):
        """Setting formation should update fleet configuration."""
        from src.fleet.fleet_manager import FleetManager
        from src.core.types import FormationConfig, FleetState
        from src.core.events import EventBus

        fleet = FleetManager(config={}, event_bus=EventBus())
        config = FormationConfig(
            pattern="v_formation",
            spacing_m=8.0,
            heading_deg=45.0,
        )

        await fleet.set_formation(config)
        assert fleet.formation_config is not None
        assert fleet.formation_config.pattern == "v_formation"
        assert fleet.formation_config.spacing_m == 8.0
        assert fleet.fleet_state == FleetState.FORMING
