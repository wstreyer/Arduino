//LM34 DZ analog pin
const int LM34 = A3;

//Initialize values to read and display dht11 data
int sensorValue = 0;        // value read from the pot
float outputValue = 0;        // value output to the PWM (analog out)

void setup()
{
  //Open serial port
  Serial.begin(9600);
}

void loop()
{
  //Update after 1 seconds
  delay(250);
  
  //Read LM34 DZ temperature
  sensorValue = analogRead(LM34);
  outputValue = map(sensorValue, 0, 1023, 0, 500);
  Serial.println(outputValue);  
}
