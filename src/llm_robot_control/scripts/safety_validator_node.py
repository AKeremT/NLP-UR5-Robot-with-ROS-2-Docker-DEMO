#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from llm_robot_control.msg import RobotCommand, SafetyStatus
import math

class SafetyValidatorNode(Node):
    def __init__(self):
        super().__init__('safety_validator')
        
        # Subscriber: LLM'den gelen komutlar
        self.command_sub = self.create_subscription(
            RobotCommand,
            '/robot_command',
            self.validate_command,
            10
        )
        
        # Publisher: Güvenli komutlar
        self.safe_command_pub = self.create_publisher(
            RobotCommand,
            '/safe_robot_command',
            10
        )
        
        # Publisher: Safety status
        self.status_pub = self.create_publisher(
            SafetyStatus,
            '/safety_status',
            10
        )
        
        # Safety parametreleri (UR5 workspace limits - base frame)
        self.workspace_limits = {
            'x_min': -0.85, 'x_max': 0.85,
            'y_min': -0.85, 'y_max': 0.85,
            'z_min': 0.0, 'z_max': 1.0
        }
        
        # Joint limits (radians)
        self.joint_limits = {
            'min': [-2*math.pi, -2*math.pi, -math.pi, -2*math.pi, -2*math.pi, -2*math.pi],
            'max': [2*math.pi, 2*math.pi, math.pi, 2*math.pi, 2*math.pi, 2*math.pi]
        }
        
        # Velocity limits
        self.max_joint_velocity = 3.14  # rad/s
        self.max_cartesian_velocity = 0.5  # m/s
        
        self.get_logger().info('🛡️ Safety Validator Node initialized!')
    
    def validate_command(self, command: RobotCommand):
        """Komutu güvenlik açısından doğrula"""
        
        violations = []
        
        # Joint move kontrolü
        if command.command_type == 'joint_move':
            violations.extend(self.check_joint_limits(command.joint_positions))
            violations.extend(self.check_joint_velocity(command.joint_positions, command.duration))
        
        # Cartesian move kontrolü
        elif command.command_type == 'cartesian_move':
            violations.extend(self.check_workspace_limits(command.x, command.y, command.z))
            violations.extend(self.check_cartesian_velocity(command.x, command.y, command.z, command.duration))
        
        # Sonuç
        status = SafetyStatus()
        status.is_safe = len(violations) == 0
        status.violations = violations
        
        if status.is_safe:
            status.message = '✅ Command is safe'
            self.get_logger().info('✅ Command passed safety checks')
            self.safe_command_pub.publish(command)
        else:
            status.message = f'❌ Safety violations: {", ".join(violations)}'
            self.get_logger().warn(f'❌ Command rejected: {status.message}')
        
        self.status_pub.publish(status)
    
    def check_joint_limits(self, positions):
        """Joint limitleri kontrol et"""
        violations = []
        
        if len(positions) != 6:
            violations.append(f'Invalid joint count: {len(positions)}')
            return violations
        
        for i, pos in enumerate(positions):
            if pos < self.joint_limits['min'][i] or pos > self.joint_limits['max'][i]:
                violations.append(f'Joint {i} out of range: {pos:.2f} rad')
        
        return violations
    
    def check_joint_velocity(self, positions, duration):
        """Joint velocity kontrolü"""
        violations = []
        
        if duration <= 0:
            violations.append('Invalid duration')
            return violations
        
        # Basit velocity hesabı (current pos = 0 varsayımı)
        for i, pos in enumerate(positions):
            velocity = abs(pos) / duration
            if velocity > self.max_joint_velocity:
                violations.append(f'Joint {i} velocity too high: {velocity:.2f} rad/s')
        
        return violations
    
    def check_workspace_limits(self, x, y, z):
        """Workspace limitleri kontrol et"""
        violations = []
        
        if x < self.workspace_limits['x_min'] or x > self.workspace_limits['x_max']:
            violations.append(f'X out of workspace: {x:.3f} m')
        
        if y < self.workspace_limits['y_min'] or y > self.workspace_limits['y_max']:
            violations.append(f'Y out of workspace: {y:.3f} m')
        
        if z < self.workspace_limits['z_min'] or z > self.workspace_limits['z_max']:
            violations.append(f'Z out of workspace: {z:.3f} m')
        
        return violations
    
    def check_cartesian_velocity(self, x, y, z, duration):
        """Kartezyen velocity kontrolü"""
        violations = []
        
        if duration <= 0:
            violations.append('Invalid duration')
            return violations
        
        distance = math.sqrt(x**2 + y**2 + z**2)
        velocity = distance / duration
        
        if velocity > self.max_cartesian_velocity:
            violations.append(f'Cartesian velocity too high: {velocity:.3f} m/s')
        
        return violations

def main(args=None):
    rclpy.init(args=args)
    node = SafetyValidatorNode()
    
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()