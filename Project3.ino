/*
  Name:
  Course-Section:
  Date:

  Title: PR3 - Photoresistor
  Description: In this circuit, you’ll be using a photoresistor,which changes resistance based on howmuch light the sensor receives.
 */
int photoresistor = 0;
int threshold = 980;
int LEDPin = 2;

void setup()
{
  Serial.begin(9600);
  pinMode(LEDPin, OUTPUT);
}

void loop()
{
  photoresistor = analogRead(A0);

  Serial.println(photoresistor);

  if (photoresistor < threshold)
  {
    digitalWrite(LEDPin, HIGH);
  }
  else
  {
    digitalWrite(LEDPin, LOW);
  }
  delay(100);
}