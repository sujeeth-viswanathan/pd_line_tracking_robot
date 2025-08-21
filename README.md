# pd_line_tracking_robot.ino

# PD Line Tracking Robot (Arduino + OSOYOO V2.1)

This project implements a closed-loop PD controller for line-following using an Arduino-based OSOYOO V2.1 robot car. The robot uses a 5-channel IR sensor array to detect a black line and dynamically adjusts motor speeds based on proportional and derivative feedback.

## 🔧 Hardware Used
- OSOYOO V2.1 Arduino Robot Car Kit
- Arduino Uno
- L298N Motor Driver
- 5x IR Sensors
- 2x DC Motors (differential drive)

## ⚙️ Features
- Real-time line-following using 5 IR sensors
- PD control loop for smooth turns and fast recovery
- Stable lap tracking with zero off-track events at PWM 160
- Modular code: easy to debug, extend, and modify

## 📊 Performance
| Metric            | Value         |
|------------------|---------------|
| Lap Time         | 15.0 seconds  |
| Controller Type  | PD (Kp = 25, Kd = 15) |
| Max Speed (PWM)  | 160           |
| Off-Track Events | 0             |

## 🧠 Control Logic
The robot computes a line position error from weighted sensor readings and applies a PD formula to generate correction values that adjust the left and right motor speeds dynamically.

## 📽️ Demo
*A demo video is recommended here*

## 📎 License

