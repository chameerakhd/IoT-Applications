// CHAMEERA K.H.D
// 220080N
// Slave Arduino – Buzzer + Diagnostic LED

#include <Wire.h>

const int buzzerPin = 10;
const int diagLED = 13;

unsigned long lastHeartbeatTime = 0;
const unsigned long heartbeatTimeout = 500;

void setup() {
  pinMode(buzzerPin, OUTPUT);
  pinMode(diagLED, OUTPUT);
  digitalWrite(diagLED, LOW); // LED off initially

  Wire.begin(8);              // I2C address 8
  Wire.onReceive(receiveEvent);
}

void loop() {
  unsigned long currentTime = millis();

  // Check heartbeat timeout
  if (currentTime - lastHeartbeatTime > heartbeatTimeout) {
    digitalWrite(diagLED, LOW);  // Turn off LED
    noTone(buzzerPin);           // Stop buzzer
  } else {
    digitalWrite(diagLED, HIGH); // Communication is active
  }
}

void receiveEvent(int howMany) {
  while (Wire.available()) {
    int command = Wire.read();

    if (command >= 1 && command <= 8) {
      int frequency = 200 + (command * 100); // 300Hz to 1000Hz
      tone(buzzerPin, frequency, 100);       // Play tone for 100ms
      lastHeartbeatTime = millis();          // Reset on command
    } else if (command == 255) {
      lastHeartbeatTime = millis();          // Reset on heartbeat
    }
  }
}
