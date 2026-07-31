#!/bin/bash
# ============================================================
# Multi-UAV — Launch Multiple PX4 SITL Instances + Gazebo
# ============================================================
# Starts N independent PX4 SITL instances sharing one Gazebo
# simulation. Each vehicle gets a unique:
#   - MAVLink system ID
#   - UDP port set
#   - Spawn position
#   - ROS 2 namespace (via XRCE-DDS)
#
# Usage:
#   ./launch_multi_sitl.sh                  # 3 vehicles (default)
#   ./launch_multi_sitl.sh --num 5          # 5 vehicles
#   ./launch_multi_sitl.sh --headless       # No Gazebo GUI
#   ./launch_multi_sitl.sh --num 3 --xrce   # Start XRCE-DDS agent too
# ============================================================

set -e

PX4_DIR="${PX4_HOME:-$HOME/PX4-Autopilot}"
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
PROJECT_DIR="$(dirname "$SCRIPT_DIR")"

# Defaults
NUM_VEHICLES=3
HEADLESS=false
START_XRCE=false
MODEL="x500"

# Parse arguments
while [[ $# -gt 0 ]]; do
    case $1 in
        --num|-n)
            NUM_VEHICLES="$2"
            shift 2
            ;;
        --headless)
            HEADLESS=true
            shift
            ;;
        --xrce)
            START_XRCE=true
            shift
            ;;
        --model|-m)
            MODEL="$2"
            shift 2
            ;;
        --help|-h)
            echo "Usage: $0 [OPTIONS]"
            echo ""
            echo "Options:"
            echo "  --num N, -n N     Number of vehicles (default: 3)"
            echo "  --model MODEL     Gazebo model (default: x500)"
            echo "  --headless        Run Gazebo without GUI"
            echo "  --xrce            Also start Micro XRCE-DDS Agent"
            echo "  --help, -h        Show this help"
            exit 0
            ;;
        *)
            echo "Unknown option: $1"
            exit 1
            ;;
    esac
done

# Validate
if [ ! -d "$PX4_DIR" ]; then
    echo "ERROR: PX4-Autopilot not found at $PX4_DIR"
    echo "Run ./scripts/setup_env.sh first, or set PX4_HOME."
    exit 1
fi

# ── Cleanup ───────────────────────────────────────────────
echo "Cleaning up orphaned processes..."
pkill -f "px4" 2>/dev/null || true
pkill -f "gz sim" 2>/dev/null || true
pkill -f "ruby" 2>/dev/null || true
pkill -f "MicroXRCEAgent" 2>/dev/null || true
sleep 2

# ── Spawn Positions (line formation, 5m apart) ───────────
# Format: "X,Y,Z,Roll,Pitch,Yaw"
SPAWN_POSITIONS=(
    "0,0,0,0,0,0"
    "0,5,0,0,0,0"
    "0,10,0,0,0,0"
    "0,15,0,0,0,0"
    "0,20,0,0,0,0"
    "0,25,0,0,0,0"
    "0,30,0,0,0,0"
    "0,35,0,0,0,0"
)

# ── Environment ──────────────────────────────────────────
export GZ_SIM_RESOURCE_PATH="${PROJECT_DIR}/config/gazebo/models:${GZ_SIM_RESOURCE_PATH:-}"
export GZ_SIM_WORLD_PATH="${PROJECT_DIR}/config/gazebo/worlds:${GZ_SIM_WORLD_PATH:-}"
export __NV_PRIME_RENDER_OFFLOAD=1
export __GLX_VENDOR_LIBRARY_NAME=nvidia

if [ "$HEADLESS" = true ]; then
    export HEADLESS=1
fi

# Apply PX4 parameter overrides
OVERRIDES="${PROJECT_DIR}/config/px4_params/sitl_overrides.sh"
if [ -f "$OVERRIDES" ]; then
    source "$OVERRIDES"
fi

