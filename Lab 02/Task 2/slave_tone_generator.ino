// CHAMEERA K.H.D
// 220080N
// Arduino I2C Slave - Buzzer Player

#include <Wire.h>

const int buzzerPin = 10;

void setup() {
  pinMode(buzzerPin, OUTPUT);
  Wire.begin(8); // join I2C bus with address #8
  Wire.onReceive(receiveData);
}

void loop() {
  // Nothing in loop, waiting for I2C data
}

void receiveData(int byteCount) {
  while (Wire.available()) {
    int buttonIndex = Wire.read();
    playTone(buttonIndex);
  }
}

void playTone(int index) {
  int frequency = 200 + index * 100;
  tone(buzzerPin, frequency, 300); // play tone for 300 ms
}

