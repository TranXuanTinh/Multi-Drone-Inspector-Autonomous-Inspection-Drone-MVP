// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from multi_drone_msgs:srv/RegisterVehicle.idl
// generated code does not contain a copyright notice
#include "multi_drone_msgs/srv/detail/register_vehicle__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

// Include directives for member types
// Member `vehicle_namespace`
// Member `name`
// Member `model`
// Member `role`
#include "rosidl_runtime_c/string_functions.h"

bool
multi_drone_msgs__srv__RegisterVehicle_Request__init(multi_drone_msgs__srv__RegisterVehicle_Request * msg)
{
  if (!msg) {
    return false;
  }
  // vehicle_id
  // vehicle_namespace
  if (!rosidl_runtime_c__String__init(&msg->vehicle_namespace)) {
    multi_drone_msgs__srv__RegisterVehicle_Request__fini(msg);
    return false;
  }
  // name
  if (!rosidl_runtime_c__String__init(&msg->name)) {
    multi_drone_msgs__srv__RegisterVehicle_Request__fini(msg);
    return false;
  }
  // model
  if (!rosidl_runtime_c__String__init(&msg->model)) {
    multi_drone_msgs__srv__RegisterVehicle_Request__fini(msg);
    return false;
  }
  // role
  if (!rosidl_runtime_c__String__init(&msg->role)) {
    multi_drone_msgs__srv__RegisterVehicle_Request__fini(msg);
    return false;
  }
  return true;
}

void
multi_drone_msgs__srv__RegisterVehicle_Request__fini(multi_drone_msgs__srv__RegisterVehicle_Request * msg)
{
  if (!msg) {
    return;
  }
  // vehicle_id
  // vehicle_namespace
  rosidl_runtime_c__String__fini(&msg->vehicle_namespace);
  // name
  rosidl_runtime_c__String__fini(&msg->name);
  // model
  rosidl_runtime_c__String__fini(&msg->model);
  // role
  rosidl_runtime_c__String__fini(&msg->role);
}

bool
multi_drone_msgs__srv__RegisterVehicle_Request__are_equal(const multi_drone_msgs__srv__RegisterVehicle_Request * lhs, const multi_drone_msgs__srv__RegisterVehicle_Request * rhs)
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
  // model
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->model), &(rhs->model)))
  {
    return false;
  }
  // role
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->role), &(rhs->role)))
  {
    return false;
  }
  return true;
}

bool
multi_drone_msgs__srv__RegisterVehicle_Request__copy(
  const multi_drone_msgs__srv__RegisterVehicle_Request * input,
  multi_drone_msgs__srv__RegisterVehicle_Request * output)
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
  // model
  if (!rosidl_runtime_c__String__copy(
      &(input->model), &(output->model)))
  {
    return false;
  }
  // role
  if (!rosidl_runtime_c__String__copy(
      &(input->role), &(output->role)))
  {
    return false;
  }
  return true;
}

