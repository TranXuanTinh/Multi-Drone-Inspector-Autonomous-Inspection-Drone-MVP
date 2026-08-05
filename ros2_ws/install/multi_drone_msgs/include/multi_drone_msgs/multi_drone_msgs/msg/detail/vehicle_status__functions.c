// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from multi_drone_msgs:msg/VehicleStatus.idl
// generated code does not contain a copyright notice
#include "multi_drone_msgs/msg/detail/vehicle_status__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `vehicle_namespace`
// Member `name`
// Member `flight_mode`
// Member `mission_state`
#include "rosidl_runtime_c/string_functions.h"
// Member `stamp`
#include "builtin_interfaces/msg/detail/time__functions.h"

bool
multi_drone_msgs__msg__VehicleStatus__init(multi_drone_msgs__msg__VehicleStatus * msg)
{
  if (!msg) {
    return false;
  }
  // vehicle_id
  // vehicle_namespace
  if (!rosidl_runtime_c__String__init(&msg->vehicle_namespace)) {
    multi_drone_msgs__msg__VehicleStatus__fini(msg);
    return false;
  }
  // name
  if (!rosidl_runtime_c__String__init(&msg->name)) {
    multi_drone_msgs__msg__VehicleStatus__fini(msg);
    return false;
  }
  // latitude_deg
  // longitude_deg
  // absolute_altitude_m
  // relative_altitude_m
  // heading_deg
  // roll_deg
  // pitch_deg
  // yaw_deg
  // groundspeed_ms
  // velocity_north_ms
  // velocity_east_ms
  // velocity_down_ms
  // battery_percent
  // battery_voltage
  // flight_mode
  if (!rosidl_runtime_c__String__init(&msg->flight_mode)) {
    multi_drone_msgs__msg__VehicleStatus__fini(msg);
    return false;
  }
  // armed
  // offboard_active
  // mission_state
  if (!rosidl_runtime_c__String__init(&msg->mission_state)) {
    multi_drone_msgs__msg__VehicleStatus__fini(msg);
    return false;
  }
  // connected
  // gps_fix_type
  // gps_num_satellites
  // is_healthy
  // local_x
  // local_y
  // local_z
  // stamp
  if (!builtin_interfaces__msg__Time__init(&msg->stamp)) {
    multi_drone_msgs__msg__VehicleStatus__fini(msg);
    return false;
  }
  return true;
}

void
multi_drone_msgs__msg__VehicleStatus__fini(multi_drone_msgs__msg__VehicleStatus * msg)
{
  if (!msg) {
    return;
  }
  // vehicle_id
  // vehicle_namespace
  rosidl_runtime_c__String__fini(&msg->vehicle_namespace);
  // name
  rosidl_runtime_c__String__fini(&msg->name);
  // latitude_deg
  // longitude_deg
  // absolute_altitude_m
  // relative_altitude_m
  // heading_deg
  // roll_deg
  // pitch_deg
  // yaw_deg
  // groundspeed_ms
  // velocity_north_ms
  // velocity_east_ms
  // velocity_down_ms
  // battery_percent
  // battery_voltage
  // flight_mode
  rosidl_runtime_c__String__fini(&msg->flight_mode);
  // armed
  // offboard_active
  // mission_state
  rosidl_runtime_c__String__fini(&msg->mission_state);
  // connected
  // gps_fix_type
  // gps_num_satellites
  // is_healthy
  // local_x
  // local_y
  // local_z
  // stamp
  builtin_interfaces__msg__Time__fini(&msg->stamp);
}

