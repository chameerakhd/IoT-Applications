//CHAMEERA K.H.D
//220080N
//8 key Tone Generator
// This code generates a sound based on the frequencies assigned to each button pressed.

const int buttonPins[8] = {2, 3, 4, 5, 6, 7, 8, 9};  // Button pins
const int frequencies[8] = {300, 400, 500, 600, 700, 800, 900, 1000};  // Assigned frequencies
const int buzzerPin = 10;

void setup() {
  for (int i = 0; i < 8; i++) {
    pinMode(buttonPins[i], INPUT); 
  }
}

void loop() {
  int totalFrequency = 0;
  bool anyKeyPressed = false;

  for (int i = 0; i < 8; i++) {
    if (digitalRead(buttonPins[i]) == HIGH) {
      totalFrequency += frequencies[i];
      anyKeyPressed = true;
    }
  }

  if (anyKeyPressed) {
    tone(buzzerPin, totalFrequency); 
    delay(20); // Play for 20ms
  } else {
    noTone(buzzerPin); // Stop sound
  }
}
