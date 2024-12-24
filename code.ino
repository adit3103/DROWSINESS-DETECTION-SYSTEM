
// Drowsiness Detection System
#include <Arduino.h>

#define IR_SENSOR_PIN A0  // IR Sensor connected to Analog pin A0
#define LED_PIN 9         // LED connected to Digital pin 9
#define BUZZER_PIN 8      // Buzzer connected to Digital pin 8

void setup() {
    pinMode(IR_SENSOR_PIN, INPUT);
    pinMode(LED_PIN, OUTPUT);
    pinMode(BUZZER_PIN, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    int sensorValue = analogRead(IR_SENSOR_PIN);
    Serial.println(sensorValue);

    // Threshold for detecting closed eyes (adjust as needed)
    if (sensorValue > 600) {
        digitalWrite(LED_PIN, HIGH);
        digitalWrite(BUZZER_PIN, HIGH);
        delay(1000);  // Alert duration
    } else {
        digitalWrite(LED_PIN, LOW);
        digitalWrite(BUZZER_PIN, LOW);
    }

    delay(100);  // Sampling interval
}
