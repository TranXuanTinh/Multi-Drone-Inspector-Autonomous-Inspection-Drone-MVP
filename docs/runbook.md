# Runbook — Operating the Multi-UAV Inspection Platform

## Quick Reference

| Action | Command |
|:---|:---|
| Build ROS 2 workspace | `./scripts/build_ros2.sh` |
| Launch Multi-SITL + XRCE | `./scripts/launch_multi_sitl.sh --num 3 --xrce` |
| Launch ROS 2 nodes | `source ros2_ws/install/setup.bash && ros2 launch multi_drone_bringup full_system.launch.py num_vehicles:=3` |
| Run Multi-Vehicle mission | `conda activate base && python3 scripts/run_multi_mission.py` |
| Run Multi-Vehicle (custom config) | `python3 scripts/run_multi_mission.py -c config/vehicle/fleet_config.yaml` |
| Run test suite | `./scripts/run_tests.sh` |
| Docker Compose up | `cd docker && docker compose up -d` |

---

## Standard Operating Procedure

### 1. Pre-Mission Checklist

- [ ] ROS 2 workspace is built (`./scripts/build_ros2.sh`)
- [ ] Miniconda base environment is activated (`conda activate base`)
- [ ] Multi-instance PX4 SITL is running (`./scripts/launch_multi_sitl.sh --num 3 --xrce`)
- [ ] Micro XRCE-DDS Agent is running on UDP port 8888
- [ ] Fleet configuration verified in `config/vehicle/fleet_config.yaml`

### 2. Launch Sequence

```bash
# Terminal 1: Launch Multi-Instance PX4 SITL + XRCE-DDS Agent
./scripts/launch_multi_sitl.sh --num 3 --xrce

# Terminal 2: Launch ROS 2 Vehicle Controllers & Fleet Coordinator
source ros2_ws/install/setup.bash
ros2 launch multi_drone_bringup full_system.launch.py num_vehicles:=3

# Terminal 3: Execute Multi-Vehicle Mission
conda activate base
python3 scripts/run_multi_mission.py
```

### 3. Formation Flight & Safety Monitoring

- **Formations**: Default formation pattern (`line`, `v_formation`, `circle`, `diamond`) configured in `fleet_config.yaml`.
- **Collision Avoidance**: Potential-field reactive collision avoidance (`CollisionAvoidance`) monitors inter-vehicle distances in real time.
- **Safety Monitor**: Per-vehicle `SafetyGuard` C++ nodes monitor battery, geofence, altitude ceilings, and separation limits.

---

## Configuration Reference

### Formations

| Pattern | Config Name | Description |
|:---|:---|:---|
| Line | `line` | Vehicles aligned perpendicular to heading |
| V-Formation | `v_formation` | Apex leader with symmetric trailing wings |
| Circle | `circle` | Radial distribution facing center |
| Diamond | `diamond` | Diamond geometry with leader front, wings, tail |

### Fleet Safety Parameters

```yaml
# config/vehicle/fleet_config.yaml
safety:
  min_separation_m: 5.0          # Minimum inter-vehicle distance
  avoidance_radius_m: 15.0       # Repulsion activation distance
  geofence_radius_m: 500.0       # Home distance limit
  max_altitude_m: 120.0          # Altitude ceiling
  min_battery_pct: 20.0          # Low battery RTL threshold
  critical_battery_pct: 10.0     # Critical battery land threshold
```

---

## Troubleshooting

### Common Issues

| Symptom | Cause | Fix |
|:---|:---|:---|
| `ModuleNotFoundError: No module named 'transitions'` | System Python used instead of miniconda | Use `/home/tinhtran/miniconda3/bin/python3` or `conda activate base` |
| `PytestCollectionWarning: cannot collect test class 'TestPatternCamera'` | Class name starts with `Test` | Fixed in v0.1.1 — `__test__ = False` added to `TestPatternCamera` |
| `DeprecationWarning: There is no current event loop` | `asyncio.get_event_loop()` used in Python ≥ 3.10 | Fixed in v0.1.1 — `ROS2VehicleBridge` uses `asyncio.get_running_loop()` |
| `MAVLinkBridge.wait_for_ready()` hangs forever | Timeout parameter was not enforced | Fixed in v0.1.1 — wrapped with `asyncio.wait_for()` |
| `ROS2FlightCommands` crashes as `FlightController` | Missing ABC methods (`rtl`, `goto`, `wait_for_*`) | Fixed in v0.1.1 — full ABC compliance |
| Incorrect `relative_altitude_m` in vehicle status | `on_global_position()` was overwriting with wrong calculation | Fixed in v0.1.1 — only `on_local_position()` sets relative altitude |

### Diagnostic Commands

```bash
# Check if PX4 SITL is running
ss -ulnp | grep 14540

# Check XRCE-DDS Agent
ss -ulnp | grep 8888

# Check ROS 2 topics
ros2 topic list | grep fleet

# Monitor vehicle status
ros2 topic echo /fleet/vehicle_status

# Monitor fleet status
ros2 topic echo /fleet/fleet_status
```

