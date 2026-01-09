#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from llm_robot_control.msg import RobotCommand # Senin özel mesaj tipin
import time
import threading

class LLMRobotMaster(Node):
    def __init__(self):
        super().__init__('llm_robot_master')
        
        # Safety Validator'a direkt komut gönderiyoruz
        self.publisher_ = self.create_publisher(RobotCommand, '/robot_command', 10)
        
        # Önceden Tanımlı Pozisyonlar (Joint Radyan)
        self.positions = {
            "home": [0.0, -1.57, 0.0, -1.57, 0.0, 0.0],
            "pick_right": [1.57, -1.57, 1.0, -1.0, -1.57, 0.0],
            "pick_left": [-1.57, -1.57, 1.0, -1.0, -1.57, 0.0],
            "place_center": [0.0, -1.0, 1.57, -2.0, -1.57, 0.0],
            "up": [0.0, -1.57, -0.5, -0.5, 0.0, 0.0]
        }

        self.get_logger().info("🤖 Robot Master Hazır!")
        self.run_console_interface()

    def send_joint_command(self, joint_values, duration=4.0):
        """RobotCommand mesajı oluşturup gönderir"""
        msg = RobotCommand()
        msg.command_type = 'joint_move'
        msg.joint_positions = [float(x) for x in joint_values] # Float dönüşümü
        msg.duration = float(duration)
        msg.relative = False
        msg.gripper_state = 'none' # Opsiyonel
        
        self.get_logger().info(f"📤 Komut Gönderiliyor: {msg.joint_positions}")
        self.publisher_.publish(msg)

    def run_auto_sequence(self):
        """Otomatik görev sırası"""
        self.get_logger().info("🔄 OTO MOD BAŞLATILIYOR...")
        
        # SENARYO LİSTESİ
        sequence = ["home", "pick_right", "up", "place_center", "home"]
        
        for step_name in sequence:
            if step_name in self.positions:
                self.get_logger().info(f"➡️ Adım: {step_name}")
                target_joints = self.positions[step_name]
                
                self.send_joint_command(target_joints)
                
                # Hareketin bitmesini bekle (Basit delay)
                # Motion executor'dan geri bildirim almak daha iyi olurdu ama şimdilik süre yeterli
                time.sleep(6.0) 
            else:
                self.get_logger().warn(f"⚠️ Bilinmeyen pozisyon: {step_name}")
        
        self.get_logger().info("✅ OTO MOD TAMAMLANDI!")

    def _console_loop(self):
        """Kullanıcı input döngüsü"""
        print("\n" + "="*40)
        print("🎮 ROBOT KONTROL PANELİ")
        print("Komutlar: auto, home, pick_right, pick_left, exit")
        print("="*40)
        
        while rclpy.ok():
            try:
                cmd = input("\nKomut > ").strip().lower()
                
                if cmd == 'exit':
                    break
                elif cmd == 'auto':
                    # Auto modunu ayrı thread'de değil, bloklayarak çalıştırıyoruz ki karışmasın
                    self.run_auto_sequence()
                elif cmd in self.positions:
                    self.send_joint_command(self.positions[cmd])
                else:
                    print("❌ Geçersiz komut! Listeden seçin.")
                    
            except Exception as e:
                print(f"Hata: {e}")

    def run_console_interface(self):
        # Input alma işlemini ayrı thread'e koyuyoruz ki ROS spin durmasın
        thread = threading.Thread(target=self._console_loop, daemon=True)
        thread.start()

def main(args=None):
    rclpy.init(args=args)
    node = LLMRobotMaster()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()