#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from rclpy.action import ActionClient
from control_msgs.action import FollowJointTrajectory
from trajectory_msgs.msg import JointTrajectoryPoint
import requests
import json
from builtin_interfaces.msg import Duration
from llm_robot_control.msg import RobotCommand

class LLMRobotInterface(Node):
    def __init__(self):
        super().__init__('llm_robot_interface')
        
        # Publisher: Robot commands
        self.command_pub = self.create_publisher(
            RobotCommand,
            '/robot_command',
            10
        )
        
        # LM Studio configuration
        self.lm_studio_url = "http://172.28.96.1:1234/v1/chat/completions"
        
        # Joint names
        self.joint_names = [
            'shoulder_pan_joint',
            'shoulder_lift_joint', 
            'elbow_joint',
            'wrist_1_joint',
            'wrist_2_joint',
            'wrist_3_joint'
        ]
        
        self.get_logger().info('🤖 LLM Robot Interface initialized!')
        
    def create_system_prompt(self):
        """Robot control için system prompt"""
        return """You are a robot control assistant. Your job is to convert natural language commands into robot joint positions.

The UR5 robot has 6 joints with these ranges (in radians):
- shoulder_pan_joint: base rotation (left/right)
- shoulder_lift_joint: shoulder up/down
- elbow_joint: elbow bend
- wrist_1_joint, wrist_2_joint, wrist_3_joint: wrist movements

IMPORTANT: Respond ONLY with a valid JSON object. NO other text!

Format: {"positions": [j1, j2, j3, j4, j5, j6], "duration": seconds}

EXAMPLES (learn from these):

1. "move to home position"
→ {"positions": [0.0, -1.57, 1.57, -1.57, -1.57, 0.0], "duration": 3}

2. "rotate base 90 degrees clockwise" (clockwise is positive)
→ {"positions": [1.57, -1.57, 1.57, -1.57, -1.57, 0.0], "duration": 2}

3. "rotate base 90 degrees counterclockwise"
→ {"positions": [-1.57, -1.57, 1.57, -1.57, -1.57, 0.0], "duration": 2}

4. "lift arm up" (shoulder lift becomes more negative to go up)
→ {"positions": [0.0, -2.2, 1.57, -1.57, -1.57, 0.0], "duration": 3}

5. "lower arm down" (shoulder lift becomes less negative)
→ {"positions": [0.0, -0.9, 1.57, -1.57, -1.57, 0.0], "duration": 3}

6. "extend arm forward" (straighten elbow)
→ {"positions": [0.0, -1.57, 0.5, -1.57, -1.57, 0.0], "duration": 3}

7. "bend elbow"
→ {"positions": [0.0, -1.57, 2.5, -1.57, -1.57, 0.0], "duration": 3}

Now process the user's command following these patterns. Output ONLY the JSON, nothing else."""

    def query_llm(self, user_command):
        """LLM'e komut gönder ve JSON yanıt al"""
        payload = {
            "model": "llama-3.2-3b-instruct",
            "messages": [
                {"role": "system", "content": self.create_system_prompt()},
                {"role": "user", "content": user_command}
            ],
            "temperature": 0.3,
            "max_tokens": 150
        }
        
        try:
            self.get_logger().info(f'🔄 LLM sorgulanıyor: "{user_command}"')
            response = requests.post(self.lm_studio_url, json=payload, timeout=10)
            
            if response.status_code == 200:
                result = response.json()
                llm_response = result['choices'][0]['message']['content'].strip()
                self.get_logger().info(f'📝 LLM cevabı: {llm_response}')
                
                # JSON parse et
                llm_response = llm_response.replace('```json', '').replace('```', '').strip()
                command_data = json.loads(llm_response)
                
                return command_data
            else:
                self.get_logger().error(f'❌ LLM hatası: {response.status_code}')
                return None
                
        except json.JSONDecodeError as e:
            self.get_logger().error(f'❌ JSON parse hatası: {e}')
            self.get_logger().error(f'LLM yanıtı: {llm_response}')
            return None
        except Exception as e:
            self.get_logger().error(f'❌ Beklenmeyen hata: {e}')
            return None
    
    def send_robot_command(self, positions, duration):
        """Robota hareket komutu gönder"""
        
        # RobotCommand mesajı oluştur
        cmd = RobotCommand()
        cmd.command_type = 'joint_move'
        cmd.joint_positions = positions
        cmd.duration = float(duration)
        cmd.relative = False
        cmd.gripper_state = 'none'
        
        self.get_logger().info(f'📤 Publishing command: {positions}')
        self.command_pub.publish(cmd)
        
        return True
    
    def process_natural_language_command(self, command):
        """Doğal dil komutunu işle"""
        
        command_data = self.query_llm(command)
        
        if command_data is None:
            self.get_logger().error('❌ LLM komutu parse edilemedi!')
            return False
        
        positions = command_data.get('positions', [])
        duration = command_data.get('duration', 3)
        
        if len(positions) != 6:
            self.get_logger().error(f'❌ Hatalı joint sayısı: {len(positions)}')
            return False
        
        return self.send_robot_command(positions, duration)

def main(args=None):
    rclpy.init(args=args)
    node = LLMRobotInterface()
    
    print("\n" + "="*50)
    print("🤖 LLM Robot Control Interface")
    print("="*50)
    print("\nÖrnek komutlar:")
    print("  - move to home position")
    print("  - rotate base 90 degrees clockwise")
    print("  - lift arm up")
    print("\nKomut girin (Çıkmak için 'quit'):\n")
    
    try:
        while rclpy.ok():
            command = input("👤 Komut: ").strip()
            
            if command.lower() in ['quit', 'exit', 'q']:
                break
            
            if command:
                node.process_natural_language_command(command)
                print()
            
    except KeyboardInterrupt:
        print("\n👋 Çıkılıyor...")
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()