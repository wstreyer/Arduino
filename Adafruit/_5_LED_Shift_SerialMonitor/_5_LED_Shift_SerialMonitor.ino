/*
Adafruit Arduino - Lesson 5. Serial Monitor
*/
 
int brightPin = 10;
int latchPin = 13;
int clockPin = 9;
int dataPin = 8;

int bright = 0;
int pot_val = 0;

const int pot = A5;

byte leds = 0;
 
void setup() 
{
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);  
  pinMode(clockPin, OUTPUT);
  pinMode(brightPin, OUTPUT);
  
  updateShiftRegister();
  Serial.begin(9600);
  while (! Serial); // Wait untilSerial is ready - Leonardo
  Serial.println("Enter LED Number 0 to 7 or 'x' to clear");
}
 
void loop() 
{
  pot_val = analogRead(pot);
  bright = map(pot_val, 0, 1023, 0, 255);
  
  analogWrite(brightPin, 255 - bright);
  
  if (Serial.available())
  {
    char ch = Serial.read();
    if (ch >= '0' && ch <= '7')
    {
      int led = ch - '0';
      bitSet(leds, led);
      updateShiftRegister();
      Serial.print("Turned on LED ");
      Serial.println(led);
    }
    if (ch == 'x')
    {
      leds = 0;
      updateShiftRegister();
      Serial.println("Cleared");
    }
  }
}
 
void updateShiftRegister()
{
   digitalWrite(latchPin, LOW);
   shiftOut(dataPin, clockPin, LSBFIRST, leds);
   digitalWrite(latchPin, HIGH);
}
