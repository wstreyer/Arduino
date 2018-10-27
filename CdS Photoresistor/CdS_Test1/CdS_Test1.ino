/*
  Name: CdS_Test1
  Date: 8/5/14
  Author: Will Streyer
  
  Description: Uses a CdS photoresistor to determine light level.
  CdS is paired with resistor, R1, as shown below.
              
  +5 |----(CdS)----{R1}----|> GND
            ^^   |______|
            ||  Analog Input
            hv
  R1 = 33k Ohm
  
  Analog input is sent to serial output.
 */

const int CdS = A0;

int sensorValue = 0;        // value read from the pot
int outputValue = 0;        // value output to the PWM (analog out)


void setup()
{
  Serial.begin(9600);
  Serial.println("CdS Photoresistor Light Sensor");
}

void loop()
{
  Serial.println("\n");

  // read the analog in value:
  sensorValue = analogRead(CdS); 
  
  // map it to a percent value:
  outputValue = map(sensorValue, 0, 1023, 0, 100);
  
  // print the results to the serial monitor:
  Serial.print("Ambient Light = " );                       
  Serial.print(outputValue);
  Serial.println(" %" );
  
  delay(2000);
}
