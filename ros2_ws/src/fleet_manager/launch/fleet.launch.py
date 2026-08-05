# Copyright 2026 MultiDrone Developer
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
# THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
# THE SOFTWARE.


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
