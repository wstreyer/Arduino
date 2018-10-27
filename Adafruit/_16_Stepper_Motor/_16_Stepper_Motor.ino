/*
Adafruit Arduino - Lesson 16. Stepper
*/
 
#include <Stepper.h>

#define STEPS 48
#define GEAR_RATIO 1

int in1Pin = 7;
int in2Pin = 10;
int in3Pin = 9;
int in4Pin = 8;
 
Stepper motor(48, in1Pin, in2Pin, in3Pin, in4Pin);  
 
void setup()
{
  pinMode(in1Pin, OUTPUT);
  pinMode(in2Pin, OUTPUT);
  pinMode(in3Pin, OUTPUT);
  pinMode(in4Pin, OUTPUT);
 
  Serial.begin(9600);
  motor.setSpeed(20);
}
 
void loop()
{
  if (Serial.available())
  {
    int steps = Serial.parseInt();
    motor.step(steps);
  }
}
