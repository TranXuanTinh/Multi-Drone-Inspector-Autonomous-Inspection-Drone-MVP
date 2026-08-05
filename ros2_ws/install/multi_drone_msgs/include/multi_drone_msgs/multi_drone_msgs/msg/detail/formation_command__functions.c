// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from multi_drone_msgs:msg/FormationCommand.idl
// generated code does not contain a copyright notice
#include "multi_drone_msgs/msg/detail/formation_command__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `pattern`
#include "rosidl_runtime_c/string_functions.h"
// Member `stamp`
#include "builtin_interfaces/msg/detail/time__functions.h"

bool
multi_drone_msgs__msg__FormationCommand__init(multi_drone_msgs__msg__FormationCommand * msg)
{
  if (!msg) {
    return false;
  }
  // pattern
  if (!rosidl_runtime_c__String__init(&msg->pattern)) {
    multi_drone_msgs__msg__FormationCommand__fini(msg);
    return false;
  }
  // spacing_m
  // heading_deg
  // altitude_m
  // altitude_offset_m
  // leader_vehicle_id
  // has_target_position
  // target_latitude_deg
  // target_longitude_deg
  // target_altitude_m
  // max_speed_ms
  // stamp
  if (!builtin_interfaces__msg__Time__init(&msg->stamp)) {
    multi_drone_msgs__msg__FormationCommand__fini(msg);
    return false;
  }
  return true;
}

void
multi_drone_msgs__msg__FormationCommand__fini(multi_drone_msgs__msg__FormationCommand * msg)
{
  if (!msg) {
    return;
  }
  // pattern
  rosidl_runtime_c__String__fini(&msg->pattern);
  // spacing_m
  // heading_deg
  // altitude_m
  // altitude_offset_m
  // leader_vehicle_id
  // has_target_position
  // target_latitude_deg
  // target_longitude_deg
  // target_altitude_m
  // max_speed_ms
  // stamp
  builtin_interfaces__msg__Time__fini(&msg->stamp);
}

bool
multi_drone_msgs__msg__FormationCommand__are_equal(const multi_drone_msgs__msg__FormationCommand * lhs, const multi_drone_msgs__msg__FormationCommand * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // pattern
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->pattern), &(rhs->pattern)))
  {
    return false;
  }
  // spacing_m
  if (lhs->spacing_m != rhs->spacing_m) {
    return false;
  }
  // heading_deg
  if (lhs->heading_deg != rhs->heading_deg) {
    return false;
  }
  // altitude_m
  if (lhs->altitude_m != rhs->altitude_m) {
    return false;
  }
  // altitude_offset_m
  if (lhs->altitude_offset_m != rhs->altitude_offset_m) {
    return false;
  }
  // leader_vehicle_id
  if (lhs->leader_vehicle_id != rhs->leader_vehicle_id) {
    return false;
  }
  // has_target_position
  if (lhs->has_target_position != rhs->has_target_position) {
    return false;
  }
  // target_latitude_deg
  if (lhs->target_latitude_deg != rhs->target_latitude_deg) {
    return false;
  }
  // target_longitude_deg
  if (lhs->target_longitude_deg != rhs->target_longitude_deg) {
    return false;
  }
  // target_altitude_m
  if (lhs->target_altitude_m != rhs->target_altitude_m) {
    return false;
  }
  // max_speed_ms
  if (lhs->max_speed_ms != rhs->max_speed_ms) {
    return false;
  }
  // stamp
  if (!builtin_interfaces__msg__Time__are_equal(
      &(lhs->stamp), &(rhs->stamp)))
  {
    return false;
  }
  return true;
}

bool
multi_drone_msgs__msg__FormationCommand__copy(
  const multi_drone_msgs__msg__FormationCommand * input,
  multi_drone_msgs__msg__FormationCommand * output)
{
  if (!input || !output) {
    return false;
  }
  // pattern
  if (!rosidl_runtime_c__String__copy(
      &(input->pattern), &(output->pattern)))
  {
    return false;
  }
  // spacing_m
  output->spacing_m = input->spacing_m;
  // heading_deg
  output->heading_deg = input->heading_deg;
  // altitude_m
  output->altitude_m = input->altitude_m;
  // altitude_offset_m
  output->altitude_offset_m = input->altitude_offset_m;
  // leader_vehicle_id
  output->leader_vehicle_id = input->leader_vehicle_id;
  // has_target_position
  output->has_target_position = input->has_target_position;
  // target_latitude_deg
  output->target_latitude_deg = input->target_latitude_deg;
  // target_longitude_deg
  output->target_longitude_deg = input->target_longitude_deg;
  // target_altitude_m
  output->target_altitude_m = input->target_altitude_m;
  // max_speed_ms
  output->max_speed_ms = input->max_speed_ms;
  // stamp
  if (!builtin_interfaces__msg__Time__copy(
      &(input->stamp), &(output->stamp)))
  {
    return false;
  }
  return true;
}

multi_drone_msgs__msg__FormationCommand *
multi_drone_msgs__msg__FormationCommand__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  multi_drone_msgs__msg__FormationCommand * msg = (multi_drone_msgs__msg__FormationCommand *)allocator.allocate(sizeof(multi_drone_msgs__msg__FormationCommand), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(multi_drone_msgs__msg__FormationCommand));
  bool success = multi_drone_msgs__msg__FormationCommand__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
multi_drone_msgs__msg__FormationCommand__destroy(multi_drone_msgs__msg__FormationCommand * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    multi_drone_msgs__msg__FormationCommand__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
multi_drone_msgs__msg__FormationCommand__Sequence__init(multi_drone_msgs__msg__FormationCommand__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  multi_drone_msgs__msg__FormationCommand * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(multi_drone_msgs__msg__FormationCommand)) {
      return false;
    }
    data = (multi_drone_msgs__msg__FormationCommand *)allocator.zero_allocate(size, sizeof(multi_drone_msgs__msg__FormationCommand), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = multi_drone_msgs__msg__FormationCommand__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        multi_drone_msgs__msg__FormationCommand__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
multi_drone_msgs__msg__FormationCommand__Sequence__fini(multi_drone_msgs__msg__FormationCommand__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      multi_drone_msgs__msg__FormationCommand__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

multi_drone_msgs__msg__FormationCommand__Sequence *
multi_drone_msgs__msg__FormationCommand__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  multi_drone_msgs__msg__FormationCommand__Sequence * array = (multi_drone_msgs__msg__FormationCommand__Sequence *)allocator.allocate(sizeof(multi_drone_msgs__msg__FormationCommand__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = multi_drone_msgs__msg__FormationCommand__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
multi_drone_msgs__msg__FormationCommand__Sequence__destroy(multi_drone_msgs__msg__FormationCommand__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    multi_drone_msgs__msg__FormationCommand__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
multi_drone_msgs__msg__FormationCommand__Sequence__are_equal(const multi_drone_msgs__msg__FormationCommand__Sequence * lhs, const multi_drone_msgs__msg__FormationCommand__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!multi_drone_msgs__msg__FormationCommand__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
multi_drone_msgs__msg__FormationCommand__Sequence__copy(
  const multi_drone_msgs__msg__FormationCommand__Sequence * input,
  multi_drone_msgs__msg__FormationCommand__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(multi_drone_msgs__msg__FormationCommand)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(multi_drone_msgs__msg__FormationCommand);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    multi_drone_msgs__msg__FormationCommand * data =
      (multi_drone_msgs__msg__FormationCommand *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!multi_drone_msgs__msg__FormationCommand__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          multi_drone_msgs__msg__FormationCommand__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!multi_drone_msgs__msg__FormationCommand__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
