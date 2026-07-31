"""
Abstract interfaces (ABCs) — Dependency Inversion Principle.

Every subsystem has an abstract interface. Consumers depend on these
abstractions, never on concrete implementations. This allows swapping
MAVSDK for ROS 2, YOLOv8 for TensorRT, etc. without touching consumer code.
"""
from __future__ import annotations

from abc import ABC, abstractmethod
from typing import List, Optional, Tuple

import numpy as np

from src.core.types import (
    TelemetryFrame, Detection, Track, GeotaggedDetection,
    SafetyAction, Waypoint,
    VehicleId, VehicleTelemetry, FleetState, FormationConfig, FleetCommand,
)


# ──────────────────────────────────────────────────────────────
# Bridge
# ──────────────────────────────────────────────────────────────

class DroneConnector(ABC):
    """Abstract drone connection manager.

    Implementations: MAVSDKConnector (MAVSDK), ROS2Connector (ROS 2), etc.
    """

    @abstractmethod
    async def connect(self) -> None:
        """Establish connection to the drone / simulator."""

    @abstractmethod
    async def disconnect(self) -> None:
        """Gracefully disconnect."""

    @abstractmethod
    async def wait_for_ready(self, timeout: float = 60.0) -> None:
        """Wait for vehicle health checks (GPS fix, home position)."""

    @property
    @abstractmethod
    def is_connected(self) -> bool:
        """Whether the connection is active."""

    @property
    @abstractmethod
    def latest_telemetry(self) -> Optional[TelemetryFrame]:
        """Most recent telemetry snapshot (non-blocking)."""

    @abstractmethod
    async def start_telemetry_stream(
        self, rate_hz: float = 10.0, callback=None
    ) -> None:
        """Start background telemetry collection."""

    @abstractmethod
    async def stop_telemetry_stream(self) -> None:
        """Stop background telemetry collection."""


class FlightController(ABC):
    """Abstract flight command interface.

    Implementations: MAVSDKFlightController, ROS2FlightController, etc.
    """

    @abstractmethod
    async def arm(self) -> None: ...

    @abstractmethod
    async def disarm(self) -> None: ...

    @abstractmethod
    async def takeoff(self, altitude_m: float = 15.0) -> None: ...

    @abstractmethod
    async def land(self) -> None: ...

    @abstractmethod
    async def rtl(self) -> None: ...

    @abstractmethod
    async def hold(self) -> None: ...

    @abstractmethod
    async def goto(
        self, latitude_deg: float, longitude_deg: float,
        altitude_m: float, yaw_deg: float = float("nan"),
    ) -> None: ...

    @abstractmethod
    async def wait_for_altitude(
        self, target_m: float, tolerance_m: float = 1.0,
        timeout_s: float = 30.0,
    ) -> bool: ...

    @abstractmethod
    async def wait_for_landed(self, timeout_s: float = 60.0) -> bool: ...

    @abstractmethod
    async def wait_for_disarmed(self, timeout_s: float = 60.0) -> bool: ...

    @property
    @abstractmethod
    def is_offboard_active(self) -> bool: ...

    @abstractmethod
    async def stop_offboard(self) -> None: ...


# ──────────────────────────────────────────────────────────────
# Perception
# ──────────────────────────────────────────────────────────────

class CameraSource(ABC):
    """Abstract camera interface.

    Implementations: GstreamerCamera, VideoFileCamera, TestPatternCamera.
    """

    @abstractmethod
    def open(self) -> bool:
        """Open the camera source. Returns True if successful."""

    @abstractmethod
    def get_frame(self) -> Optional[np.ndarray]:
        """Capture a single BGR frame, or None on failure."""

    @abstractmethod
    def release(self) -> None:
        """Release camera resources."""

    @property
    @abstractmethod
    def frame_count(self) -> int:
        """Total frames captured."""

    def __enter__(self):
        self.open()
        return self

    def __exit__(self, *exc):
        self.release()


class ObjectDetector(ABC):
    """Abstract object detection interface.

    Implementations: YOLODetector, ONNXDetector, TensorRTDetector.
    """

    @abstractmethod
    def load(self) -> None:
        """Load the model weights."""

    @abstractmethod
    def detect(self, frame: np.ndarray) -> List[Detection]:
        """Run inference on a BGR frame. Returns list of detections."""

    @property
    @abstractmethod
    def avg_inference_ms(self) -> float:
        """Average inference time in milliseconds."""


class ObjectTracker(ABC):
    """Abstract multi-object tracker interface.

    Implementations: ByteTrackTracker, SortTracker, etc.
    """

    @abstractmethod
    def update(self, detections: List[Detection]) -> List[Track]:
        """Update tracks with new detections. Returns active tracks."""

    @abstractmethod
    def reset(self) -> None:
        """Clear all tracks."""


