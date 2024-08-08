#include <Servo.h>
Servo my;
int button = 1;
int button2 = 2;


void setup() {
  // put your setup code here, to run once:
  pinMode(button,INPUT);
  pinMode(button2,INPUT);
  my.attach(8);
  Serial.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:

  int r = digitalRead(button);
  int r2 = digitalRead(button2);
  my.write(0);
  if(r == 1 || r2 == 1){
    //digitalWrite(bulb,1);
    my.write(0);
    delay(1000);
  }
  else
  {
    my.write(90);
    delay(1000);
  }
}

//void open()
//{
//
//  for (int pos = 0; pos <= 90; pos++) 
//  { 
//    my.write(pos);              // tell servo to go to position in variable 'pos'
//    delay(15);                       // waits 15ms for the servo to reach the position
//  }
//}
//
//void close()
//{
//  for (int pos = 90; pos >= 0; pos--) 
//  { 
//    my.write(pos);              // tell servo to go to position in variable 'pos'
//    delay(15);                       // waits 15ms for the servo to reach the position
//  }                       // waits 15ms for the servo to reach the position 
//}
