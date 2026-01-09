# 🤖 Natural Language Controlled UR5 Robot with ROS 2 & Docker

![ROS 2 Humble](https://img.shields.io/badge/ROS_2-Humble-blue?logo=ros&logoColor=white)
![Docker](https://img.shields.io/badge/Docker-Containerized-2496ED?logo=docker&logoColor=white)
![Python](https://img.shields.io/badge/Python-3.10-yellow?logo=python&logoColor=white)
![Platform](https://img.shields.io/badge/Platform-WSL2_/_Linux-lightgrey)

**Control a UR5 Robotic Arm using plain English commands via a local Large Language Model.**

This project integrates **ROS 2 Humble**, **Gazebo** (Physics Simulation), and **MoveIt 2** (Motion Planning) with a local LLM (running via **LM Studio**). The entire stack is containerized using **Docker**, making it easy to run on Windows (WSL 2) or Linux without complex local environment setups.

---

## 🚀 Features

* **🗣️ Natural Language Interface:** Control the robot with commands like *"Move forward 20cm"* or *"Rotate base 90 degrees"*.
* **🐳 Fully Dockerized:** One-command setup using `docker compose`. No need to install ROS 2 locally.
* **🦾 Full Simulation:** Uses `ur_simulation_gazebo` for realistic physics and `MoveIt 2` for collision-free path planning.
* **🖥️ Cross-Platform GUI:** Supports GUI forwarding to Windows via **VcXsrv** (X11 Forwarding).
* **🧠 Local Privacy:** Uses a local LLM server; no data is sent to the cloud.

---

## 🛠️ System Architecture

1.  **User Input:** You type a command in the Xterm window.
2.  **LLM Processing:** The Python node sends the prompt to your local **LM Studio** server (e.g., running Qwen 2.5 or Llama 3).
3.  **Command Translation:** The LLM converts the text into structured motion parameters.
4.  **Motion Execution:** The `motion_executor` node commands MoveIt 2 to plan a path.
5.  **Visualization:** The robot moves synchronously in **RViz** (Visualization) and **Gazebo** (Physics).

---

## 📋 Prerequisites

### 1. Docker
* **Windows:** Install [Docker Desktop](https://www.docker.com/products/docker-desktop/).
    * *Important:* Go to Settings > Resources > WSL Integration > Enable for your distro.
* **Linux:** Install Docker Engine and Docker Compose.

### 2. LM Studio (The Brain)
* Download [LM Studio](https://lmstudio.ai/).
* Download a model capable of instruction following (Recommended: `Llama 3.2 3B Instruct`).

### 3. VcXsrv (For Windows Users Only)
Since Docker runs in a Linux container, we need an X Server to display the GUI (Gazebo/RViz) on Windows.
* Download [VcXsrv Windows X Server](https://sourceforge.net/projects/vcxsrv/).

---

## ⚙️ Installation & Setup

### 1. Clone the Repository
```bash
git clone [https://github.com/AKeremT/Natural-Language-Controlled-UR5-Robot-with-ROS-2-Docker.git](https://github.com/AKeremT/Natural-Language-Controlled-UR5-Robot-with-ROS-2-Docker.git)
cd Natural-Language-Controlled-UR5-Robot-with-ROS-2-Docker# Natural-Language-Controlled-UR5-Robot-with-ROS-2-Docker
```
### 2. Network Configuration (Crucial!)
Docker needs to know where to send the display output. We use a `.env` file for this configuration to keep it dynamic.

1.  Create a `.env` file from the example:
    ```bash
    cp .env.example .env
    ```
2.  Find your computer's IP address:
    * **Windows:** Open CMD, type `ipconfig`. Copy the **IPv4 Address** of your **Wi-Fi** or **Ethernet** adapter. (Do NOT use the WSL adapter IP).
    * **Linux:** Usually you can skip this or use `localhost`.
3.  Edit the `.env` file:
    ```bash
    nano .env
    ```
    Paste your IP address:
    ```ini
    DISPLAY_IP=192.168.1.35  <-- Replace with YOUR actual IP
    ```

### 3. Configure LM Studio (The Brain)
1.  Open LM Studio and go to the **Local Server** tab (`<->` icon on the left).
2.  Select your downloaded model at the top.
3.  **Server Settings (Right Panel):**
    * **Port:** `1234`
    * ✅ **Enable CORS** (Cross-Origin Resource Sharing) -> *Must be ON*.
4.  Click **"Start Server"**.

### 4. Configure VcXsrv (Windows Users)
Launch **XLaunch** and use these exact settings to avoid connection errors:

1.  **Display settings:** Multiple windows -> *Next*
2.  **Client startup:** Start no client -> *Next*
3.  **Extra settings:**
    * ✅ **Clipboard**
    * ✅ **Disable access control** (Critical! If unchecked, Docker cannot connect).
4.  **Finish**.

---

## 🏃‍♂️ Usage

Run the entire system with a single command:

```bash
docker compose up
```