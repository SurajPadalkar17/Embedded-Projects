#include <SoftwareSerial.h>
#define BLYNK_PRINT Serial
#include <SPI.h>
#include <Servo.h>
Servo myservo;
//#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>



#define echoPin D6 
#define trigPin D7
long duration; 
int distance;
int buzzer=D0;


void setup() {
  // put your setup code here, to run once:
pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
pinMode(echoPin, INPUT);
//pinMode(D8,INPUT);
pinMode(buzzer,OUTPUT);
myservo.attach(D5);
  Serial.begin(9600);
  Serial.println();
  
  //timer.setInterval(1000L, checkGPS); 
}

void loop() {
  // put your main code here, to run repeatedly:
   
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
     distance = duration * 0.034 / 2;
    Serial.print("Distance:");
    Serial.println(distance);
   // Blynk.virtualWrite(V8,distance); 
   if(distance>15)
   {
    myservo.write(180);
    digitalWrite(buzzer,1);
   delay(500);
   digitalWrite(buzzer,0);
   delay(500);
   digitalWrite(buzzer,1);
   delay(500);
   digitalWrite(buzzer,0);
   delay(500);
    }
    else
    {
      myservo.write(0);
      }
   
}
