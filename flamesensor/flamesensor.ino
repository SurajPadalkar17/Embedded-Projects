#include<Servo.h>

int en1=A0;
int mo1=A1;
int mo2=A2;
int mo3=A3;
int mo4=A4;
int en2=A5; 

// Flame sensor 
int sf=3;
int sr=4;
int sl=5;
int sb=6;

#define trig_pin 7 
#define echo_pin 8

Servo s1;
Servo s2;

void forward()
{
  digitalWrite(en1,1);
  digitalWrite(en2,1);
  digitalWrite(mo1,1);
  digitalWrite(mo2,0);
  digitalWrite(mo3,1);
  digitalWrite(mo4,0);
}
  
void backward()
{
  digitalWrite(en1,1);
  digitalWrite(en2,1);
  digitalWrite(mo1,0);
  digitalWrite(mo2,1);
  digitalWrite(mo3,0);
  digitalWrite(mo4,1);
}
void left()
{
  analogWrite(en1,1);
  digitalWrite(en2,1);
  digitalWrite(mo1,0);
  digitalWrite(mo2,0);
  digitalWrite(mo3,1);
  digitalWrite(mo4,0);
}
void right()
{
  digitalWrite(en1,1);
  digitalWrite(en2,1);
  digitalWrite(mo1,1);
  digitalWrite(mo2,0);
  digitalWrite(mo3,0);
  digitalWrite(mo4,0);
}
void brake()
{
  digitalWrite(en1,1);
  digitalWrite(en2,1);
  digitalWrite(mo1,0);
  digitalWrite(mo2,0);
  digitalWrite(mo3,0);
  digitalWrite(mo4,0);
}

