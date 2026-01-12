**Automatic Trash Bin System Using Arduino Uno**
**Project Overview**

This project presents an Automatic Trash Bin System developed as a Final Project (Tugas Akhir) using Arduino Uno. The system is designed to improve hygiene and convenience by automatically opening and closing the trash bin lid based on object detection. In addition, the system monitors the trash level and provides an alert when the bin is full.

Although this is a physical embedded system project, all source code, system design, and documentation are managed and published on GitHub as part of academic reporting and professional portfolio development.


**Objectives**

-Design an automatic trash bin using an embedded system
-Implement distance-based object detection using ultrasonic sensors
-Control a servo motor for automatic lid operation
-Provide an alert mechanism when the trash bin is full
-Document the system in a structured and reproducible manner


**System Working Principle**

-Ultrasonic Sensor 1 detects the presence of an object (e.g., hand) in front of the trash bin.
-When the detected distance is below a predefined threshold, the Arduino Uno activates the servo motor to open the lid.
-After a short delay, the lid automatically closes.
-Ultrasonic Sensor 2 measures the trash level inside the bin.
-If the measured distance indicates a full condition, a buzzer is activated as an alert.

**Hardware Components**

Arduino Uno
-Ultrasonic Sensor HC-SR04 (2 units)
-Servo Motor
-Buzzer
-Jumper Wires
-External Power Supply


**Software & Tools**

Arduino IDE
Arduino Servo Library
GitHub (version control & documentation)
