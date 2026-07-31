# ============================================================
# FormationCommand.msg — Command to set or change formation
# Published by fleet_coordinator or dashboard
# ============================================================

# Formation pattern
string pattern              # "line", "v_formation", "circle", "diamond", "custom"

# Formation parameters
float32 spacing_m           # Inter-vehicle distance
float32 heading_deg         # Formation heading direction
float32 altitude_m          # Formation altitude (0 = maintain current)
float32 altitude_offset_m   # Per-vehicle altitude stagger

# Leader specification
uint8 leader_vehicle_id     # Which vehicle leads the formation

# Target position for formation center (optional)
bool has_target_position
float64 target_latitude_deg
float64 target_longitude_deg
float32 target_altitude_m

# Speed
float32 max_speed_ms        # Formation movement speed

# Timestamp
builtin_interfaces/Time stamp
