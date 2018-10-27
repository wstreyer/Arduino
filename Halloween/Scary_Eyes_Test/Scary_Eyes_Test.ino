/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the Uno and
  Leonardo, it is attached to digital pin 13. If you're unsure what
  pin the on-board LED is connected to on your Arduino model, check
  the documentation at http://arduino.cc

  This example code is in the public domain.

  modified 8 May 2014
  by Scott Fitzgerald
 */

//Pins to control Scary_Eyes units
const int left1Pin = 13;
const int right1Pin =12;

//Pin for PIR sensor
const int pirPin = 2;

//Initialize target detection state
int target_detected = 0;

// the setup function runs once when you press reset or power the board
void setup()
{
  // initialize Scary_Eyes pins
  pinMode(left1Pin, OUTPUT);
  pinMode(right1Pin, OUTPUT);
  
  //initialize PIR sensor pin
  pinMode(pirPin, INPUT);
}

// the loop function runs over and over again forever
void loop()
{
  target_detected = digitalRead(pirPin);
  if (target_detected)
  {
    digitalWrite(left1Pin, HIGH);
    delay(500);
  
    digitalWrite(right1Pin, HIGH);
  
    delay(30000);
    digitalWrite(left1Pin, LOW);
    digitalWrite(right1Pin, LOW);
  }
}