class Geotagger(ABC):
    """Abstract GPS geotagging interface."""

    @abstractmethod
    def tag_detections(
        self,
        tracks: List[Track],
        drone_lat: float, drone_lon: float,
        drone_alt: float, drone_heading_deg: float,
        timestamp: float,
    ) -> List[GeotaggedDetection]:
        """Add GPS coordinates to tracked detections."""


# ──────────────────────────────────────────────────────────────
# Mission
# ──────────────────────────────────────────────────────────────

class SearchPatternStrategy(ABC):
    """Strategy interface for search pattern generation (OCP).

    To add a new pattern: create a new class, register it — no
    existing code needs to change.
    """

    @property
    @abstractmethod
    def name(self) -> str:
        """Human-readable pattern name for config/API."""

    @abstractmethod
    def generate(self, config: dict) -> List[Waypoint]:
        """Generate waypoints from configuration parameters."""


class SafetyRule(ABC):
    """Single safety check (Chain of Responsibility link).

    Each rule inspects one aspect of telemetry and returns a SafetyAction.
    """

    @property
    @abstractmethod
    def name(self) -> str:
        """Human-readable rule name for logging."""

    @abstractmethod
    def evaluate(self, telemetry: TelemetryFrame) -> SafetyAction:
        """Evaluate this rule. Returns SafetyAction.NONE if OK."""


class SafetyChecker(ABC):
    """Composite safety checker that runs all rules."""

    @abstractmethod
    def check(self, telemetry: TelemetryFrame) -> SafetyAction:
        """Run all rules. Return the highest-priority action."""

    @abstractmethod
    def add_rule(self, rule: SafetyRule) -> None:
        """Add a safety rule to the chain."""


# ──────────────────────────────────────────────────────────────
# Reports
# ──────────────────────────────────────────────────────────────

class ReportGenerator(ABC):
    """Abstract report generator."""

    @property
    @abstractmethod
    def format_name(self) -> str:
        """e.g. 'pdf', 'csv'."""

    @abstractmethod
    def generate(
        self, output_path: str, detections: list,
        mission_duration_s: float, waypoint_count: int,
    ) -> None:
        """Generate and write the report file."""


# ──────────────────────────────────────────────────────────────
# Multi-Vehicle Interfaces
# ──────────────────────────────────────────────────────────────

class MultiVehicleConnector(ABC):
    """Manages connections to multiple vehicles.

    Extends the single-vehicle DroneConnector pattern to support
    a fleet of vehicles, each with its own telemetry stream and
    command channel.
    """

    @abstractmethod
    async def register_vehicle(self, vehicle_id: VehicleId) -> None:
        """Register a new vehicle with the connector."""

    @abstractmethod
    async def unregister_vehicle(self, instance_id: int) -> None:
        """Remove a vehicle from the connector."""

    @abstractmethod
    def get_vehicle_telemetry(
        self, instance_id: int,
    ) -> Optional[VehicleTelemetry]:
        """Get the latest telemetry for a specific vehicle."""

    @abstractmethod
    def get_all_telemetry(self) -> dict:
        """Get telemetry for all connected vehicles."""

    @abstractmethod
    async def send_command(self, command: FleetCommand) -> None:
        """Send a command to one or all vehicles."""


class FleetCoordinatorInterface(ABC):
    """Coordinates multi-vehicle operations.

    Manages fleet state machine, formation control, and
    coordinated mission execution.
    """

    @abstractmethod
    async def set_formation(self, config: FormationConfig) -> None:
        """Set the fleet formation pattern."""

    @abstractmethod
    async def execute_formation(self) -> None:
        """Compute and send formation positions to all vehicles."""

    @abstractmethod
    async def scatter(self) -> None:
        """Emergency scatter — all vehicles move away from each other."""

    @abstractmethod
    def get_fleet_state(self) -> FleetState:
        """Get the current fleet coordination state."""

    @abstractmethod
    async def takeoff_all(self, altitude_m: float) -> None:
        """Command all vehicles to take off."""

    @abstractmethod
    async def land_all(self) -> None:
        """Command all vehicles to land."""

    @abstractmethod
    async def rtl_all(self) -> None:
        """Command all vehicles to return to launch."""


class OffboardControllerInterface(ABC):
    """Per-vehicle offboard mode controller.

    Manages the PX4 offboard control lifecycle for a single vehicle:
    start/stop offboard mode and send position/velocity setpoints.
    """

    @abstractmethod
    async def start_offboard(self) -> None:
        """Enter offboard control mode."""

    @abstractmethod
    async def stop_offboard(self) -> None:
        """Exit offboard control mode."""

    @abstractmethod
    async def send_position_setpoint(
        self, x: float, y: float, z: float, yaw: float,
    ) -> None:
        """Send a position setpoint in NED frame (meters, radians)."""

    @abstractmethod
    async def send_velocity_setpoint(
        self, vx: float, vy: float, vz: float, yaw_rate: float,
    ) -> None:
        """Send a velocity setpoint in NED frame (m/s, rad/s)."""
