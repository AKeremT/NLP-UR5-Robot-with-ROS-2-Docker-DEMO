// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from llm_robot_control:msg/RobotCommand.idl
// generated code does not contain a copyright notice

#ifndef LLM_ROBOT_CONTROL__MSG__DETAIL__ROBOT_COMMAND__FUNCTIONS_H_
#define LLM_ROBOT_CONTROL__MSG__DETAIL__ROBOT_COMMAND__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "llm_robot_control/msg/rosidl_generator_c__visibility_control.h"

#include "llm_robot_control/msg/detail/robot_command__struct.h"

/// Initialize msg/RobotCommand message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * llm_robot_control__msg__RobotCommand
 * )) before or use
 * llm_robot_control__msg__RobotCommand__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_llm_robot_control
bool
llm_robot_control__msg__RobotCommand__init(llm_robot_control__msg__RobotCommand * msg);

/// Finalize msg/RobotCommand message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_llm_robot_control
void
llm_robot_control__msg__RobotCommand__fini(llm_robot_control__msg__RobotCommand * msg);

/// Create msg/RobotCommand message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * llm_robot_control__msg__RobotCommand__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_llm_robot_control
llm_robot_control__msg__RobotCommand *
llm_robot_control__msg__RobotCommand__create();

/// Destroy msg/RobotCommand message.
/**
 * It calls
 * llm_robot_control__msg__RobotCommand__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_llm_robot_control
void
llm_robot_control__msg__RobotCommand__destroy(llm_robot_control__msg__RobotCommand * msg);

/// Check for msg/RobotCommand message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_llm_robot_control
bool
llm_robot_control__msg__RobotCommand__are_equal(const llm_robot_control__msg__RobotCommand * lhs, const llm_robot_control__msg__RobotCommand * rhs);

/// Copy a msg/RobotCommand message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_llm_robot_control
bool
llm_robot_control__msg__RobotCommand__copy(
  const llm_robot_control__msg__RobotCommand * input,
  llm_robot_control__msg__RobotCommand * output);

/// Initialize array of msg/RobotCommand messages.
/**
 * It allocates the memory for the number of elements and calls
 * llm_robot_control__msg__RobotCommand__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_llm_robot_control
bool
llm_robot_control__msg__RobotCommand__Sequence__init(llm_robot_control__msg__RobotCommand__Sequence * array, size_t size);

/// Finalize array of msg/RobotCommand messages.
/**
 * It calls
 * llm_robot_control__msg__RobotCommand__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_llm_robot_control
void
llm_robot_control__msg__RobotCommand__Sequence__fini(llm_robot_control__msg__RobotCommand__Sequence * array);

/// Create array of msg/RobotCommand messages.
/**
 * It allocates the memory for the array and calls
 * llm_robot_control__msg__RobotCommand__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_llm_robot_control
llm_robot_control__msg__RobotCommand__Sequence *
llm_robot_control__msg__RobotCommand__Sequence__create(size_t size);

/// Destroy array of msg/RobotCommand messages.
/**
 * It calls
 * llm_robot_control__msg__RobotCommand__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_llm_robot_control
void
llm_robot_control__msg__RobotCommand__Sequence__destroy(llm_robot_control__msg__RobotCommand__Sequence * array);

/// Check for msg/RobotCommand message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_llm_robot_control
bool
llm_robot_control__msg__RobotCommand__Sequence__are_equal(const llm_robot_control__msg__RobotCommand__Sequence * lhs, const llm_robot_control__msg__RobotCommand__Sequence * rhs);

/// Copy an array of msg/RobotCommand messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_llm_robot_control
bool
llm_robot_control__msg__RobotCommand__Sequence__copy(
  const llm_robot_control__msg__RobotCommand__Sequence * input,
  llm_robot_control__msg__RobotCommand__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // LLM_ROBOT_CONTROL__MSG__DETAIL__ROBOT_COMMAND__FUNCTIONS_H_
