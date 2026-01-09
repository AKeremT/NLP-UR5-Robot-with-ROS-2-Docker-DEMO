// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from llm_robot_control:msg/RobotCommand.idl
// generated code does not contain a copyright notice
#include "llm_robot_control/msg/detail/robot_command__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `command_type`
// Member `gripper_state`
#include "rosidl_runtime_c/string_functions.h"
// Member `joint_positions`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
llm_robot_control__msg__RobotCommand__init(llm_robot_control__msg__RobotCommand * msg)
{
  if (!msg) {
    return false;
  }
  // command_type
  if (!rosidl_runtime_c__String__init(&msg->command_type)) {
    llm_robot_control__msg__RobotCommand__fini(msg);
    return false;
  }
  // joint_positions
  if (!rosidl_runtime_c__double__Sequence__init(&msg->joint_positions, 0)) {
    llm_robot_control__msg__RobotCommand__fini(msg);
    return false;
  }
  // x
  // y
  // z
  // roll
  // pitch
  // yaw
  // duration
  // relative
  // gripper_state
  if (!rosidl_runtime_c__String__init(&msg->gripper_state)) {
    llm_robot_control__msg__RobotCommand__fini(msg);
    return false;
  }
  return true;
}

void
llm_robot_control__msg__RobotCommand__fini(llm_robot_control__msg__RobotCommand * msg)
{
  if (!msg) {
    return;
  }
  // command_type
  rosidl_runtime_c__String__fini(&msg->command_type);
  // joint_positions
  rosidl_runtime_c__double__Sequence__fini(&msg->joint_positions);
  // x
  // y
  // z
  // roll
  // pitch
  // yaw
  // duration
  // relative
  // gripper_state
  rosidl_runtime_c__String__fini(&msg->gripper_state);
}

bool
llm_robot_control__msg__RobotCommand__are_equal(const llm_robot_control__msg__RobotCommand * lhs, const llm_robot_control__msg__RobotCommand * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // command_type
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->command_type), &(rhs->command_type)))
  {
    return false;
  }
  // joint_positions
  if (!rosidl_runtime_c__double__Sequence__are_equal(
      &(lhs->joint_positions), &(rhs->joint_positions)))
  {
    return false;
  }
  // x
  if (lhs->x != rhs->x) {
    return false;
  }
  // y
  if (lhs->y != rhs->y) {
    return false;
  }
  // z
  if (lhs->z != rhs->z) {
    return false;
  }
  // roll
  if (lhs->roll != rhs->roll) {
    return false;
  }
  // pitch
  if (lhs->pitch != rhs->pitch) {
    return false;
  }
  // yaw
  if (lhs->yaw != rhs->yaw) {
    return false;
  }
  // duration
  if (lhs->duration != rhs->duration) {
    return false;
  }
  // relative
  if (lhs->relative != rhs->relative) {
    return false;
  }
  // gripper_state
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->gripper_state), &(rhs->gripper_state)))
  {
    return false;
  }
  return true;
}

bool
llm_robot_control__msg__RobotCommand__copy(
  const llm_robot_control__msg__RobotCommand * input,
  llm_robot_control__msg__RobotCommand * output)
{
  if (!input || !output) {
    return false;
  }
  // command_type
  if (!rosidl_runtime_c__String__copy(
      &(input->command_type), &(output->command_type)))
  {
    return false;
  }
  // joint_positions
  if (!rosidl_runtime_c__double__Sequence__copy(
      &(input->joint_positions), &(output->joint_positions)))
  {
    return false;
  }
  // x
  output->x = input->x;
  // y
  output->y = input->y;
  // z
  output->z = input->z;
  // roll
  output->roll = input->roll;
  // pitch
  output->pitch = input->pitch;
  // yaw
  output->yaw = input->yaw;
  // duration
  output->duration = input->duration;
  // relative
  output->relative = input->relative;
  // gripper_state
  if (!rosidl_runtime_c__String__copy(
      &(input->gripper_state), &(output->gripper_state)))
  {
    return false;
  }
  return true;
}

llm_robot_control__msg__RobotCommand *
llm_robot_control__msg__RobotCommand__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  llm_robot_control__msg__RobotCommand * msg = (llm_robot_control__msg__RobotCommand *)allocator.allocate(sizeof(llm_robot_control__msg__RobotCommand), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(llm_robot_control__msg__RobotCommand));
  bool success = llm_robot_control__msg__RobotCommand__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
llm_robot_control__msg__RobotCommand__destroy(llm_robot_control__msg__RobotCommand * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    llm_robot_control__msg__RobotCommand__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
llm_robot_control__msg__RobotCommand__Sequence__init(llm_robot_control__msg__RobotCommand__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  llm_robot_control__msg__RobotCommand * data = NULL;

  if (size) {
    data = (llm_robot_control__msg__RobotCommand *)allocator.zero_allocate(size, sizeof(llm_robot_control__msg__RobotCommand), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = llm_robot_control__msg__RobotCommand__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        llm_robot_control__msg__RobotCommand__fini(&data[i - 1]);
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
llm_robot_control__msg__RobotCommand__Sequence__fini(llm_robot_control__msg__RobotCommand__Sequence * array)
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
      llm_robot_control__msg__RobotCommand__fini(&array->data[i]);
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

llm_robot_control__msg__RobotCommand__Sequence *
llm_robot_control__msg__RobotCommand__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  llm_robot_control__msg__RobotCommand__Sequence * array = (llm_robot_control__msg__RobotCommand__Sequence *)allocator.allocate(sizeof(llm_robot_control__msg__RobotCommand__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = llm_robot_control__msg__RobotCommand__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
llm_robot_control__msg__RobotCommand__Sequence__destroy(llm_robot_control__msg__RobotCommand__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    llm_robot_control__msg__RobotCommand__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
llm_robot_control__msg__RobotCommand__Sequence__are_equal(const llm_robot_control__msg__RobotCommand__Sequence * lhs, const llm_robot_control__msg__RobotCommand__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!llm_robot_control__msg__RobotCommand__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
llm_robot_control__msg__RobotCommand__Sequence__copy(
  const llm_robot_control__msg__RobotCommand__Sequence * input,
  llm_robot_control__msg__RobotCommand__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(llm_robot_control__msg__RobotCommand);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    llm_robot_control__msg__RobotCommand * data =
      (llm_robot_control__msg__RobotCommand *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!llm_robot_control__msg__RobotCommand__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          llm_robot_control__msg__RobotCommand__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!llm_robot_control__msg__RobotCommand__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
