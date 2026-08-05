// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from multi_drone_msgs:msg/FleetStatus.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "multi_drone_msgs/msg/fleet_status.h"


#ifndef MULTI_DRONE_MSGS__MSG__DETAIL__FLEET_STATUS__STRUCT_H_
#define MULTI_DRONE_MSGS__MSG__DETAIL__FLEET_STATUS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

// Include directives for member types
// Member 'fleet_state'
// Member 'current_formation'
#include "rosidl_runtime_c/string.h"
// Member 'vehicles'
#include "multi_drone_msgs/msg/detail/vehicle_status__struct.h"
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.h"

/// Struct defined in msg/FleetStatus in the package multi_drone_msgs.
/**
  * ============================================================
  * FleetStatus.msg — Aggregated fleet-wide status
  * Published by the fleet_coordinator node
  * ============================================================
 */
typedef struct multi_drone_msgs__msg__FleetStatus
{
  /// Fleet state
  /// IDLE, FORMING, IN_FORMATION, EXECUTING, SCATTERING, RTL_ALL
  rosidl_runtime_c__String fleet_state;
  /// Per-vehicle statuses
  multi_drone_msgs__msg__VehicleStatus__Sequence vehicles;
  /// Formation info
  /// "none", "line", "v_formation", "circle", "diamond"
  rosidl_runtime_c__String current_formation;
  float formation_spacing_m;
  float formation_heading_deg;
  /// Fleet health
  uint8_t num_vehicles_registered;
  uint8_t num_vehicles_connected;
  uint8_t num_vehicles_armed;
  uint8_t num_vehicles_airborne;
  /// Safety
  float min_inter_vehicle_distance_m;
  bool collision_warning;
  /// Timing
  builtin_interfaces__msg__Time stamp;
  double mission_elapsed_s;
} multi_drone_msgs__msg__FleetStatus;

// Struct for a sequence of multi_drone_msgs__msg__FleetStatus.
typedef struct multi_drone_msgs__msg__FleetStatus__Sequence
{
  multi_drone_msgs__msg__FleetStatus * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} multi_drone_msgs__msg__FleetStatus__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MULTI_DRONE_MSGS__MSG__DETAIL__FLEET_STATUS__STRUCT_H_
