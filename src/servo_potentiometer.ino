#include <Servo.h>

// Create servo object
Servo myServo;

// Define pins
int potPin = A0;
int servoPin = 3;

// Variables
int potValue;
int angle;

void setup() {

  // Attach servo
  myServo.attach(servoPin);

  // Start serial communication
  Serial.begin(9600);

}

void loop() {

  // Read potentiometer
  potValue = analogRead(potPin);

  // Convert analog value to angle
  angle = map(potValue, 0, 1023, 0, 180);

  // Move servo
  myServo.write(angle);

  // Display values
  Serial.print("Analog: ");
  Serial.print(potValue);

  Serial.print(" | Angle: ");
  Serial.println(angle);

  delay(15);

}
