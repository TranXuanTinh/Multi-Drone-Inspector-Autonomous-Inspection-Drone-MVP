# ============================================================
# FleetStatus.msg — Aggregated fleet-wide status
# Published by the fleet_coordinator node
# ============================================================

# Fleet state
string fleet_state          # IDLE, FORMING, IN_FORMATION, EXECUTING, SCATTERING, RTL_ALL

# Per-vehicle statuses
multi_drone_msgs/VehicleStatus[] vehicles

# Formation info
string current_formation    # "none", "line", "v_formation", "circle", "diamond"
float32 formation_spacing_m
float32 formation_heading_deg

# Fleet health
uint8 num_vehicles_registered
uint8 num_vehicles_connected
uint8 num_vehicles_armed
uint8 num_vehicles_airborne

# Safety
float32 min_inter_vehicle_distance_m
bool collision_warning

# Timing
builtin_interfaces/Time stamp
float64 mission_elapsed_s
