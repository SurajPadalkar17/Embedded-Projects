#include <LiquidCrystal.h>

// Water Tank Level Detector
// Top: Display Top level, Motor OFF and ON Red led.
// Middle: Display Middle level and ON Yellow led.
// Bottom: Display Bottom level, Motor ON and ON Green led.

int Bottom = 1;
int Middle = 2;
int Top = 3;
int Green = 4;
int Yellow = 5;
int Red = 6;
//int Buzzer=15;

const int rs=8, en=9, d4=10, d5=11, d6=12, d7=13;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);
  pinMode(Bottom,INPUT);
  pinMode(Middle,INPUT);
  pinMode(Top,INPUT);
  pinMode(Green,OUTPUT);
  pinMode(Yellow,OUTPUT);
  pinMode(Red,OUTPUT);
 // pinMode(Buzzer,OUTPUT);
  lcd.clear();
  lcd.print("Water Tank Level");
  lcd.setCursor(0,1);
  lcd.print("Idicator");
  delay(1500);
  
}


void loop() {
  
  // put your main code here, to run repeatedly:
  int b1 = digitalRead(Bottom);
  int m1 = digitalRead(Middle);
  int t1 = digitalRead(Top);

  if(b1==1 && m1==0 && t1==0)
  {
    digitalWrite(Green,1);
    digitalWrite(Yellow,0);
    digitalWrite(Red,0);
    delay(1000);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Bottom Level");
    lcd.setCursor(0,1);
    lcd.print("Motor ON");
    delay(1500);
  }

  else if(b1==1 && m1==1 && t1==0)
  {
    
    digitalWrite(Green,0);
    digitalWrite(Yellow,1);
    digitalWrite(Red,0);
    delay(1000);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Middle Level");
    //Serial.println("Motor ON");
    delay(1500);
  }

  else if(b1==1 && m1==1 && t1==1)
  {
    digitalWrite(Green,0);
    digitalWrite(Yellow,0);
    digitalWrite(Red,1);
    delay(1000);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Top Level");
    lcd.setCursor(0,1);
    lcd.print("Motor OFF");
    tone(15,1000,500);
    delay(1500);
    
   // digitalWrite(Buzzer,1); // tone is used for buzzer.
   // delay(1000);
   // digitalWrite(Buzzer,0)
  }

  else
  {
    digitalWrite(Green,0);
    digitalWrite(Yellow,0);
    digitalWrite(Red,0);
  }
}
