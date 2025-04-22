# 🧪 Lab 02 - Task 1: Serial Communication Between Two Arduino Boards

## 📋 Task Overview

In this lab, we extended the tone generator project from **Lab 01** by **distributing the workload between two Arduino Uno boards** and enabling them to communicate over a **UART serial connection**.

- 🔹 **Board 1:** Handles the **keyboard inputs** and **7-segment display**.
- 🔹 **Board 2:** Handles the **tone generation (speaker output)**.

The two boards communicate using a **Serial (UART)** interface. When a key is pressed on Board 1, it sends the corresponding frequency or key ID over serial to Board 2, which then generates the appropriate tone.

---

## 🔧 Components Used

- 2 × Arduino Uno boards  
- 8 × Push buttons  
- 1 × 7-segment display  
- 1 × Speaker or buzzer  
- Resistors (for buttons and current-limiting)  
- Jumper wires, breadboards  
- Serial UART TX/RX wiring between boards  
- Optional: TinkerCAD or Wokwi for simulation

---

## 🔌 Circuit Split

### 🟦 Arduino Uno #1 (Input + Display)
- Reads 8 push buttons.
- Displays the key number on the 7-segment display.
- Sends key information via **Serial (UART)** to Board #2.

### 🟩 Arduino Uno #2 (Sound Generator)
- Receives serial input.
- Generates tones on speaker based on received frequency or key ID.

---

## 🔁 Communication Protocol

- **Baud Rate:** 9600  
- **Data Sent:** Key number (1–8) or equivalent frequency in Hz  
- **Format:** Can be plain text (e.g., `"400\n"`)

---

## 🧠 Key Learning Points

- Splitting embedded tasks between multiple microcontrollers  
- Serial communication using UART in Arduino  
- Synchronizing display, input, and output across devices  
- Modular hardware and code design

---

## ✅ Status

✔️ Simulated and tested on [TinkerCAD/Wokwi]  
✔️ Verified tone generation via second Arduino  
✔️ Data transmission verified via Serial Monitor

---

## 📌 Notes

> For real hardware testing, ensure proper **ground connection** between the two Arduino boards and use **voltage divider or level shifter** if you're mixing 3.3V and 5V boards.

---


