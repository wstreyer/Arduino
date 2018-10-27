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
  
  -Additionally, a DHT11 digital temperature and humidity sensor is attached to pin 7
  
  -Attached an Adafruit BMP180 to A4 and A5 for barametric pressure, temperature and altitude

  The temperature, humidity, and light level are displayed on a Liquid Crystal Display
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

//Initialize values to read and display dht11 data
int sensorValue = 0;        // value read from the pot
float outputValue = 0;        // value output to the PWM (analog out)

void setup()
{
  //Open serial port
  Serial.begin(9600);
  Serial.println("CdS Photoresistor Light Sensor and");
  Serial.println("DHT11 Digital Humidity and Temperature Sensor");
     
  //Connect dht11 to digital pin 
  DHT11.attach(7); 
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
    Serial.print("something");
  }
  else
  {
    
  }
  // read the analog in light sensor value:
  sensorValue = analogRead(CdS); 
  
  // map it to a percent value:
  int outputValue = round(map(sensorValue, 0, 1023, 0, 100));
  
  // print the ambient light level
  Serial.print("Light: ");  
  Serial.print(outputValue);
  Serial.println("%");
  
  Serial.print("Pressure: ");
  Serial.print(hPa);
  Serial.print(" hPa");
  
  
  //Read DHT11 Output
  DHT11.read();
  
  //Print the humidity
  Serial.print("Humidity: ");
  Serial.print(DHT11.humidity);
  Serial.println(" %");
 
  //Print the temperature 
  Serial.print("Temperature: ");
  Serial.print(DHT11.temperature);
  Serial.println(" *C"); 
  
}
