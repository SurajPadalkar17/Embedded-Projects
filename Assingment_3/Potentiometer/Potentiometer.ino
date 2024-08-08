#include <LiquidCrystal.h>


int Pot=A0;
const int rs=8,en=9,d4=10,d5=11,d6=12,d7=13;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);

void setup() {
  // put your setup code here, to run once:
  pinMode(Pot,INPUT);
  lcd.begin(16,2);
  lcd.clear();
 }

void loop() {
  // put your main code here, to run repeatedly:
  int result= analogRead(Pot);
  //Map() funtion is used for Mapping. For user difine range.
  int res = map(result,0,1024,0,255);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Pot Value:");
  lcd.setCursor(10,0);
  lcd.println(result);
 // delay(1500);
  lcd.setCursor(0,1);
  lcd.print("Map Value:");
  lcd.setCursor(10,1);
  lcd.print(res);
  delay(1500);
  
}
