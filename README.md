# 🛸 Multi-UAV Inspector — Autonomous Multi-Drone Inspection Platform

> **Simulation-Only** — PX4 SITL + Gazebo Harmonic + ROS 2 Jazzy + Micro XRCE-DDS | C++ & Python | No hardware required

An enterprise-grade autonomous multi-UAV inspection platform built with **PX4 SITL**, **ROS 2 Jazzy (C++)**, **Micro XRCE-DDS**, **Gazebo Harmonic**, computer vision (**YOLOv8 + ByteTrack**), and a real-time operator dashboard. Supports multi-vehicle SITL simulation, offboard position/velocity setpoints, dynamic formation control (Line, V, Circle, Diamond), and reactive collision avoidance.

> **Environment**: Miniconda `base` — all Python dependencies run in the conda base environment (no virtualenv).

---

## 🏗️ System Architecture

### Multi-Vehicle Topology

```
┌─────────────────────────────────────────────────────────────────────────────────┐
│                           GAZEBO HARMONIC SIMULATION                            │
│                  multi_vehicle_empty.sdf  (Shared Physics & World)             │
└───────┬─────────────────────────────────┬─────────────────────────────────┬─────┘
        │                                 │                                 │
┌───────▼────────────────┐       ┌────────▼───────────────┐        ┌────────▼───────────────┐
│  PX4 Instance 0        │       │  PX4 Instance 1        │        │  PX4 Instance 2        │
│  SysID=1 | Port: 14540 │       │  SysID=2 | Port: 14550 │        │  SysID=3 | Port: 14560 │
└───────┬────────────────┘       └────────┬───────────────┘        └────────┬───────────────┘
        │ uORB (XRCE Client)              │ uORB (XRCE Client)              │ uORB (XRCE Client)
┌───────▼─────────────────────────────────▼─────────────────────────────────▼─────┐
│                          MICRO XRCE-DDS AGENT  (UDP Port 8888)                  │
└───────┬─────────────────────────────────┬─────────────────────────────────┬─────┘
        │ ROS 2 DDS Network               │ ROS 2 DDS Network               │ ROS 2 DDS Network
┌───────▼────────────────┐       ┌────────▼───────────────┐        ┌────────▼───────────────┐
│ /px4_0/ vehicle_nodes  │       │ /px4_1/ vehicle_nodes  │       │ /px4_2/ vehicle_nodes  │
│  - offboard_controller │       │  - offboard_controller │       │  - offboard_controller │
│  - safety_guard        │       │  - safety_guard        │       │  - safety_guard        │
└───────┬────────────────┘       └────────┬───────────────┘        └────────┬───────────────┘
        │ /fleet/vehicle_status           │ /fleet/vehicle_status           │ /fleet/vehicle_status
┌───────▼─────────────────────────────────▼─────────────────────────────────▼─────┐
│                        FLEET MANAGER (C++ / fleet_coordinator)                  │
│   Formation Controller (Line, V, Circle, Diamond)  ·  Collision Avoidance (VO)  │
└───────┬─────────────────────────────────────────────────────────────────────────┘
        │ /fleet/fleet_status  ·  ROS2VehicleBridge (Python)
┌───────▼─────────────────────────────────────────────────────────────────────────┐
│                         PYTHON OPERATOR DASHBOARD                               │
│   FastAPI Backend (port 8000)  ·  React + Vite Frontend (port 3000)             │
└─────────────────────────────────────────────────────────────────────────────────┘
```

---

## 🛠️ Key Technical Features

- **PX4 SITL Multi-Vehicle Foundation**: Independent PX4 instances running concurrent SITL simulations with customized MAVLink system IDs and isolated UDP telemetry channels.
- **Native ROS 2 Interface**: C++ nodes (`offboard_controller`, `safety_guard`, `telemetry_monitor`) communicating directly with PX4 via Micro XRCE-DDS uORB topic bridge.
- **Offboard Control**: Reliable 50Hz setpoint stream (`OffboardControlMode` + `TrajectorySetpoint`) in local NED frame with state machine safety checks.
- **Fleet Coordination**: Central C++ `fleet_coordinator` node with formation target generator (`FormationController`) supporting:
  - 📏 **Line**: Perpendicular to heading, centered on leader
  - 📐 **V-Formation**: Apex leader with staggered follower positions
  - ⭕ **Circle**: Even radial distribution facing inward
  - 💎 **Diamond**: Front leader, lateral wings, and tail
- **Collision Avoidance**: Reactive potential-field / velocity-obstacle approach (`CollisionAvoidance`) with priority-based vehicle resolution.
- **Perception Pipeline**: YOLOv8 real-time object detection + ByteTrack multi-object tracking + GPS geotagging.
- **Containerized Deployment**: Docker Compose stack orchestrating PX4 SITL instances, Micro XRCE-DDS Agent, ROS 2 C++ nodes, and Dashboard.

---

## 🚀 Quick Start

### Prerequisites

| Requirement | Version | Notes |
|:---|:---|:---|
| Ubuntu | 22.04 LTS / 24.04 LTS | Required for PX4 SITL + ROS 2 |
| ROS 2 | Jazzy Jalisco | ROS 2 build environment |
| Miniconda / Conda | Any | Python dependencies |
| Python | ≥ 3.10 | Active Conda `base` environment |
| Node.js | ≥ 18 | Dashboard UI |
| PX4 Autopilot | v1.15+ | Installed by setup script |

