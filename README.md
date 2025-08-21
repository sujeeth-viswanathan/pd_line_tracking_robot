# 🚗 PD Line Tracking Robot

A closed-loop PD (Proportional-Derivative) controller-based line-following robot built using the OSOYOO V2.1 Arduino platform. This robot detects and follows a black line using a 5-IR sensor array, adjusting motor speeds in real-time for accurate and stable path tracking.

---

## 👨‍💻 Developed by
**Sujeeth Viswanathan**  
License: [Apache 2.0](LICENSE)

---

## 📦 Hardware Used

| Component                 | Description                                  |
|--------------------------|----------------------------------------------|
| Arduino Uno              | Main microcontroller                         |
| OSOYOO V2.1 Robot Chassis| Robot platform with motor driver (L298N)     |
| L298N Motor Driver       | Dual H-Bridge motor controller               |
| 5x IR Sensors            | For black-line detection                     |
| 2x DC Motors             | Differential drive                           |
| Power Supply             | 2x 18650 or 9V battery pack                  |

---

## 🚀 Features

- Real-time black line detection using 5 IR sensors
- PD control loop for dynamic motor speed adjustment
- Smooth, accurate turns even at higher speeds
- Stop condition detection (e.g. full black line)
- Modular code structure (easy to tune & extend)
- Visual debugging via Serial Monitor

---
## visuals
## 📷 Robot Photo
![Robot Photo](images/osoyoo_car.jpg)

## 🔌 Wiring Diagram
![Wiring Diagram](images/ossoyoo_car_2.jpg)

## 🧠 Control Logic Overview

### PD Control Formula:

correction = Kp * error + Kd * (error - lastError)

- **Kp = 25.0**, **Kd = 15.0**, **Ki = 0.0**
- Sensor weights: `[-200, -100, 0, +100, +200]`
- The correction is applied to the left and right motors to steer the robot toward the center of the line.

---

## ⚙️ Setup Instructions

### 1. Wiring Guide
- IR Sensors → A0 to A4
- Motor Direction Pins:
  - Left: D7 (IN3), D8 (IN4)
  - Right: D12 (IN1), D11 (IN2)
- Motor Speed (PWM):
  - Left: D6 (ENB)
  - Right: D9 (ENA)

### 2. Arduino IDE Setup
- Open `pd_line_tracking_robot.ino`
- Board: **Arduino Uno**
- Baud rate: **9600**
- Upload code, then open Serial Monitor for debug output

---

## 🛠️ Tuning Tips

- Adjust `BASE_SPEED`, `Kp`, `Kd` values in code to adapt for:
  - Different floor reflectivity
  - Track size or turns
  - Motor calibration

- Use Serial Monitor output to read sensor values (`e.g. "00100"`, `"01100"`, etc.) for live debugging.

---

## 📊 Performance Summary

| Metric             | Value             |
|--------------------|------------------|
| Track Type         | Circular loop    |
| Lap Time           | 15 seconds       |
| Controller         | PD               |
| Max PWM Speed      | 160              |
| Off-track Events   | 0                |
| Behavior           | Smooth, stable   |

---

## 📚 References & Credits

- [OSOYOO V2.1 Car Docs](https://osoyoo.com/?p=33129)
- [PID Control - Arduino](https://www.youtube.com/watch?v=0vqWyramGy8)
- [Line Follower Robot Tutorial](https://www.electronicwings.com/nodemcu/line-follower-robot-using-ir-sensor)

---

## 📝 License

This project is licensed under the **Apache 2.0 License**. See the [LICENSE](LICENSE) file for full details.
