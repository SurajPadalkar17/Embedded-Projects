#include <Servo.h>          //Servo motor library. This is standard library
#include <NewPing.h>  

//Motor Define
int en1=A0;
int en2=A1;
int mo1=A2;
int mo2=A3;
int mo3=A4;
int mo4=A5; 

int pwm=255;
int pwm1=255;
#define trig_pin 7 //analog input 1

#define echo_pin 8 //analog input 2

#define maximum_distance 200

boolean goesForward = false;

int distance = 100;

NewPing sonar(trig_pin, echo_pin, maximum_distance); 

Servo s1;
void setup() {
pinMode(mo1,OUTPUT);
pinMode(mo2,OUTPUT);
pinMode(mo3,OUTPUT);
pinMode(mo4,OUTPUT);
pinMode(en1,OUTPUT);
pinMode(en2,OUTPUT); 
Serial.begin(9600);
s1.attach(9);
  // put your setup code here, to run once:

  s1.write(90);

  delay(2000);

  distance = readPing();

  delay(100);

  distance = readPing();

  delay(100);

  distance = readPing();

  delay(100);

  //distance = readPing();

  //delay(100);

}

void loop(){

  int distanceRight = 0;

  int distanceLeft = 0;

  delay(50);

  if (distance <= 35){

    br();

    delay(300);

    rv();

    delay(200);

    br();

    delay(300);

    distanceRight = lookRight();

    delay(300);

    distanceLeft = lookLeft();

    delay(300);

    if (distance >= distanceLeft){

      rt();
      delay(500);
      br();
      delay(400);
    }

    else{

      lt();
      delay(500);
      br();
      delay(400);

    }

  }

  else{

    forward();

  }

    distance = readPing();

}

int lookRight(){  

  s1.write(0);

  delay(500);

  int distance = readPing();

  delay(100);

  s1.write(150);

  return distance;

}

int lookLeft(){

  s1.write(180);

  delay(500);

  int distance = readPing();

  delay(100);

  s1.write(90);

  return distance;

  delay(100);

}

int readPing(){

  delay(70);

  int cm = sonar.ping_cm();

  if (cm==0){

    cm=250;

  }

  return cm;

} 

void forward()
{
  if(!goesForward){
  goesForward=true;
  analogWrite(en1,130);
  analogWrite(en2,130);
  digitalWrite(mo1,1);
  digitalWrite(mo2,0);
  digitalWrite(mo3,1);
  digitalWrite(mo4,0);
 
  }
}
  void rv()
{
  goesForward = false;
  analogWrite(en1,pwm);
  analogWrite(en2,pwm1);
  digitalWrite(mo1,0);
  digitalWrite(mo2,1);
  digitalWrite(mo3,0);
  digitalWrite(mo4,1);
  delay(100);
}
  void br()
{
  analogWrite(en1,0);
  analogWrite(en2,0);
  digitalWrite(mo1,0);
  digitalWrite(mo2,0);
  digitalWrite(mo3,0);
  digitalWrite(mo4,0);
  delay(100);
}
  
  void rt()
{
  analogWrite(en1,pwm);
  analogWrite(en2,0);
  digitalWrite(mo1,1);
  digitalWrite(mo2,0);
  digitalWrite(mo3,0);
  digitalWrite(mo4,0);
  }
  void lt()
{
  analogWrite(en1,0);
  analogWrite(en2,pwm);
  digitalWrite(mo1,0);
  digitalWrite(mo2,0);
  digitalWrite(mo3,1);
  digitalWrite(mo4,0);
  }
  void all(){
  analogWrite(en1,pwm);
  analogWrite(en2,pwm1);
  digitalWrite(mo1,0);
  digitalWrite(mo2,1);
  digitalWrite(mo3,1);
  digitalWrite(mo4,0);
  delay(200);
  br();
  delay(200);
  }