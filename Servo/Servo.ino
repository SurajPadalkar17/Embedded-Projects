#include <LiquidCrystal.h>

// include servo library
#include <Servo.h>
// name the servo, here Servo is class/
Servo myservo;
int in = 0;
//int pot = A15;

const int rs=8,en=9,d4=10,d5=11,d6=12,d7=13;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);
int F = 2;
void setup() {
  // put your setup code here, to run once:
  myservo.attach(6);
  lcd.begin(16,2);
  Serial.begin(9600);
  pinMode(F,INPUT);
//  pinMode(pot,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
//  int movement = analogRead(pot);
//  movement = map(movement,0,1024,0,180);
  
//  lcd.clear();
//  lcd.print("Servo Angle:");
//  lcd.print(movement);
//  myservo.write(movement);
//  delay(1500);
//Swap();
//    myservo.write(360);
//    Serial.println("360o");
//    delay(1000);
//    myservo.write(180);
//    Serial.println("180o");
//    delay(1000);
//    myservo.write(90);
//    Serial.println("90o");
//    delay(1000);
//    myservo.write(0);
//    Serial.println("0o");
//    delay(1000);

//   int f = digitalRead(F);
//
//   if ((f==1))
//   {
//    t();
//    Serial.println("yo");
//   }
//  

  myservo.write(90);
  delay(1000);
  Serial.println("9o");
  myservo.write(180);
  delay(1000);
  Serial.println("18o");
}

//void Swap()
//{
//  lcd.clear();
//  Serial.println("Swapping ");
// 
//  
//  if ((f==1))
//  {
//      myservo.write(90);
//     
//  }
//}


void t()
{
   for(int i = 90;i<=180;i++)
    {
      myservo.write(i);
      delay(5);
    }
    for(int i = 180;i>=90;i--)
    {
      myservo.write(i);
      delay(5);
    }
}
