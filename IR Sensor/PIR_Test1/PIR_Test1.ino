/*
  Name: PIR_Test1
  Date: 8/4/14
  Author: Will Streyer
  
  Description: Reads input from a passive infrared detector-
  typically used for motion sensing applications.
  Turns on an LED whenever an event is detected.  
 */
 
int led = 13;
int gnd = 8;
int vcc = 9;
int pir = 10;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the LED pin as an output.
  pinMode(led, OUTPUT);
  
  // initialize the power for sensor
  // new 5V and ground are used so sensor can be plugged dirctly into I/O pins
  pinMode(gnd, OUTPUT);
  pinMode(vcc, OUTPUT);
  
  // initialize sensor output as system input
  pinMode(pir, INPUT);
  
  // set sensor power pins
  digitalWrite(vcc, HIGH);   // Provide power to sensor
  digitalWrite(gnd, LOW);   // Provide ground to sensor 
}

// the loop routine runs over and over again forever:
void loop() {
  //Read output of sensor
  int pir_event = digitalRead(pir);
  
  //if pir event is detected, turn on led
  if (pir_event == HIGH) {
      digitalWrite(led, HIGH);  
  }
  //otherwise, turn the led off
  else {
     digitalWrite(led, LOW);  
  }
}
