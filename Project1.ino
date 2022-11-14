/*
  Name:
  Section: BSIT-3A
  Date:

  Title: Project 1 - LED
  Description: Build a circuit that has a single LED blinking per 2s.

 */
void setup()
{
  pinMode(13, OUTPUT);
}

void loop()
{
  digitalWrite(13, HIGH);
  delay(2000);

  digitalWrite(13, LOW);
  delay(2000);
}