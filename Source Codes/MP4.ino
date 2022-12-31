/*
  Name:
  Course-Section: BSIT-3A
  Date:

  Title: MP4 - Build a prototype on the breadboard using DISTANCE SENSOR, BUZZER AND LED
  Description: Create a prototype that measures distances through utilization of buzzer,
            distance sensor, and LEDs to indicate a certain parameters of measurement of
            light with corresponding variations.
*/

// defines pins numbers
const int trigPin = 9;
const int echoPin = 10;
const int buzzer = 11;
const int ledRPin = 2;
const int ledYPin = 3;
const int ledGPin = 4;

// defines variables
long duration;
int distance;
int safetyDistance;

void setup()
{
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT);  // Sets the echoPin as an Input
  pinMode(buzzer, OUTPUT);
  pinMode(ledRPin, OUTPUT);
  pinMode(ledYPin, OUTPUT);
  pinMode(ledGPin, OUTPUT);
  Serial.begin(9600); // Starts the serial communication
}

void loop()
{
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);

  // Calculating the distance
  distance = duration * 0.034 / 2;

  if (distance >= 1 and distance <= 10)
  {

    delay(2000);
    digitalWrite(buzzer, LOW);
    digitalWrite(ledRPin, HIGH);
  }
  else
  {
    digitalWrite(buzzer, HIGH);
    digitalWrite(ledRPin, LOW);
  }

  if (distance > 11 and distance <= 20)
  {
    digitalWrite(ledYPin, HIGH);
  }
  else
  {
    digitalWrite(ledYPin, LOW);
  }

  if (distance > 21 and distance <= 35)
  {
    digitalWrite(ledGPin, HIGH);
  }
  else
  {
    digitalWrite(ledGPin, LOW);
  }

  // Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance);
}
