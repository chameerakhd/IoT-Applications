// CHAMEERA K.H.D
// 220080N
// Master Arduino – I2C Button Reader + Diagnostic LED
#include <Wire.h>

const int buttonPins[8] = {2, 3, 4, 5, 6, 7, 8, 9};
const int segmentPins[7] = {A0, A1, A2, A3, 10, 12, 11};
const int diagLED = 13;

bool lastButtonState[8] = {0}; // Track previous button states
unsigned long lastHeartbeat = 0;
const unsigned long heartbeatInterval = 500; // 0.5 seconds

// Segment encodings for digits 1–8
const byte digits[8][7] = {
  {0,1,1,0,0,0,0}, // 1
  {1,1,0,1,1,0,1}, // 2
  {1,1,1,1,0,0,1}, // 3
  {0,1,1,0,0,1,1}, // 4
  {1,0,1,1,0,1,1}, // 5
  {1,0,1,1,1,1,1}, // 6
  {1,1,1,0,0,0,0}, // 7
  {1,1,1,1,1,1,1}  // 8
};

void setup() {
  Wire.begin(); // Start I2C as Master
  pinMode(diagLED, OUTPUT);
  digitalWrite(diagLED, LOW); // Turn off diagnostic LED initially

  for (int i = 0; i < 8; i++) {
    pinMode(buttonPins[i], INPUT);
  }

  for (int i = 0; i < 7; i++) {
    pinMode(segmentPins[i], OUTPUT);
  }
}

void loop() {
  for (int i = 0; i < 8; i++) {
    bool currentState = digitalRead(buttonPins[i]);

    // Button just pressed
    if (currentState == HIGH && lastButtonState[i] == LOW) {
      displayDigit(i);
      Wire.beginTransmission(8);
      Wire.write(i + 1); // Send button number 1–8
      Wire.endTransmission();
    }

    // Button just released
    if (currentState == LOW && lastButtonState[i] == HIGH) {
      clearDisplay(); // Turn off all segments
    }

    lastButtonState[i] = currentState;
  }

  // Send heartbeat periodically
  if (millis() - lastHeartbeat >= heartbeatInterval) {
    Wire.beginTransmission(8);
    Wire.write(255); // Heartbeat signal
    byte error = Wire.endTransmission();

    // Diagnostic LED: ON = OK, OFF = failed
    digitalWrite(diagLED, (error == 0) ? HIGH : LOW);
    lastHeartbeat = millis();
  }
}

void displayDigit(int num) {
  for (int i = 0; i < 7; i++) {
    digitalWrite(segmentPins[i], digits[num][i]);
  }
}

void clearDisplay() {
  for (int i = 0; i < 7; i++) {
    digitalWrite(segmentPins[i], LOW);
  }
}
