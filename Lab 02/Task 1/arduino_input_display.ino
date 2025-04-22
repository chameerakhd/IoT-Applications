// CHAMEERA K.H.D
// 220080N
// Arduino #1: Keyboard and Display Unit (Transmitter)

const int buttonPins[8] = {2, 3, 4, 5, 6, 7, 8, 9};
const int frequencies[8] = {300, 400, 500, 600, 700, 800, 900, 1000};

const int segmentPins[7] = {A0, A1, A2, A3, A4, A5, 11};

const byte digits[10][7] = {
  {1, 1, 1, 1, 1, 1, 0}, // 0
  {0, 1, 1, 0, 0, 0, 0}, // 1
  {1, 1, 0, 1, 1, 0, 1}, // 2
  {1, 1, 1, 1, 0, 0, 1}, // 3
  {0, 1, 1, 0, 0, 1, 1}, // 4
  {1, 0, 1, 1, 0, 1, 1}, // 5
  {1, 0, 1, 1, 1, 1, 1}, // 6
  {1, 1, 1, 0, 0, 0, 0}, // 7
  {1, 1, 1, 1, 1, 1, 1}, // 8
  {1, 1, 1, 1, 0, 1, 1}  // 9
};

void setup() {
  Serial.begin(9600); // UART communication

  for (int i = 0; i < 8; i++) {
    pinMode(buttonPins[i], INPUT);
  }

  for (int i = 0; i < 7; i++) {
    pinMode(segmentPins[i], OUTPUT);
  }
}

void loop() {
  int totalFrequency = 0;
  int pressedKeys[8];
  int keyCount = 0;

  for (int i = 0; i < 8; i++) {
    if (digitalRead(buttonPins[i]) == HIGH) {
      totalFrequency += frequencies[i];
      pressedKeys[keyCount] = i + 1;
      keyCount++;
    }
  }

  if (keyCount > 0) {
    Serial.println(totalFrequency); // Send frequency to Arduino #2
  }

  // Display logic
  if (keyCount == 1) {
    displayDigit(pressedKeys[0]);
  } else if (keyCount > 1) {
    for (int j = 0; j < keyCount; j++) {
      displayDigit(pressedKeys[j]);
      delay(500);
    }
  } else {
    clearDisplay();
  }

  delay(50); // Give time to process
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
