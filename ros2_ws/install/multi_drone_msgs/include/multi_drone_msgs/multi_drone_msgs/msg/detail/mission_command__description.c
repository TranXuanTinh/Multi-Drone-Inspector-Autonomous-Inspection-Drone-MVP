// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from multi_drone_msgs:msg/MissionCommand.idl
// generated code does not contain a copyright notice

#include "multi_drone_msgs/msg/detail/mission_command__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_multi_drone_msgs
const rosidl_type_hash_t *
multi_drone_msgs__msg__MissionCommand__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x9d, 0xf5, 0x63, 0xfe, 0xab, 0x1e, 0x8c, 0xf3,
      0xfb, 0xb7, 0xe1, 0x77, 0x99, 0x63, 0x83, 0x2c,
      0xaa, 0xa5, 0x3f, 0x83, 0x2c, 0xa6, 0x8c, 0x4e,
      0xaf, 0x29, 0xd0, 0xd3, 0x64, 0x01, 0xc4, 0xf2,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "builtin_interfaces/msg/detail/time__functions.h"

// Hashes for external referenced types
#ifndef NDEBUG
static const rosidl_type_hash_t builtin_interfaces__msg__Time__EXPECTED_HASH = {1, {
    0xb1, 0x06, 0x23, 0x5e, 0x25, 0xa4, 0xc5, 0xed,
    0x35, 0x09, 0x8a, 0xa0, 0xa6, 0x1a, 0x3e, 0xe9,
    0xc9, 0xb1, 0x8d, 0x19, 0x7f, 0x39, 0x8b, 0x0e,
    0x42, 0x06, 0xce, 0xa9, 0xac, 0xf9, 0xc1, 0x97,
  }};
#endif

static char multi_drone_msgs__msg__MissionCommand__TYPE_NAME[] = "multi_drone_msgs/msg/MissionCommand";
static char builtin_interfaces__msg__Time__TYPE_NAME[] = "builtin_interfaces/msg/Time";

// Define type names, field names, and default values
static char multi_drone_msgs__msg__MissionCommand__FIELD_NAME__command[] = "command";
static char multi_drone_msgs__msg__MissionCommand__FIELD_NAME__target_vehicle_id[] = "target_vehicle_id";
static char multi_drone_msgs__msg__MissionCommand__FIELD_NAME__param1[] = "param1";
static char multi_drone_msgs__msg__MissionCommand__FIELD_NAME__param2[] = "param2";
static char multi_drone_msgs__msg__MissionCommand__FIELD_NAME__param3[] = "param3";
static char multi_drone_msgs__msg__MissionCommand__FIELD_NAME__param4[] = "param4";
static char multi_drone_msgs__msg__MissionCommand__FIELD_NAME__target_latitude_deg[] = "target_latitude_deg";
static char multi_drone_msgs__msg__MissionCommand__FIELD_NAME__target_longitude_deg[] = "target_longitude_deg";
static char multi_drone_msgs__msg__MissionCommand__FIELD_NAME__target_altitude_m[] = "target_altitude_m";
static char multi_drone_msgs__msg__MissionCommand__FIELD_NAME__target_yaw_deg[] = "target_yaw_deg";
static char multi_drone_msgs__msg__MissionCommand__FIELD_NAME__stamp[] = "stamp";

static rosidl_runtime_c__type_description__Field multi_drone_msgs__msg__MissionCommand__FIELDS[] = {
  {
    {multi_drone_msgs__msg__MissionCommand__FIELD_NAME__command, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {multi_drone_msgs__msg__MissionCommand__FIELD_NAME__target_vehicle_id, 17, 17},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {multi_drone_msgs__msg__MissionCommand__FIELD_NAME__param1, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {multi_drone_msgs__msg__MissionCommand__FIELD_NAME__param2, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {multi_drone_msgs__msg__MissionCommand__FIELD_NAME__param3, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {multi_drone_msgs__msg__MissionCommand__FIELD_NAME__param4, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {multi_drone_msgs__msg__MissionCommand__FIELD_NAME__target_latitude_deg, 19, 19},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {multi_drone_msgs__msg__MissionCommand__FIELD_NAME__target_longitude_deg, 20, 20},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {multi_drone_msgs__msg__MissionCommand__FIELD_NAME__target_altitude_m, 17, 17},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {multi_drone_msgs__msg__MissionCommand__FIELD_NAME__target_yaw_deg, 14, 14},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {multi_drone_msgs__msg__MissionCommand__FIELD_NAME__stamp, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription multi_drone_msgs__msg__MissionCommand__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
multi_drone_msgs__msg__MissionCommand__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {multi_drone_msgs__msg__MissionCommand__TYPE_NAME, 35, 35},
      {multi_drone_msgs__msg__MissionCommand__FIELDS, 11, 11},
    },
    {multi_drone_msgs__msg__MissionCommand__REFERENCED_TYPE_DESCRIPTIONS, 1, 1},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "# ============================================================\n"
  "# MissionCommand.msg \\xe2\\x80\\x94 Multi-vehicle mission command\n"
  "# Published by dashboard or mission planner\n"
  "# ============================================================\n"
  "\n"
  "# Command constants\n"
  "uint8 CMD_TAKEOFF_ALL = 0\n"
  "uint8 CMD_LAND_ALL = 1\n"
  "uint8 CMD_RTL_ALL = 2\n"
  "uint8 CMD_ARM_ALL = 3\n"
  "uint8 CMD_DISARM_ALL = 4\n"
  "uint8 CMD_OFFBOARD_START = 5\n"
  "uint8 CMD_OFFBOARD_STOP = 6\n"
  "uint8 CMD_GOTO = 7\n"
  "uint8 CMD_HOLD_ALL = 8\n"
  "uint8 CMD_ABORT_ALL = 9\n"
  "uint8 CMD_SINGLE_VEHICLE = 10\n"
  "\n"
  "# Command type\n"
  "uint8 command\n"
  "\n"
  "# Target vehicle (255 = broadcast to all)\n"
  "uint8 target_vehicle_id\n"
  "\n"
  "# Parameters (command-specific)\n"
  "float32 param1              # e.g., takeoff altitude\n"
  "float32 param2\n"
  "float32 param3\n"
  "float32 param4\n"
  "\n"
  "# GPS target (for CMD_GOTO)\n"
  "float64 target_latitude_deg\n"
  "float64 target_longitude_deg\n"
  "float32 target_altitude_m\n"
  "float32 target_yaw_deg\n"
  "\n"
  "# Timestamp\n"
  "builtin_interfaces/Time stamp";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
multi_drone_msgs__msg__MissionCommand__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {multi_drone_msgs__msg__MissionCommand__TYPE_NAME, 35, 35},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 921, 921},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
multi_drone_msgs__msg__MissionCommand__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[2];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 2, 2};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *multi_drone_msgs__msg__MissionCommand__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
