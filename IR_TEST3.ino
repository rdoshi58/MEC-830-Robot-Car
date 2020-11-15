

#include "IRremote.h"

int IRpin = 13;  // pin for the IR sensor
#define Button_1 0xFF629D
#define Button_2 0xFFA857
int speedPin=5;
int dir1=4;
int dir2=3;
int mSpeed=255;
int nSpeed=0;
IRrecv irrecv(IRpin);
decode_results results;


void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  pinMode(speedPin, OUTPUT);
  pinMode(dir1, OUTPUT);
  pinMode(dir2, OUTPUT);
}

void loop() 
{
   
  if (irrecv.decode(&results)) 
    {
      
      irrecv.resume();   // Receive the next value
    }
  
  if (results.value==0xFF629D)
 {
 digitalWrite(dir1, HIGH);
 digitalWrite(dir2, LOW);
 analogWrite(speedPin,mSpeed);
 delay(1000);
 }
  else  {
 digitalWrite(dir1, HIGH);
 digitalWrite(dir2, LOW);
 analogWrite(speedPin,nSpeed);
 delay(1000);
  }
 }
