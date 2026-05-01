# An IoT-Based Real-Time Health Monitoring System with Integrated Fall Detection and Cloud Analytics

### 📝 Project Overview
This project presents a wearable IoT health monitoring system using an **ESP32** to track vital signs and detect accidental falls. It captures heart rate and SpO2 levels using a MAX30100 sensor and utilizes an MPU6050 IMU for precision fall detection. The system follows a "Local-First" architecture for immediate alerts while logging historical data to the **ThingSpeak** cloud for remote monitoring.

---

### 📄 Conference Paper
You can access the full technical paper, methodology, and experimental results here:
<a href="https://github.com/harshithagandluri/AN-IOT-BASED-REAL-TIME-HEALTH-MONITORING-SYSTEM-WITH-INTEGRATED-FALL-DETECTION-AND-CLOUD-ANALYTICS/blob/main/IEEE_Conference_Template__2_.pdf">**View Official Conference Paper (PDF)**</a>

---

### 🚀 Key Technical Features
* **Dual-Core Task Management:** Core 1 handles high-frequency sensor polling, while Core 0 manages the Wi-Fi stack and cloud synchronization.
* **High Reliability:** Achieves 97.8% accuracy in SpO2 monitoring and 95% effectiveness in fall detection.
* **Global Time Sync:** Implements the **SNTP protocol** for precise clinical-grade timestamping of every health event.
* **Redundant Sensing:** Combines a MAX30100 oximeter with a secondary analog pulse sensor for cross-verification.
* **Immediate Alerts:** Features a 0.96-inch OLED display, tri-color LEDs, and a piezo buzzer for standalone safety.

### 🛠 Hardware Architecture
* **Microcontroller:** ESP32 DevKit V1
* **Physiological Sensors:** MAX30100 Pulse Oximeter, Secondary Analog Pulse Sensor
* **Motion Tracking:** MPU6050 6-Axis Inertial Measurement Unit (IMU)
* **Feedback Modules:** SSD1306 OLED Display (128x64), Tri-color LED array, Piezo Buzzer

### 📊 Experimental Results
* **Accuracy:** Successfully distinguished between actual falls and routine movements like sitting or walking.
* **Cloud Latency:** Maintained an average data transmission latency of 1.5 seconds to the cloud dashboard.
* **Confidence Metric:** A dynamic score based on multi-sensor fusion ensures data integrity before medical feedback.

---
**Author:** Harshitha Gandluri  
**Institution:** Madanapalle Institute of Technology and Science  
**Collaborator:** Mehak Majeed
