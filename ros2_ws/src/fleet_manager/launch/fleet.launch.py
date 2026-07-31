"""
fleet.launch.py — Launch the fleet coordinator node.

Usage:
    ros2 launch fleet_manager fleet.launch.py
    ros2 launch fleet_manager fleet.launch.py expected_num_vehicles:=5
"""

from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node


def generate_launch_description():
    return LaunchDescription([
        DeclareLaunchArgument(
            'expected_num_vehicles', default_value='3',
            description='Number of vehicles expected in the fleet',
        ),
        DeclareLaunchArgument(
            'default_formation', default_value='line',
            description='Default formation pattern',
        ),
        DeclareLaunchArgument(
            'default_spacing_m', default_value='10.0',
            description='Default inter-vehicle spacing',
        ),

        Node(
            package='fleet_manager',
            executable='fleet_coordinator',
            name='fleet_coordinator',
            parameters=[{
                'expected_num_vehicles':
                    LaunchConfiguration('expected_num_vehicles'),
                'vehicle_timeout_s': 5.0,
                'status_publish_rate_hz': 5.0,
                'formation_update_rate_hz': 10.0,
                'default_formation':
                    LaunchConfiguration('default_formation'),
                'default_spacing_m':
                    LaunchConfiguration('default_spacing_m'),
            }],
            output='screen',
        ),
    ])
