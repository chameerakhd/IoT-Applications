// CHAMEERA K.H.D
// 220080N
// Arduino #2: Buzzer Output Unit (Receiver)

const int buzzerPin = 10;
String inputString = "";
bool stringComplete = false;

void setup() {
  Serial.begin(9600); // UART
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  if (Serial.available()) {
    char inChar = (char)Serial.read();
    if (inChar == '\n') {
      stringComplete = true;
    } else {
      inputString += inChar;
    }
  }

  if (stringComplete) {
    int frequency = inputString.toInt();
    if (frequency > 0) {
      tone(buzzerPin, frequency);
      delay(20); // Small tone duration
      noTone(buzzerPin);
    }
    inputString = "";
    stringComplete = false;
  }
}
