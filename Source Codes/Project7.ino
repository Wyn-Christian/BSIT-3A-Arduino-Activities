/*
  Name:
  Course-Section: BSIT-3A
  Date:

  Title: PR7 - PIR
  Description: In this ciruit, we will use the PIR sensor to detect
      movement with a certain range which make turns the LED ON and
      print a message in the Serial Port when it detects motion.
 */

int ledPin = 13;    // choose the pin for the LED
int inputPin = 8;   // choose the input pin (for PIR sensor)
int pirState = LOW; // we start, assuming no motion detected
int val = 0;        // variable for reading the pin status

void setup()
{
  pinMode(ledPin, OUTPUT);  // declare LED as output
  pinMode(inputPin, INPUT); // declare sensor as input

  Serial.begin(9600);
}

void loop()
{
  val = digitalRead(inputPin); // read input value

  if (val == HIGH) // check if the input is HIGH
  {
    digitalWrite(ledPin, HIGH); // turn LED ON
    if (pirState == LOW)
    {
      Serial.println("Motion detected!"); // print on output change
      pirState = HIGH;
    }
  }
  else
  {
    digitalWrite(ledPin, LOW); // turn LED OFF
    if (pirState == HIGH)
    {
      Serial.println("Motion ended!"); // print on output change
      pirState = LOW;
    }
  }
}