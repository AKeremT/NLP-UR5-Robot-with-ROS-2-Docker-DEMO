// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from llm_robot_control:msg/RobotCommand.idl
// generated code does not contain a copyright notice

#ifndef LLM_ROBOT_CONTROL__MSG__DETAIL__ROBOT_COMMAND__STRUCT_H_
#define LLM_ROBOT_CONTROL__MSG__DETAIL__ROBOT_COMMAND__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'command_type'
// Member 'gripper_state'
#include "rosidl_runtime_c/string.h"
// Member 'joint_positions'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in msg/RobotCommand in the package llm_robot_control.
typedef struct llm_robot_control__msg__RobotCommand
{
  rosidl_runtime_c__String command_type;
  rosidl_runtime_c__double__Sequence joint_positions;
  double x;
  double y;
  double z;
  double roll;
  double pitch;
  double yaw;
  double duration;
  bool relative;
  rosidl_runtime_c__String gripper_state;
} llm_robot_control__msg__RobotCommand;

// Struct for a sequence of llm_robot_control__msg__RobotCommand.
typedef struct llm_robot_control__msg__RobotCommand__Sequence
{
  llm_robot_control__msg__RobotCommand * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} llm_robot_control__msg__RobotCommand__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // LLM_ROBOT_CONTROL__MSG__DETAIL__ROBOT_COMMAND__STRUCT_H_