---

### 1. Setup Environment

```bash
# 1. Activate your miniconda environment
conda activate base

# 2. Install system dependencies & PX4-Autopilot
chmod +x scripts/setup_env.sh
./scripts/setup_env.sh

# 3. Install Python dependencies
pip install -r requirements.txt

# 4. Build ROS 2 workspace
./scripts/build_ros2.sh
```

---

### 2. Launch Multi-Vehicle Simulation

#### Step 1: Start Multi-Instance PX4 SITL + XRCE-DDS Agent (Terminal 1)
```bash
./scripts/launch_multi_sitl.sh --num 3 --xrce
```

#### Step 2: Launch ROS 2 Vehicle Controllers & Fleet Manager (Terminal 2)
```bash
source ros2_ws/install/setup.bash
ros2 launch multi_drone_bringup full_system.launch.py num_vehicles:=3
```

#### Step 3: Run Coordinated Multi-Vehicle Mission (Terminal 3)
```bash
conda activate base
python3 scripts/run_multi_mission.py
```

---

### 3. Operator Dashboard (Optional)

```bash
conda activate base

# Terminal 3: Start backend
cd src/dashboard/backend && uvicorn main:app --reload --port 8000

# Terminal 4: Start frontend
cd src/dashboard/frontend && npm install && npm run dev
# Open http://localhost:3000
```

---

## 🐳 Docker Deployment

To launch the complete multi-vehicle simulation stack in Docker containers:

```bash
cd docker
docker compose up -d           # Starts 3 PX4 instances, XRCE Agent, ROS 2 nodes, and Dashboard
docker compose logs -f         # Follow logs
docker compose down            # Stop all containers
```

---

## 📁 Project Structure

```
MultiDronePX4/
├── ros2_ws/                               # ROS 2 C++ Workspace
│   └── src/
│       ├── multi_drone_msgs/              # Custom ROS 2 msg & srv interfaces
│       ├── vehicle_controller/            # C++ Offboard control & SafetyGuard
│       ├── fleet_manager/                 # C++ FleetCoordinator & FormationController
│       └── multi_drone_bringup/           # ROS 2 Launch files
│
├── src/                                   # Python Core & Ecosystem
│   ├── core/                              # Shared DTOs, ABCs, EventBus
│   ├── bridge/                            # ROS 2 bridge & flight commands
│   ├── fleet/                             # FleetManager & Formation Patterns
│   ├── perception/                        # YOLOv8 + ByteTrack + Geotagging
│   ├── mission/                           # Mission State Machine & Waypoint Planner
│   ├── streaming/                         # Video server & overlays
│   └── dashboard/                         # FastAPI backend & React frontend
│
├── config/
│   ├── vehicle/fleet_config.yaml          # Fleet & safety configuration
│   ├── gazebo/worlds/                     # Gazebo Harmonic multi-vehicle SDF
│   └── px4_params/sitl_overrides.sh       # PX4 SITL parameters
│
├── scripts/
│   ├── build_ros2.sh                      # ROS 2 workspace builder script
│   ├── launch_multi_sitl.sh               # Multi-instance PX4 SITL launcher
│   └── run_multi_mission.py               # Coordinated mission entrypoint
│
├── tests/
│   ├── sitl/                              # Multi-vehicle SITL tests
│   └── unit/                              # 126 passing unit tests
│
└── docker/                                # Multi-container Docker Compose setup
```

---

## 🧪 Testing

```bash
conda activate base

# Run all 126 unit tests
/home/tinhtran/miniconda3/bin/python3 -m pytest tests/unit/ -v

# Run SITL integration tests (requires PX4 SITL running)
/home/tinhtran/miniconda3/bin/python3 -m pytest tests/sitl/ -v

# Run full test suite via runner script
./scripts/run_tests.sh

# Run ROS 2 C++ tests
./scripts/build_ros2.sh --test
```

> **Note**: SITL tests are auto-skipped when PX4 is not running. Use `./scripts/launch_sitl.sh` first.

---

## 📄 License

MIT

---

## 📝 Changelog

### v0.1.1 — Bug Fixes & Interface Compliance
- **Fixed**: `ROS2FlightCommands` now fully implements `FlightController` ABC (`rtl()`, `goto()`, `wait_for_altitude()`, `wait_for_landed()`, `wait_for_disarmed()`, `is_offboard_active`)
- **Fixed**: `offboard_controller.cpp` no longer overwrites `relative_altitude_m` with incorrect `alt_ellipsoid - alt` calculation
- **Fixed**: `ROS2VehicleBridge.wait_for_ready()` uses `asyncio.get_running_loop()` (was deprecated `get_event_loop()`)
- **Fixed**: `ROS2VehicleBridge._on_vehicle_status` uses thread-safe asyncio scheduling for telemetry callbacks
- **Fixed**: `MAVLinkBridge.wait_for_ready()` now enforces its `timeout` parameter via `asyncio.wait_for()`
- **Fixed**: `TestPatternCamera` no longer triggers `PytestCollectionWarning`
- **Environment**: Migrated from virtualenv to Miniconda `base`