bool
multi_drone_msgs__msg__VehicleStatus__are_equal(const multi_drone_msgs__msg__VehicleStatus * lhs, const multi_drone_msgs__msg__VehicleStatus * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // vehicle_id
  if (lhs->vehicle_id != rhs->vehicle_id) {
    return false;
  }
  // vehicle_namespace
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->vehicle_namespace), &(rhs->vehicle_namespace)))
  {
    return false;
  }
  // name
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->name), &(rhs->name)))
  {
    return false;
  }
  // latitude_deg
  if (lhs->latitude_deg != rhs->latitude_deg) {
    return false;
  }
  // longitude_deg
  if (lhs->longitude_deg != rhs->longitude_deg) {
    return false;
  }
  // absolute_altitude_m
  if (lhs->absolute_altitude_m != rhs->absolute_altitude_m) {
    return false;
  }
  // relative_altitude_m
  if (lhs->relative_altitude_m != rhs->relative_altitude_m) {
    return false;
  }
  // heading_deg
  if (lhs->heading_deg != rhs->heading_deg) {
    return false;
  }
  // roll_deg
  if (lhs->roll_deg != rhs->roll_deg) {
    return false;
  }
  // pitch_deg
  if (lhs->pitch_deg != rhs->pitch_deg) {
    return false;
  }
  // yaw_deg
  if (lhs->yaw_deg != rhs->yaw_deg) {
    return false;
  }
  // groundspeed_ms
  if (lhs->groundspeed_ms != rhs->groundspeed_ms) {
    return false;
  }
  // velocity_north_ms
  if (lhs->velocity_north_ms != rhs->velocity_north_ms) {
    return false;
  }
  // velocity_east_ms
  if (lhs->velocity_east_ms != rhs->velocity_east_ms) {
    return false;
  }
  // velocity_down_ms
  if (lhs->velocity_down_ms != rhs->velocity_down_ms) {
    return false;
  }
  // battery_percent
  if (lhs->battery_percent != rhs->battery_percent) {
    return false;
  }
  // battery_voltage
  if (lhs->battery_voltage != rhs->battery_voltage) {
    return false;
  }
  // flight_mode
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->flight_mode), &(rhs->flight_mode)))
  {
    return false;
  }
  // armed
  if (lhs->armed != rhs->armed) {
    return false;
  }
  // offboard_active
  if (lhs->offboard_active != rhs->offboard_active) {
    return false;
  }
  // mission_state
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->mission_state), &(rhs->mission_state)))
  {
    return false;
  }
  // connected
  if (lhs->connected != rhs->connected) {
    return false;
  }
  // gps_fix_type
  if (lhs->gps_fix_type != rhs->gps_fix_type) {
    return false;
  }
  // gps_num_satellites
  if (lhs->gps_num_satellites != rhs->gps_num_satellites) {
    return false;
  }
  // is_healthy
  if (lhs->is_healthy != rhs->is_healthy) {
    return false;
  }
  // local_x
  if (lhs->local_x != rhs->local_x) {
    return false;
  }
  // local_y
  if (lhs->local_y != rhs->local_y) {
    return false;
  }
  // local_z
  if (lhs->local_z != rhs->local_z) {
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
multi_drone_msgs__msg__VehicleStatus__copy(
  const multi_drone_msgs__msg__VehicleStatus * input,
  multi_drone_msgs__msg__VehicleStatus * output)
{
  if (!input || !output) {
    return false;
  }
  // vehicle_id
  output->vehicle_id = input->vehicle_id;
  // vehicle_namespace
  if (!rosidl_runtime_c__String__copy(
      &(input->vehicle_namespace), &(output->vehicle_namespace)))
  {
    return false;
  }
  // name
  if (!rosidl_runtime_c__String__copy(
      &(input->name), &(output->name)))
  {
    return false;
  }
  // latitude_deg
  output->latitude_deg = input->latitude_deg;
  // longitude_deg
  output->longitude_deg = input->longitude_deg;
  // absolute_altitude_m
  output->absolute_altitude_m = input->absolute_altitude_m;
  // relative_altitude_m
  output->relative_altitude_m = input->relative_altitude_m;
  // heading_deg
  output->heading_deg = input->heading_deg;
  // roll_deg
  output->roll_deg = input->roll_deg;
  // pitch_deg
  output->pitch_deg = input->pitch_deg;
  // yaw_deg
  output->yaw_deg = input->yaw_deg;
  // groundspeed_ms
  output->groundspeed_ms = input->groundspeed_ms;
  // velocity_north_ms
  output->velocity_north_ms = input->velocity_north_ms;
  // velocity_east_ms
  output->velocity_east_ms = input->velocity_east_ms;
  // velocity_down_ms
  output->velocity_down_ms = input->velocity_down_ms;
  // battery_percent
  output->battery_percent = input->battery_percent;
  // battery_voltage
  output->battery_voltage = input->battery_voltage;
  // flight_mode
  if (!rosidl_runtime_c__String__copy(
      &(input->flight_mode), &(output->flight_mode)))
  {
    return false;
  }
  // armed
  output->armed = input->armed;
  // offboard_active
  output->offboard_active = input->offboard_active;
  // mission_state
  if (!rosidl_runtime_c__String__copy(
      &(input->mission_state), &(output->mission_state)))
  {
    return false;
  }
  // connected
  output->connected = input->connected;
  // gps_fix_type
  output->gps_fix_type = input->gps_fix_type;
  // gps_num_satellites
  output->gps_num_satellites = input->gps_num_satellites;
  // is_healthy
  output->is_healthy = input->is_healthy;
  // local_x
  output->local_x = input->local_x;
  // local_y
  output->local_y = input->local_y;
  // local_z
  output->local_z = input->local_z;
  // stamp
  if (!builtin_interfaces__msg__Time__copy(
      &(input->stamp), &(output->stamp)))
  {
    return false;
  }
  return true;
}

multi_drone_msgs__msg__VehicleStatus *
multi_drone_msgs__msg__VehicleStatus__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  multi_drone_msgs__msg__VehicleStatus * msg = (multi_drone_msgs__msg__VehicleStatus *)allocator.allocate(sizeof(multi_drone_msgs__msg__VehicleStatus), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(multi_drone_msgs__msg__VehicleStatus));
  bool success = multi_drone_msgs__msg__VehicleStatus__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
multi_drone_msgs__msg__VehicleStatus__destroy(multi_drone_msgs__msg__VehicleStatus * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    multi_drone_msgs__msg__VehicleStatus__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
multi_drone_msgs__msg__VehicleStatus__Sequence__init(multi_drone_msgs__msg__VehicleStatus__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  multi_drone_msgs__msg__VehicleStatus * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(multi_drone_msgs__msg__VehicleStatus)) {
      return false;
    }
    data = (multi_drone_msgs__msg__VehicleStatus *)allocator.zero_allocate(size, sizeof(multi_drone_msgs__msg__VehicleStatus), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = multi_drone_msgs__msg__VehicleStatus__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        multi_drone_msgs__msg__VehicleStatus__fini(&data[i - 1]);
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
multi_drone_msgs__msg__VehicleStatus__Sequence__fini(multi_drone_msgs__msg__VehicleStatus__Sequence * array)
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
      multi_drone_msgs__msg__VehicleStatus__fini(&array->data[i]);
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

multi_drone_msgs__msg__VehicleStatus__Sequence *
multi_drone_msgs__msg__VehicleStatus__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  multi_drone_msgs__msg__VehicleStatus__Sequence * array = (multi_drone_msgs__msg__VehicleStatus__Sequence *)allocator.allocate(sizeof(multi_drone_msgs__msg__VehicleStatus__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = multi_drone_msgs__msg__VehicleStatus__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
multi_drone_msgs__msg__VehicleStatus__Sequence__destroy(multi_drone_msgs__msg__VehicleStatus__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    multi_drone_msgs__msg__VehicleStatus__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
multi_drone_msgs__msg__VehicleStatus__Sequence__are_equal(const multi_drone_msgs__msg__VehicleStatus__Sequence * lhs, const multi_drone_msgs__msg__VehicleStatus__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!multi_drone_msgs__msg__VehicleStatus__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
multi_drone_msgs__msg__VehicleStatus__Sequence__copy(
  const multi_drone_msgs__msg__VehicleStatus__Sequence * input,
  multi_drone_msgs__msg__VehicleStatus__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(multi_drone_msgs__msg__VehicleStatus)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(multi_drone_msgs__msg__VehicleStatus);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    multi_drone_msgs__msg__VehicleStatus * data =
      (multi_drone_msgs__msg__VehicleStatus *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!multi_drone_msgs__msg__VehicleStatus__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          multi_drone_msgs__msg__VehicleStatus__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!multi_drone_msgs__msg__VehicleStatus__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
