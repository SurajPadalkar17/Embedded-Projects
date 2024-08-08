// Water Tank Level Detector
// Top: Display Top level, Motor OFF and ON Red led.
// Middle: Display Middle level and ON Yellow led.
// Bottom: Display Bottom level, Motor ON and ON Green led.

int Bottom = 1;
int Middle = 2;
int Top = 3;
int Green = 4;
int Yellow = 5;
int Red = 6;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(Bottom,INPUT);
  pinMode(Middle,INPUT);
  pinMode(Top,INPUT);
  pinMode(Green,OUTPUT);
  pinMode(Yellow,OUTPUT);
  pinMode(Red,OUTPUT);
  
}


void loop() {
  // put your main code here, to run repeatedly:
  int b1 = digitalRead(Bottom);
  int m1 = digitalRead(Middle);
  int t1 = digitalRead(Top);

  if(b1==1 && m1==0 && t1==0)
  {
    Serial.println("Bottom Level");
    Serial.println("Motor ON");
    digitalWrite(Green,1);
    digitalWrite(Yellow,0);
    digitalWrite(Red,0);
    
    delay(1000);
  }

  else if(b1==1 && m1==1 && t1==0)
  {
    Serial.println("Middle Level");
    //Serial.println("Motor ON");
    digitalWrite(Green,0);
    digitalWrite(Yellow,1);
    digitalWrite(Red,0);
    
    delay(1000);
  }

  else if(b1==1 && m1==1 && t1==1)
  {
    Serial.println("Top Level");
    Serial.println("Motor OFF");
    digitalWrite(Green,0);
    digitalWrite(Yellow,0);
    digitalWrite(Red,1);
    tone (A15,1000,500); // tone is used for buzzer. 
    delay(1000);
  }

  else
  {
    digitalWrite(Green,0);
    digitalWrite(Yellow,0);
    digitalWrite(Red,0);
  }
}
