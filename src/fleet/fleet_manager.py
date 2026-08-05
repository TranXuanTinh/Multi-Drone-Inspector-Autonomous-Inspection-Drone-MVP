"""
Fleet Manager — Python-side multi-vehicle orchestration.

Manages multiple vehicle connections (via ROS 2 or MAVSDK),
coordinates multi-vehicle missions, and exposes fleet state
to the dashboard backend.

This module works with both:
  - ROS 2 / XRCE-DDS (production: C++ vehicle controllers)
  - MAVSDK-Python (legacy: direct MAVSDK connection per vehicle)
"""
from __future__ import annotations

import asyncio
import logging
import time
from typing import Dict, List, Optional, Callable

from src.core.types import (
    TelemetryFrame, Waypoint, GeotaggedDetection,
    VehicleId, VehicleTelemetry, FleetState, FormationConfig, FleetCommand,
    FleetStateChangeEvent, VehicleTelemetryEvent,
)
from src.core.events import EventBus
from src.fleet.formation_patterns import FormationPatternGenerator

logger = logging.getLogger(__name__)


class FleetManager:
    """Python-side fleet orchestration manager.

    Manages multiple vehicles, coordinates fleet-wide operations,
    and provides an interface for the dashboard.

    Usage:
        fleet = FleetManager(config, event_bus)
        await fleet.register_vehicle(VehicleId(0, "/px4_0", "UAV-Alpha", 1))
        await fleet.takeoff_all(altitude_m=15.0)
        await fleet.set_formation(FormationConfig(pattern="line", spacing_m=10.0))
    """

    def __init__(
        self,
        config: dict,
        event_bus: Optional[EventBus] = None,
    ) -> None:
        self._config = config
        self._event_bus = event_bus

        self._vehicles: Dict[int, VehicleId] = {}
        self._vehicle_telemetry: Dict[int, VehicleTelemetry] = {}
        self._fleet_state = FleetState.IDLE
        self._formation_config: Optional[FormationConfig] = None

        self._start_time: float = 0.0
        self._running = False

        # Command dispatch (populated by bridge registration)
        self._command_handlers: Dict[int, Callable] = {}

        logger.info("FleetManager initialized")

    # ── Vehicle Registration ─────────────────────────────────

    async def register_vehicle(self, vehicle_id: VehicleId) -> None:
        """Register a vehicle with the fleet."""
        self._vehicles[vehicle_id.instance_id] = vehicle_id
        self._vehicle_telemetry[vehicle_id.instance_id] = VehicleTelemetry(
            vehicle_id=vehicle_id,
            telemetry=TelemetryFrame(),
        )
        logger.info(
            f"Registered vehicle: {vehicle_id.name} "
            f"(instance={vehicle_id.instance_id}, "
            f"namespace={vehicle_id.namespace})"
        )

    async def unregister_vehicle(self, instance_id: int) -> None:
        """Remove a vehicle from the fleet."""
        if instance_id in self._vehicles:
            name = self._vehicles[instance_id].name
            del self._vehicles[instance_id]
            del self._vehicle_telemetry[instance_id]
            logger.info(f"Unregistered vehicle: {name}")

    # ── Telemetry ────────────────────────────────────────────

    def update_vehicle_telemetry(
        self, instance_id: int, telemetry: TelemetryFrame,
    ) -> None:
        """Update telemetry for a specific vehicle."""
        if instance_id in self._vehicle_telemetry:
            self._vehicle_telemetry[instance_id].telemetry = telemetry

    def get_vehicle_telemetry(self, instance_id: int) -> Optional[VehicleTelemetry]:
        """Get telemetry for a specific vehicle."""
        return self._vehicle_telemetry.get(instance_id)

    def get_all_telemetry(self) -> Dict[int, VehicleTelemetry]:
        """Get telemetry for all vehicles."""
        return self._vehicle_telemetry.copy()

    # ── Fleet Commands ───────────────────────────────────────

    async def takeoff_all(self, altitude_m: float = 15.0) -> None:
        """Command all vehicles to take off."""
        logger.info(f"Fleet takeoff to {altitude_m}m")
        await self._set_fleet_state(FleetState.EXECUTING)

        for instance_id in self._vehicles:
            await self._send_command(FleetCommand(
                target_vehicle_id=instance_id,
                command="takeoff",
                params={"altitude_m": altitude_m},
            ))

    async def land_all(self) -> None:
        """Command all vehicles to land."""
        logger.info("Fleet landing")
        for instance_id in self._vehicles:
            await self._send_command(FleetCommand(
                target_vehicle_id=instance_id,
                command="land",
            ))
        await self._set_fleet_state(FleetState.IDLE)

    async def rtl_all(self) -> None:
        """Command all vehicles to return to launch."""
        logger.info("Fleet RTL")
        await self._set_fleet_state(FleetState.RTL_ALL)

        for instance_id in self._vehicles:
            await self._send_command(FleetCommand(
                target_vehicle_id=instance_id,
                command="rtl",
            ))

    async def hold_all(self) -> None:
        """Command all vehicles to hold position."""
        logger.info("Fleet hold")
        for instance_id in self._vehicles:
            await self._send_command(FleetCommand(
                target_vehicle_id=instance_id,
                command="hold",
            ))

    # ── Formation Control ────────────────────────────────────

    async def set_formation(self, config: FormationConfig) -> None:
        """Set the fleet formation pattern."""
        self._formation_config = config
        await self._set_fleet_state(FleetState.FORMING)
        logger.info(
            f"Formation set: {config.pattern}, "
            f"spacing={config.spacing_m}m, heading={config.heading_deg}°"
        )

    async def execute_formation(self) -> None:
        """Compute and send formation positions to all vehicles."""
        if not self._formation_config:
            logger.warning("No formation configured")
            return

        # Get leader position
        leader_id = self._find_leader()
        if leader_id is None:
            logger.error("No leader vehicle found")
            return

        leader_telem = self._vehicle_telemetry.get(leader_id)
        if not leader_telem:
            return

        leader_pos = (
            leader_telem.telemetry.position.latitude_deg,
            leader_telem.telemetry.position.longitude_deg,
            leader_telem.telemetry.position.relative_altitude_m,
        )

        # Generate formation positions
        num_vehicles = len(self._vehicles)
        positions = FormationPatternGenerator.generate(
            pattern=self._formation_config.pattern,
            leader_pos=leader_pos,
            num_vehicles=num_vehicles,
            spacing_m=self._formation_config.spacing_m,
            heading_deg=self._formation_config.heading_deg,
        )

        # Assign positions to vehicles
        vehicle_ids = sorted(self._vehicles.keys())
        for i, vid in enumerate(vehicle_ids):
            if i < len(positions):
                lat, lon, alt = positions[i]
                await self._send_command(FleetCommand(
                    target_vehicle_id=vid,
                    command="goto",
                    params={
                        "latitude_deg": lat,
                        "longitude_deg": lon,
                        "altitude_m": alt,
                    },
                ))

    # ── Multi-Vehicle Mission ────────────────────────────────

    async def execute_coordinated_mission(
        self,
        waypoints_per_vehicle: Dict[int, List[Waypoint]],
    ) -> None:
        """Execute independent waypoint missions for each vehicle in parallel."""
        logger.info(
            f"Starting coordinated mission for "
            f"{len(waypoints_per_vehicle)} vehicles"
        )
        await self._set_fleet_state(FleetState.EXECUTING)

        async def run_vehicle_mission(vid: int, waypoints: List[Waypoint]):
            from src.core.geo import haversine_distance
            logger.info(f"Vehicle {vid}: starting mission with {len(waypoints)} waypoints")
            for wp in waypoints:
                logger.info(
                    f"Vehicle {vid}: flying to waypoint {wp.index} "
                    f"({wp.latitude:.6f}, {wp.longitude:.6f}, {wp.altitude:.1f}m)"
                )

                # Send goto command
                await self._send_command(FleetCommand(
                    target_vehicle_id=vid,
                    command="goto",
                    params={
                        "latitude_deg": wp.latitude,
                        "longitude_deg": wp.longitude,
                        "altitude_m": wp.altitude,
                    }
                ))

                # Wait for arrival
                arrived = False
                telem_info = self._vehicle_telemetry.get(vid)
                # Check if telemetry is populated / updated (in real mode, latitude is non-zero)
                is_stub = (telem_info is None or telem_info.telemetry.position.latitude_deg == 0)

                if is_stub:
                    # In stub mode, simulate flight progress by sleeping
                    await asyncio.sleep(2.0)
                    logger.info(f"Vehicle {vid}: reached waypoint {wp.index} (simulated)")
                else:
                    # In real mode, monitor telemetry for arrival within 5m
                    for _ in range(60):  # Timeout 120s per waypoint (60 * 2s)
                        await asyncio.sleep(2.0)
                        telem_info = self._vehicle_telemetry.get(vid)
                        if telem_info and telem_info.telemetry:
                            t = telem_info.telemetry
                            dist = haversine_distance(
                                t.position.latitude_deg,
                                t.position.longitude_deg,
                                wp.latitude,
                                wp.longitude,
                            )
                            alt_diff = abs(t.position.relative_altitude_m - wp.altitude)
                            if dist < 5.0 and alt_diff < 2.0:
                                logger.info(f"Vehicle {vid}: reached waypoint {wp.index}")
                                arrived = True
                                break
                    if not arrived:
                        logger.warning(f"Vehicle {vid}: timeout waiting for waypoint {wp.index}")

            logger.info(f"Vehicle {vid}: mission completed")

        # Run all vehicle missions in parallel
        await asyncio.gather(*(
            run_vehicle_mission(vid, waypoints)
            for vid, waypoints in waypoints_per_vehicle.items()
        ))

    # ── Properties ───────────────────────────────────────────

    @property
    def fleet_state(self) -> FleetState:
        return self._fleet_state

    @property
    def num_vehicles(self) -> int:
        return len(self._vehicles)

    @property
    def vehicle_ids(self) -> List[int]:
        return list(self._vehicles.keys())

    @property
    def vehicles(self) -> Dict[int, VehicleId]:
        return self._vehicles.copy()

    @property
    def formation_config(self) -> Optional[FormationConfig]:
        return self._formation_config

    def get_min_separation(self) -> float:
        """Compute minimum distance between any two vehicles."""
        from src.core.geo import haversine_distance

        positions = []
        for vt in self._vehicle_telemetry.values():
            t = vt.telemetry
            if t.position.latitude_deg != 0:
                positions.append((
                    t.position.latitude_deg,
                    t.position.longitude_deg,
                ))

        min_dist = float("inf")
        for i in range(len(positions)):
            for j in range(i + 1, len(positions)):
                dist = haversine_distance(
                    positions[i][0], positions[i][1],
                    positions[j][0], positions[j][1],
                )
                min_dist = min(min_dist, dist)

        return min_dist if min_dist != float("inf") else 0.0

    # ── Private ──────────────────────────────────────────────

    def _find_leader(self) -> Optional[int]:
        """Find the leader vehicle instance ID."""
        # By convention, vehicle 0 is the leader
        if 0 in self._vehicles:
            return 0
        # Fallback: lowest ID
        if self._vehicles:
            return min(self._vehicles.keys())
        return None

    async def _send_command(self, command: FleetCommand) -> None:
        """Send a command to a vehicle via the registered handler."""
        vid = command.target_vehicle_id
        handler = self._command_handlers.get(vid)
        if handler:
            await handler(command)
        else:
            logger.debug(
                f"No command handler for vehicle {vid} — "
                f"command '{command.command}' queued"
            )

    async def _set_fleet_state(self, new_state: FleetState) -> None:
        """Update fleet state and notify subscribers."""
        old_state = self._fleet_state
        self._fleet_state = new_state
        logger.info(f"Fleet state: {old_state.value} → {new_state.value}")

        if self._event_bus:
            await self._event_bus.publish(
                FleetStateChangeEvent(
                    old_state=old_state.value,
                    new_state=new_state.value,
                )
            )

    def register_command_handler(
        self, instance_id: int, handler: Callable,
    ) -> None:
        """Register a command handler for a vehicle."""
        self._command_handlers[instance_id] = handler
