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

//LCD control pins
const int buttonPin = 2;
const int lcdPin =  8;

//LM34 DZ analog pin
const int LM34 = A3;

// variables will change:
boolean buttonState = false;         // variable for reading the pushbutton status

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 6);

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
  
  //configure lcd control pins
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(lcdPin, OUTPUT);
   
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
  delay(500);
  
  //Turn LCD off/on
  //read the pushbutton value into a variable
  if (!digitalRead(buttonPin))
  {
    buttonState = !buttonState;
  }
  
  if (buttonState == HIGH)
  {
    digitalWrite(lcdPin, LOW);
  } 
  else
  {
    digitalWrite(lcdPin, HIGH);
    lcd.begin(16, 2);
  }
  
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
  
  // print the ambient light level
  lcd.setCursor(0,0);
  lcd.print("L: " );                       
  lcd.print(round(outputValue));
  lcd.print("% " );
  
  //Print the BMP180 pressure and temperature
  Serial.print(hPa);  
  Serial.print(",");
  Serial.print(temperature);
  Serial.print(",");
  
  /* Display atmospheric pressue in hPa */
  lcd.setCursor(7,0);
  lcd.print("P: ");
  lcd.print(round(event.pressure));
  lcd.println("hPa");
  
  //Read DHT11 Output
  DHT11.read();
 
  //Print the DNHT11 humidity and temperature
  Serial.print((float)DHT11.humidity, 2);
  Serial.print(",");
  Serial.print((float)DHT11.fahrenheit(), DEC);
  Serial.print(",");
  
  //Print the humidity
  lcd.setCursor(0,1);
  lcd.print(" RH: ");
  lcd.print(DHT11.humidity);
  lcd.print("% " );
  
  //Print the temperature 
  lcd.print("T: ");
  lcd.print((float)DHT11.fahrenheit(), 0);
  lcd.print("F");
  
  //Read LM34 DZ temperature
  int LM34Temp = map(analogRead(LM34), 0, 1023, 0, 5000);
  Serial.println("");
  Serial.print(LM34Temp/10);
  Serial.println(""); 
}
