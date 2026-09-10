# Natural Disaster Detection & Alert System

An Arduino-based IoT prototype designed to monitor environmental conditions using sensors and provide real-time alerts when abnormal conditions are detected.

## 📌 Project Overview

The Natural Disaster Detection & Alert System uses an Arduino microcontroller along with ultrasonic and motion sensors to monitor environmental conditions.

Sensor readings are processed in real time using threshold-based logic. When an abnormal condition is detected, the system activates an LED and buzzer to provide an immediate alert.

The project demonstrates the fundamentals of:

- Embedded systems
- IoT-based monitoring
- Real-time sensor processing
- Threshold-based decision making
- Alert systems
- Arduino programming

## 🚀 Features

- Real-time sensor monitoring
- Ultrasonic distance measurement
- Motion detection using PIR sensor
- Threshold-based alert logic
- LED visual indication
- Buzzer-based audio alert
- Serial Monitor data output

## 🛠️ Technologies Used

- Arduino Uno
- Embedded C / Arduino C++
- HC-SR04 Ultrasonic Sensor
- PIR Motion Sensor
- Buzzer
- LED
- Arduino IDE

## 🔧 Hardware Components

| Component | Quantity |
|---|---:|
| Arduino Uno | 1 |
| HC-SR04 Ultrasonic Sensor | 1 |
| PIR Motion Sensor | 1 |
| Buzzer | 1 |
| LED | 1 |
| Resistor | 1 |
| Breadboard | 1 |
| Jumper Wires | As required |

## 🔌 Pin Configuration

### HC-SR04 Ultrasonic Sensor

| Sensor Pin | Arduino Pin |
|---|---|
| VCC | 5V |
| GND | GND |
| TRIG | D9 |
| ECHO | D10 |

### PIR Sensor

| Sensor Pin | Arduino Pin |
|---|---|
| VCC | 5V |
| GND | GND |
| OUT | D7 |

### Alert Components

| Component | Arduino Pin |
|---|---|
| Buzzer | D6 |
| LED | D5 |

## ⚙️ Working Principle

1. The Arduino initializes the connected sensors and alert components.
2. The HC-SR04 sensor measures the distance of an object or detected surface.
3. The PIR sensor monitors for motion.
4. Sensor readings are continuously processed by the Arduino.
5. A predefined threshold is used to identify an abnormal condition.
6. When the required alert conditions are satisfied, the LED and buzzer are activated.
7. Sensor readings and system status are displayed through the Serial Monitor.

## 🔄 System Workflow

```text
Sensors
   ↓
Arduino Uno
   ↓
Real-Time Data Processing
   ↓
Threshold Evaluation
   ↓
Abnormal Condition?
   ↓
 ┌───────────────┐
 │               │
 YES             NO
 │               │
 ↓               ↓
LED + Buzzer    Continue
Alert           Monitoring
