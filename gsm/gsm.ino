int fire=2;
int buzzer=3;
int fireindication=4;
int smsled=5;
#include <SoftwareSerial.h>
SoftwareSerial SIM900(7,8); //(tx rx)
 
void setup() {
  // put your setup code here, to run once:
pinMode(fire,INPUT);
pinMode(buzzer,OUTPUT);
pinMode(fireindication,OUTPUT);
pinMode(smsled,OUTPUT);
SIM900.begin(19200);
 delay(1000);
}

void loop() {
 if (digitalRead(fire)==0)
  {
    digitalWrite(buzzer,HIGH);
    delay(500);
    digitalWrite(buzzer,LOW);
    delay(500);
    digitalWrite(buzzer,HIGH);
    delay(500);
    digitalWrite(buzzer,LOW);
    delay(500);
    digitalWrite(fireindication,HIGH);
    sendSMS();
    
    }
    else
    {
       digitalWrite(buzzer,LOW);
    digitalWrite(fireindication,LOW);
      }
 

}
void sendSMS() 
{
  // AT command to set SIM900 to SMS mode
  SIM900.print("AT+CMGF=1\r"); 
  delay(100);

  // REPLACE THE X's WITH THE RECIPIENT'S MOBILE NUMBER
  // USE INTERNATIONAL FORMAT CODE FOR MOBILE NUMBERS
  SIM900.println("AT+CMGS=\"+919637431966\""); 
  delay(100);
  
  // REPLACE WITH YOUR OWN SMS MESSAGE CONTENT
  SIM900.println("http://maps.google.com/maps?&z=15&mrt=yp&t=k&q="); 
  delay(100);

  // End AT command with a ^Z, ASCII code 26
  SIM900.println((char)26); 
  delay(100);
  SIM900.println();
  
  // Give module time to send SMS
  delay(5000); 
  digitalWrite(smsled,1);
  delay(1000);
digitalWrite(smsled,0);
delay(1000);

 
}
