//#include<Keypad.h>

// This file contains predefined setup for various Adafruit Matrix Keypads.
//#ifndef __KEYPAD_CONFIG_H__
#define __KEYPAD_CONFIG_H__

#if defined(KEYPAD_PID3844)
const byte ROWS = 4; // rows
const byte COLS = 4; // columns
// define the symbols on the buttons of the keypads
char keys[ROWS][COLS] = {{'1', '2', '3', 'A'},
                         {'4', '5', '6', 'B'},
                         {'7', '8', '9', 'C'},
                         {'*', '0', '#', 'D'}};
byte rowPins[ROWS] = {R1, R2, R3,
                      R4}; // connect to the row pinouts of the keypad
byte colPins[COLS] = {C1, C2, C3,
                      C4}; // connect to the column pinouts of the keypad
//#endif

#include<LiquidCrystal.h>
#include<EEPROM.h>
LiquidCrystal lcd(A0,A1,A2,A3,A4,A5);
char password[4];
char pass[4],pass1[4];
int i=0;
char customKey=0;
const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
char hexaKeys[ROWS][COLS] = {
{'1','2','3','A'},
{'4','5','6','B'},
{'7','8','9','C'},
{'*','0','#','D'}
};
byte rowPins[ROWS] = {1,2,3,4}; //row pinouts of the keypad
byte colPins[COLS] = {5,6,7,8}; //column pinouts of the keypad
//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);
int redLed = 10;
int greenLed = 11;
void setup()
{
lcd.begin(16,2);
pinMode(redLed, OUTPUT);
pinMode(greenLed, OUTPUT);
lcd.print(" WELCOME... ");
lcd.setCursor(0,1);
lcd.print(" Keypad Lock ");
delay(2000);
lcd.clear();
lcd.print("Enter password:");
lcd.setCursor(0,1);
for(int j=0;j<4;j++)
EEPROM.write(j, j+49);
for(int j=0;j<4;j++)
pass[j]=EEPROM.read(j);
}
void loop()
{
//digitalWrite(11, HIGH);
customKey = customKeypad.getKey();
if(customKey=='#')
change();
if (customKey)
{
password[i++]=customKey;
lcd.print(customKey);
}
if(i==4)
{
delay(200);
for(int j=0;j<4;j++)
pass[j]=EEPROM.read(j);
if(!(strncmp(password, pass,4)))
{
digitalWrite(greenLed, HIGH);
lcd.clear();
lcd.print("Passkey Accepted");
delay(2000);
lcd.clear();
lcd.setCursor(0,1);
lcd.print("PRESS # TO CHANGE PASSWORD.");
for(int PositionCount=0;PositionCount<80; PositionCount++)//loop for scrolling the LCD text
{
lcd.scrollDisplayLeft();//builtin command to scroll left the text
delay(150);// delay of 150 msec
}
delay(3000);
lcd.clear();
lcd.print("Enter Passkey:");
lcd.setCursor(0,1);
i=0;
digitalWrite(greenLed, LOW);
}
else
{
digitalWrite(redLed, HIGH);
lcd.clear();
lcd.print("Access Denied...");
lcd.setCursor(0,1);
lcd.print("#.Change Passkey");
delay(3000);
lcd.clear();
lcd.print("Enter right key:");
lcd.setCursor(0,1);
i=0;
digitalWrite(redLed, LOW);
}
}
}
void change()
{
int j=0;
lcd.clear();
lcd.print("Enter Current Key");
lcd.setCursor(0,1);
while(j<4)
{
char key=customKeypad.getKey();
if(key)
{
pass1[j++]=key;
lcd.print(key);
}
key=0;
}
delay(500);
if((strncmp(pass1, pass, 4)))
{
lcd.clear();
lcd.print("Wrong Passkey...");
lcd.setCursor(0,1);
lcd.print("Enter Right Key");
delay(1000);
}
else
{
j=0;
lcd.clear();
lcd.print("Enter New Key:");
lcd.setCursor(0,1);
while(j<4)
{
char key=customKeypad.getKey();
if(key)
{
pass[j]=key;
lcd.print(key);
EEPROM.write(j,key);
j++;
}
}
lcd.print(" Done......");
delay(1000);
}
lcd.clear();
lcd.print("Enter your key:");
lcd.setCursor(0,1);
customKey=0;
}
