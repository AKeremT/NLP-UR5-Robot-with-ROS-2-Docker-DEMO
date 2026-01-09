// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from llm_robot_control:msg/SafetyStatus.idl
// generated code does not contain a copyright notice

#ifndef LLM_ROBOT_CONTROL__MSG__DETAIL__SAFETY_STATUS__STRUCT_H_
#define LLM_ROBOT_CONTROL__MSG__DETAIL__SAFETY_STATUS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'violations'
// Member 'message'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/SafetyStatus in the package llm_robot_control.
typedef struct llm_robot_control__msg__SafetyStatus
{
  bool is_safe;
  rosidl_runtime_c__String__Sequence violations;
  rosidl_runtime_c__String message;
} llm_robot_control__msg__SafetyStatus;

// Struct for a sequence of llm_robot_control__msg__SafetyStatus.
typedef struct llm_robot_control__msg__SafetyStatus__Sequence
{
  llm_robot_control__msg__SafetyStatus * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} llm_robot_control__msg__SafetyStatus__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // LLM_ROBOT_CONTROL__MSG__DETAIL__SAFETY_STATUS__STRUCT_H_
