/*
Adafruit Arduino - Lesson 10. Simple Sounds
*/
 
//int speakerPin = 6;
//int delayTime = 1000;
// 
//int numTones = 10;
//int tones[] = {261, 277, 294, 311, 330, 349, 370, 392, 415, 440};
////            mid C  C#   D    D#   E    F    F#   G    G#   A
// 
//void setup()
//{
//  for (int i = 0; i < numTones; i++)
//  {
//    tone(speakerPin, tones[i]*70);
//    delay(delayTime);
//  }
//  noTone(speakerPin);
//}
// 
//void loop()
//{
//}

/*
Adafruit Arduino - Lesson 10. Pseudo Thermin
*/
 
int speakerPin = 6;
int photocellPin = 0;
 
void setup()
{
}
 
void loop()
{
  int reading = analogRead(photocellPin);
  int pitch = 200 + reading;
  tone(speakerPin, pitch);
}
