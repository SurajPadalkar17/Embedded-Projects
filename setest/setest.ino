//#include <Servo.h>

//Servo myservo;

int S1=2;
int S2=4;
int En1=5;
int En2=6;

void setup() {
  // put your setup code here, to run once:
//myservo.attach(7);
 pinMode(S1,OUTPUT);
 pinMode(S2,OUTPUT);
 pinMode(En1,INPUT);
 pinMode(En2,INPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
//myservo.write(90);
analogWrite(En1,50);
analogWrite(En2,50);
digitalWrite(S1,1);
digitalWrite(S2,0);
Serial.println("working");
}
