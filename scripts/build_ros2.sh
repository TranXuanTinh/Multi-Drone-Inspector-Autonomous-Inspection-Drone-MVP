#!/bin/bash
# ============================================================
# Build ROS 2 Workspace
# ============================================================
# Builds the multi-drone ROS 2 packages using colcon.
#
# Prerequisites:
#   - ROS 2 Jazzy installed and sourced
#   - px4_msgs package available
#   - Eigen3 installed
#
# Usage:
#   ./scripts/build_ros2.sh              # Full build
#   ./scripts/build_ros2.sh --clean      # Clean + full build
#   ./scripts/build_ros2.sh --test       # Build + run tests
# ============================================================

set -e

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
PROJECT_DIR="$(dirname "$SCRIPT_DIR")"
ROS2_WS="$PROJECT_DIR/ros2_ws"

# Parse arguments
CLEAN=false
RUN_TESTS=false

while [[ $# -gt 0 ]]; do
    case $1 in
        --clean)
            CLEAN=true
            shift
            ;;
        --test)
            RUN_TESTS=true
            shift
            ;;
        --help|-h)
            echo "Usage: $0 [OPTIONS]"
            echo ""
            echo "Options:"
            echo "  --clean    Remove build/install/log dirs before building"
            echo "  --test     Run tests after building"
            echo "  --help     Show this help"
            exit 0
            ;;
        *)
            echo "Unknown option: $1"
            exit 1
            ;;
    esac
done

# Ensure ROS 2 is sourced
if [ -z "$ROS_DISTRO" ]; then
    echo "Sourcing ROS 2 Jazzy..."
    source /opt/ros/jazzy/setup.bash 2>/dev/null || {
        echo "ERROR: ROS 2 Jazzy not found. Install it first."
        exit 1
    }
fi

# Ensure px4_msgs is cloned in ros2_ws/src
if [ ! -d "$ROS2_WS/src/px4_msgs" ]; then
    echo "Cloning px4_msgs repository into $ROS2_WS/src/px4_msgs..."
    git clone https://github.com/PX4/px4_msgs.git "$ROS2_WS/src/px4_msgs"
fi

echo "=============================================="
echo " Building ROS 2 Multi-Drone Workspace"
echo "  ROS Distro: $ROS_DISTRO"
echo "  Workspace:  $ROS2_WS"
echo "=============================================="

BUILD_DIR="$HOME/.cache/ros2_build_multidrone"
mkdir -p "$BUILD_DIR"

cd "$ROS2_WS"

# Clean if requested
if [ "$CLEAN" = true ]; then
    echo "Cleaning previous build..."
    rm -rf "$BUILD_DIR" build/ install/ log/
    mkdir -p "$BUILD_DIR"
fi

# Build
echo ""
echo "Building packages..."
colcon --log-base "$BUILD_DIR/log" build \
    --build-base "$BUILD_DIR/build" \
    --install-base "$BUILD_DIR/install" \
    --cmake-args \
        --no-warn-unused-cli \
        -DCMAKE_BUILD_TYPE=RelWithDebInfo \
        -DCMAKE_EXPORT_COMPILE_COMMANDS=ON \
        -DPython3_EXECUTABLE=/usr/bin/python3 \
    --symlink-install \
    --event-handlers console_direct+ \
    --packages-up-to multi_drone_bringup

BUILD_STATUS=$?

if [ $BUILD_STATUS -ne 0 ]; then
    echo ""
    echo "ERROR: Build failed with status $BUILD_STATUS"
    exit $BUILD_STATUS
fi

# Link install directory locally to ros2_ws/install
ln -sfn "$BUILD_DIR/install" "$ROS2_WS/install"

echo ""
echo "=============================================="
echo " Build successful!"
echo "=============================================="
echo ""
echo " Source the workspace:"
echo "   source $ROS2_WS/install/setup.bash"
echo ""

# Run tests if requested
if [ "$RUN_TESTS" = true ]; then
    colcon --log-base "$BUILD_DIR/log" test \
        --build-base "$BUILD_DIR/build" \
        --install-base "$BUILD_DIR/install" \
        --packages-select vehicle_controller fleet_manager multi_drone_msgs \
        --event-handlers console_direct+

    echo ""
    echo "Test results:"
    colcon test-result --test-result-base "$BUILD_DIR/build" --verbose
fi

echo ""
echo "Next steps:"
echo "  1. Start PX4 SITL:   ./scripts/launch_multi_sitl.sh --num 3 --xrce"
echo "  2. Source workspace:  source $ROS2_WS/install/setup.bash"
echo "  3. Launch nodes:      ros2 launch multi_drone_bringup full_system.launch.py"
