/***************************************************
Project: Smart Dustbin  
Organisation: Soham Academy Of Human Excellence
Website: https://ria.sohamacademy.org/
****************************************************/

#include <Servo.h>
Servo servoMain;
int trigpin = 10;
int echopin = 11;
int distance; 
float duration;
float cm;

void setup()
{
   servoMain.attach(9); // servo on digital pin 10
   pinMode(trigpin, OUTPUT);
   pinMode(echopin, INPUT);
   Serial.begin(9600);
}

void loop()
{ 
  digitalWrite(trigpin, LOW);
  delay(2);  
  digitalWrite(trigpin, HIGH);
  delayMicroseconds(10);  
  digitalWrite(trigpin, LOW);  
  duration = pulseIn(echopin, HIGH);  
  cm = (duration/58.82);
  distance = cm;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if(distance<30)
  {
    servoMain.write(180);  
    delay(1000); 
  }
  else{
    servoMain.write(0);
    delay(50);
  }
}
