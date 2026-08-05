// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from multi_drone_msgs:srv/AssignMission.idl
// generated code does not contain a copyright notice
#include "multi_drone_msgs/srv/detail/assign_mission__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

// Include directives for member types
// Member `mission_type`
#include "rosidl_runtime_c/string_functions.h"
// Member `waypoint_lats`
// Member `waypoint_lons`
// Member `waypoint_alts`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
multi_drone_msgs__srv__AssignMission_Request__init(multi_drone_msgs__srv__AssignMission_Request * msg)
{
  if (!msg) {
    return false;
  }
  // vehicle_id
  // mission_type
  if (!rosidl_runtime_c__String__init(&msg->mission_type)) {
    multi_drone_msgs__srv__AssignMission_Request__fini(msg);
    return false;
  }
  // waypoint_lats
  if (!rosidl_runtime_c__double__Sequence__init(&msg->waypoint_lats, 0)) {
    multi_drone_msgs__srv__AssignMission_Request__fini(msg);
    return false;
  }
  // waypoint_lons
  if (!rosidl_runtime_c__double__Sequence__init(&msg->waypoint_lons, 0)) {
    multi_drone_msgs__srv__AssignMission_Request__fini(msg);
    return false;
  }
  // waypoint_alts
  if (!rosidl_runtime_c__float__Sequence__init(&msg->waypoint_alts, 0)) {
    multi_drone_msgs__srv__AssignMission_Request__fini(msg);
    return false;
  }
  // speed_ms
  return true;
}

void
multi_drone_msgs__srv__AssignMission_Request__fini(multi_drone_msgs__srv__AssignMission_Request * msg)
{
  if (!msg) {
    return;
  }
  // vehicle_id
  // mission_type
  rosidl_runtime_c__String__fini(&msg->mission_type);
  // waypoint_lats
  rosidl_runtime_c__double__Sequence__fini(&msg->waypoint_lats);
  // waypoint_lons
  rosidl_runtime_c__double__Sequence__fini(&msg->waypoint_lons);
  // waypoint_alts
  rosidl_runtime_c__float__Sequence__fini(&msg->waypoint_alts);
  // speed_ms
}

bool
multi_drone_msgs__srv__AssignMission_Request__are_equal(const multi_drone_msgs__srv__AssignMission_Request * lhs, const multi_drone_msgs__srv__AssignMission_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // vehicle_id
  if (lhs->vehicle_id != rhs->vehicle_id) {
    return false;
  }
  // mission_type
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->mission_type), &(rhs->mission_type)))
  {
    return false;
  }
  // waypoint_lats
  if (!rosidl_runtime_c__double__Sequence__are_equal(
      &(lhs->waypoint_lats), &(rhs->waypoint_lats)))
  {
    return false;
  }
  // waypoint_lons
  if (!rosidl_runtime_c__double__Sequence__are_equal(
      &(lhs->waypoint_lons), &(rhs->waypoint_lons)))
  {
    return false;
  }
  // waypoint_alts
  if (!rosidl_runtime_c__float__Sequence__are_equal(
      &(lhs->waypoint_alts), &(rhs->waypoint_alts)))
  {
    return false;
  }
  // speed_ms
  if (lhs->speed_ms != rhs->speed_ms) {
    return false;
  }
  return true;
}

bool
multi_drone_msgs__srv__AssignMission_Request__copy(
  const multi_drone_msgs__srv__AssignMission_Request * input,
  multi_drone_msgs__srv__AssignMission_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // vehicle_id
  output->vehicle_id = input->vehicle_id;
  // mission_type
  if (!rosidl_runtime_c__String__copy(
      &(input->mission_type), &(output->mission_type)))
  {
    return false;
  }
  // waypoint_lats
  if (!rosidl_runtime_c__double__Sequence__copy(
      &(input->waypoint_lats), &(output->waypoint_lats)))
  {
    return false;
  }
  // waypoint_lons
  if (!rosidl_runtime_c__double__Sequence__copy(
      &(input->waypoint_lons), &(output->waypoint_lons)))
  {
    return false;
  }
  // waypoint_alts
  if (!rosidl_runtime_c__float__Sequence__copy(
      &(input->waypoint_alts), &(output->waypoint_alts)))
  {
    return false;
  }
  // speed_ms
  output->speed_ms = input->speed_ms;
  return true;
}

