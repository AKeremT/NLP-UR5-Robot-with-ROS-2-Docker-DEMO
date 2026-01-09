#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from rclpy.action import ActionClient
from llm_robot_control.msg import RobotCommand

# MoveIt Mesajları
from moveit_msgs.action import MoveGroup, ExecuteTrajectory
from moveit_msgs.msg import Constraints, JointConstraint, PositionConstraint, OrientationConstraint, RobotTrajectory
from shape_msgs.msg import SolidPrimitive
from geometry_msgs.msg import Pose, Quaternion

import threading
import math
import time

class MotionExecutorNode(Node):
    def __init__(self):
        super().__init__('motion_executor')
        
        # Subscriber
        self.safe_command_sub = self.create_subscription(
            RobotCommand,
            '/safe_robot_command',
            self.execute_command,
            10
        )
        
        # 1. Action Client: Planlama için (MoveGroup)
        self._move_group_client = ActionClient(self, MoveGroup, 'move_action')
        
        # 2. Action Client: Yürütme için (ExecuteTrajectory)
        self._execute_client = ActionClient(self, ExecuteTrajectory, 'execute_trajectory')
        
        # Robot Ayarları
        self.group_name = "ur_manipulator"
        self.base_frame = "base_link"
        self.end_effector = "tool0"
        
        self.joint_names = [
            'shoulder_pan_joint', 'shoulder_lift_joint', 'elbow_joint',
            'wrist_1_joint', 'wrist_2_joint', 'wrist_3_joint'
        ]
        
        self.get_logger().info('🎯 Motion Executor Node initialized!')
        
        # Serverları bekle
        threading.Thread(target=self._wait_for_servers, daemon=True).start()
    
    def _wait_for_servers(self):
        """Action serverları bekle"""
        self.get_logger().info('⏳ Waiting for MoveIt action servers...')
        
        if not self._move_group_client.wait_for_server(timeout_sec=20.0):
            self.get_logger().error('❌ MoveGroup server not found!')
            return
            
        if not self._execute_client.wait_for_server(timeout_sec=20.0):
            self.get_logger().error('❌ ExecuteTrajectory server not found!')
            return
            
        self.get_logger().info('✅ All MoveIt servers connected!')
    
    def execute_command(self, command: RobotCommand):
        self.get_logger().info(f'🎯 Received command: {command.command_type}')
        thread = threading.Thread(target=self._execute_sequence, args=(command,), daemon=True)
        thread.start()

    def _execute_sequence(self, command):
        """Planla -> İzle -> Yürüt Döngüsü"""
        
        # --- ADIM 1: PLANLAMA (Sadece Hayalet) ---
        self.get_logger().info('Build Planning...')
        goal_msg = MoveGroup.Goal()
        goal_msg.request.group_name = self.group_name
        goal_msg.request.num_planning_attempts = 10
        goal_msg.request.allowed_planning_time = 5.0
        
        # Hız Ayarları (Yavaş ve güvenli)
        goal_msg.request.max_velocity_scaling_factor = 0.1
        goal_msg.request.max_acceleration_scaling_factor = 0.1
        
        # ÖNEMLİ: Sadece planla, hareket etme!
        goal_msg.planning_options.plan_only = True 
        
        # Constraintleri oluştur
        try:
            constraints = Constraints()
            if command.command_type == 'joint_move':
                constraints = self.create_joint_constraints(command.joint_positions)
            elif command.command_type == 'cartesian_move':
                target_quat = self.euler_to_quaternion(command.roll, command.pitch, command.yaw)
                constraints.position_constraints.append(self.create_position_constraints(command.x, command.y, command.z))
                constraints.orientation_constraints.append(self.create_orientation_constraints(target_quat))
            
            goal_msg.request.goal_constraints.append(constraints)
        except Exception as e:
            self.get_logger().error(f'❌ Constraint error: {e}')
            return

        # Planı Gönder
        self.get_logger().info('🤔 Calculating path (showing ghost)...')
        send_future = self._move_group_client.send_goal_async(goal_msg)
        while not send_future.done(): time.sleep(0.1)
        plan_handle = send_future.result()
        
        if not plan_handle.accepted:
            self.get_logger().error('❌ Planning rejected!')
            return
            
        res_future = plan_handle.get_result_async()
        while not res_future.done(): time.sleep(0.1)
        plan_result = res_future.result().result
        
        # Plan Başarılı mı?
        if plan_result.error_code.val != 1: # 1 = SUCCESS
            self.get_logger().error(f'❌ Planning failed code: {plan_result.error_code.val}')
            return
            
        trajectory = plan_result.planned_trajectory
        self.get_logger().info('✨ Plan found! Visualization active on RViz.')

        # --- ADIM 2: BEKLEME (Hayaleti İzle) ---
        wait_time = 4.0 # Saniye
        self.get_logger().info(f'👀 Waiting {wait_time}s for visual check...')
        time.sleep(wait_time)
        
        # --- ADIM 3: YÜRÜTME (Gerçek Robot) ---
        self.get_logger().info('🚀 Executing the plan on real robot...')
        
        exec_goal = ExecuteTrajectory.Goal()
        exec_goal.trajectory = trajectory
        
        exec_future = self._execute_client.send_goal_async(exec_goal)
        while not exec_future.done(): time.sleep(0.1)
        exec_handle = exec_future.result()
        
        if not exec_handle.accepted:
            self.get_logger().error('❌ Execution rejected!')
            return
            
        exec_res_future = exec_handle.get_result_async()
        while not exec_res_future.done(): time.sleep(0.1)
        
        final_res = exec_res_future.result().result
        if final_res.error_code.val == 1:
            self.get_logger().info('✅ Motion completed successfully!')
        else:
            self.get_logger().error('❌ Execution failed during motion!')

    # --- Yardımcı Fonksiyonlar (Aynı) ---
    def create_joint_constraints(self, positions):
        constraints = Constraints()
        for i, pos in enumerate(positions):
            jc = JointConstraint()
            jc.joint_name = self.joint_names[i]
            jc.position = float(pos)
            jc.tolerance_above = 0.01
            jc.tolerance_below = 0.01
            jc.weight = 1.0
            constraints.joint_constraints.append(jc)
        return constraints

    def create_position_constraints(self, x, y, z):
        pc = PositionConstraint()
        pc.header.frame_id = self.base_frame
        pc.link_name = self.end_effector
        pc.weight = 1.0
        box = SolidPrimitive()
        box.type = SolidPrimitive.BOX
        box.dimensions = [0.005, 0.005, 0.005]
        pc.constraint_region.primitives.append(box)
        target_pose = Pose()
        target_pose.position.x = float(x)
        target_pose.position.y = float(y)
        target_pose.position.z = float(z)
        target_pose.orientation.w = 1.0 
        pc.constraint_region.primitive_poses.append(target_pose)
        return pc

    def create_orientation_constraints(self, quaternion):
        oc = OrientationConstraint()
        oc.header.frame_id = self.base_frame
        oc.link_name = self.end_effector
        oc.orientation = quaternion
        oc.absolute_x_axis_tolerance = 0.1
        oc.absolute_y_axis_tolerance = 0.1
        oc.absolute_z_axis_tolerance = 0.1
        oc.weight = 1.0
        return oc

    def euler_to_quaternion(self, roll, pitch, yaw):
        qx = math.sin(roll/2) * math.cos(pitch/2) * math.cos(yaw/2) - math.cos(roll/2) * math.sin(pitch/2) * math.sin(yaw/2)
        qy = math.cos(roll/2) * math.sin(pitch/2) * math.cos(yaw/2) + math.sin(roll/2) * math.cos(pitch/2) * math.sin(yaw/2)
        qz = math.cos(roll/2) * math.cos(pitch/2) * math.sin(yaw/2) - math.sin(roll/2) * math.sin(pitch/2) * math.cos(yaw/2)
        qw = math.cos(roll/2) * math.cos(pitch/2) * math.cos(yaw/2) + math.sin(roll/2) * math.sin(pitch/2) * math.sin(yaw/2)
        return Quaternion(x=qx, y=qy, z=qz, w=qw)

def main(args=None):
    rclpy.init(args=args)
    node = MotionExecutorNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()