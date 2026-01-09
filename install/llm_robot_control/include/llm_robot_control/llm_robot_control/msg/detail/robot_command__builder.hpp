// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from llm_robot_control:msg/RobotCommand.idl
// generated code does not contain a copyright notice

#ifndef LLM_ROBOT_CONTROL__MSG__DETAIL__ROBOT_COMMAND__BUILDER_HPP_
#define LLM_ROBOT_CONTROL__MSG__DETAIL__ROBOT_COMMAND__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "llm_robot_control/msg/detail/robot_command__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace llm_robot_control
{

namespace msg
{

namespace builder
{

class Init_RobotCommand_gripper_state
{
public:
  explicit Init_RobotCommand_gripper_state(::llm_robot_control::msg::RobotCommand & msg)
  : msg_(msg)
  {}
  ::llm_robot_control::msg::RobotCommand gripper_state(::llm_robot_control::msg::RobotCommand::_gripper_state_type arg)
  {
    msg_.gripper_state = std::move(arg);
    return std::move(msg_);
  }

private:
  ::llm_robot_control::msg::RobotCommand msg_;
};

class Init_RobotCommand_relative
{
public:
  explicit Init_RobotCommand_relative(::llm_robot_control::msg::RobotCommand & msg)
  : msg_(msg)
  {}
  Init_RobotCommand_gripper_state relative(::llm_robot_control::msg::RobotCommand::_relative_type arg)
  {
    msg_.relative = std::move(arg);
    return Init_RobotCommand_gripper_state(msg_);
  }

private:
  ::llm_robot_control::msg::RobotCommand msg_;
};

class Init_RobotCommand_duration
{
public:
  explicit Init_RobotCommand_duration(::llm_robot_control::msg::RobotCommand & msg)
  : msg_(msg)
  {}
  Init_RobotCommand_relative duration(::llm_robot_control::msg::RobotCommand::_duration_type arg)
  {
    msg_.duration = std::move(arg);
    return Init_RobotCommand_relative(msg_);
  }

private:
  ::llm_robot_control::msg::RobotCommand msg_;
};

class Init_RobotCommand_yaw
{
public:
  explicit Init_RobotCommand_yaw(::llm_robot_control::msg::RobotCommand & msg)
  : msg_(msg)
  {}
  Init_RobotCommand_duration yaw(::llm_robot_control::msg::RobotCommand::_yaw_type arg)
  {
    msg_.yaw = std::move(arg);
    return Init_RobotCommand_duration(msg_);
  }

private:
  ::llm_robot_control::msg::RobotCommand msg_;
};

class Init_RobotCommand_pitch
{
public:
  explicit Init_RobotCommand_pitch(::llm_robot_control::msg::RobotCommand & msg)
  : msg_(msg)
  {}
  Init_RobotCommand_yaw pitch(::llm_robot_control::msg::RobotCommand::_pitch_type arg)
  {
    msg_.pitch = std::move(arg);
    return Init_RobotCommand_yaw(msg_);
  }

private:
  ::llm_robot_control::msg::RobotCommand msg_;
};

class Init_RobotCommand_roll
{
public:
  explicit Init_RobotCommand_roll(::llm_robot_control::msg::RobotCommand & msg)
  : msg_(msg)
  {}
  Init_RobotCommand_pitch roll(::llm_robot_control::msg::RobotCommand::_roll_type arg)
  {
    msg_.roll = std::move(arg);
    return Init_RobotCommand_pitch(msg_);
  }

private:
  ::llm_robot_control::msg::RobotCommand msg_;
};

class Init_RobotCommand_z
{
public:
  explicit Init_RobotCommand_z(::llm_robot_control::msg::RobotCommand & msg)
  : msg_(msg)
  {}
  Init_RobotCommand_roll z(::llm_robot_control::msg::RobotCommand::_z_type arg)
  {
    msg_.z = std::move(arg);
    return Init_RobotCommand_roll(msg_);
  }

private:
  ::llm_robot_control::msg::RobotCommand msg_;
};

class Init_RobotCommand_y
{
public:
  explicit Init_RobotCommand_y(::llm_robot_control::msg::RobotCommand & msg)
  : msg_(msg)
  {}
  Init_RobotCommand_z y(::llm_robot_control::msg::RobotCommand::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_RobotCommand_z(msg_);
  }

private:
  ::llm_robot_control::msg::RobotCommand msg_;
};

class Init_RobotCommand_x
{
public:
  explicit Init_RobotCommand_x(::llm_robot_control::msg::RobotCommand & msg)
  : msg_(msg)
  {}
  Init_RobotCommand_y x(::llm_robot_control::msg::RobotCommand::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_RobotCommand_y(msg_);
  }

private:
  ::llm_robot_control::msg::RobotCommand msg_;
};

class Init_RobotCommand_joint_positions
{
public:
  explicit Init_RobotCommand_joint_positions(::llm_robot_control::msg::RobotCommand & msg)
  : msg_(msg)
  {}
  Init_RobotCommand_x joint_positions(::llm_robot_control::msg::RobotCommand::_joint_positions_type arg)
  {
    msg_.joint_positions = std::move(arg);
    return Init_RobotCommand_x(msg_);
  }

private:
  ::llm_robot_control::msg::RobotCommand msg_;
};

class Init_RobotCommand_command_type
{
public:
  Init_RobotCommand_command_type()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RobotCommand_joint_positions command_type(::llm_robot_control::msg::RobotCommand::_command_type_type arg)
  {
    msg_.command_type = std::move(arg);
    return Init_RobotCommand_joint_positions(msg_);
  }

private:
  ::llm_robot_control::msg::RobotCommand msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::llm_robot_control::msg::RobotCommand>()
{
  return llm_robot_control::msg::builder::Init_RobotCommand_command_type();
}

}  // namespace llm_robot_control

#endif  // LLM_ROBOT_CONTROL__MSG__DETAIL__ROBOT_COMMAND__BUILDER_HPP_
