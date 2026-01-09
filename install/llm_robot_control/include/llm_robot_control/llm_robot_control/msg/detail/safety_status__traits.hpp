// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from llm_robot_control:msg/SafetyStatus.idl
// generated code does not contain a copyright notice

#ifndef LLM_ROBOT_CONTROL__MSG__DETAIL__SAFETY_STATUS__TRAITS_HPP_
#define LLM_ROBOT_CONTROL__MSG__DETAIL__SAFETY_STATUS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "llm_robot_control/msg/detail/safety_status__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace llm_robot_control
{

namespace msg
{

inline void to_flow_style_yaml(
  const SafetyStatus & msg,
  std::ostream & out)
{
  out << "{";
  // member: is_safe
  {
    out << "is_safe: ";
    rosidl_generator_traits::value_to_yaml(msg.is_safe, out);
    out << ", ";
  }

  // member: violations
  {
    if (msg.violations.size() == 0) {
      out << "violations: []";
    } else {
      out << "violations: [";
      size_t pending_items = msg.violations.size();
      for (auto item : msg.violations) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: message
  {
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SafetyStatus & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: is_safe
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "is_safe: ";
    rosidl_generator_traits::value_to_yaml(msg.is_safe, out);
    out << "\n";
  }

  // member: violations
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.violations.size() == 0) {
      out << "violations: []\n";
    } else {
      out << "violations:\n";
      for (auto item : msg.violations) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: message
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SafetyStatus & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace llm_robot_control

namespace rosidl_generator_traits
{

[[deprecated("use llm_robot_control::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const llm_robot_control::msg::SafetyStatus & msg,
  std::ostream & out, size_t indentation = 0)
{
  llm_robot_control::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use llm_robot_control::msg::to_yaml() instead")]]
inline std::string to_yaml(const llm_robot_control::msg::SafetyStatus & msg)
{
  return llm_robot_control::msg::to_yaml(msg);
}

template<>
inline const char * data_type<llm_robot_control::msg::SafetyStatus>()
{
  return "llm_robot_control::msg::SafetyStatus";
}

template<>
inline const char * name<llm_robot_control::msg::SafetyStatus>()
{
  return "llm_robot_control/msg/SafetyStatus";
}

template<>
struct has_fixed_size<llm_robot_control::msg::SafetyStatus>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<llm_robot_control::msg::SafetyStatus>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<llm_robot_control::msg::SafetyStatus>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // LLM_ROBOT_CONTROL__MSG__DETAIL__SAFETY_STATUS__TRAITS_HPP_
