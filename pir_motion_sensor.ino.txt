/*
  PIR Motion Sensor - Arduino
  ---------------------------
  Wiring:
    PIR VCC  -> 5V
    PIR GND  -> GND
    PIR OUT  -> Digital Pin 2

    LED (optional) -> Digital Pin 13 (built-in LED on most boards)

  Behavior:
    - Prints "Motion detected!" / "Motion stopped." to Serial Monitor
    - Turns the LED on while motion is detected
*/

const int PIR_PIN = 2;
const int LED_PIN = 13;

bool motionState = false;   // tracks last known state

void setup() {
  pinMode(PIR_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);

  Serial.println("PIR sensor warming up...");
  delay(20000); // most PIR sensors need ~20-60s to stabilize after power-on
  Serial.println("PIR sensor ready.");
}

void loop() {
  int sensorValue = digitalRead(PIR_PIN);

  if (sensorValue == HIGH) {
    digitalWrite(LED_PIN, HIGH);
    if (!motionState) {
      Serial.println("Motion detected!");
      motionState = true;
    }
  } else {
    digitalWrite(LED_PIN, LOW);
    if (motionState) {
      Serial.println("Motion stopped.");
      motionState = false;
    }
  }

  delay(50); // small debounce delay
}
