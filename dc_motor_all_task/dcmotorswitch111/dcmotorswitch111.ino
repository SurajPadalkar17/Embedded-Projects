#include <LiquidCrystal.h>


int in1 = 1;
int in2 = 2;
int in3 = 3;
int in4 = 4;
int obs = 14;
int nobs = 15;
int buzzer=15;
const int rs=8,en=9,d4=10,d5=11,d6=12,d7=13;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);




void setup() {
  // put your setup code here, to run once:
  pinMode(obs,INPUT);
  pinMode(nobs,INPUT);
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);
  pinMode(buzzer,OUTPUT);
  lcd.begin(16,2);
}

void forward()
{

 // digitalWrite(in1,150);//for 150 rpm
  //digitalWrite(in3,150);
  
  digitalWrite(in1,1);
  digitalWrite(in2,0);
  digitalWrite(in3,1);
  digitalWrite(in4,0);
 }
void backward()
{
 
   //digitalWrite(in1,150);
   //digitalWrite(in3,150);
   digitalWrite(in1,0);
   digitalWrite(in2,1);
   digitalWrite(in3,0);
   digitalWrite(in4,1);
  

}
void stop()
{
   digitalWrite(in1,0);
   digitalWrite(in2,0);
   digitalWrite(in3,0);
   digitalWrite(in4,0);

}

void loop() {
  // put your main code here, to run repeatedly:
 //control();
 int b1=digitalRead(obs);
 int b2=digitalRead(nobs);
 int obs=1;
 int nobs=0;
 forward();
 delay(1000);

  if(b1==1&&b2==0)
   {
    digitalWrite(obs,1);
    //stop();
    //delay(1000);
    
    lcd.clear();
    lcd.print("Obstacle come:");
    tone(15,1000,50);
    delay(1000);
    stop();
    lcd.clear();
    lcd.print("motor stop");
    delay(1000);
    lcd.clear();
    lcd.print("moveleftside:");
    digitalWrite(in1,0);
    digitalWrite(in2,0);
    digitalWrite(in3,1);
    digitalWrite(in4,0);
    delay(6000);
    forward();
    delay(1000);
    lcd.clear();
    lcd.print("motor stop");
    stop();
    delay(1000);
    lcd.clear();
    lcd.print("Move forward side:");
    forward();
    delay(2000);
    lcd.clear();
    lcd.print("motor stop");
    stop();
    delay(1000);
    lcd.clear();
    lcd.print("Move right side:");
    digitalWrite(in1,1);
    digitalWrite(in2,0);
    digitalWrite(in3,0);
    digitalWrite(in4,0);
    delay(6000);
    lcd.clear();
    lcd.print("motor stop");
    stop();
    delay(1000);
    lcd.clear();
    lcd.print("Move forward side:");
    forward();
    delay(1000);

   }
   else
   {
     digitalWrite(nobs,1);
     lcd.clear();
    lcd.print("no obstacle");
    forward();
    delay(1000);
   }
 //forward();
 //delay(2000);
 //backward();
 //delay(2000);
 //stop();
 //delay(2000);

}
