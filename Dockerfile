# Temel İmaj: ROS 2 Humble (Desktop Full - Gazebo ve araçlar dahil)
FROM osrf/ros:humble-desktop-full

# Derleme sırasında etkileşimi kapat (Timezone sorusu sormasın)
ENV DEBIAN_FRONTEND=noninteractive

# Temel araçları ve Python kütüphanelerini yükle
RUN apt-get update && apt-get install -y \
    python3-pip \
    python3-colcon-common-extensions \
    git \
    xterm \
    ros-humble-moveit \
    ros-humble-ros2-control \
    ros-humble-ros2-controllers \
    ros-humble-gazebo-ros2-control \
    && rm -rf /var/lib/apt/lists/*

# Python bağımlılıkları (LLM interface için)
RUN pip3 install requests

# Workspace oluştur
WORKDIR /root/ros2_ws

# Mevcut src klasörünü (bağımlılıkları çözmek için) kopyala
# NOT: Bu sadece build aşaması içindir, development için volume mount kullanacağız.
COPY src ./src

# ROS bağımlılıklarını yükle (rosdep)
RUN apt-get update && rosdep update && \
    rosdep install --from-paths src --ignore-src -r -y

# Entrypoint scriptini kopyala ve yetki ver
COPY entrypoint.sh /entrypoint.sh
RUN chmod +x /entrypoint.sh

# Entrypoint ayarla
ENTRYPOINT ["/entrypoint.sh"]

# Varsayılan komut (Boş bırakıyoruz, compose'dan gelecek)
CMD ["bash"]
