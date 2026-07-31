# Multi-UAV Platform — Testing Guide

This guide covers the automated testing framework for the Multi-UAV Autonomous Inspection Platform, including Python unit/integration tests, ROS 2 C++ node tests, and multi-vehicle SITL simulation tests.

## Testing Architecture

1. **Unit Tests** (`tests/unit/` & `ros2_ws/src/*/test/`)
   - Python unit tests (126 passing) for `FleetManager`, `FormationPatternGenerator`, `EventBus`, `SafetyMonitor`, `MissionStateMachine`, `MissionExecutor`, `ByteTrackWrapper`, `WaypointPlanner`, and `GPSGeotagger`.
   - C++ ROS 2 package unit tests for `vehicle_controller` and `fleet_manager`.
2. **Integration Tests** (`tests/integration/`)
   - Cross-component wiring and event distribution tests.
3. **Multi-Vehicle SITL Tests** (`tests/sitl/`)
   - `test_offboard_control.py`: ROS 2 bridge & offboard setpoints.
   - `test_formation_flight.py`: Line, V, Circle, and Diamond formation geometry tests.
   - `test_multi_vehicle_takeoff.py`: Multi-vehicle connection, state machine, and minimum separation checks.
4. **Failsafe & Safety Tests** (`tests/failsafe/`)
   - Battery failsafes, geofencing limits, altitude ceilings, and separation rule checks.

---

## Environment

All tests run in the **Miniconda `base`** environment. The `transitions` and `pytest-asyncio` packages are required:

```bash
conda activate base
pip install transitions pytest-asyncio pytest-timeout pytest-cov
```

---

## Running Tests

### 1. Python Unit Tests (No SITL Required)

```bash
conda activate base

# Run all 126 unit tests
/home/tinhtran/miniconda3/bin/python3 -m pytest tests/unit/ -v

# Run with coverage report
/home/tinhtran/miniconda3/bin/python3 -m pytest tests/unit/ --cov=src --cov-report=term-missing -v
```

### 2. SITL Integration Tests (Requires Running PX4)

```bash
# First start PX4 SITL in another terminal:
# ./scripts/launch_multi_sitl.sh --num 3 --xrce

# Then run SITL tests:
/home/tinhtran/miniconda3/bin/python3 -m pytest tests/sitl/ -v
```

> **Note**: SITL tests are automatically skipped when PX4 is not running. The `conftest.py` probes UDP port 14540 to detect SITL availability.

### 3. Full Test Suite

```bash
# Run all test layers via the test runner script
./scripts/run_tests.sh
```

### 4. ROS 2 C++ Package Tests

```bash
# Build and run C++ tests for vehicle_controller and fleet_manager
./scripts/build_ros2.sh --test
```

---

## Test Configuration

Test configuration is defined in `pyproject.toml`:

```toml
[tool.pytest.ini_options]
asyncio_mode = "auto"           # Async tests run automatically
testpaths = ["tests"]
timeout = 30                     # Per-test timeout in seconds
```

### Custom Markers

| Marker | Description |
|:---|:---|
| `@pytest.mark.unit` | Unit tests — no SITL or hardware required |
| `@pytest.mark.integration` | Integration tests — no SITL required |
| `@pytest.mark.sitl` | SITL tests — auto-skipped when PX4 is not running |
| `@pytest.mark.failsafe` | Failsafe & safety scenario tests |
| `@pytest.mark.protocol` | Communication protocol tests |
| `@pytest.mark.hitl` | Hardware-in-the-loop tests (always skipped without hardware) |

---

## Known Issues (Resolved)

- **`TestPatternCamera` pytest warning**: The `TestPatternCamera` class in `src/perception/camera.py` previously triggered a `PytestCollectionWarning` because its name starts with `Test`. Fixed by adding `__test__ = False` to the class.
- **`transitions` module not found**: The system Python may not have `transitions` installed. Always use the miniconda environment: `/home/tinhtran/miniconda3/bin/python3 -m pytest`.
