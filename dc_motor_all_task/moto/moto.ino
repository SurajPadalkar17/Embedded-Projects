#include <LiquidCrystal.h>

#include<Servo.h>


int pot =A7;
Servo myServo;
const int rs=13,en=12,d4=11,d5=10,d6=9,d7=8;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);

void setup() {
  // put your setup code here, to run once:
 myServo.attach(2);
 pinMode(pot,INPUT);
 lcd.begin(16,2);

}

void loop() {
  // put your main code here, to run repeatedly:
  int moment = analogRead(pot);
  moment = map(moment,0,1024,0,180);
  
  lcd.clear();
  lcd.print("Servo Angle:");
  lcd.print(moment);
  delay(1500);
  myServo.write(moment);
  delay(10);
}
