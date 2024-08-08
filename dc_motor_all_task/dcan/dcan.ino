
int in1 = 1;
int in2 = 2;
int in3 = 3;
int in4 = 4;
int en =A7;
int s =A6;



void setup() {
  // put your setup code here, to run once:
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);
  pinMode(en,INPUT);
}
void control()
{
  for(int i=0;i<=255;i++)
  {
    analogRead(en);
    analogWrite(en,i);
    analogRead(s);
    analogWrite(s,i);
  }
 
}


void forward()
{
  control();
  digitalWrite(in1,150);//for 150 rpm
  digitalWrite(in3,150);
  
  digitalWrite(in1,1);
  digitalWrite(in2,0);
  digitalWrite(in3,1);
  digitalWrite(in4,0);
 


}
void backward()
{
    control();
   digitalWrite(in1,150);
   digitalWrite(in3,150);
   digitalWrite(in1,0);
   digitalWrite(in2,1);
   digitalWrite(in3,0);
   digitalWrite(in4,1);
  

}
void stop()
{
   control();
   digitalWrite(in1,0);
   digitalWrite(in2,0);
   digitalWrite(in3,0);
   digitalWrite(in4,0);

}

void loop() {
  // put your main code here, to run repeatedly:
 control();
 forward();
 delay(2000);
 backward();
 delay(2000);
 stop();
 delay(2000);

}
