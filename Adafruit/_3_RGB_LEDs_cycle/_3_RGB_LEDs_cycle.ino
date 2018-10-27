/*
Adafruit Arduino - Lesson 3. RGB LED
*/
 
int redPin = 10;
int greenPin = 9;
int bluePin = 11;

const int delay_time = 1000;
 
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
  for (int i = 0; i <= 255; i = i + 32){
    for (int j = 255; j >= 0; j = j - 32){
      for (int k = 255; k >= 0; k = k - 32){
        setColor(k, j, i);
        delay(delay_time);
      }
    }
  }
}
void setColor(int red, int green, int blue)
{
  #ifdef COMMON_ANODE
    red = 255 - red;
    green = 255 - green;
    blue = 255 - blue;
  #endif
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);  
}
