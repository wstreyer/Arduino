/*
Adafruit Arduino - Lesson 4. 8 LEDs and a Shift Register
*/
 
int brightPin = 10;
int latchPin = 13;
int clockPin = 9;
int dataPin = 8;

int delay_time = 20;
int level = 0;
int bright = 0;
int pot_val = 0;
int spin = 0;


const int pot = A5;
 
byte leds = 0;
 
void setup() 
{
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);  
  pinMode(clockPin, OUTPUT);
  pinMode(brightPin, OUTPUT);
}
 
void loop() 
{
  pot_val = analogRead(pot);
  level = map(pot_val, 0, 1000, 1, 8);
  bright = map(pot_val, 0, 1023, 0, 255);
  
  analogWrite(brightPin, 255 - bright);
  
  for (int i = 0; i < 8; i++)
  {
    if(i < level){
      bitSet(leds, i);
    }
    else{
      bitClear(leds, i);
    }
  }
  updateShiftRegister();
  delay(delay_time);
  if(level == 8)
  {
    spin = random(0, 8);
    bitClear(leds, spin);
    updateShiftRegister();
    delay(delay_time);
  }
}
 
void updateShiftRegister()
{
   digitalWrite(latchPin, LOW);
   shiftOut(dataPin, clockPin, MSBFIRST, leds);
   digitalWrite(latchPin, HIGH);
}

void spinTheWheel()
{
  for (int i = 0; i < 8; i++)
  {
    spin = random(1, 9);
    bitClear(leds, spin);
  }
}
