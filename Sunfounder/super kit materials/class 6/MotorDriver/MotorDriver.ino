// define PINS and variables
int motor1_enable = 4;
int motor1_pin1   = 3;
int motor1_pin2   = 9;
int motor2_enable = 7;
int motor2_pin1   = 6;
int motor2_pin2   = 5;
int btn_val       = 0;
int pot_val       = 0;
int pot_pin       = 0;
int btn_pin       = 2;
int led_pin       = 13;

void setup() {
  // set all pins
  pinMode(motor1_enable, OUTPUT);
  pinMode(motor2_enable, OUTPUT);
  pinMode(motor1_pin1, OUTPUT);
  pinMode(motor1_pin2, OUTPUT);
  pinMode(motor2_pin1, OUTPUT);
  pinMode(motor2_pin2, OUTPUT);
  pinMode(led_pin, OUTPUT);
  pinMode(pot_pin, INPUT);
  pinMode(btn_pin, INPUT);
  
  // turn motor on
  digitalWrite(motor1_enable, HIGH);
  digitalWrite(motor2_enable, HIGH);
  
  Serial.begin(9600);
}

void loop() {
  pot_val = analogRead(pot_pin); // read out
  
  if(pot_val <32)
  {
    digitalWrite(motor1_enable, LOW);
    digitalWrite(motor2_enable, LOW);
  }
  else
  {
    digitalWrite(motor1_enable, HIGH);
    digitalWrite(motor2_enable, HIGH);
  }
  
  pot_val = map(pot_val, 32, 1023, 64, 254); // map to value 0-254 to use for PWM
     
  btn_val = digitalRead(btn_pin); // get the button value
  if (btn_val == HIGH) {          // check if button is pressed
    digitalWrite(led_pin, LOW);   // turn LED OFF
    analogWrite(motor1_pin1, pot_val); 
    analogWrite(motor1_pin2, LOW);
    analogWrite(motor2_pin1, pot_val);
    analogWrite(motor2_pin2, LOW);
  } else {
    digitalWrite(led_pin, HIGH);  // turn LED ON
    analogWrite(motor2_pin1, pot_val); 
    analogWrite(motor2_pin2, LOW);
    analogWrite(motor1_pin1, LOW);
    analogWrite(motor1_pin2, pot_val);
  }
  
  delay(15);
}
