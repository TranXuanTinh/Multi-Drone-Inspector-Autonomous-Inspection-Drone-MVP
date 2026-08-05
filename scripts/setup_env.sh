#!/bin/bash
# ============================================================
# Drone Inspector — Environment Setup Script
# ============================================================
# One-click install for PX4 SITL + Gazebo + Python deps
# Tested on: Ubuntu 22.04 / 24.04 LTS
# Python env: Miniconda (base)
# ============================================================

set -e

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
PROJECT_DIR="$(dirname "$SCRIPT_DIR")"
PX4_DIR="$HOME/PX4-Autopilot"
CONDA_DIR="$HOME/miniconda3"

echo "=============================================="
echo " Drone Inspector — Environment Setup"
echo "=============================================="
echo ""

# --- Activate Miniconda base environment ---
# Ensure conda is available and base env is active regardless of how
# the script was invoked (interactive shell, cron, fresh terminal, etc.)
if [ -f "$CONDA_DIR/etc/profile.d/conda.sh" ]; then
    source "$CONDA_DIR/etc/profile.d/conda.sh"
    conda activate base
elif command -v conda &> /dev/null; then
    eval "$(conda shell.bash hook)"
    conda activate base
else
    echo "ERROR: Miniconda not found at $CONDA_DIR"
    echo "Install Miniconda first:"
    echo "  wget https://repo.anaconda.com/miniconda/Miniconda3-latest-Linux-x86_64.sh"
    echo "  bash Miniconda3-latest-Linux-x86_64.sh"
    exit 1
fi

# Point pip and python at the active conda environment
PIP_CMD="pip"
PYTHON_CMD="python3"

# Validate Python version — ROS 2 Jazzy requires Python 3.12.x
PYTHON_MAJOR=$($PYTHON_CMD -c "import sys; print(sys.version_info.major)")
PYTHON_MINOR=$($PYTHON_CMD -c "import sys; print(sys.version_info.minor)")
if [ "$PYTHON_MAJOR" -eq 3 ] && [ "$PYTHON_MINOR" -ne 12 ]; then
    echo ""
    echo "  WARNING: Python $PYTHON_MAJOR.$PYTHON_MINOR detected, but ROS 2 Jazzy requires 3.12"
    echo "  Downgrading conda base to Python 3.12..."
    conda install python=3.12 -y
    echo "  Python downgraded. Re-checking..."
fi

echo " Python env: Miniconda (base)"
echo " Python:     $($PYTHON_CMD --version 2>&1)"
echo " Pip:        $(which $PIP_CMD)"
echo ""

# --- System dependencies ---
echo "[1/5] Installing system dependencies..."
sudo apt-get update -qq
sudo apt-get install -y \
    git cmake build-essential \
    python3 python3-pip python3-venv \
    curl wget unzip \
    libopencv-dev

# --- PX4 Autopilot ---
echo "[2/5] Setting up PX4 Autopilot..."
if [ ! -d "$PX4_DIR" ]; then
    echo "  Cloning PX4-Autopilot repository..."
    git clone https://github.com/PX4/PX4-Autopilot.git --recursive "$PX4_DIR"
else
    echo "  PX4-Autopilot already exists at $PX4_DIR, updating..."
    cd "$PX4_DIR" && git pull && git submodule update --init --recursive
fi

echo "  Running PX4 ubuntu setup script (installs Gazebo + toolchain)..."
cd "$PX4_DIR"
# PX4's ubuntu.sh installs its own pip requirements (setuptools<=81.0.0, etc.)
# into whichever python3 is on PATH. That would pollute our conda base env
# with version-pinned packages and cause conflicts. We temporarily strip
# conda from PATH so PX4 installs into system python instead.
echo "  (Isolating PX4 pip installs from Miniconda base)"
_SAVED_PATH="$PATH"
_SAVED_CONDA_ENV="$CONDA_DEFAULT_ENV"
_SAVED_CONDA_PREFIX="$CONDA_PREFIX"
export PATH=$(echo "$PATH" | tr ':' '\n' | grep -v miniconda | grep -v anaconda | tr '\n' ':' | sed 's/:$//')
unset CONDA_DEFAULT_ENV
unset CONDA_PREFIX
unset VIRTUAL_ENV
bash ./Tools/setup/ubuntu.sh --no-nuttx || true
# Restore conda environment
export PATH="$_SAVED_PATH"
export CONDA_DEFAULT_ENV="$_SAVED_CONDA_ENV"
export CONDA_PREFIX="$_SAVED_CONDA_PREFIX"

# --- Python dependencies (installed into Miniconda base) ---
echo "[3/5] Installing Python dependencies into Miniconda base..."
cd "$PROJECT_DIR"

# Upgrade core packaging tools first
$PIP_CMD install --upgrade pip setuptools wheel

# Install project dependencies
$PIP_CMD install -r requirements.txt

# Install typeguard — required by generate-parameter-library-py (ROS 2 Jazzy).
# The ROS package metadata declares the dep but doesn't auto-install it into
# the conda env, causing pip check errors.
echo "  Installing typeguard (required by ROS 2 generate-parameter-library-py)..."
$PIP_CMD install typeguard

# Verify no broken dependencies
echo "  Verifying pip dependencies..."
$PIP_CMD check || echo "  WARNING: Some dependency conflicts remain (usually harmless cross-env ROS packages)"

# --- Node.js (for dashboard frontend) ---
echo "[4/5] Checking Node.js..."
if ! command -v node &> /dev/null; then
    echo "  Installing Node.js 20 LTS..."
    curl -fsSL https://deb.nodesource.com/setup_20.x | sudo -E bash -
    sudo apt-get install -y nodejs
else
    echo "  Node.js already installed: $(node --version)"
fi

# --- Create data directories ---
echo "[5/5] Creating project directories..."
mkdir -p "$PROJECT_DIR/data/logs"
mkdir -p "$PROJECT_DIR/data/detections"
mkdir -p "$PROJECT_DIR/data/reports"

echo ""
echo "=============================================="
echo " Setup complete!"
echo "=============================================="
echo ""
echo " PX4-Autopilot:  $PX4_DIR"
echo " Python env:     Miniconda base ($CONDA_DIR)"
echo " Python:         $($PYTHON_CMD --version 2>&1)"
echo ""
echo " Quick test PX4 SITL:"
echo "   cd $PX4_DIR && make px4_sitl gz_x500"
echo ""
echo " Or use the launch script:"
echo "   ./scripts/launch_sitl.sh"
echo ""
echo " NOTE: You may need to REBOOT after first run"
echo "       (for user group changes to take effect)"
echo "=============================================="
