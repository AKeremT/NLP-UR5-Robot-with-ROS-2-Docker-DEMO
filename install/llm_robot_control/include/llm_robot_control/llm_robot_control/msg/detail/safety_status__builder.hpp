// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from llm_robot_control:msg/SafetyStatus.idl
// generated code does not contain a copyright notice

#ifndef LLM_ROBOT_CONTROL__MSG__DETAIL__SAFETY_STATUS__BUILDER_HPP_
#define LLM_ROBOT_CONTROL__MSG__DETAIL__SAFETY_STATUS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "llm_robot_control/msg/detail/safety_status__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace llm_robot_control
{

namespace msg
{

namespace builder
{

class Init_SafetyStatus_message
{
public:
  explicit Init_SafetyStatus_message(::llm_robot_control::msg::SafetyStatus & msg)
  : msg_(msg)
  {}
  ::llm_robot_control::msg::SafetyStatus message(::llm_robot_control::msg::SafetyStatus::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::llm_robot_control::msg::SafetyStatus msg_;
};

class Init_SafetyStatus_violations
{
public:
  explicit Init_SafetyStatus_violations(::llm_robot_control::msg::SafetyStatus & msg)
  : msg_(msg)
  {}
  Init_SafetyStatus_message violations(::llm_robot_control::msg::SafetyStatus::_violations_type arg)
  {
    msg_.violations = std::move(arg);
    return Init_SafetyStatus_message(msg_);
  }

private:
  ::llm_robot_control::msg::SafetyStatus msg_;
};

class Init_SafetyStatus_is_safe
{
public:
  Init_SafetyStatus_is_safe()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SafetyStatus_violations is_safe(::llm_robot_control::msg::SafetyStatus::_is_safe_type arg)
  {
    msg_.is_safe = std::move(arg);
    return Init_SafetyStatus_violations(msg_);
  }

private:
  ::llm_robot_control::msg::SafetyStatus msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::llm_robot_control::msg::SafetyStatus>()
{
  return llm_robot_control::msg::builder::Init_SafetyStatus_is_safe();
}

}  // namespace llm_robot_control

#endif  // LLM_ROBOT_CONTROL__MSG__DETAIL__SAFETY_STATUS__BUILDER_HPP_
