#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 10, 5, 4, 3, 2);

int backLight = 13; 

void setup()
{
  pinMode(backLight, OUTPUT);
  digitalWrite(backLight, HIGH); 
  lcd.begin(16,2);             
  lcd.clear();                  
  lcd.setCursor(0,0);          
  lcd.print("Hello, World");  
  lcd.setCursor(0,1);          
  lcd.print("Sunfounder.com");
}

void loop()
{
}

