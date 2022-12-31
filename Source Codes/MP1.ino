/*
  Name:
  Course-Section: BSIT-3A
  Date:

  Title: MP1 — Alternating Blinky Lights
  Description: Build a prototype on the breadboard that has 5 LEDs alternating blinking lights

 */
int pins[] = {4, 7, 8, 12, 13};

void setup()
{
  for (int pinNum = 0; pinNum < 5; pinNum++)
  {
    pinMode(pins[pinNum], OUTPUT);
  }
}

void loop()
{
  for (int pinNum = 0; pinNum < 5; pinNum++)
  {
    digitalWrite(pins[pinNum], HIGH);
    delay(2000);

    digitalWrite(pins[pinNum], LOW);
    delay(2000);
  }
}