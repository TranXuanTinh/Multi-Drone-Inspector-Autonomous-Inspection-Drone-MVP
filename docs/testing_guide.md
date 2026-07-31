# Multi-UAV Platform — Testing Guide

This guide covers the automated testing framework for the Multi-UAV Autonomous Inspection Platform, including Python unit/integration tests, ROS 2 C++ node tests, and multi-vehicle SITL simulation tests.

## Testing Architecture

1. **Unit Tests** (`tests/unit/` & `ros2_ws/src/*/test/`)
   - Python unit tests (126 passing) for `FleetManager`, `FormationPatternGenerator`, `EventBus`, `SafetyMonitor`.
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

## Running Tests

### 1. Python Test Suite

```bash
# Activate Miniconda environment
conda activate base

# Run offline unit tests
./scripts/run_tests.sh --layer unit

# Run multi-vehicle formation & offboard tests
python3 -m pytest tests/sitl/test_formation_flight.py tests/sitl/test_offboard_control.py -v

# Run full test runner script
./scripts/run_tests.sh
```

### 2. ROS 2 C++ Package Tests

```bash
# Build and run C++ tests for vehicle_controller and fleet_manager
./scripts/build_ros2.sh --test
```