multi_drone_msgs__srv__RegisterVehicle_Request *
multi_drone_msgs__srv__RegisterVehicle_Request__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  multi_drone_msgs__srv__RegisterVehicle_Request * msg = (multi_drone_msgs__srv__RegisterVehicle_Request *)allocator.allocate(sizeof(multi_drone_msgs__srv__RegisterVehicle_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(multi_drone_msgs__srv__RegisterVehicle_Request));
  bool success = multi_drone_msgs__srv__RegisterVehicle_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
multi_drone_msgs__srv__RegisterVehicle_Request__destroy(multi_drone_msgs__srv__RegisterVehicle_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    multi_drone_msgs__srv__RegisterVehicle_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
multi_drone_msgs__srv__RegisterVehicle_Request__Sequence__init(multi_drone_msgs__srv__RegisterVehicle_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  multi_drone_msgs__srv__RegisterVehicle_Request * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(multi_drone_msgs__srv__RegisterVehicle_Request)) {
      return false;
    }
    data = (multi_drone_msgs__srv__RegisterVehicle_Request *)allocator.zero_allocate(size, sizeof(multi_drone_msgs__srv__RegisterVehicle_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = multi_drone_msgs__srv__RegisterVehicle_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        multi_drone_msgs__srv__RegisterVehicle_Request__fini(&data[i - 1]);
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
multi_drone_msgs__srv__RegisterVehicle_Request__Sequence__fini(multi_drone_msgs__srv__RegisterVehicle_Request__Sequence * array)
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
      multi_drone_msgs__srv__RegisterVehicle_Request__fini(&array->data[i]);
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

multi_drone_msgs__srv__RegisterVehicle_Request__Sequence *
multi_drone_msgs__srv__RegisterVehicle_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  multi_drone_msgs__srv__RegisterVehicle_Request__Sequence * array = (multi_drone_msgs__srv__RegisterVehicle_Request__Sequence *)allocator.allocate(sizeof(multi_drone_msgs__srv__RegisterVehicle_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = multi_drone_msgs__srv__RegisterVehicle_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
multi_drone_msgs__srv__RegisterVehicle_Request__Sequence__destroy(multi_drone_msgs__srv__RegisterVehicle_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    multi_drone_msgs__srv__RegisterVehicle_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
multi_drone_msgs__srv__RegisterVehicle_Request__Sequence__are_equal(const multi_drone_msgs__srv__RegisterVehicle_Request__Sequence * lhs, const multi_drone_msgs__srv__RegisterVehicle_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!multi_drone_msgs__srv__RegisterVehicle_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
multi_drone_msgs__srv__RegisterVehicle_Request__Sequence__copy(
  const multi_drone_msgs__srv__RegisterVehicle_Request__Sequence * input,
  multi_drone_msgs__srv__RegisterVehicle_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(multi_drone_msgs__srv__RegisterVehicle_Request)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(multi_drone_msgs__srv__RegisterVehicle_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    multi_drone_msgs__srv__RegisterVehicle_Request * data =
      (multi_drone_msgs__srv__RegisterVehicle_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!multi_drone_msgs__srv__RegisterVehicle_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          multi_drone_msgs__srv__RegisterVehicle_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!multi_drone_msgs__srv__RegisterVehicle_Request__copy(
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
multi_drone_msgs__srv__RegisterVehicle_Response__init(multi_drone_msgs__srv__RegisterVehicle_Response * msg)
{
  if (!msg) {
    return false;
  }
  // success
  // message
  if (!rosidl_runtime_c__String__init(&msg->message)) {
    multi_drone_msgs__srv__RegisterVehicle_Response__fini(msg);
    return false;
  }
  return true;
}

void
multi_drone_msgs__srv__RegisterVehicle_Response__fini(multi_drone_msgs__srv__RegisterVehicle_Response * msg)
{
  if (!msg) {
    return;
  }
  // success
  // message
  rosidl_runtime_c__String__fini(&msg->message);
}

bool
multi_drone_msgs__srv__RegisterVehicle_Response__are_equal(const multi_drone_msgs__srv__RegisterVehicle_Response * lhs, const multi_drone_msgs__srv__RegisterVehicle_Response * rhs)
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
  return true;
}

bool
multi_drone_msgs__srv__RegisterVehicle_Response__copy(
  const multi_drone_msgs__srv__RegisterVehicle_Response * input,
  multi_drone_msgs__srv__RegisterVehicle_Response * output)
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
  return true;
}

multi_drone_msgs__srv__RegisterVehicle_Response *
multi_drone_msgs__srv__RegisterVehicle_Response__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  multi_drone_msgs__srv__RegisterVehicle_Response * msg = (multi_drone_msgs__srv__RegisterVehicle_Response *)allocator.allocate(sizeof(multi_drone_msgs__srv__RegisterVehicle_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(multi_drone_msgs__srv__RegisterVehicle_Response));
  bool success = multi_drone_msgs__srv__RegisterVehicle_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
multi_drone_msgs__srv__RegisterVehicle_Response__destroy(multi_drone_msgs__srv__RegisterVehicle_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    multi_drone_msgs__srv__RegisterVehicle_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
multi_drone_msgs__srv__RegisterVehicle_Response__Sequence__init(multi_drone_msgs__srv__RegisterVehicle_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  multi_drone_msgs__srv__RegisterVehicle_Response * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(multi_drone_msgs__srv__RegisterVehicle_Response)) {
      return false;
    }
    data = (multi_drone_msgs__srv__RegisterVehicle_Response *)allocator.zero_allocate(size, sizeof(multi_drone_msgs__srv__RegisterVehicle_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = multi_drone_msgs__srv__RegisterVehicle_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        multi_drone_msgs__srv__RegisterVehicle_Response__fini(&data[i - 1]);
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
multi_drone_msgs__srv__RegisterVehicle_Response__Sequence__fini(multi_drone_msgs__srv__RegisterVehicle_Response__Sequence * array)
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
      multi_drone_msgs__srv__RegisterVehicle_Response__fini(&array->data[i]);
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

multi_drone_msgs__srv__RegisterVehicle_Response__Sequence *
multi_drone_msgs__srv__RegisterVehicle_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  multi_drone_msgs__srv__RegisterVehicle_Response__Sequence * array = (multi_drone_msgs__srv__RegisterVehicle_Response__Sequence *)allocator.allocate(sizeof(multi_drone_msgs__srv__RegisterVehicle_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = multi_drone_msgs__srv__RegisterVehicle_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
multi_drone_msgs__srv__RegisterVehicle_Response__Sequence__destroy(multi_drone_msgs__srv__RegisterVehicle_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    multi_drone_msgs__srv__RegisterVehicle_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
multi_drone_msgs__srv__RegisterVehicle_Response__Sequence__are_equal(const multi_drone_msgs__srv__RegisterVehicle_Response__Sequence * lhs, const multi_drone_msgs__srv__RegisterVehicle_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!multi_drone_msgs__srv__RegisterVehicle_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
multi_drone_msgs__srv__RegisterVehicle_Response__Sequence__copy(
  const multi_drone_msgs__srv__RegisterVehicle_Response__Sequence * input,
  multi_drone_msgs__srv__RegisterVehicle_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(multi_drone_msgs__srv__RegisterVehicle_Response)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(multi_drone_msgs__srv__RegisterVehicle_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    multi_drone_msgs__srv__RegisterVehicle_Response * data =
      (multi_drone_msgs__srv__RegisterVehicle_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!multi_drone_msgs__srv__RegisterVehicle_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          multi_drone_msgs__srv__RegisterVehicle_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!multi_drone_msgs__srv__RegisterVehicle_Response__copy(
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
// #include "multi_drone_msgs/srv/detail/register_vehicle__functions.h"

bool
multi_drone_msgs__srv__RegisterVehicle_Event__init(multi_drone_msgs__srv__RegisterVehicle_Event * msg)
{
  if (!msg) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__init(&msg->info)) {
    multi_drone_msgs__srv__RegisterVehicle_Event__fini(msg);
    return false;
  }
  // request
  if (!multi_drone_msgs__srv__RegisterVehicle_Request__Sequence__init(&msg->request, 0)) {
    multi_drone_msgs__srv__RegisterVehicle_Event__fini(msg);
    return false;
  }
  // response
  if (!multi_drone_msgs__srv__RegisterVehicle_Response__Sequence__init(&msg->response, 0)) {
    multi_drone_msgs__srv__RegisterVehicle_Event__fini(msg);
    return false;
  }
  return true;
}

void
multi_drone_msgs__srv__RegisterVehicle_Event__fini(multi_drone_msgs__srv__RegisterVehicle_Event * msg)
{
  if (!msg) {
    return;
  }
  // info
  service_msgs__msg__ServiceEventInfo__fini(&msg->info);
  // request
  multi_drone_msgs__srv__RegisterVehicle_Request__Sequence__fini(&msg->request);
  // response
  multi_drone_msgs__srv__RegisterVehicle_Response__Sequence__fini(&msg->response);
}

bool
multi_drone_msgs__srv__RegisterVehicle_Event__are_equal(const multi_drone_msgs__srv__RegisterVehicle_Event * lhs, const multi_drone_msgs__srv__RegisterVehicle_Event * rhs)
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
  if (!multi_drone_msgs__srv__RegisterVehicle_Request__Sequence__are_equal(
      &(lhs->request), &(rhs->request)))
  {
    return false;
  }
  // response
  if (!multi_drone_msgs__srv__RegisterVehicle_Response__Sequence__are_equal(
      &(lhs->response), &(rhs->response)))
  {
    return false;
  }
  return true;
}

bool
multi_drone_msgs__srv__RegisterVehicle_Event__copy(
  const multi_drone_msgs__srv__RegisterVehicle_Event * input,
  multi_drone_msgs__srv__RegisterVehicle_Event * output)
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
  if (!multi_drone_msgs__srv__RegisterVehicle_Request__Sequence__copy(
      &(input->request), &(output->request)))
  {
    return false;
  }
  // response
  if (!multi_drone_msgs__srv__RegisterVehicle_Response__Sequence__copy(
      &(input->response), &(output->response)))
  {
    return false;
  }
  return true;
}

multi_drone_msgs__srv__RegisterVehicle_Event *
multi_drone_msgs__srv__RegisterVehicle_Event__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  multi_drone_msgs__srv__RegisterVehicle_Event * msg = (multi_drone_msgs__srv__RegisterVehicle_Event *)allocator.allocate(sizeof(multi_drone_msgs__srv__RegisterVehicle_Event), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(multi_drone_msgs__srv__RegisterVehicle_Event));
  bool success = multi_drone_msgs__srv__RegisterVehicle_Event__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
multi_drone_msgs__srv__RegisterVehicle_Event__destroy(multi_drone_msgs__srv__RegisterVehicle_Event * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    multi_drone_msgs__srv__RegisterVehicle_Event__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
multi_drone_msgs__srv__RegisterVehicle_Event__Sequence__init(multi_drone_msgs__srv__RegisterVehicle_Event__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  multi_drone_msgs__srv__RegisterVehicle_Event * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(multi_drone_msgs__srv__RegisterVehicle_Event)) {
      return false;
    }
    data = (multi_drone_msgs__srv__RegisterVehicle_Event *)allocator.zero_allocate(size, sizeof(multi_drone_msgs__srv__RegisterVehicle_Event), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = multi_drone_msgs__srv__RegisterVehicle_Event__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        multi_drone_msgs__srv__RegisterVehicle_Event__fini(&data[i - 1]);
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
multi_drone_msgs__srv__RegisterVehicle_Event__Sequence__fini(multi_drone_msgs__srv__RegisterVehicle_Event__Sequence * array)
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
      multi_drone_msgs__srv__RegisterVehicle_Event__fini(&array->data[i]);
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

multi_drone_msgs__srv__RegisterVehicle_Event__Sequence *
multi_drone_msgs__srv__RegisterVehicle_Event__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  multi_drone_msgs__srv__RegisterVehicle_Event__Sequence * array = (multi_drone_msgs__srv__RegisterVehicle_Event__Sequence *)allocator.allocate(sizeof(multi_drone_msgs__srv__RegisterVehicle_Event__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = multi_drone_msgs__srv__RegisterVehicle_Event__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
multi_drone_msgs__srv__RegisterVehicle_Event__Sequence__destroy(multi_drone_msgs__srv__RegisterVehicle_Event__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    multi_drone_msgs__srv__RegisterVehicle_Event__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
multi_drone_msgs__srv__RegisterVehicle_Event__Sequence__are_equal(const multi_drone_msgs__srv__RegisterVehicle_Event__Sequence * lhs, const multi_drone_msgs__srv__RegisterVehicle_Event__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!multi_drone_msgs__srv__RegisterVehicle_Event__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
multi_drone_msgs__srv__RegisterVehicle_Event__Sequence__copy(
  const multi_drone_msgs__srv__RegisterVehicle_Event__Sequence * input,
  multi_drone_msgs__srv__RegisterVehicle_Event__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(multi_drone_msgs__srv__RegisterVehicle_Event)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(multi_drone_msgs__srv__RegisterVehicle_Event);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    multi_drone_msgs__srv__RegisterVehicle_Event * data =
      (multi_drone_msgs__srv__RegisterVehicle_Event *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!multi_drone_msgs__srv__RegisterVehicle_Event__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          multi_drone_msgs__srv__RegisterVehicle_Event__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!multi_drone_msgs__srv__RegisterVehicle_Event__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
