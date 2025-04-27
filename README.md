# 📡 IoT Devices and Applications – Arduino Projects

Welcome to my project repository for the **IoT Devices and Applications** module. This repository documents weekly assignments involving hands-on work with **Arduino Uno**, circuits, sensors, and actuators. Each folder includes:
- ✅ Arduino code
- 🧠 Weekly notes & observations
- 🔌 Circuit diagrams
- 🖼️ Images / media
- 📁 TinkerCAD or Wokwi simulations (when available)

---

## 📅 Task Breakdown

### 🔹 Lab 01
**Task 1: 8-Key Tone Generator**  
- Created a tone generator using 8 push buttons.
- Each button outputs a different frequency (300Hz to 1kHz).
- Multiple key presses result in summed frequency output.

**Task 2: Display Key Number on 7-Segment Display**  
- Integrated a 7-segment display to show the key number pressed.
- Alternates key numbers every 500ms if multiple keys are pressed.


---

### 🔹 Lab 02
**Task 1: Communication Using Serial (UART) Interface**  
- Split the system into two Arduino boards:
  - One board handles keyboard input and key number display.
  - The other board handles sound output through a speaker.
- Boards communicate via UART (Serial).

**Task 2: Communication Using I2C Interface**  
- Changed the communication method from UART to I2C.
- One board acts as I2C Master, the other as I2C Slave.
- Maintains the same input-display and output-sound split.

**Task 3: Adding Onboard Diagnostics**  
- Added a diagnostic LED to each Arduino board.
- Boards exchange periodic heartbeat messages over I2C.
- LEDs remain ON if communication is healthy; LEDs turn OFF if communication fails.


## 📂 Repository Structure
```
📦 IoT-Arduino-Projects/
│
├── Lab 01/
│   ├── Task 1
│     ├── code_task1.ino
│     ├── circuit_diagram.jpg
|     ├── README.md
│   ├── Task 2
│     ├── code_task2.ino
│     ├── circuit_diagram.jpg
|     ├── README.md
├── Lab 02/
│   ├── Task 1
│     ├── arduino_input_display.ino
│     ├── arduino_sound_output.ino
│     ├── Task_1_using_a_serial_UART_interface.png
|     ├── README.md
│   ├── Task 2
│     ├── master_input_display.ino
│     ├── slave_tone_generator.ino
│     ├── Task_2_using_I2C_communication.png
|     ├── README.md
│   ├── Task 3
│     ├── master_diagnostic.ino
│     ├── slave_diagnostic.ino 
│     ├── Task_3_adding_onboard_diagnostics.png
|     ├── README.md
│
└── README.md  ← You are here!```


---

## 🔧 Tools & Platforms Used
- Arduino Uno
- TinkerCAD Circuits
- Wokwi Simulator
- Arduino IDE

---

## 📌 Notes
This repository is actively maintained and updated weekly with new projects and improvements. Feel free to explore each folder for code, diagrams, and insights into each build.

---

## 📬 Contact
If you're working on similar projects or want to collaborate, feel free to reach out via GitHub or email!

---




