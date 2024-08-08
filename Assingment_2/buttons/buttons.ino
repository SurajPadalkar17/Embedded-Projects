
int button1 = 1;
int button2 = 2;
int button3 = 3;
int bulb1 = 4;
int bulb2 = 5;
int bulb3 = 6;


void setup() {
  // put your setup code here, to run once:
  pinMode(button1,INPUT);
  pinMode(button2,INPUT);
  pinMode(button3,INPUT);
  pinMode(bulb1,OUTPUT);
  pinMode(bulb2,OUTPUT);
  pinMode(bulb3,OUTPUT);
  Serial.begin(9600);
  
}
void loop() {
  // put your main code here, to run repeatedly:
  int r1 = digitalRead(button1);
  int r2 = digitalRead(button2);
  int r3 = digitalRead(button3);

  if(r1==1 && r2==0 && r3==0){
    digitalWrite(bulb1,1);
    digitalWrite(bulb2,0);
    digitalWrite(bulb3,0);
  }

  else if(r1==1 && r2==1 && r3==0){
    digitalWrite(bulb1,0);
    digitalWrite(bulb2,1);
    digitalWrite(bulb3,0);
  }

  else if(r1==1 && r2==1 && r3==1){
    digitalWrite(bulb1,0);
    digitalWrite(bulb2,0);
    digitalWrite(bulb3,1);
  }

  else{
    //Serial.println("All Buttons Are OFF");
  }
}
