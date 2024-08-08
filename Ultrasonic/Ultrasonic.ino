#include <LiquidCrystal.h>


int trig = 2;
int echo = 3;
const int rs=8, en=9, d4=10, d5=11, d6=12, d7=13;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);


void setup() {
  // put your setup code here, to run once:
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  lcd.begin(16,2);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  long duration;
  int Distance;
  float inch,foot;

  digitalWrite(trig,0);
  delayMicroseconds(2);
  digitalWrite(trig,1);
  delayMicroseconds(10);
  digitalWrite(trig,0);

  duration = pulseIn(echo,1);
  delay(1000);
  Distance = duration*0.034/2;
  inch = Distance*0.3937;
  foot = Distance*0.0328;

  
  Serial.println("Distance In : ");
  Serial.println("cm \t inch \t foot");
  Serial.print(Distance );
  Serial.print("\t");
  Serial.print(inch);
  Serial.print("\t"); 
  Serial.print(foot);
  Serial.print("\t");
  

  lcd.clear();
  lcd.print("cm \t inch \t foot");
  lcd.setCursor(0,1);
  lcd.print(Distance);
  lcd.print("\t");
  lcd.print(inch);
  lcd.print("\t");
  lcd.print(foot);
  lcd.print("\t");
  
}
