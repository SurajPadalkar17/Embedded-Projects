#include <LiquidCrystal.h>

// DC Motor 

int S1=2;
int S2=4;
int S3=7;
int S4=8;
int En1=10;
int En2=11;

void setup() {
  // put your setup code here, to run once:
  pinMode(S1,OUTPUT);
  pinMode(S2,OUTPUT);
  pinMode(S3,OUTPUT);
  pinMode(S4,OUTPUT);
  pinMode(En1,INPUT);
  pinMode(En2,INPUT);
  Serial.begin(9600);
}

void forward()
{ 
  //Control();
  analogWrite(En1,130);
  analogWrite(En2,130);
  digitalWrite(S1,1);
  digitalWrite(S2,0);
  digitalWrite(S3,1);
  digitalWrite(S4,0);
}

void backward()
{
  analogWrite(En1,130);
  analogWrite(En2,250);
  digitalWrite(S1,0);
  digitalWrite(S2,1);
  digitalWrite(S3,0);
  digitalWrite(S4,1);
  
}
void Stop()
{
  digitalWrite(S1,0);
  digitalWrite(S2,0);
  digitalWrite(S3,0);
  digitalWrite(S4,0);
}

void Control()
{
  for(int i=0;i<=255;i++)
  {
    analogWrite(En1,i);
    analogWrite(En2,i);
    Serial.println(i);
    delay(200);
  }

}
void loop() {
  // put your main code here, to run repeatedly:
//  forward();
  
  //Stop();
  //delay(2000);
  //backward();
  //delay(5000);
 // Stop();
 // delay(2000);

  analogWrite(En1,20);
  analogWrite(En2,20);
  digitalWrite(S1,1);
  digitalWrite(S2,0);
  digitalWrite(S3,1);
  digitalWrite(S4,0);

  
}
