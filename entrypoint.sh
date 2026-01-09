#!/bin/bash
set -e

# ROS 2 ortamını yükle
source /opt/ros/humble/setup.bash

# Eğer workspace derlenmişse, overlay'i de yükle
if [ -f "/root/ros2_ws/install/setup.bash" ]; then
    source /root/ros2_ws/install/setup.bash
fi

# Komutu çalıştır
exec "$@"
