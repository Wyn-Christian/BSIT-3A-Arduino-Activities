/*
  Name:
  Section: BSIT-3A
  Date:

  Title: MP5 - Traffic Light
  Description: Build a prototype on the breadboard using RGB LED TO SIMULATE TRAFFIC LIGHT.

 */

int redPin = 3;
int greenPin = 5;
int bluePin = 6;

void setup()
{
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop()
{
  setColor(255, 0, 0); // Red Color
  delay(5000);
  setColor(255, 60, 0); // orangetrrt
  delay(2000);
  setColor(0, 255, 0); // green
  delay(5000);
  setColor(255, 60, 0); // orangetrrt
  delay(2000);
}

void setColor(int redValue, int greenValue, int blueValue)
{
  analogWrite(redPin, redValue);
  analogWrite(greenPin, greenValue);
  analogWrite(bluePin, blueValue);
}
