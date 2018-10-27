/*
Adafruit Arduino - Lesson 3. RGB LED
*/
 
int redPin = 10;
int greenPin = 9;
int bluePin = 11;

const int delay_time = 2500;
 
//uncomment this line if using a Common Anode LED
#define COMMON_ANODE
 
void setup()
{
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);  
}
 
void loop()
{
  setColor(255, 0, 0);  // red
  delay(delay_time);
  
  setColor(200, 100, 51);  // indigo
  delay(delay_time);
  
  setColor(0, 255, 0);  // green
  delay(delay_time);
  setColor(0, 0, 255);  // blue
  delay(delay_time);
  setColor(255, 150, 0);  // yellow
  delay(delay_time);  
  setColor(255, 0, 255);  // purple
  delay(delay_time);
  setColor(0, 255, 255);  // aqua
  delay(delay_time);
}
 
void setColor(int red, int green, int blue)
{
  #ifdef COMMON_ANODE
    red = 0xFF - red;
    green = 0xFF - green;
    blue = 0xFF - blue;
  #endif
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);  
}
