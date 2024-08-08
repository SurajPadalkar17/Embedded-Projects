// Traffic Light 
  int Green=2;
  int Orange=3;
  int Red=4;

void setup() {

  pinMode(Green,OUTPUT);
  pinMode(Orange,OUTPUT);
  pinMode(Red,OUTPUT);
  
}

void loop() {

  digitalWrite(Green,1);
  digitalWrite(Orange,0);
  digitalWrite(Red,0);
  delay(5000);

  digitalWrite(Green,0);
  digitalWrite(Orange,1);
  digitalWrite(Red,0);
  delay(3000);

  digitalWrite(Green,0);
  digitalWrite(Orange,0);
  digitalWrite(Red,1);
  delay(5000);

}
