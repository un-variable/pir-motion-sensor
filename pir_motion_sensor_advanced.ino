/*
  PIR Motion Sensor - Advanced Version
  -------------------------------------
  Adds to the basic version:
    - Buzzer alarm on motion
    - Motion event counter
    - Non-blocking warm-up (Serial Monitor stays responsive)
    - Timestamps (milliseconds since start) for each event

  Wiring:
    PIR VCC     -> 5V
    PIR GND     -> GND
    PIR OUT     -> Digital Pin 2

    LED         -> Digital Pin 13 (or use built-in LED)
    Buzzer (+)  -> Digital Pin 8
    Buzzer (-)  -> GND
*/

const int PIR_PIN = 2;
const int LED_PIN = 13;
const int BUZZER_PIN = 8;

const unsigned long WARMUP_TIME = 20000; // ms, PIR stabilization time

bool motionState = false;
bool sensorReady = false;
unsigned long startTime = 0;
unsigned int motionCount = 0;

void setup() {
  pinMode(PIR_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  Serial.begin(9600);

  startTime = millis();
  Serial.println("PIR sensor warming up (20s)...");
}

void loop() {
  // Non-blocking warm-up check
  if (!sensorReady) {
    if (millis() - startTime >= WARMUP_TIME) {
      sensorReady = true;
      Serial.println("PIR sensor ready.");
    } else {
      return; // skip motion logic until warm-up finishes
    }
  }

  int sensorValue = digitalRead(PIR_PIN);

  if (sensorValue == HIGH) {
    digitalWrite(LED_PIN, HIGH);
    digitalWrite(BUZZER_PIN, HIGH);

    if (!motionState) {
      motionCount++;
      Serial.print("[");
      Serial.print(millis());
      Serial.print(" ms] Motion detected! (Event #");
      Serial.print(motionCount);
      Serial.println(")");
      motionState = true;
    }
  } else {
    digitalWrite(LED_PIN, LOW);
    digitalWrite(BUZZER_PIN, LOW);

    if (motionState) {
      Serial.print("[");
      Serial.print(millis());
      Serial.println(" ms] Motion stopped.");
      motionState = false;
    }
  }

  delay(50); // small debounce delay
}
