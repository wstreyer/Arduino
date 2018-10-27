/*
  Name: CdS_DHT11_BMP180_File
  Date: 10/22/14
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
  
  -Additionally, a DHT11 digital temperature and humidity sensor is attached to pin 7
  
  -Attached an Adafruit BMP180 to A4 and A5 for barametric pressure, temperature and altitude

  The temperature (From DHT11 and BMP180), pressure, humidity, and light level are sent to the serial port in CSV format.
 */

//Include the dht11 code
#include <dht11.h>

//include the LCD code:
#include <LiquidCrystal.h>

//include the math library
#include <math.h>

//include BMP180 libraries
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP085_U.h>

//Initialize the BMP180 sensor entity
Adafruit_BMP085_Unified bmp = Adafruit_BMP085_Unified(10085);
float hPa = 101;

//initialize an instance of the dht11 entity
dht11 DHT11;

//Set pin numbers for CdS light sensor
const int CdS = A0;

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

//Initialize values to read and display dht11 data
int sensorValue = 0;        // value read from the pot
float outputValue = 0;        // value output to the PWM (analog out)

//Initialize BMP180 temperature value
float temperature;

void setup()
{
  //Open serial port
  Serial.begin(9600);
  
  // set up the LCD's number of columns and rows: 
  lcd.begin(16, 2);
   
  // Print a message to the LCD.
  lcd.print("CdS_DHT11_BMP180");
  delay(3000);
       
  //Connect dht11 to digital pin 
  DHT11.attach(7);
 
  //Initialize BMP180
  bmp.begin();
}

void loop()
{
  //Update after 1 seconds
  delay(1000);
  
  // print pressure value
  sensors_event_t event;
  bmp.getEvent(&event);
  if (event.pressure)
  {
    hPa = event.pressure;
    bmp.getTemperature(&temperature);
  }
  
  // read the analog in light sensor value:
  sensorValue = analogRead(CdS); 
  
  // map it to a percent value:
  int outputValue = round(map(sensorValue, 0, 1023, 0, 100));
  
  // print the ambient light level
  Serial.print(outputValue);
  Serial.print(",");
  
  //Print the BMP180 pressure and temperature
  Serial.print(hPa);  
  Serial.print(",");
  Serial.print(temperature);
  Serial.print(",");
  
  //Read DHT11 Output
  DHT11.read();
 
  //Print the DNHT11 humidity and temperature
  Serial.print((float)DHT11.humidity, 2);
  Serial.print(",");
  Serial.print((float)DHT11.fahrenheit(), DEC);
  Serial.println("");
}
