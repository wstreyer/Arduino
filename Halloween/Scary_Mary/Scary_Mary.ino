//Pins to control Scary Mary
const int rightEye = A2;
const int leftEye = 3;
const int flash = 67;

// the setup function runs once when you press reset or power the board
void setup()
{
  // initialize Scary_Eyes pins
  pinMode(rightEye, OUTPUT);
  pinMode(leftEye, OUTPUT);
}

// the loop function runs over and over again forever
void loop()
{
    digitalWrite(rightEye, HIGH);
    digitalWrite(leftEye, HIGH);
    delay(flash);
  
    digitalWrite(rightEye, LOW);
    digitalWrite(leftEye, LOW);
    delay(flash);
    
    digitalWrite(rightEye, HIGH);
    digitalWrite(leftEye, HIGH);
    delay(flash);

    digitalWrite(rightEye, LOW);
    digitalWrite(leftEye, LOW);
    delay(flash);

    digitalWrite(rightEye, HIGH);
    digitalWrite(leftEye, HIGH);
    delay(flash);

    digitalWrite(rightEye, LOW);
    digitalWrite(leftEye, LOW);
    delay(flash);

    digitalWrite(rightEye, HIGH);
    digitalWrite(leftEye, HIGH);
    delay(flash);

    digitalWrite(rightEye, LOW);
    digitalWrite(leftEye, LOW);
    delay(flash);  

    digitalWrite(rightEye, HIGH);
    digitalWrite(leftEye, HIGH);
    delay(15000);
    
    digitalWrite(rightEye, LOW);
    digitalWrite(leftEye, LOW);
    delay(5000);
}
