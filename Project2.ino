/*
  Name:
  Course-Section: BSIT-3A
  Date:

  Title: PR2 - Potentiometer
  Description: In this circuit, you'll use a potentiometer as an input device to control the speed at which your LED blinks.
 */
int potPosition, pinNum = 2;
void setup()
{
  Serial.begin(9600);

  pinMode(pinNum, OUTPUT);
}

void loop()
{
  potPosition = analogRead(A0);

  Serial.println(potPosition);

  digitalWrite(pinNum, HIGH);
  delay(potPosition);

  digitalWrite(pinNum, LOW);
  delay(potPosition);
}