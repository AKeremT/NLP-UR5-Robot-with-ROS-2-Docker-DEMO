from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription, TimerAction
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare
from launch.substitutions import PathJoinSubstitution

def generate_launch_description():
    
    # 1. Gazebo Server (HEADLESS MOD)
    # gui='false' yaptık ki pencere açılıp çökmesin. Sen sonra açacaksın.
    ur_gazebo_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource([
            PathJoinSubstitution([
                FindPackageShare('ur_simulation_gazebo'),
                'launch',
                'ur_sim_control.launch.py'
            ])
        ]),
        launch_arguments={
            'ur_type': 'ur5',
            'launch_rviz': 'false',
            'gui': 'false',          # <--- KRİTİK AYAR: Pencere açma
            'spawn_joint_controller': 'true'
        }.items()
    )

    # 2. MoveIt Başlatıcı (Gazebo'ya Bağlanacak)
    ur_moveit_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource([
            PathJoinSubstitution([
                FindPackageShare('ur_moveit_config'),
                'launch',
                'ur_moveit.launch.py'
            ])
        ]),
        launch_arguments={
            'ur_type': 'ur5',
            'use_sim_time': 'true',       # Gazebo zamanı
            'use_fake_hardware': 'false', # Gerçek simülasyon
            'launch_rviz': 'true'
        }.items()
    )
    
    # --- ZAMANLAMA BÖLÜMÜ ---
    
    # MoveIt'i Gazebo açıldıktan 15 sn sonra başlat (Garanti olsun)
    delayed_moveit = TimerAction(
        period=15.0,
        actions=[ur_moveit_launch]
    )

    # Safety Validator (MoveIt'ten 5 sn sonra)
    safety_validator = TimerAction(
        period=20.0,
        actions=[
            Node(
                package='llm_robot_control',
                executable='safety_validator_node.py',
                name='safety_validator',
                output='screen',
                parameters=[{'use_sim_time': True}]
            )
        ]
    )
    
    # Motion Executor (25. sn)
    motion_executor = TimerAction(
        period=25.0,
        actions=[
            Node(
                package='llm_robot_control',
                executable='motion_executor_node.py',
                name='motion_executor',
                output='screen',
                parameters=[{'use_sim_time': True}]
            )
        ]
    )
    
    # LLM Interface (30. sn)
    llm_interface = TimerAction(
        period=30.0,
        actions=[
            Node(
                package='llm_robot_control',
                executable='llm_interface_node.py',
                name='llm_interface',
                output='screen',
                prefix='xterm -e',
                parameters=[{'use_sim_time': True}]
            )
        ]
    )
    
    return LaunchDescription([
        ur_gazebo_launch,
        delayed_moveit,
        safety_validator,
        motion_executor,
        llm_interface
    ])