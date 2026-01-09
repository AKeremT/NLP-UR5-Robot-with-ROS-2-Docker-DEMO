// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from llm_robot_control:msg/SafetyStatus.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "llm_robot_control/msg/detail/safety_status__rosidl_typesupport_introspection_c.h"
#include "llm_robot_control/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "llm_robot_control/msg/detail/safety_status__functions.h"
#include "llm_robot_control/msg/detail/safety_status__struct.h"


// Include directives for member types
// Member `violations`
// Member `message`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void llm_robot_control__msg__SafetyStatus__rosidl_typesupport_introspection_c__SafetyStatus_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  llm_robot_control__msg__SafetyStatus__init(message_memory);
}

void llm_robot_control__msg__SafetyStatus__rosidl_typesupport_introspection_c__SafetyStatus_fini_function(void * message_memory)
{
  llm_robot_control__msg__SafetyStatus__fini(message_memory);
}

size_t llm_robot_control__msg__SafetyStatus__rosidl_typesupport_introspection_c__size_function__SafetyStatus__violations(
  const void * untyped_member)
{
  const rosidl_runtime_c__String__Sequence * member =
    (const rosidl_runtime_c__String__Sequence *)(untyped_member);
  return member->size;
}

const void * llm_robot_control__msg__SafetyStatus__rosidl_typesupport_introspection_c__get_const_function__SafetyStatus__violations(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__String__Sequence * member =
    (const rosidl_runtime_c__String__Sequence *)(untyped_member);
  return &member->data[index];
}

void * llm_robot_control__msg__SafetyStatus__rosidl_typesupport_introspection_c__get_function__SafetyStatus__violations(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__String__Sequence * member =
    (rosidl_runtime_c__String__Sequence *)(untyped_member);
  return &member->data[index];
}

void llm_robot_control__msg__SafetyStatus__rosidl_typesupport_introspection_c__fetch_function__SafetyStatus__violations(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const rosidl_runtime_c__String * item =
    ((const rosidl_runtime_c__String *)
    llm_robot_control__msg__SafetyStatus__rosidl_typesupport_introspection_c__get_const_function__SafetyStatus__violations(untyped_member, index));
  rosidl_runtime_c__String * value =
    (rosidl_runtime_c__String *)(untyped_value);
  *value = *item;
}

void llm_robot_control__msg__SafetyStatus__rosidl_typesupport_introspection_c__assign_function__SafetyStatus__violations(
  void * untyped_member, size_t index, const void * untyped_value)
{
  rosidl_runtime_c__String * item =
    ((rosidl_runtime_c__String *)
    llm_robot_control__msg__SafetyStatus__rosidl_typesupport_introspection_c__get_function__SafetyStatus__violations(untyped_member, index));
  const rosidl_runtime_c__String * value =
    (const rosidl_runtime_c__String *)(untyped_value);
  *item = *value;
}

bool llm_robot_control__msg__SafetyStatus__rosidl_typesupport_introspection_c__resize_function__SafetyStatus__violations(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__String__Sequence * member =
    (rosidl_runtime_c__String__Sequence *)(untyped_member);
  rosidl_runtime_c__String__Sequence__fini(member);
  return rosidl_runtime_c__String__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember llm_robot_control__msg__SafetyStatus__rosidl_typesupport_introspection_c__SafetyStatus_message_member_array[3] = {
  {
    "is_safe",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(llm_robot_control__msg__SafetyStatus, is_safe),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "violations",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(llm_robot_control__msg__SafetyStatus, violations),  // bytes offset in struct
    NULL,  // default value
    llm_robot_control__msg__SafetyStatus__rosidl_typesupport_introspection_c__size_function__SafetyStatus__violations,  // size() function pointer
    llm_robot_control__msg__SafetyStatus__rosidl_typesupport_introspection_c__get_const_function__SafetyStatus__violations,  // get_const(index) function pointer
    llm_robot_control__msg__SafetyStatus__rosidl_typesupport_introspection_c__get_function__SafetyStatus__violations,  // get(index) function pointer
    llm_robot_control__msg__SafetyStatus__rosidl_typesupport_introspection_c__fetch_function__SafetyStatus__violations,  // fetch(index, &value) function pointer
    llm_robot_control__msg__SafetyStatus__rosidl_typesupport_introspection_c__assign_function__SafetyStatus__violations,  // assign(index, value) function pointer
    llm_robot_control__msg__SafetyStatus__rosidl_typesupport_introspection_c__resize_function__SafetyStatus__violations  // resize(index) function pointer
  },
  {
    "message",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(llm_robot_control__msg__SafetyStatus, message),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers llm_robot_control__msg__SafetyStatus__rosidl_typesupport_introspection_c__SafetyStatus_message_members = {
  "llm_robot_control__msg",  // message namespace
  "SafetyStatus",  // message name
  3,  // number of fields
  sizeof(llm_robot_control__msg__SafetyStatus),
  llm_robot_control__msg__SafetyStatus__rosidl_typesupport_introspection_c__SafetyStatus_message_member_array,  // message members
  llm_robot_control__msg__SafetyStatus__rosidl_typesupport_introspection_c__SafetyStatus_init_function,  // function to initialize message memory (memory has to be allocated)
  llm_robot_control__msg__SafetyStatus__rosidl_typesupport_introspection_c__SafetyStatus_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t llm_robot_control__msg__SafetyStatus__rosidl_typesupport_introspection_c__SafetyStatus_message_type_support_handle = {
  0,
  &llm_robot_control__msg__SafetyStatus__rosidl_typesupport_introspection_c__SafetyStatus_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_llm_robot_control
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, llm_robot_control, msg, SafetyStatus)() {
  if (!llm_robot_control__msg__SafetyStatus__rosidl_typesupport_introspection_c__SafetyStatus_message_type_support_handle.typesupport_identifier) {
    llm_robot_control__msg__SafetyStatus__rosidl_typesupport_introspection_c__SafetyStatus_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &llm_robot_control__msg__SafetyStatus__rosidl_typesupport_introspection_c__SafetyStatus_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
