// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from multi_drone_msgs:msg/MissionCommand.idl
// generated code does not contain a copyright notice
#include "multi_drone_msgs/msg/detail/mission_command__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `stamp`
#include "builtin_interfaces/msg/detail/time__functions.h"

bool
multi_drone_msgs__msg__MissionCommand__init(multi_drone_msgs__msg__MissionCommand * msg)
{
  if (!msg) {
    return false;
  }
  // command
  // target_vehicle_id
  // param1
  // param2
  // param3
  // param4
  // target_latitude_deg
  // target_longitude_deg
  // target_altitude_m
  // target_yaw_deg
  // stamp
  if (!builtin_interfaces__msg__Time__init(&msg->stamp)) {
    multi_drone_msgs__msg__MissionCommand__fini(msg);
    return false;
  }
  return true;
}

void
multi_drone_msgs__msg__MissionCommand__fini(multi_drone_msgs__msg__MissionCommand * msg)
{
  if (!msg) {
    return;
  }
  // command
  // target_vehicle_id
  // param1
  // param2
  // param3
  // param4
  // target_latitude_deg
  // target_longitude_deg
  // target_altitude_m
  // target_yaw_deg
  // stamp
  builtin_interfaces__msg__Time__fini(&msg->stamp);
}

bool
multi_drone_msgs__msg__MissionCommand__are_equal(const multi_drone_msgs__msg__MissionCommand * lhs, const multi_drone_msgs__msg__MissionCommand * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // command
  if (lhs->command != rhs->command) {
    return false;
  }
  // target_vehicle_id
  if (lhs->target_vehicle_id != rhs->target_vehicle_id) {
    return false;
  }
  // param1
  if (lhs->param1 != rhs->param1) {
    return false;
  }
  // param2
  if (lhs->param2 != rhs->param2) {
    return false;
  }
  // param3
  if (lhs->param3 != rhs->param3) {
    return false;
  }
  // param4
  if (lhs->param4 != rhs->param4) {
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
  // target_yaw_deg
  if (lhs->target_yaw_deg != rhs->target_yaw_deg) {
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
multi_drone_msgs__msg__MissionCommand__copy(
  const multi_drone_msgs__msg__MissionCommand * input,
  multi_drone_msgs__msg__MissionCommand * output)
{
  if (!input || !output) {
    return false;
  }
  // command
  output->command = input->command;
  // target_vehicle_id
  output->target_vehicle_id = input->target_vehicle_id;
  // param1
  output->param1 = input->param1;
  // param2
  output->param2 = input->param2;
  // param3
  output->param3 = input->param3;
  // param4
  output->param4 = input->param4;
  // target_latitude_deg
  output->target_latitude_deg = input->target_latitude_deg;
  // target_longitude_deg
  output->target_longitude_deg = input->target_longitude_deg;
  // target_altitude_m
  output->target_altitude_m = input->target_altitude_m;
  // target_yaw_deg
  output->target_yaw_deg = input->target_yaw_deg;
  // stamp
  if (!builtin_interfaces__msg__Time__copy(
      &(input->stamp), &(output->stamp)))
  {
    return false;
  }
  return true;
}

multi_drone_msgs__msg__MissionCommand *
multi_drone_msgs__msg__MissionCommand__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  multi_drone_msgs__msg__MissionCommand * msg = (multi_drone_msgs__msg__MissionCommand *)allocator.allocate(sizeof(multi_drone_msgs__msg__MissionCommand), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(multi_drone_msgs__msg__MissionCommand));
  bool success = multi_drone_msgs__msg__MissionCommand__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
multi_drone_msgs__msg__MissionCommand__destroy(multi_drone_msgs__msg__MissionCommand * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    multi_drone_msgs__msg__MissionCommand__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
multi_drone_msgs__msg__MissionCommand__Sequence__init(multi_drone_msgs__msg__MissionCommand__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  multi_drone_msgs__msg__MissionCommand * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(multi_drone_msgs__msg__MissionCommand)) {
      return false;
    }
    data = (multi_drone_msgs__msg__MissionCommand *)allocator.zero_allocate(size, sizeof(multi_drone_msgs__msg__MissionCommand), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = multi_drone_msgs__msg__MissionCommand__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        multi_drone_msgs__msg__MissionCommand__fini(&data[i - 1]);
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
multi_drone_msgs__msg__MissionCommand__Sequence__fini(multi_drone_msgs__msg__MissionCommand__Sequence * array)
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
      multi_drone_msgs__msg__MissionCommand__fini(&array->data[i]);
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

multi_drone_msgs__msg__MissionCommand__Sequence *
multi_drone_msgs__msg__MissionCommand__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  multi_drone_msgs__msg__MissionCommand__Sequence * array = (multi_drone_msgs__msg__MissionCommand__Sequence *)allocator.allocate(sizeof(multi_drone_msgs__msg__MissionCommand__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = multi_drone_msgs__msg__MissionCommand__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
multi_drone_msgs__msg__MissionCommand__Sequence__destroy(multi_drone_msgs__msg__MissionCommand__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    multi_drone_msgs__msg__MissionCommand__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
multi_drone_msgs__msg__MissionCommand__Sequence__are_equal(const multi_drone_msgs__msg__MissionCommand__Sequence * lhs, const multi_drone_msgs__msg__MissionCommand__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!multi_drone_msgs__msg__MissionCommand__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
multi_drone_msgs__msg__MissionCommand__Sequence__copy(
  const multi_drone_msgs__msg__MissionCommand__Sequence * input,
  multi_drone_msgs__msg__MissionCommand__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(multi_drone_msgs__msg__MissionCommand)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(multi_drone_msgs__msg__MissionCommand);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    multi_drone_msgs__msg__MissionCommand * data =
      (multi_drone_msgs__msg__MissionCommand *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!multi_drone_msgs__msg__MissionCommand__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          multi_drone_msgs__msg__MissionCommand__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!multi_drone_msgs__msg__MissionCommand__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
