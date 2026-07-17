# PIR Motion Sensor - Arduino

A simple Arduino sketch that detects motion using a PIR (Passive Infrared) sensor and reports it over Serial, with an LED indicator.

## Hardware Required

- Arduino board (Uno, Nano, Mega, etc.)
- PIR motion sensor (e.g. HC-SR501)
- LED (optional — most boards have one built in on pin 13)
- Jumper wires

## Wiring

| PIR Pin | Arduino Pin |
|---------|-------------|
| VCC     | 5V          |
| GND     | GND         |
| OUT     | Digital Pin 2 |

LED (optional): connect to Digital Pin 13, or just use the board's built-in LED.

## How It Works

1. On startup, the sketch waits about 20 seconds while the PIR sensor stabilizes (this is normal for PIR sensors — ignore any false triggers during this period).
2. Once ready, it continuously reads the sensor:
   - When motion is detected, it prints `Motion detected!` to the Serial Monitor and turns the LED on.
   - When motion stops, it prints `Motion stopped.` and turns the LED off.

## Usage

1. Open `pir_motion_sensor.ino` in the Arduino IDE.
2. Select your board and port under **Tools**.
3. Upload the sketch.
4. Open **Tools > Serial Monitor** (set baud rate to `9600`) to see motion events.

## Notes / Troubleshooting

- Most PIR sensors have two onboard potentiometers to adjust **sensitivity** and **delay time** — turn these if detections feel too sensitive or too slow to reset.
- If you get constant false triggers, double-check the sensor is powered from 5V and give it more warm-up time.
- Some PIR modules have a jumper for **repeatable trigger mode (H)** vs **single trigger mode (L)** — use H mode for continuous motion tracking like this sketch expects.

## License

Feel free to use and modify this for your own projects.
