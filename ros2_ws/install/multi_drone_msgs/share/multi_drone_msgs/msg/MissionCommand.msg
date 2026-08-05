# ============================================================
# MissionCommand.msg — Multi-vehicle mission command
# Published by dashboard or mission planner
# ============================================================

# Command constants
uint8 CMD_TAKEOFF_ALL = 0
uint8 CMD_LAND_ALL = 1
uint8 CMD_RTL_ALL = 2
uint8 CMD_ARM_ALL = 3
uint8 CMD_DISARM_ALL = 4
uint8 CMD_OFFBOARD_START = 5
uint8 CMD_OFFBOARD_STOP = 6
uint8 CMD_GOTO = 7
uint8 CMD_HOLD_ALL = 8
uint8 CMD_ABORT_ALL = 9
uint8 CMD_SINGLE_VEHICLE = 10

# Command type
uint8 command

# Target vehicle (255 = broadcast to all)
uint8 target_vehicle_id

# Parameters (command-specific)
float32 param1              # e.g., takeoff altitude
float32 param2
float32 param3
float32 param4

# GPS target (for CMD_GOTO)
float64 target_latitude_deg
float64 target_longitude_deg
float32 target_altitude_m
float32 target_yaw_deg

# Timestamp
builtin_interfaces/Time stamp
