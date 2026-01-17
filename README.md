# Autonomous Obstacle-Avoidance Robot (Arduino)

A working simulation and hardware implementation of an autonomous obstacle-avoidance robot using an Arduino UNO, ultrasonic distance sensing, and an L293D motor driver.

The robot continuously measures distance to nearby objects and dynamically adjusts its movement to avoid collisions without human intervention.

---

## Project Overview

This project demonstrates the fundamental principles of:
- Autonomous navigation
- Sensor-based decision making
- Motor control using a dual H-bridge driver

An ultrasonic sensor (HC-SR04) is used to detect obstacles ahead of the robot. Based on the measured distance, the Arduino controls two DC gear motors through an L293D motor driver to move forward, stop, reverse, or turn.

---

## Hardware Components

- Arduino UNO  
- HC-SR04 Ultrasonic Distance Sensor  
- L293D Dual H-Bridge Motor Driver  
- 2 × DC Gear Motors  
- 2 × Freewheel / Caster Wheels  
- External Motor Power Supply  
- Jumper Wires and Chassis  

---

## Circuit & Power Configuration

- **L293D VCC (Logic Power):** +5V supplied from the Arduino  
- **L293D VEE (Motor Ground):** Connected to system ground  
- **Important:** All grounds (Arduino, motor driver, power supply) must be interconnected to ensure stable operation.

The circuit design follows standard L293D motor driver wiring practices.

---

## How It Works

1. The ultrasonic sensor emits a pulse and measures the echo return time.
2. Distance is calculated from the pulse duration.
3. If the distance is greater than 15 cm:
   - The robot moves forward.
4. If the distance is less than 15 cm:
   - The robot stops.
   - Reverses briefly.
   - Executes a left-turn maneuver to escape the obstacle.
5. The process repeats continuously in real time.

---

## Arduino Pin Configuration

### Ultrasonic Sensor
- **Trig Pin:** D3  
- **Echo Pin:** D2  

### Motor Driver (L293D)
- **Left Motor:**  
  - IN1: D11  
  - IN2: D10  
  - EN1: D9  

- **Right Motor:**  
  - IN3: D5  
  - IN4: D4  
  - EN2: D6  

---

## Code Structure

- Distance measurement using `pulseIn()`
- PWM motor speed control via `analogWrite()`
- Conditional logic for obstacle detection and movement control
- Calibrated delays to ensure stable motor response

The code is designed to be easily modified for tuning speed, distance thresholds, and turning behavior.

---

## Usage Instructions

1. Assemble the robot according to the circuit design.
2. Upload the Arduino sketch to the Arduino UNO.
3. Power the Arduino and motor driver correctly.
4. Place the robot on a flat surface and observe autonomous navigation.

---

## Academic Context

- **Institution:** Veritas University Abuja  
- **Course Requirement:** Group Project  
- **Lecturer:** Calistus C. Chimezie  
- **Submission Format:** 10-minute group presentation  
- **Delivery Time:** 1 week  

---

## Future Improvements

- Servo-mounted ultrasonic sensor for wider field of view  
- Dynamic speed control based on distance  
- Right/left decision logic using multiple sensors  
- Integration with line-following or mapping algorithms  

---

## License

This project is intended for educational and academic use.
