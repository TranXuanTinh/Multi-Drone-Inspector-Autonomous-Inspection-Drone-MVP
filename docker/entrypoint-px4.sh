#!/bin/bash
# Entrypoint for PX4 SITL container
set -e

echo "=========================================="
echo " PX4 SITL Instance: ${PX4_INSTANCE}"
echo " System ID:         $((PX4_INSTANCE + 1))"
echo " Model:             ${PX4_GZ_MODEL}"
echo " Pose:              ${PX4_GZ_MODEL_POSE}"
echo "=========================================="

# Source parameter overrides
if [ -f /opt/config/sitl_overrides.sh ]; then
    source /opt/config/sitl_overrides.sh
fi

# Set system ID
export PX4_PARAM_MAV_SYS_ID=$((PX4_INSTANCE + 1))

# Start PX4 SITL
cd ${PX4_HOME}
exec ./build/px4_sitl_default/bin/px4 \
    -i ${PX4_INSTANCE} \
    -d ./build/px4_sitl_default/etc \
    -s ./build/px4_sitl_default/etc/init.d-posix/rcS \
    -w ./build/px4_sitl_default/instance_${PX4_INSTANCE}