void setup() {
  // put your setup code here, to run once:
pinMode(mo1,OUTPUT);
pinMode(mo2,OUTPUT);
pinMode(mo3,OUTPUT);
pinMode(mo4,OUTPUT);
pinMode(en1,OUTPUT);
pinMode(en2,OUTPUT); 
pinMode(sf,INPUT); 
pinMode(sr,INPUT);
pinMode(sl,INPUT);
pinMode(sb,INPUT);
pinMode(trig_pin,OUTPUT);
pinMode(echo_pin,INPUT);
s1.attach(10);
s1.write(90);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int f=digitalRead(sf);
  int b=digitalRead(sr);
  int l=digitalRead(sl);
  int r=digitalRead(sb);
  //no flame
  if(f==0 && b==0 && l==0 && r==0)
  {
    Serial.println("no flame ditected");
    s1.write(90);
    
    forward();
  }
  //forward
  else if (f==1 && b==0 && l==0 && r==0)
  {
    brake();
    s1.write(90);
    Serial.print("Forward pump1 on");
    delay(100);
  }
  //left
  else if (f==0 && b==0 && l==1 && r==0)
  {
    brake();
   // for(int i=90;i>0;i++)
    //{
      s1.write(0);
      Serial.println("pump1 on");
    //}
      //if(f==0 && b==0 && l==0 && r==0)
      //{
      //  for(int i=0;i<90;i--)
        //{
        //  s1.write(i);
         // Serial.print("Water pump stop");
        //  forward();
      //  }
      //}
    
  }
  //right
 else if (f==0 && b==0 && l==0 && r==1)
  {
    brake();
    //for(int i=90;i<180;i++)
    //{
      s1.write(180);
      Serial.print("pump1 on");
      //Serial.println("pump1 on");
    }
     // if(f==0 && b==0 && l==0 && r==0)
      //{
       // for(int i=180;i>90;i--)
        //{
        //  s1.write(i);
        //  Serial.println("Water pump stop");
         // forward();
       // }
      //}
  //}

//back
  else if (f==0 && b==1 && l==0 && r==0)
  {
    brake();
    s1.write(90);
    Serial.println(" pump2 on");
    delay(100);
    if(f==0 && b==0 && l==0 && r==0)
   {
     Serial.println("Water pump stop");
    s1.write(90);
    forward();
   }
  }


//forward and left
  else if (f==1 && b==0 && l==1 && r==0)
  {
   Serial.println("pump1 on");
   for(int i=90;i>0;i--)
   {
    s1.write(i);
 
   }
   for(int i=0;i<90;i++)
   {
    s1.write(i);
    
   }
   if(f==0 && b==0 && l==0 && r==0)
   {
     s1.write(90);
   }
  }


 //forward and right
   else if (f==1 && b==0 && l==0 && r==1)
  {
   Serial.println("pump1 on");
   for(int i=90;i<180;i++)
   {
    s1.write(i);
    }
   for(int i=180;i>90;i--)
   {
    s1.write(i);
   }
   if(f==0 && b==0 && l==0 && r==0)
   {
     Serial.println("Water pump stop");
     s1.write(90);
     forward();
   }
  }

//forward and backward
   else if (f==1 && b==1 && l==0 && r==0)
  {
    brake();
    s1.write(90);
    
    Serial.println("pump1 and pump2 on");
    delay(100);
    if(f==0 && b==0 && l==0 && r==0)
   {
     Serial.println("Water pump stop");
     s1.write(90);
     forward();
   }
  }


//backward left
   else if (f==0 && b==1 && l==1 && r==0)
  {
    brake();
    for(int i=90;i<180;i++)
    {
      s1.write(i);
      Serial.println("pump2 on");
      for(i=180;i>90;i--)
      {
        s1.write(i);
      }
      if(f==0 && b==0 && l==0 && r==0)
      {
          s1.write(i);
          Serial.println("Water pump stop");
        
      }
    }
  }
  

  //backward and right
  else if (f==0 && b==1 && l==0 && r==1)
  {
    brake();
    for(int i=90;i>180;i++)
    {
      s1.write(i);
      Serial.println("pump2 on");
      for(i=180;i>90;i++)
      {
        s1.write(i);
      }
      if(f==0 && b==0 && l==0 && r==0)
      {
        for(i=0;i<90;i--)
        {
          s1.write(i);
          Serial.println("Water pump stop");
          forward();
        }
      }
    }
  }
  //forwrd left and right on
  else if (f==1 && b==0 && l==1 && r==1)
  {
    brake();
    for(int i=90;i>0;i--)
    {
       s1.write(i);
       
       Serial.print("pump1 on");
         delay(100);

      for(int i=0;i<180;i++)
        {
          s1.write(i);
          Serial.println("pump2 on");
          delay(100);
        }
     if(f==0 && b==0 && l==0 && r==0)
       {
           for(i=180;i>90;i--)
        {
          s1.write(i);
          Serial.println("Water pump stop");
          forward();
        }
       }
      }
  }

  //backward lef and right
  else if (f==0 && b==1 && l==1 && r==1)
  {
    brake();
    for(int i=90;i>0;i--)
    {
      s1.write(i);
      for(int i=0;i<180;i++)
        {
          s1.write(i);
          Serial.println("pump2 on");
        }
      if(f==0 && b==0 && l==0 && r==0)
         {
           for(i=180;i>90;i--)
          {
          s1.write(i);
          Serial.println("Water pump stop");
          forward();
          }
         }
    }
  }

  //forward left backward
   else if(f==1 && b==1 && l==1 && r==0)
  {
    brake();
    for(int i=90;i>0;i--)
    {
      s1.write(i);
     
      Serial.println("pump1 on");
      for(i=0;i>90;i--)
      {
        s1.write(i);
       
      }
      for(i=90;i<180;i++)
      {
        Serial.println("pump2 on");
        s1.write(i);
        
      }
      if(f==0 && b==0 && l==0 && r==0)
      {
        s1.write(90);
        }
      }
    }
  //}
  //forward right backward
  else if(f==1 && b==1 && l==0 && r==1)
  {
    brake();
    for(int i=90;i>180;i++)
    {
      s1.write(i);
      Serial.println("pump1 on");
      for(i=180;i>90;i--)
      {
        s1.write(i);
       
      }
      for(i=90;i>0;i++)
      {
        Serial.println("pump2 on");
        s1.write(i);
      
      }
      if(f==0 && b==0 && l==0 && r==0)
      {
        s1.write(90);
      }
    }
  }


  else if(f==1 && b==1 && l==1 && r==1)
  {
    brake();
    for(int i=90;i>0;i--)
    {
       s1.write(i);
     
      for(int i=0;i<180;i++)
        {
          s1.write(i);
          Serial.println("pump1 and pump 2 on");
        }
     if(f==0 && b==0 && l==0 && r==0)
       {
         Serial.println("Water pump stop");
        s1.write(90);
         forward();
      }
      }
  }
}