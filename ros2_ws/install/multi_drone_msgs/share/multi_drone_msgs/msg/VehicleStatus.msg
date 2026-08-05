# ============================================================
# VehicleStatus.msg — Per-vehicle telemetry and status
# Published by each vehicle_controller node
# ============================================================

# Vehicle identity
uint8 vehicle_id
string vehicle_namespace
string name

# Position & attitude
float64 latitude_deg
float64 longitude_deg
float32 absolute_altitude_m
float32 relative_altitude_m
float32 heading_deg
float32 roll_deg
float32 pitch_deg
float32 yaw_deg

# Velocity
float32 groundspeed_ms
float32 velocity_north_ms
float32 velocity_east_ms
float32 velocity_down_ms

# Battery
float32 battery_percent
float32 battery_voltage

# Flight state
string flight_mode
bool armed
bool offboard_active
string mission_state

# Health & connectivity
bool connected
uint8 gps_fix_type
uint8 gps_num_satellites
bool is_healthy

# Local position (NED frame, meters from home)
float32 local_x
float32 local_y
float32 local_z

# Timestamp
builtin_interfaces/Time stamp
