/*
  Name: CdS_DHT11
  Date: 8/5/14
  Author: Will Streyer
  
  Description: Uses a CdS photoresistor to determine light level.
  CdS is paired with resistor, R1, as shown below.
  
  SCHEMATIC of CdS Light Sensor
  ====================================            
  | +5 |----(CdS)----{R1}----|> GND  |
  |           ^^   |______|          |
  |           ||  Analog Input       |
  |           hv                     |
  |                                  |
  |          R1 = 33k Ohm            |
  ====================================
  -Analog input is sent to serial output.
  
  -Additionally, a DHT11 digital temperature and humidity sensor is attached to pin 2

  The temperature, humidity, and light level are displayed on a Liquid Crystal Display
 */

//Include the dht11 code
#include <dht11.h>

//include the LCD code:
#include <LiquidCrystal.h>

#include <math.h>

//initialize an instance of the dht11 entity
dht11 DHT11;

//Set pin numbers for CdS light sensor
const int CdS = A0;

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

//Initialize values to read and display dht11 data
int sensorValue = 0;        // value read from the pot
float outputValue = 0;        // value output to the PWM (analog out)

void setup()
{
//  //Open serial port
//  Serial.begin(9600);
//  Serial.print("CdS Photoresistor Light Sensor and");
//  Serial.println("DHT11 Digital Humidity and Temperature Sensor");
  
  // set up the LCD's number of columns and rows: 
  lcd.begin(16, 2);
   
  // Print a message to the LCD.
  lcd.print(" CdS_DHT11_LCD");
  delay(3000);  
  
  //Connect dht11 to digital pin 2
  DHT11.attach(7);
}

void loop()
{
  //Update after 1 seconds
  delay(1000);
  
  // read the analog in light sensor value:
  sensorValue = analogRead(CdS); 
  
  // map it to a percent value:
  outputValue = map(sensorValue, 0, 1023, 0, 10000);
  float logVal = log10(outputValue)/4;
  
  // print the ambient light level
  lcd.setCursor(0,0);
  lcd.print("Light:          " );                       
  lcd.setCursor(7,0);
  lcd.print(logVal);
  //lcd.print("% " );
  
  //Read DHT11 Output
  DHT11.read();
  
  //Print the humidity
  lcd.setCursor(0,1);
  lcd.print(" RH: ");
  lcd.print(DHT11.humidity);
  lcd.print("% " );
 
  //Print the temperature 
  lcd.print("T: ");
  lcd.print(DHT11.temperature);
  lcd.print("C");
}
