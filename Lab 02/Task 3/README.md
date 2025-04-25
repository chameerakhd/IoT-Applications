# 🧪 Lab 02 - Task 3: Onboard Diagnostic Features via I2C

## 📋 Task Overview

This task adds **diagnostic functionality** to the existing dual-Arduino I2C setup by incorporating **heartbeat monitoring** between the two devices:

- 🟥 **Each Arduino has an LED** connected for diagnostics.
- 🔄 The Master and Slave Arduinos exchange **health-status (heartbeat)** messages periodically (every 500ms).
- ✅ If the heartbeat is **received successfully**, the diagnostic LED stays **ON**.
- ❌ If heartbeat **fails or times out**, the LED turns **OFF**, indicating a communication issue.

---

## 🛠️ Features Implemented

| Feature                          | Description                                                                 |
|----------------------------------|-----------------------------------------------------------------------------|
| 🔁 I2C Heartbeat Exchange        | Bi-directional "I'm alive" message every 500ms                             |
| 🟢 Diagnostic LED (Both Boards)  | Lights up when I2C is active and stable                                    |
| 🔴 LED OFF on Comm Failure       | Indicates communication failure or device unavailability                   |
| 🔌 Always Active                 | Works independently of key press / tone generation                        |

---

## 🔧 Hardware Requirements

- 2 × Arduino Uno boards  
- 8 × Push buttons  
- 1 × 7-segment display  
- 1 × Speaker / buzzer  
- 2 × Diagnostic LEDs  
- 2 × 220Ω resistors (for LEDs)  
- Pull-up resistors (4.7kΩ) for I2C  
- Jumper wires, breadboard  
- TinkerCAD / Wokwi simulator

---

## 🔌 Diagnostic LED Setup

| Arduino Board | LED Pin | Purpose           |
|---------------|---------|-------------------|
| Master        | D13     | I2C Status LED     |
| Slave         | D13     | I2C Status LED     |

Both LEDs turn ON when communication is healthy and OFF otherwise.

---

---

## 🧠 Implementation Logic

**Master:**
- Sends heartbeat signal (`0x01`) to Slave every 500ms
- Expects a response from Slave
- If response received: turns LED ON
- If not received within timeout: LED OFF

**Slave:**
- Listens for heartbeat from Master
- Responds immediately upon receiving valid heartbeat
- If heartbeat not received in expected time: LED OFF

---

## 🔄 Communication Protocol

| Master Action              | Slave Response             |
|---------------------------|----------------------------|
| Send `0x01` via I2C       | Receive + Respond `0x02`   |
| Wait 500ms                | Update diagnostic status   |

---

## ✅ Status

✔️ Simulated heartbeat exchange  
✔️ LEDs toggle correctly based on communication  
✔️ Reliable detection of I2C link failure  

---

## ⚠️ Notes

- Ensure **shared GND** between Arduinos  
- Check I2C wiring with **pull-up resistors**  
- Maintain timing accuracy using `millis()` to avoid delay() conflicts with other tasks

---

## 🧪 Next Steps

- Extend diagnostics with serial logs  
- Add retry mechanism or soft-reset on failure  
- Log heartbeat status to EEPROM for persistent tracking




