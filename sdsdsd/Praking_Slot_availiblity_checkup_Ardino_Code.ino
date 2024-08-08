/* Program for Praking Management.
 *  Discription: Program done to Show the available slots in Parking Yard of 10 Slots.
 * Author: Omkar Malgunde.
 * Guide: Rohan Sir.
 */

#include <LiquidCrystal.h>

int supply = 1;
int in = 2;
int out = 3;
int counter = 10;
bool objectCounted = false; // Flag to track whether an object has been counted

const int rs=8,en=9,d4=10,d5=11,d6=12,d7=13;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);

void setup() {
  // put your setup code here, to run once:
  pinMode(supply, INPUT);
  pinMode(in, INPUT);
  pinMode(out, INPUT);
  lcd.begin(20, 4);
  lcd.clear();
}

void loop() {
  // put your main code here, to run repeatedly:
  int Power = digitalRead(supply);
  int Entry = digitalRead(in);
  int Exit = digitalRead(out);
  if(Power==1)
  {
  
      if (Entry == 1)
      {
       counter = counter -1;
       if(counter<=0)
            {
              counter = 0;
              lcd.setCursor(0,2);
              lcd.print("Parking Full");
              delay(2000);
            }
      }
    
      else //if(Entry==0)
      {
       counter = counter;
      }
      if(Exit==1)
      {
       counter = counter + 1;
        if(counter>=10)
          {
              counter = 10;
          }
       }
    
       else //if(Exit==0)
       {
         counter = counter;
       }
       
       lcd.clear();
       lcd.setCursor(0,0);
       lcd.print("WelCome To Parking");
       lcd.setCursor(0,1);
       lcd.print("Available Slots:");
       lcd.print(counter);
       delay(1500);
    
      
  }
 
  
}
