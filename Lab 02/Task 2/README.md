# 🧪 Lab 02 - Task 2: I2C Communication Between Two Arduino Boards

## 📋 Task Overview

In this task, we **modified the serial communication setup** from Task 1 by replacing the **UART (Serial)** interface with **I2C (Inter-Integrated Circuit)** communication between the two Arduino Uno boards.

- 🟦 **Master (Arduino #1):** Reads keyboard input and displays key number on the 7-segment display. Sends data via I2C.
- 🟩 **Slave (Arduino #2):** Receives data through I2C and generates the corresponding tone via speaker.

---

## 🔧 Components Used

- 2 × Arduino Uno boards  
- 8 × Push buttons  
- 1 × 7-segment display  
- 1 × Speaker / buzzer  
- Pull-up resistors (4.7kΩ) for I2C lines (SDA, SCL)  
- Jumper wires, breadboards  
- TinkerCAD / Wokwi simulator (preferred)

---

## 🔌 I2C Setup

| Arduino #1 (Master) | Arduino #2 (Slave) |
|---------------------|--------------------|
| A4 (SDA)            | A4 (SDA)           |
| A5 (SCL)            | A5 (SCL)           |
| GND                 | GND (common ground)|
|                     | I2C address: `0x08`|

---

## 🧠 Communication Flow

- Master detects key press and sends either key number or frequency value to the slave.
- Slave listens using `Wire.onReceive()` and generates tone on the speaker.
- If multiple keys are pressed, Master sends updated info every 20ms or when key state changes.

---

## 🧪 Key Learning Outcomes

- Implementing I2C communication between two Arduino Uno boards  
- Understanding Master-Slave architecture  
- Sending and receiving data using the `Wire` library  
- Designing reliable modular systems using multiple MCUs

---

## ✅ Status

✔️ I2C connection tested in Wokwi simulator  
✔️ Key data successfully sent from Master to Slave  
✔️ Speaker tone generation triggered correctly based on input  

---

## ⚠️ Notes

> - Always ensure both Arduinos share a **common GND**.  
> - Use **pull-up resistors** (typically 4.7kΩ) for SDA and SCL lines.  
> - I2C is ideal for short-range communication with fewer wires than UART.

---



