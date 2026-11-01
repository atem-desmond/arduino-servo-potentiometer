# Arduino Servo Control Using a Potentiometer

## Overview

This project demonstrates basic Arduino-based servo motor control using a potentiometer as an input device.

The potentiometer acts as a voltage divider, providing a variable analog voltage to the Arduino. The Arduino reads this voltage, converts it into a digital value, maps the value to a servo angle, and commands the servo to move accordingly.

This project was completed as an introduction to embedded systems and as preparation for developing my 6-DOF robotic arm.

## Objectives

- Understand how a potentiometer operates as a voltage divider.
- Read analog voltage values using the Arduino ADC.
- Convert analog readings into servo angles.
- Control a servo motor using the Arduino Servo library.
- Use Serial Monitor for debugging and displaying sensor values.

## Components

- Arduino Uno
- SG90 servo motor
- Potentiometer
- Breadboard
- Jumper wires
- USB cable

## Circuit Connections

### Potentiometer

| Potentiometer | Arduino |
|---|---|
| Outer pin | 5V |
| Other outer pin | GND |
| Middle pin (wiper) | A0 |

### Servo

| Servo wire | Arduino |
|---|---|
| Signal | Digital pin 3|
| Power | 5V for unloaded SG90 testing |
| Ground | GND |

## How It Works

1. The potentiometer is connected across the 5V supply and ground.
2. Turning the potentiometer changes the voltage at its middle pin.
3. The Arduino reads this voltage using `analogRead()`.
4. The ADC converts the voltage into a digital value between 0 and 1023.
5. The `map()` function converts the analog reading into an angle between 0 and 180 degrees.
6. The Servo library commands the servo to move to the calculated angle.
7. Serial Monitor displays the analog reading and calculated angle.

## Arduino Code

```cpp
#include <Servo.h>

Servo myServo;

int potPin = A0;
int servoPin = 9;

int potValue;
int angle;

void setup() {
  myServo.attach(servoPin);
  Serial.begin(9600);
}

void loop() {
  potValue = analogRead(potPin);

  angle = map(potValue, 0, 1023, 0, 180);

  myServo.write(angle);

  Serial.print("Analog: ");
  Serial.print(potValue);

  Serial.print(" | Angle: ");
  Serial.println(angle);

  delay(15);
}
```

## Results

The servo position changes according to the potentiometer position.

| Analog input | Approximate servo angle |
|---|---|
| 0 | 0° |
| 256 | 45° |
| 512 | 90° |
| 768 | 135° |
| 1023 | 180° |

The analog input and calculated servo angle were successfully displayed using the Arduino Serial Monitor.

## Skills Demonstrated

- Arduino coding
- Analog input reading
- Analog-to-digital conversion
- Voltage divider circuits
- Servo motor control
- Serial communication
- Basic hardware integration

## Future Improvements

- Control multiple servo motors independently.
- Implement coordinated servo movement.
- Add multiple potentiometers for controlling different joints.
- Integrate servo control into a 6-DOF robotic arm.
- Implement calculated joint angles using forward and inverse kinematics.

## Motivation

This project is part of my progression toward developing a functional robotic arm and improving my understanding of embedded systems, electronics, and robotics.
