// CHAMEERA K.H.D
// 220080N
// Arduino I2C Master - Button Reader & Sender

#include <Wire.h>

const int buttonPins[8] = {2, 3, 4, 5, 6, 7, 8, 9};
const int segmentPins[7] = {A0, A1, A2, A3, 10, 12, 11};

// Segment encodings for digits 1 to 8
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
  Wire.begin(); // join I2C bus as master
  for (int i = 0; i < 8; i++) {
    pinMode(buttonPins[i], INPUT);
  }
  for (int i = 0; i < 7; i++) {
    pinMode(segmentPins[i], OUTPUT);
  }
}

void loop() {
  for (int i = 0; i < 8; i++) {
    if (digitalRead(buttonPins[i]) == HIGH) {
      displayDigit(i); // display 1–8 by index
      Wire.beginTransmission(8); // send to slave with address 8
      Wire.write(i + 1); // send button number 1–8
      Wire.endTransmission();
      delay(300); // debounce delay
    }
  }
}

void displayDigit(int num) {
  for (int i = 0; i < 7; i++) {
    digitalWrite(segmentPins[i], digits[num][i]);
  }
}