echo "=============================================="
echo " Multi-UAV SITL Launcher"
echo "  Vehicles: $NUM_VEHICLES"
echo "  Model:    $MODEL"
echo "  PX4:      $PX4_DIR"
echo "  Headless: $HEADLESS"
echo "=============================================="
echo ""
echo " Port allocation:"
echo " ┌──────────┬───────────┬──────────┬──────────┐"
echo " │ Vehicle  │ SITL UDP  │ GCS UDP  │ XRCE-DDS │"
echo " ├──────────┼───────────┼──────────┼──────────┤"

for i in $(seq 0 $((NUM_VEHICLES - 1))); do
    SITL_PORT=$((14540 + i * 10))
    GCS_PORT=$((14550 + i * 10))
    XRCE_PORT=$((8888 + i))
    SYS_ID=$((i + 1))
    printf " │ UAV-%-4d │ %-9d │ %-8d │ %-8d │\n" "$i" "$SITL_PORT" "$GCS_PORT" "$XRCE_PORT"
done

echo " └──────────┴───────────┴──────────┴──────────┘"
echo ""

# ── Start Micro XRCE-DDS Agent ──────────────────────────
if [ "$START_XRCE" = true ]; then
    echo "[XRCE] Starting Micro XRCE-DDS Agent on port 8888..."
    MicroXRCEAgent udp4 -p 8888 &
    XRCE_PID=$!
    echo "[XRCE] Agent PID: $XRCE_PID"
    sleep 1
fi

# ── Launch PX4 Instances ─────────────────────────────────
PIDS=()

for i in $(seq 0 $((NUM_VEHICLES - 1))); do
    INSTANCE=$i
    SYS_ID=$((i + 1))
    SPAWN_POS="${SPAWN_POSITIONS[$i]:-0,$((i * 5)),0,0,0,0}"

    echo ""
    echo "[Vehicle $i] Launching PX4 instance..."
    echo "  System ID:     $SYS_ID"
    echo "  Spawn:         $SPAWN_POS"
    echo "  ROS namespace: /px4_$i"

    # PX4 environment variables for multi-instance
    PX4_SYS_AUTOSTART=4001 \
    PX4_GZ_MODEL=$MODEL \
    PX4_GZ_MODEL_POSE="$SPAWN_POS" \
    PX4_INSTANCE=$INSTANCE \
    $PX4_DIR/build/px4_sitl_default/bin/px4 \
        -i $INSTANCE \
        -d "$PX4_DIR/build/px4_sitl_default/etc" \
        -s "$PX4_DIR/build/px4_sitl_default/etc/init.d-posix/rcS" \
        -w "$PX4_DIR/build/px4_sitl_default/instance_$INSTANCE" \
        > /dev/null 2>&1 &

    PIDS+=($!)
    echo "  PID: ${PIDS[-1]}"

    # Wait between instances to avoid Gazebo spawn conflicts
    sleep 3
done

echo ""
echo "=============================================="
echo " All $NUM_VEHICLES vehicles launched!"
echo " PIDs: ${PIDS[*]}"
echo ""
echo " Next steps:"
echo "   1. Start XRCE-DDS Agent (if not --xrce):"
echo "      MicroXRCEAgent udp4 -p 8888"
echo ""
echo "   2. Launch ROS 2 nodes:"
echo "      ros2 launch multi_drone_bringup full_system.launch.py num_vehicles:=$NUM_VEHICLES"
echo ""
echo "   3. Optional: Open QGroundControl to see all vehicles"
echo ""
echo " Press Ctrl+C to stop all instances"
echo "=============================================="

# ── Wait and handle shutdown ─────────────────────────────
cleanup() {
    echo ""
    echo "Shutting down all PX4 instances..."
    for pid in "${PIDS[@]}"; do
        kill "$pid" 2>/dev/null || true
    done
    if [ -n "$XRCE_PID" ]; then
        kill "$XRCE_PID" 2>/dev/null || true
    fi
    pkill -f "gz sim" 2>/dev/null || true
    echo "All processes stopped."
    exit 0
}

trap cleanup SIGINT SIGTERM

# Wait for all PX4 processes
wait "${PIDS[@]}" 2>/dev/null
