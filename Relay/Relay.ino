// Relay working

int button1 = 2;
int button2 = 3;
int button3 = 4;
int button4 = 5;
int r1 = 6;
int r2 = 7;
int r3 = 8;
int r4 = 9;


void setup() {
  // put your setup code here, to run once:
  pinMode(button1,INPUT);
  pinMode(button2,INPUT);
  pinMode(button3,INPUT);
  pinMode(button4,INPUT);
  pinMode(r1,OUTPUT);
  pinMode(r2,OUTPUT);
  pinMode(r3,OUTPUT);
  pinMode(r4,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int b1 = digitalRead(button1);
  int b2 = digitalRead(button2);
  int b3 = digitalRead(button3);
  int b4 = digitalRead(button4);

  if(b1==1){
    digitalWrite(r1,1);
  }
  else
  {
    digitalWrite(r1,0);
  }

  if(b2==1){
    digitalWrite(r2,1);
  }
  else
  {
    digitalWrite(r2,0);
  }

  if(b3==1){
    digitalWrite(r3,1);
  }
  else
  {
    digitalWrite(r3,0);
  }

  if(b4==1)
  {
    digitalWrite(r1,0);
    digitalWrite(r2,0);
    digitalWrite(r3,0);
  }
  

}
