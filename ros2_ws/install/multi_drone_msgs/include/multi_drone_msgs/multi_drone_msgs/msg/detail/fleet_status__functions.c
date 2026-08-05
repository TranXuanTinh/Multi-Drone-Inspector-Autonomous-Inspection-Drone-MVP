// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from multi_drone_msgs:msg/FleetStatus.idl
// generated code does not contain a copyright notice
#include "multi_drone_msgs/msg/detail/fleet_status__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `fleet_state`
// Member `current_formation`
#include "rosidl_runtime_c/string_functions.h"
// Member `vehicles`
#include "multi_drone_msgs/msg/detail/vehicle_status__functions.h"
// Member `stamp`
#include "builtin_interfaces/msg/detail/time__functions.h"

bool
multi_drone_msgs__msg__FleetStatus__init(multi_drone_msgs__msg__FleetStatus * msg)
{
  if (!msg) {
    return false;
  }
  // fleet_state
  if (!rosidl_runtime_c__String__init(&msg->fleet_state)) {
    multi_drone_msgs__msg__FleetStatus__fini(msg);
    return false;
  }
  // vehicles
  if (!multi_drone_msgs__msg__VehicleStatus__Sequence__init(&msg->vehicles, 0)) {
    multi_drone_msgs__msg__FleetStatus__fini(msg);
    return false;
  }
  // current_formation
  if (!rosidl_runtime_c__String__init(&msg->current_formation)) {
    multi_drone_msgs__msg__FleetStatus__fini(msg);
    return false;
  }
  // formation_spacing_m
  // formation_heading_deg
  // num_vehicles_registered
  // num_vehicles_connected
  // num_vehicles_armed
  // num_vehicles_airborne
  // min_inter_vehicle_distance_m
  // collision_warning
  // stamp
  if (!builtin_interfaces__msg__Time__init(&msg->stamp)) {
    multi_drone_msgs__msg__FleetStatus__fini(msg);
    return false;
  }
  // mission_elapsed_s
  return true;
}

void
multi_drone_msgs__msg__FleetStatus__fini(multi_drone_msgs__msg__FleetStatus * msg)
{
  if (!msg) {
    return;
  }
  // fleet_state
  rosidl_runtime_c__String__fini(&msg->fleet_state);
  // vehicles
  multi_drone_msgs__msg__VehicleStatus__Sequence__fini(&msg->vehicles);
  // current_formation
  rosidl_runtime_c__String__fini(&msg->current_formation);
  // formation_spacing_m
  // formation_heading_deg
  // num_vehicles_registered
  // num_vehicles_connected
  // num_vehicles_armed
  // num_vehicles_airborne
  // min_inter_vehicle_distance_m
  // collision_warning
  // stamp
  builtin_interfaces__msg__Time__fini(&msg->stamp);
  // mission_elapsed_s
}

bool
multi_drone_msgs__msg__FleetStatus__are_equal(const multi_drone_msgs__msg__FleetStatus * lhs, const multi_drone_msgs__msg__FleetStatus * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // fleet_state
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->fleet_state), &(rhs->fleet_state)))
  {
    return false;
  }
  // vehicles
  if (!multi_drone_msgs__msg__VehicleStatus__Sequence__are_equal(
      &(lhs->vehicles), &(rhs->vehicles)))
  {
    return false;
  }
  // current_formation
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->current_formation), &(rhs->current_formation)))
  {
    return false;
  }
  // formation_spacing_m
  if (lhs->formation_spacing_m != rhs->formation_spacing_m) {
    return false;
  }
  // formation_heading_deg
  if (lhs->formation_heading_deg != rhs->formation_heading_deg) {
    return false;
  }
  // num_vehicles_registered
  if (lhs->num_vehicles_registered != rhs->num_vehicles_registered) {
    return false;
  }
  // num_vehicles_connected
  if (lhs->num_vehicles_connected != rhs->num_vehicles_connected) {
    return false;
  }
  // num_vehicles_armed
  if (lhs->num_vehicles_armed != rhs->num_vehicles_armed) {
    return false;
  }
  // num_vehicles_airborne
  if (lhs->num_vehicles_airborne != rhs->num_vehicles_airborne) {
    return false;
  }
  // min_inter_vehicle_distance_m
  if (lhs->min_inter_vehicle_distance_m != rhs->min_inter_vehicle_distance_m) {
    return false;
  }
  // collision_warning
  if (lhs->collision_warning != rhs->collision_warning) {
    return false;
  }
  // stamp
  if (!builtin_interfaces__msg__Time__are_equal(
      &(lhs->stamp), &(rhs->stamp)))
  {
    return false;
  }
  // mission_elapsed_s
  if (lhs->mission_elapsed_s != rhs->mission_elapsed_s) {
    return false;
  }
  return true;
}

