/*
  Name:
  Course-Section: BSIT-3A
  Date:

  Title: MP2
  Description: Build a prototype on the breadboard using single BUTTON and SERVO MOTOR.
                  - If button pressed, rotate servo 90 degrees
                  - If button pressed again, rotate servo back to 0 degrees
  Refs: https://roboticsbackend.com/arduino-push-button-tutorial/

 */

#include <Servo.h>

// Constants
const int BTN = 7;
const int SRV = 9;

Servo servo; // create servo object to control a servo

int angle = 0;          // Current angle of servo motor
int lastButtonState;    // Previous state of button
int currentButtonState; // Current state of button

void setup()
{
  Serial.begin(9600);

  pinMode(BTN, INPUT_PULLUP); // set arduino pin to input pull-up mode
  servo.attach(SRV);          // attaches the servo on pin 9 to the servo object

  servo.write(angle);
  currentButtonState = digitalRead(BTN);
}

void loop()
{
  // save the last state
  lastButtonState = currentButtonState;

  // read new state
  currentButtonState = digitalRead(BTN);

  // Event handler for button
  if (lastButtonState == HIGH && currentButtonState == LOW)
  {
    Serial.println("The button is pressed");

    // change angle of servo motor
    if (angle == 0)
      angle = 90;
    else if (angle == 90)
      angle = 0;

    // control servo motor according to the angle
    servo.write(angle);
  }
}