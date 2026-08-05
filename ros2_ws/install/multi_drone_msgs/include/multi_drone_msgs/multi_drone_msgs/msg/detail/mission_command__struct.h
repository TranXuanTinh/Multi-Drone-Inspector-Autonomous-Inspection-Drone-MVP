// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from multi_drone_msgs:msg/MissionCommand.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "multi_drone_msgs/msg/mission_command.h"


#ifndef MULTI_DRONE_MSGS__MSG__DETAIL__MISSION_COMMAND__STRUCT_H_
#define MULTI_DRONE_MSGS__MSG__DETAIL__MISSION_COMMAND__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

/// Constant 'CMD_TAKEOFF_ALL'.
/**
  * Command constants
 */
enum
{
  multi_drone_msgs__msg__MissionCommand__CMD_TAKEOFF_ALL = 0
};

/// Constant 'CMD_LAND_ALL'.
enum
{
  multi_drone_msgs__msg__MissionCommand__CMD_LAND_ALL = 1
};

/// Constant 'CMD_RTL_ALL'.
enum
{
  multi_drone_msgs__msg__MissionCommand__CMD_RTL_ALL = 2
};

/// Constant 'CMD_ARM_ALL'.
enum
{
  multi_drone_msgs__msg__MissionCommand__CMD_ARM_ALL = 3
};

/// Constant 'CMD_DISARM_ALL'.
enum
{
  multi_drone_msgs__msg__MissionCommand__CMD_DISARM_ALL = 4
};

/// Constant 'CMD_OFFBOARD_START'.
enum
{
  multi_drone_msgs__msg__MissionCommand__CMD_OFFBOARD_START = 5
};

/// Constant 'CMD_OFFBOARD_STOP'.
enum
{
  multi_drone_msgs__msg__MissionCommand__CMD_OFFBOARD_STOP = 6
};

/// Constant 'CMD_GOTO'.
enum
{
  multi_drone_msgs__msg__MissionCommand__CMD_GOTO = 7
};

/// Constant 'CMD_HOLD_ALL'.
enum
{
  multi_drone_msgs__msg__MissionCommand__CMD_HOLD_ALL = 8
};

/// Constant 'CMD_ABORT_ALL'.
enum
{
  multi_drone_msgs__msg__MissionCommand__CMD_ABORT_ALL = 9
};

/// Constant 'CMD_SINGLE_VEHICLE'.
enum
{
  multi_drone_msgs__msg__MissionCommand__CMD_SINGLE_VEHICLE = 10
};

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.h"

/// Struct defined in msg/MissionCommand in the package multi_drone_msgs.
/**
  * ============================================================
  * MissionCommand.msg — Multi-vehicle mission command
  * Published by dashboard or mission planner
  * ============================================================
 */
typedef struct multi_drone_msgs__msg__MissionCommand
{
  /// Command type
  uint8_t command;
  /// Target vehicle (255 = broadcast to all)
  uint8_t target_vehicle_id;
  /// Parameters (command-specific)
  /// e.g., takeoff altitude
  float param1;
  float param2;
  float param3;
  float param4;
  /// GPS target (for CMD_GOTO)
  double target_latitude_deg;
  double target_longitude_deg;
  float target_altitude_m;
  float target_yaw_deg;
  /// Timestamp
  builtin_interfaces__msg__Time stamp;
} multi_drone_msgs__msg__MissionCommand;

// Struct for a sequence of multi_drone_msgs__msg__MissionCommand.
typedef struct multi_drone_msgs__msg__MissionCommand__Sequence
{
  multi_drone_msgs__msg__MissionCommand * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} multi_drone_msgs__msg__MissionCommand__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MULTI_DRONE_MSGS__MSG__DETAIL__MISSION_COMMAND__STRUCT_H_
