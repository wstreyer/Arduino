int i,j,segment[10]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x27,0x7f,0x67};

void setup()   {

 for(i=0;i<14;i++){
 pinMode(i, OUTPUT);
 }
}

void loop()
{
 for(i=0;i<10;i++){
   for(j=0;j<10;j++){
     int analogValue = constrain(analogRead(0),50,750);
     digitalWrite(0, ((segment[i]&0x01))?HIGH:LOW);
     digitalWrite(1, ((segment[i]&0x02))?HIGH:LOW);
     digitalWrite(2, ((segment[i]&0x04))?HIGH:LOW);
     digitalWrite(3, ((segment[i]&0x08))?HIGH:LOW);
     digitalWrite(4, ((segment[i]&0x10))?HIGH:LOW);
     digitalWrite(5, ((segment[i]&0x20))?HIGH:LOW);
     digitalWrite(6, ((segment[i]&0x40))?HIGH:LOW);
     digitalWrite(7, ((segment[j]&0x01))?HIGH:LOW);
     digitalWrite(8, ((segment[j]&0x02))?HIGH:LOW);
     digitalWrite(9, ((segment[j]&0x04))?HIGH:LOW);
     digitalWrite(10, ((segment[j]&0x08))?HIGH:LOW);
     digitalWrite(11, ((segment[j]&0x10))?HIGH:LOW);
     digitalWrite(12, ((segment[j]&0x20))?HIGH:LOW);
     digitalWrite(13, ((segment[j]&0x40))?HIGH:LOW);
     delay(analogValue);
     }
   }
}