bool
multi_drone_msgs__msg__FleetStatus__copy(
  const multi_drone_msgs__msg__FleetStatus * input,
  multi_drone_msgs__msg__FleetStatus * output)
{
  if (!input || !output) {
    return false;
  }
  // fleet_state
  if (!rosidl_runtime_c__String__copy(
      &(input->fleet_state), &(output->fleet_state)))
  {
    return false;
  }
  // vehicles
  if (!multi_drone_msgs__msg__VehicleStatus__Sequence__copy(
      &(input->vehicles), &(output->vehicles)))
  {
    return false;
  }
  // current_formation
  if (!rosidl_runtime_c__String__copy(
      &(input->current_formation), &(output->current_formation)))
  {
    return false;
  }
  // formation_spacing_m
  output->formation_spacing_m = input->formation_spacing_m;
  // formation_heading_deg
  output->formation_heading_deg = input->formation_heading_deg;
  // num_vehicles_registered
  output->num_vehicles_registered = input->num_vehicles_registered;
  // num_vehicles_connected
  output->num_vehicles_connected = input->num_vehicles_connected;
  // num_vehicles_armed
  output->num_vehicles_armed = input->num_vehicles_armed;
  // num_vehicles_airborne
  output->num_vehicles_airborne = input->num_vehicles_airborne;
  // min_inter_vehicle_distance_m
  output->min_inter_vehicle_distance_m = input->min_inter_vehicle_distance_m;
  // collision_warning
  output->collision_warning = input->collision_warning;
  // stamp
  if (!builtin_interfaces__msg__Time__copy(
      &(input->stamp), &(output->stamp)))
  {
    return false;
  }
  // mission_elapsed_s
  output->mission_elapsed_s = input->mission_elapsed_s;
  return true;
}

multi_drone_msgs__msg__FleetStatus *
multi_drone_msgs__msg__FleetStatus__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  multi_drone_msgs__msg__FleetStatus * msg = (multi_drone_msgs__msg__FleetStatus *)allocator.allocate(sizeof(multi_drone_msgs__msg__FleetStatus), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(multi_drone_msgs__msg__FleetStatus));
  bool success = multi_drone_msgs__msg__FleetStatus__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
multi_drone_msgs__msg__FleetStatus__destroy(multi_drone_msgs__msg__FleetStatus * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    multi_drone_msgs__msg__FleetStatus__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
multi_drone_msgs__msg__FleetStatus__Sequence__init(multi_drone_msgs__msg__FleetStatus__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  multi_drone_msgs__msg__FleetStatus * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(multi_drone_msgs__msg__FleetStatus)) {
      return false;
    }
    data = (multi_drone_msgs__msg__FleetStatus *)allocator.zero_allocate(size, sizeof(multi_drone_msgs__msg__FleetStatus), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = multi_drone_msgs__msg__FleetStatus__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        multi_drone_msgs__msg__FleetStatus__fini(&data[i - 1]);
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
multi_drone_msgs__msg__FleetStatus__Sequence__fini(multi_drone_msgs__msg__FleetStatus__Sequence * array)
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
      multi_drone_msgs__msg__FleetStatus__fini(&array->data[i]);
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

multi_drone_msgs__msg__FleetStatus__Sequence *
multi_drone_msgs__msg__FleetStatus__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  multi_drone_msgs__msg__FleetStatus__Sequence * array = (multi_drone_msgs__msg__FleetStatus__Sequence *)allocator.allocate(sizeof(multi_drone_msgs__msg__FleetStatus__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = multi_drone_msgs__msg__FleetStatus__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
multi_drone_msgs__msg__FleetStatus__Sequence__destroy(multi_drone_msgs__msg__FleetStatus__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    multi_drone_msgs__msg__FleetStatus__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
multi_drone_msgs__msg__FleetStatus__Sequence__are_equal(const multi_drone_msgs__msg__FleetStatus__Sequence * lhs, const multi_drone_msgs__msg__FleetStatus__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!multi_drone_msgs__msg__FleetStatus__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
multi_drone_msgs__msg__FleetStatus__Sequence__copy(
  const multi_drone_msgs__msg__FleetStatus__Sequence * input,
  multi_drone_msgs__msg__FleetStatus__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(multi_drone_msgs__msg__FleetStatus)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(multi_drone_msgs__msg__FleetStatus);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    multi_drone_msgs__msg__FleetStatus * data =
      (multi_drone_msgs__msg__FleetStatus *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!multi_drone_msgs__msg__FleetStatus__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          multi_drone_msgs__msg__FleetStatus__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!multi_drone_msgs__msg__FleetStatus__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
