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

  The temperature, humidity, and light level is written to the serial port and displayed on the serial monitor
 */

//Include the dht11 code
#include <dht11.h>

//initialize an instance of the dht11 entity
dht11 DHT11;

//Set pin numbers for CdS light sensor
const int CdS = A0;

//Initialize values to read and display dht11 data
int sensorValue = 0;        // value read from the pot
int outputValue = 0;        // value output to the PWM (analog out)

void setup()
{
  //Open serial port
  Serial.begin(9600);
  Serial.print("CdS Photoresistor Light Sensor and");
  Serial.println("DHT11 Digital Humidity and Temperature Sensor");
  
  //Connect dht11 to digital pin 2
  DHT11.attach(2);
}

void loop()
{
  Serial.println("\n");
  
  // read the analog in light sensor value:
  sensorValue = analogRead(CdS); 
  
  // map it to a percent value:
  outputValue = map(sensorValue, 0, 1023, 0, 100);
  
  // print the ambient light level
  Serial.print("Ambient Light = " );                       
  Serial.print(outputValue);
  Serial.println(" %" );
  
  //Read DHT11 Output
  DHT11.read();
  
  //Print the humidity
  Serial.print("Humidity (%): ");
  Serial.println((float)DHT11.humidity, DEC);
 
  //Print the temperature 
  Serial.print("Temperature (°C): ");
  Serial.println((float)DHT11.temperature, DEC);
  
  //Update after 2 seconds
  delay(2000);
}
