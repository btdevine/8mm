/*
  Stepper Motor Demonstration 4
  Stepper-Demo4.ino
  Demonstrates NEMA 17 Bipolar Stepper with A4988 Driver

  DroneBot Workshop 2018
  https://dronebotworkshop.com
*/

// Define Constants

// Connections to A4988
const int dirPin = 2;  // Direction
const int stepPin = 3; // Step

// Motor steps per rotation
const int STEPS_PER_REV = 200;
const int MICRO_ADJUST = 2;

void setup() {
  Serial.begin(9600);
  // Setup the pins as Outputs
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  // Set motor direction clockwise
  digitalWrite(dirPin, HIGH);
}

void loop() {
  if (Serial.available()) // if there is data comming
  {
    String command = Serial.readStringUntil('\n'); // read string until meet newline character
    if (command == "+")
    {
      for (int x = 0; x < STEPS_PER_REV*0.7; x++) {
        digitalWrite(stepPin, HIGH);
        delayMicroseconds(750);
        digitalWrite(stepPin, LOW);
        delayMicroseconds(750);
      }
    }
    else if (command == ".")
    {
      for (int x = 0; x < MICRO_ADJUST; x++) {
        digitalWrite(stepPin, HIGH);
        delayMicroseconds(3000);
        digitalWrite(stepPin, LOW);
        delayMicroseconds(3000);
      }
    }
  }
}