multi_drone_msgs__srv__AssignMission_Request *
multi_drone_msgs__srv__AssignMission_Request__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  multi_drone_msgs__srv__AssignMission_Request * msg = (multi_drone_msgs__srv__AssignMission_Request *)allocator.allocate(sizeof(multi_drone_msgs__srv__AssignMission_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(multi_drone_msgs__srv__AssignMission_Request));
  bool success = multi_drone_msgs__srv__AssignMission_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
multi_drone_msgs__srv__AssignMission_Request__destroy(multi_drone_msgs__srv__AssignMission_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    multi_drone_msgs__srv__AssignMission_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
multi_drone_msgs__srv__AssignMission_Request__Sequence__init(multi_drone_msgs__srv__AssignMission_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  multi_drone_msgs__srv__AssignMission_Request * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(multi_drone_msgs__srv__AssignMission_Request)) {
      return false;
    }
    data = (multi_drone_msgs__srv__AssignMission_Request *)allocator.zero_allocate(size, sizeof(multi_drone_msgs__srv__AssignMission_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = multi_drone_msgs__srv__AssignMission_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        multi_drone_msgs__srv__AssignMission_Request__fini(&data[i - 1]);
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
multi_drone_msgs__srv__AssignMission_Request__Sequence__fini(multi_drone_msgs__srv__AssignMission_Request__Sequence * array)
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
      multi_drone_msgs__srv__AssignMission_Request__fini(&array->data[i]);
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

multi_drone_msgs__srv__AssignMission_Request__Sequence *
multi_drone_msgs__srv__AssignMission_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  multi_drone_msgs__srv__AssignMission_Request__Sequence * array = (multi_drone_msgs__srv__AssignMission_Request__Sequence *)allocator.allocate(sizeof(multi_drone_msgs__srv__AssignMission_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = multi_drone_msgs__srv__AssignMission_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
multi_drone_msgs__srv__AssignMission_Request__Sequence__destroy(multi_drone_msgs__srv__AssignMission_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    multi_drone_msgs__srv__AssignMission_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
multi_drone_msgs__srv__AssignMission_Request__Sequence__are_equal(const multi_drone_msgs__srv__AssignMission_Request__Sequence * lhs, const multi_drone_msgs__srv__AssignMission_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!multi_drone_msgs__srv__AssignMission_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
multi_drone_msgs__srv__AssignMission_Request__Sequence__copy(
  const multi_drone_msgs__srv__AssignMission_Request__Sequence * input,
  multi_drone_msgs__srv__AssignMission_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(multi_drone_msgs__srv__AssignMission_Request)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(multi_drone_msgs__srv__AssignMission_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    multi_drone_msgs__srv__AssignMission_Request * data =
      (multi_drone_msgs__srv__AssignMission_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!multi_drone_msgs__srv__AssignMission_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          multi_drone_msgs__srv__AssignMission_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!multi_drone_msgs__srv__AssignMission_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `message`
// already included above
// #include "rosidl_runtime_c/string_functions.h"

bool
multi_drone_msgs__srv__AssignMission_Response__init(multi_drone_msgs__srv__AssignMission_Response * msg)
{
  if (!msg) {
    return false;
  }
  // success
  // message
  if (!rosidl_runtime_c__String__init(&msg->message)) {
    multi_drone_msgs__srv__AssignMission_Response__fini(msg);
    return false;
  }
  // num_waypoints_accepted
  return true;
}

void
multi_drone_msgs__srv__AssignMission_Response__fini(multi_drone_msgs__srv__AssignMission_Response * msg)
{
  if (!msg) {
    return;
  }
  // success
  // message
  rosidl_runtime_c__String__fini(&msg->message);
  // num_waypoints_accepted
}

bool
multi_drone_msgs__srv__AssignMission_Response__are_equal(const multi_drone_msgs__srv__AssignMission_Response * lhs, const multi_drone_msgs__srv__AssignMission_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // success
  if (lhs->success != rhs->success) {
    return false;
  }
  // message
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->message), &(rhs->message)))
  {
    return false;
  }
  // num_waypoints_accepted
  if (lhs->num_waypoints_accepted != rhs->num_waypoints_accepted) {
    return false;
  }
  return true;
}

bool
multi_drone_msgs__srv__AssignMission_Response__copy(
  const multi_drone_msgs__srv__AssignMission_Response * input,
  multi_drone_msgs__srv__AssignMission_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // success
  output->success = input->success;
  // message
  if (!rosidl_runtime_c__String__copy(
      &(input->message), &(output->message)))
  {
    return false;
  }
  // num_waypoints_accepted
  output->num_waypoints_accepted = input->num_waypoints_accepted;
  return true;
}

multi_drone_msgs__srv__AssignMission_Response *
multi_drone_msgs__srv__AssignMission_Response__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  multi_drone_msgs__srv__AssignMission_Response * msg = (multi_drone_msgs__srv__AssignMission_Response *)allocator.allocate(sizeof(multi_drone_msgs__srv__AssignMission_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(multi_drone_msgs__srv__AssignMission_Response));
  bool success = multi_drone_msgs__srv__AssignMission_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
multi_drone_msgs__srv__AssignMission_Response__destroy(multi_drone_msgs__srv__AssignMission_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    multi_drone_msgs__srv__AssignMission_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
multi_drone_msgs__srv__AssignMission_Response__Sequence__init(multi_drone_msgs__srv__AssignMission_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  multi_drone_msgs__srv__AssignMission_Response * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(multi_drone_msgs__srv__AssignMission_Response)) {
      return false;
    }
    data = (multi_drone_msgs__srv__AssignMission_Response *)allocator.zero_allocate(size, sizeof(multi_drone_msgs__srv__AssignMission_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = multi_drone_msgs__srv__AssignMission_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        multi_drone_msgs__srv__AssignMission_Response__fini(&data[i - 1]);
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
multi_drone_msgs__srv__AssignMission_Response__Sequence__fini(multi_drone_msgs__srv__AssignMission_Response__Sequence * array)
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
      multi_drone_msgs__srv__AssignMission_Response__fini(&array->data[i]);
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

multi_drone_msgs__srv__AssignMission_Response__Sequence *
multi_drone_msgs__srv__AssignMission_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  multi_drone_msgs__srv__AssignMission_Response__Sequence * array = (multi_drone_msgs__srv__AssignMission_Response__Sequence *)allocator.allocate(sizeof(multi_drone_msgs__srv__AssignMission_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = multi_drone_msgs__srv__AssignMission_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
multi_drone_msgs__srv__AssignMission_Response__Sequence__destroy(multi_drone_msgs__srv__AssignMission_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    multi_drone_msgs__srv__AssignMission_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
multi_drone_msgs__srv__AssignMission_Response__Sequence__are_equal(const multi_drone_msgs__srv__AssignMission_Response__Sequence * lhs, const multi_drone_msgs__srv__AssignMission_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!multi_drone_msgs__srv__AssignMission_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
multi_drone_msgs__srv__AssignMission_Response__Sequence__copy(
  const multi_drone_msgs__srv__AssignMission_Response__Sequence * input,
  multi_drone_msgs__srv__AssignMission_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(multi_drone_msgs__srv__AssignMission_Response)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(multi_drone_msgs__srv__AssignMission_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    multi_drone_msgs__srv__AssignMission_Response * data =
      (multi_drone_msgs__srv__AssignMission_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!multi_drone_msgs__srv__AssignMission_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          multi_drone_msgs__srv__AssignMission_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!multi_drone_msgs__srv__AssignMission_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `info`
#include "service_msgs/msg/detail/service_event_info__functions.h"
// Member `request`
// Member `response`
// already included above
// #include "multi_drone_msgs/srv/detail/assign_mission__functions.h"

bool
multi_drone_msgs__srv__AssignMission_Event__init(multi_drone_msgs__srv__AssignMission_Event * msg)
{
  if (!msg) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__init(&msg->info)) {
    multi_drone_msgs__srv__AssignMission_Event__fini(msg);
    return false;
  }
  // request
  if (!multi_drone_msgs__srv__AssignMission_Request__Sequence__init(&msg->request, 0)) {
    multi_drone_msgs__srv__AssignMission_Event__fini(msg);
    return false;
  }
  // response
  if (!multi_drone_msgs__srv__AssignMission_Response__Sequence__init(&msg->response, 0)) {
    multi_drone_msgs__srv__AssignMission_Event__fini(msg);
    return false;
  }
  return true;
}

void
multi_drone_msgs__srv__AssignMission_Event__fini(multi_drone_msgs__srv__AssignMission_Event * msg)
{
  if (!msg) {
    return;
  }
  // info
  service_msgs__msg__ServiceEventInfo__fini(&msg->info);
  // request
  multi_drone_msgs__srv__AssignMission_Request__Sequence__fini(&msg->request);
  // response
  multi_drone_msgs__srv__AssignMission_Response__Sequence__fini(&msg->response);
}

bool
multi_drone_msgs__srv__AssignMission_Event__are_equal(const multi_drone_msgs__srv__AssignMission_Event * lhs, const multi_drone_msgs__srv__AssignMission_Event * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__are_equal(
      &(lhs->info), &(rhs->info)))
  {
    return false;
  }
  // request
  if (!multi_drone_msgs__srv__AssignMission_Request__Sequence__are_equal(
      &(lhs->request), &(rhs->request)))
  {
    return false;
  }
  // response
  if (!multi_drone_msgs__srv__AssignMission_Response__Sequence__are_equal(
      &(lhs->response), &(rhs->response)))
  {
    return false;
  }
  return true;
}

bool
multi_drone_msgs__srv__AssignMission_Event__copy(
  const multi_drone_msgs__srv__AssignMission_Event * input,
  multi_drone_msgs__srv__AssignMission_Event * output)
{
  if (!input || !output) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__copy(
      &(input->info), &(output->info)))
  {
    return false;
  }
  // request
  if (!multi_drone_msgs__srv__AssignMission_Request__Sequence__copy(
      &(input->request), &(output->request)))
  {
    return false;
  }
  // response
  if (!multi_drone_msgs__srv__AssignMission_Response__Sequence__copy(
      &(input->response), &(output->response)))
  {
    return false;
  }
  return true;
}

multi_drone_msgs__srv__AssignMission_Event *
multi_drone_msgs__srv__AssignMission_Event__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  multi_drone_msgs__srv__AssignMission_Event * msg = (multi_drone_msgs__srv__AssignMission_Event *)allocator.allocate(sizeof(multi_drone_msgs__srv__AssignMission_Event), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(multi_drone_msgs__srv__AssignMission_Event));
  bool success = multi_drone_msgs__srv__AssignMission_Event__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
multi_drone_msgs__srv__AssignMission_Event__destroy(multi_drone_msgs__srv__AssignMission_Event * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    multi_drone_msgs__srv__AssignMission_Event__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
multi_drone_msgs__srv__AssignMission_Event__Sequence__init(multi_drone_msgs__srv__AssignMission_Event__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  multi_drone_msgs__srv__AssignMission_Event * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(multi_drone_msgs__srv__AssignMission_Event)) {
      return false;
    }
    data = (multi_drone_msgs__srv__AssignMission_Event *)allocator.zero_allocate(size, sizeof(multi_drone_msgs__srv__AssignMission_Event), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = multi_drone_msgs__srv__AssignMission_Event__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        multi_drone_msgs__srv__AssignMission_Event__fini(&data[i - 1]);
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
multi_drone_msgs__srv__AssignMission_Event__Sequence__fini(multi_drone_msgs__srv__AssignMission_Event__Sequence * array)
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
      multi_drone_msgs__srv__AssignMission_Event__fini(&array->data[i]);
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

multi_drone_msgs__srv__AssignMission_Event__Sequence *
multi_drone_msgs__srv__AssignMission_Event__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  multi_drone_msgs__srv__AssignMission_Event__Sequence * array = (multi_drone_msgs__srv__AssignMission_Event__Sequence *)allocator.allocate(sizeof(multi_drone_msgs__srv__AssignMission_Event__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = multi_drone_msgs__srv__AssignMission_Event__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
multi_drone_msgs__srv__AssignMission_Event__Sequence__destroy(multi_drone_msgs__srv__AssignMission_Event__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    multi_drone_msgs__srv__AssignMission_Event__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
multi_drone_msgs__srv__AssignMission_Event__Sequence__are_equal(const multi_drone_msgs__srv__AssignMission_Event__Sequence * lhs, const multi_drone_msgs__srv__AssignMission_Event__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!multi_drone_msgs__srv__AssignMission_Event__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
multi_drone_msgs__srv__AssignMission_Event__Sequence__copy(
  const multi_drone_msgs__srv__AssignMission_Event__Sequence * input,
  multi_drone_msgs__srv__AssignMission_Event__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(multi_drone_msgs__srv__AssignMission_Event)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(multi_drone_msgs__srv__AssignMission_Event);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    multi_drone_msgs__srv__AssignMission_Event * data =
      (multi_drone_msgs__srv__AssignMission_Event *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!multi_drone_msgs__srv__AssignMission_Event__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          multi_drone_msgs__srv__AssignMission_Event__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!multi_drone_msgs__srv__AssignMission_Event__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
