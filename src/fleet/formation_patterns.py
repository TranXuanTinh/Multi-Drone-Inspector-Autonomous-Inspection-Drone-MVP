"""
Formation Patterns — Python formation geometry generator.

Mirrors the C++ FormationController for Python-side usage.
Generates GPS-based formation positions for multi-vehicle operations.
"""
from __future__ import annotations

import math
import logging
from typing import List, Tuple

from src.core.geo import offset_gps

logger = logging.getLogger(__name__)


class FormationPatternGenerator:
    """Generate per-vehicle GPS positions for various formations.

    All positions are in GPS coordinates (lat, lon, alt).
    The generator uses offset_gps() to compute positions relative
    to the leader/center position.
    """

    @staticmethod
    def generate(
        pattern: str,
        leader_pos: Tuple[float, float, float],
        num_vehicles: int,
        spacing_m: float,
        heading_deg: float = 0.0,
        **kwargs,
    ) -> List[Tuple[float, float, float]]:
        """Generate formation positions for the given pattern.

        Args:
            pattern: Pattern name ("line", "v_formation", "circle", "diamond")
            leader_pos: (lat, lon, alt) of the leader/center
            num_vehicles: Total number of vehicles
            spacing_m: Inter-vehicle distance in meters
            heading_deg: Formation heading in degrees (0=North)

        Returns:
            List of (lat, lon, alt) tuples, one per vehicle.
        """
        generators = {
            "line": FormationPatternGenerator.line,
            "v_formation": FormationPatternGenerator.v_formation,
            "circle": FormationPatternGenerator.circle,
            "diamond": FormationPatternGenerator.diamond,
        }

        gen = generators.get(pattern)
        if gen is None:
            logger.warning(
                f"Unknown formation pattern '{pattern}', using line"
            )
            gen = FormationPatternGenerator.line

        return gen(
            leader_pos=leader_pos,
            num_vehicles=num_vehicles,
            spacing_m=spacing_m,
            heading_deg=heading_deg,
            **kwargs,
        )

    @staticmethod
    def line(
        leader_pos: Tuple[float, float, float],
        num_vehicles: int,
        spacing_m: float,
        heading_deg: float = 0.0,
        **kwargs,
    ) -> List[Tuple[float, float, float]]:
        """Line formation perpendicular to heading.

        Leader at center, followers alternate left/right.

        Example (heading=0°/North, 5 vehicles):
            2   0   1
            4       3
        """
        lat, lon, alt = leader_pos
        heading_rad = math.radians(heading_deg)

        # Perpendicular direction (East when heading=North)
        perp_rad = heading_rad + math.pi / 2

        positions = []
        for i in range(num_vehicles):
            if i == 0:
                # Leader at center
                positions.append((lat, lon, alt))
            else:
                # Alternate right/left
                side = 1 if (i % 2 == 1) else -1
                rank = (i + 1) // 2
                offset = side * rank * spacing_m

                # Offset in perpendicular direction
                north_offset = offset * math.cos(perp_rad)
                east_offset = offset * math.sin(perp_rad)

                new_lat, new_lon = offset_gps(
                    lat, lon, north_offset, east_offset,
                )
                positions.append((new_lat, new_lon, alt))

        logger.debug(
            f"Line formation: {num_vehicles} vehicles, "
            f"spacing={spacing_m}m, heading={heading_deg}°"
        )
        return positions

    @staticmethod
    def v_formation(
        leader_pos: Tuple[float, float, float],
        num_vehicles: int,
        spacing_m: float,
        heading_deg: float = 0.0,
        angle_deg: float = 30.0,
        **kwargs,
    ) -> List[Tuple[float, float, float]]:
        """V-formation with leader at apex.

        Example (3 vehicles, heading=North):
                0         ← Leader (apex)
              1   2       ← Followers behind & to sides
        """
        lat, lon, alt = leader_pos
        heading_rad = math.radians(heading_deg)
        angle_rad = math.radians(angle_deg)

        positions = [(lat, lon, alt)]  # Leader at apex

        for i in range(1, num_vehicles):
            side = 1 if (i % 2 == 1) else -1
            rank = (i + 1) // 2

            # Behind and to the side
            back_offset = rank * spacing_m * math.cos(angle_rad)
            side_offset = side * rank * spacing_m * math.sin(angle_rad)

            # Rotate by heading
            north = -back_offset * math.cos(heading_rad) + side_offset * math.sin(heading_rad)
            east = -back_offset * math.sin(heading_rad) - side_offset * math.cos(heading_rad)

            new_lat, new_lon = offset_gps(lat, lon, north, east)
            positions.append((new_lat, new_lon, alt))

        logger.debug(
            f"V-formation: {num_vehicles} vehicles, "
            f"spacing={spacing_m}m, angle={angle_deg}°"
        )
        return positions

    @staticmethod
    def circle(
        leader_pos: Tuple[float, float, float],
        num_vehicles: int,
        spacing_m: float,
        heading_deg: float = 0.0,
        **kwargs,
    ) -> List[Tuple[float, float, float]]:
        """Circle formation with vehicles evenly distributed.

        The spacing_m parameter is treated as the radius.
        """
        lat, lon, alt = leader_pos
        radius_m = spacing_m

        positions = []
        for i in range(num_vehicles):
            angle = 2.0 * math.pi * i / num_vehicles
            north = radius_m * math.cos(angle)
            east = radius_m * math.sin(angle)

            new_lat, new_lon = offset_gps(lat, lon, north, east)
            positions.append((new_lat, new_lon, alt))

        logger.debug(
            f"Circle formation: {num_vehicles} vehicles, radius={radius_m}m"
        )
        return positions

    @staticmethod
    def diamond(
        leader_pos: Tuple[float, float, float],
        num_vehicles: int,
        spacing_m: float,
        heading_deg: float = 0.0,
        **kwargs,
    ) -> List[Tuple[float, float, float]]:
        """Diamond formation (best with 4 vehicles).

        Example:
              0         ← Leader (front)
            1   2       ← Wings
              3         ← Tail
        """
        lat, lon, alt = leader_pos
        heading_rad = math.radians(heading_deg)

        # Relative offsets (forward, right) in heading frame
        offsets = [
            (0.0, 0.0),                                     # Leader
            (-spacing_m, -spacing_m * 0.7),                  # Left wing
            (-spacing_m, spacing_m * 0.7),                   # Right wing
            (-spacing_m * 2.0, 0.0),                         # Tail
        ]

        # Extend for additional vehicles
        for i in range(4, num_vehicles):
            rank = (i - 3 + 1) // 2 + 1
            side = -1 if (i % 2 == 0) else 1
            offsets.append(
                (-rank * spacing_m, side * rank * spacing_m * 0.5)
            )

        positions = []
        for fwd, rgt in offsets[:num_vehicles]:
            # Rotate by heading
            north = fwd * math.cos(heading_rad) + rgt * math.sin(heading_rad)
            east = fwd * math.sin(heading_rad) - rgt * math.cos(heading_rad)

            new_lat, new_lon = offset_gps(lat, lon, north, east)
            positions.append((new_lat, new_lon, alt))

        logger.debug(
            f"Diamond formation: {num_vehicles} vehicles, spacing={spacing_m}m"
        )
        return positions

    @staticmethod
    def available_patterns() -> List[str]:
        """List available formation pattern names."""
        return ["line", "v_formation", "circle", "diamond"]
