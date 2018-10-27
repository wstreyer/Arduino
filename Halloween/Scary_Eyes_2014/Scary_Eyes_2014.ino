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
const int right1Pin =11;
const int left2Pin = 9;
const int right2Pin = 7;
const int left3Pin = 5;
const int right3Pin = 4;

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
  pinMode(left2Pin, OUTPUT);
  pinMode(right2Pin, OUTPUT);
  pinMode(left3Pin, OUTPUT);
  pinMode(right3Pin, OUTPUT);
  
  // initialize extra gound pins
  pinMode(12, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(6, OUTPUT);
  //pinMode(4, OUTPUT);
  
  digitalWrite(12, LOW);
  digitalWrite(10, LOW);
  digitalWrite(8, LOW);
  digitalWrite(6, LOW);
  //digitalWrite(4, LOW);
  
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
    digitalWrite(right1Pin, HIGH);
    delay(500);
  
    digitalWrite(left2Pin, HIGH);
    digitalWrite(right2Pin, HIGH);
    delay(500);
    
    digitalWrite(left3Pin, HIGH);
    digitalWrite(right3Pin, HIGH);
    delay(500);
  
    delay(15000);
    digitalWrite(left1Pin, LOW);
    digitalWrite(right1Pin, LOW);
    digitalWrite(left2Pin, LOW);
    digitalWrite(right2Pin, LOW);
    digitalWrite(left3Pin, LOW);
    digitalWrite(right3Pin, LOW);
    
    delay(5000);
  }
}
