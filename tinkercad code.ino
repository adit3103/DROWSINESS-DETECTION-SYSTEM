const int irPin = 2;  // IR sensor output pin
const int ledPin = 13;  // LED connected to pin 13
const int buzzerPin = 9;  // Buzzer connected to pin 9

void setup() {
  pinMode(irPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  int irValue = digitalRead(irPin);

  // IR sensor detects an object (simulating drowsiness)
  if (irValue == HIGH) {
    digitalWrite(ledPin, HIGH);  // Turn on LED
    tone(buzzerPin, 1000);  // Play a tone on the buzzer
    delay(500);  // Delay for a brief period
    digitalWrite(ledPin, LOW);  // Turn off LED
    noTone(buzzerPin);  // Stop the buzzer sound
  } else {
    digitalWrite(ledPin, LOW);  // No drowsiness detected, turn off LED
    noTone(buzzerPin);  // No drowsiness detected, stop the buzzer sound
  }
}
