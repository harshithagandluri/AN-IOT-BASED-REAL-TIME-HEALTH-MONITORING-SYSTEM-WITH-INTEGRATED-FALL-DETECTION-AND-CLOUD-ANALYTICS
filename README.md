# An IoT-Based Real-Time Health Monitoring System with Integrated Fall Detection and Cloud Analytics

### 📝 Project Overview
This project presents a wearable IoT health monitoring system using an **ESP32** to track vital signs and detect accidental falls. It captures heart rate and SpO2 levels using a MAX30100 sensor and utilizes an MPU6050 IMU for precision fall detection.

---

### 📄 Conference Paper
You can access the full technical paper, methodology, and experimental results here:
<a href="https://github.com/harshithagandluri/AN-IOT-BASED-REAL-TIME-HEALTH-MONITORING-SYSTEM-WITH-INTEGRATED-FALL-DETECTION-AND-CLOUD-ANALYTICS/blob/main/IEEE_Conference_Template__2_.pdf">**View Official Conference Paper (PDF)**</a>

---

### 📸 Project Visuals
Below is the hardware implementation of the project:

<img src="https://github.com/harshithagandluri/AN-IOT-BASED-REAL-TIME-HEALTH-MONITORING-SYSTEM-WITH-INTEGRATED-FALL-DETECTION-AND-CLOUD-ANALYTICS/blob/main/MajorProject/1.jpeg?raw=true" width="500" alt="Project Hardware Setup">

---

### 🚀 Key Technical Features
* **Dual-Core Task Management:** Core 1 handles high-frequency sensor polling, while Core 0 manages the Wi-Fi stack and cloud synchronization.
* **High Reliability:** Achieves 97.8% accuracy in SpO2 monitoring and 95% effectiveness in fall detection.
* **Global Time Sync:** Implements the **SNTP protocol** for precise clinical-grade timestamping.
* **Immediate Alerts:** Features a 0.96-inch OLED display, tri-color LEDs, and a piezo buzzer for standalone safety.

### 🛠 Hardware Architecture
* **Microcontroller:** ESP32 DevKit V1
* **Physiological Sensors:** MAX30100 Pulse Oximeter, Secondary Analog Pulse Sensor
* **Motion Tracking:** MPU6050 6-Axis IMU
* **Feedback Modules:** SSD1306 OLED Display, Tri-color LED array, Piezo Buzzer

---
**Author:** Harshitha Gandluri  
**Institution:** Madanapalle Institute of Technology and Science  
**Collaborator:** Mehak Majeed
