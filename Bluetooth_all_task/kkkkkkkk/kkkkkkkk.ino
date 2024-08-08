
//byte byteRead
char name;
int en1=A0;
int en2=A1;
int mo1=A2;
int mo2=A3;
int mo3=A4;
int mo4=A5;
int pwm=200;
int pwm1=130;

void setup() 
{
    Serial.begin(9600);
  pinMode(mo1,OUTPUT);
  pinMode(mo2,OUTPUT);
  pinMode(mo3,OUTPUT);
  pinMode(mo4,OUTPUT);
  pinMode(en1,OUTPUT);
  pinMode(en2,OUTPUT);
  Serial.write("Serial echo Test\n");
}

void forward()
{
  analogWrite(en1,pwm);
  analogWrite(en2,pwm1);
  digitalWrite(mo1,1);
  digitalWrite(mo2,0);
  digitalWrite(mo3,1);
  digitalWrite(mo4,0);
  delay(100);
  }

  void rv()
{
  analogWrite(en1,pwm);
  analogWrite(en2,pwm);
  digitalWrite(mo1,0);
  digitalWrite(mo2,1);
  digitalWrite(mo3,0);
  digitalWrite(mo4,1);
  }

void br()
{
  analogWrite(en1,0);
  analogWrite(en2,0);
  digitalWrite(mo1,0);
  digitalWrite(mo2,0);
  digitalWrite(mo3,0);
  digitalWrite(mo4,0);
  }

void loop() 
{
     if( Serial.available() ) 
    
       name = Serial.read();
       //Serial.println(name);
       
        switch(name)
        {
          case 'F'://for a
            forward();
            Serial.println("Forward");
            break;
          case 'G'://for b
            rv();
            Serial.println("backward");
            break;
          case 'S'://for c
            Serial.println("cat");
            break;
          case 'd'://for d
            Serial.write("dog");
            break;
          case 'e'://for 1
            Serial.write("elephant");
            break;
          case '1'://for 2
            Serial.write("one");
            break;
          case '2'://for 2
            Serial.write("two");
            break;
          case '3'://for 2
            Serial.write("three");
            break;
          case '4'://for 2
            Serial.write("four");
            break;
          case '5'://for 2
            Serial.write("five");
            break;
          case '6'://for 2
            Serial.write("six");
            break;
 
          default:
             Serial.write("Invalid input:");
             break;
        }
    
        Serial.write(byteRead);
     }
}
