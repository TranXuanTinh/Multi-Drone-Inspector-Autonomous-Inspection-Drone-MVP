# Setup Guide — Multi-UAV Platform

Complete setup instructions for running the Multi-UAV Drone Inspector simulation platform.

## Prerequisites

| Requirement | Version | Check Command |
|:---|:---|:---|
| **Ubuntu** | 22.04 LTS / 24.04 LTS | `lsb_release -a` |
| **ROS 2** | Jazzy Jalisco | `ros2 --version` |
| **Python** | ≥ 3.10 (Miniconda `base`) | `python3 --version` |
| **Git** | Any | `git --version` |
| **CMake** | ≥ 3.22 | `cmake --version` |
| **Node.js** | ≥ 18 (for dashboard) | `node --version` |

---

## Method A: Automated Setup (Recommended)

```bash
# 1. Activate Miniconda base environment
conda activate base

# 2. Run system setup script (installs PX4, Gazebo Harmonic, Node.js, and deps)
chmod +x scripts/setup_env.sh
./scripts/setup_env.sh

# 3. Install Python dependencies into Conda base
pip install -r requirements.txt

# 4. Build ROS 2 workspace (C++ vehicle_controller & fleet_manager)
./scripts/build_ros2.sh
```

---

## Method B: Docker Setup

```bash
cd docker

# Build and start all multi-vehicle services
docker compose up -d --build
```

Services launched:
- `px4-sitl-0`, `px4-sitl-1`, `px4-sitl-2`: 3 independent PX4 SITL instances
- `xrce-agent`: Micro XRCE-DDS Agent (port 8888)
- `ros2-nodes`: C++ ROS 2 `offboard_controller`, `safety_guard`, `fleet_coordinator`
- `dashboard`: FastAPI Backend (port 8000)

---

## Method C: Manual Setup & ROS 2 Build

### 1. Build ROS 2 Workspace

```bash
# Source ROS 2 Jazzy
source /opt/ros/jazzy/setup.bash

# Build C++ packages using the helper script
./scripts/build_ros2.sh

# Or directly with colcon:
cd ros2_ws
colcon build --symlink-install --packages-up-to multi_drone_bringup
source install/setup.bash
```

---

## Verification & Execution

### 1. Launch Multi-Instance PX4 SITL & XRCE Agent

```bash
# Terminal 1: Launch 3 PX4 SITL instances + Micro XRCE-DDS agent
./scripts/launch_multi_sitl.sh --num 3 --xrce
```

### 2. Launch ROS 2 Nodes

```bash
# Terminal 2: Source workspace and launch vehicle controllers + fleet manager
source ros2_ws/install/setup.bash
ros2 launch multi_drone_bringup full_system.launch.py num_vehicles:=3
```

### 3. Run Coordinated Multi-Vehicle Mission

```bash
# Terminal 3: Execute multi-vehicle mission
conda activate base
python3 scripts/run_multi_mission.py
```

### 4. Run Tests

```bash
conda activate base

# Run all 126 unit tests (no SITL required)
/home/tinhtran/miniconda3/bin/python3 -m pytest tests/unit/ -v

# Run SITL integration tests (requires running PX4 SITL from step 1)
/home/tinhtran/miniconda3/bin/python3 -m pytest tests/sitl/ -v

# Run full test suite via script
./scripts/run_tests.sh
```

> **Note**: SITL tests are automatically skipped when PX4 is not running.

