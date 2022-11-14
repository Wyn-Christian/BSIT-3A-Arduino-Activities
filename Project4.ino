/*
  Name:
  Course-Section: BSIT-3A
  Date:

  Title: PR4 - RGB LED
  Description: In this circuit, you’ll be using a photoresistor,
        which changes resistance based on how much light the sensor
        receives. Using this sensor you can make a simple night-light
        that turns on when the room gets dark and turns off when it is bright.

 */

int photoresistor = A0;
int potentiometer = A1;
int threshold = 700;

int RedPin = 9;
int GreenPin = 10;
int BluePin = 11;

void setup()
{
  Serial.begin(9600);

  // set the LED pins to output
  pinMode(RedPin, OUTPUT);
  pinMode(GreenPin, OUTPUT);
  pinMode(BluePin, OUTPUT);
}

void loop()
{
  photoresistor = analogRead(A0);
  potentiometer = analogRead(A1);

  Serial.print("Photoresistor value: ");
  Serial.print(photoresistor);

  Serial.print(" - ");

  Serial.print("Potentiometer value: ");
  Serial.println(potentiometer);

  if (photoresistor < threshold)
  {
    // If it's dark (the photoresistor value is below the threshold) turn the LED on
    /*
      These nested if statements check for a variety of ranges and
        call different functions based on the current potentiometer value.

      Those functions are found at the bottom of the sketch.
     */
    if (potentiometer > 900)
      magenta();
    else if (potentiometer > 750)
      blue();
    else if (potentiometer > 600)
      cyan();
    else if (potentiometer > 450)
      green();
    else if (potentiometer > 300)
      yellow();
    else if (potentiometer > 150)
      orange();
    else if (potentiometer > 0)
      red();

    // if (potentiometer > 0 && potentiometer <= 150)
    //   red();
  }
  else
    turnOff();

  delay(100);
}

void red()
{
  analogWrite(RedPin, 100);
  analogWrite(GreenPin, 0);
  analogWrite(BluePin, 0);
}
void orange()
{
  analogWrite(RedPin, 100);
  analogWrite(GreenPin, 50);
  analogWrite(BluePin, 0);
}
void yellow()
{
  analogWrite(RedPin, 100);
  analogWrite(GreenPin, 100);
  analogWrite(BluePin, 0);
}
void green()
{
  analogWrite(RedPin, 0);
  analogWrite(GreenPin, 100);
  analogWrite(BluePin, 0);
}
void cyan()
{
  analogWrite(RedPin, 0);
  analogWrite(GreenPin, 100);
  analogWrite(BluePin, 100);
}
void blue()
{
  analogWrite(RedPin, 0);
  analogWrite(GreenPin, 0);
  analogWrite(BluePin, 100);
}
void magenta()
{
  analogWrite(RedPin, 100);
  analogWrite(GreenPin, 0);
  analogWrite(BluePin, 100);
}
void turnOff()
{
  analogWrite(RedPin, 0);
  analogWrite(GreenPin, 0);
  analogWrite(BluePin, 0);
}