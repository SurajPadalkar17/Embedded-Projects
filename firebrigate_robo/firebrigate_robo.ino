#include<Servo.h>
#define leftMotorspeed 100
#define rightMotorspeed 100
#define trig_pin 7 
#define echo_pin 8

// dc motor wheels
int en1=A0;
int mo1=A1;
int mo2=A2;
int mo3=A3;
int mo4=A4;
int en2=A5; 

// Flame sensor 
int sf=3;
int sr=4;
int sl=5;
int sb=6;

Servo s1;
Servo s2;

int f,b,l,r; // variable to digitally read  flame detection sensors

void forward()
{
  analogWrite(en1,leftMotorspeed);
  analogWrite(en2,rightMotorspeed);
  digitalWrite(mo1,1);
  digitalWrite(mo2,0);
  digitalWrite(mo3,1);
  digitalWrite(mo4,0);
}
  
void backward()
{
  analogWrite(en1,leftMotorspeed);
  analogWrite(en2,rightMotorspeed);
  digitalWrite(mo1,0);
  digitalWrite(mo2,1);
  digitalWrite(mo3,0);
  digitalWrite(mo4,1);
}
void left()
{
  analogWrite(en1,leftMotorspeed);
  analogWrite(en2,rightMotorspeed);
  digitalWrite(mo1,0);
  digitalWrite(mo2,0);
  digitalWrite(mo3,1);
  digitalWrite(mo4,0);
}
void right()
{
  analogWrite(en1,leftMotorspeed);
  analogWrite(en2,rightMotorspeed);
  digitalWrite(mo1,1);
  digitalWrite(mo2,0);
  digitalWrite(mo3,0);
  digitalWrite(mo4,0);
}
void brake()
{
  analogWrite(en1,0);
  analogWrite(en2,0);
  digitalWrite(mo1,0);
  digitalWrite(mo2,0);
  digitalWrite(mo3,0);
  digitalWrite(mo4,0);
}

void setup() {
  // put your setup code here, to run once:
pinMode(mo1,OUTPUT);
pinMode(mo2,OUTPUT);
pinMode(mo3,OUTPUT);
pinMode(mo4,OUTPUT);
pinMode(en1,OUTPUT);
pinMode(en2,OUTPUT); 
pinMode(sf,INPUT); 
pinMode(sr,INPUT);
pinMode(sl,INPUT);
pinMode(sb,INPUT);
pinMode(trig_pin,OUTPUT);
pinMode(echo_pin,INPUT);
s1.attach(10);
s2.attach(11);
s1.write(90);
s2.write(90);
Serial.begin(9600);
}

void forward_pump(){
  f = digitalRead(sf);
  l = digitalRead(sl);
  r = digitalRead(sr);
 //no flame
  if(f==0 &&  l==0 && r==0)
  {
    Serial.println("no flame ditected");
    s1.write(90);
    forward();
  }
  //forward
  else if (f==1 &&  l==0 && r==0)
  {
    brake();
    s1.write(90);
    Serial.print("Forward pump1 on");
    delay(100);
  }
  //left
  else if (f==0  && l==1 && r==0)
  {
    brake();
      s1.write(0);
      Serial.println("pump1 on");
  }
  //right
 else if (f==0 &&  l==0 && r==1)
  {
    brake();
    s1.write(180);
    Serial.print("pump1 on");
    }

    //forward and left
  else if (f==1 &&  l==1 && r==0)
  {
   Serial.println("pump1 on");
   for(int i=90;i>0;i--){
    s1.write(i);
   }
   for(int i=0;i<90;i++){
    s1.write(i);
   }
  }
 //forward and right
   else if (f==1 && l==0 && r==1)
  {
   Serial.println("pump1 on");
   for(int i=90;i<180;i++){ 
    s1.write(i);
    }
   for(int i=180;i>90;i--){
    s1.write(i);
   }
  }
}

void backward_pump(){
  b = digitalRead(sb);
  l = digitalRead(sl);
  r = digitalRead(sr);
 //no flame
  if(b==0 &&  l==0 && r==0)
  {
    Serial.println("no flame ditected");
    s1.write(90);
    forward();
  }
  //backward
  else if (b==1 &&  l==0 && r==0)
  {
    brake();
    s2.write(90);
    Serial.print("Backward pump2 on");
    delay(100);
  }
  //left
  else if (b==0  && l==1 && r==0)
  {
    brake();
      s2.write(180);
      Serial.println("pump2 on");
  }
  //right
 else if (b==0 &&  l==0 && r==1)
  {
    brake();
    s2.write(0);
    Serial.print("pump2 on");
    }

    //backward and left
  else if (b==1 &&  l==1 && r==0)
  {
   Serial.println("pump2 on");
   for(int i=90;i<=180;i++){
    s2.write(i);
   }
   for(int i=180;i<=90;i--){
    s2.write(i);
   }
  }
 //Backward and right
   else if (b==1 && l==0 && r==1)
  {
   Serial.println("pump1 on");
   for(int i=90;i>=0;i--){ 
    s2.write(i);
    }
   for(int i=0;i<=90;i++){
    s2.write(i);
   }
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  forward_pump();
  backward_pump();
}