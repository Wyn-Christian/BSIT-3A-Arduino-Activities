/*
  Name:
  Course-Section: BSIT-3A
  Date:

  Title: PR5 - Servo Motor
  Description: In thiscircuit, you’ll be using a photoresistor,which changes resistance based on howmuch light the sensor receives.
 */
#include <Servo.h>

int potPos;
int servoPos;

Servo myservo;

void setup()
{
  myservo.attach(9);
}
void loop()
{
  potPos = analogRead(A0);

  servoPos = map(potPos, 0, 1023, 20, 160);

  myservo.write(servoPos);
}
