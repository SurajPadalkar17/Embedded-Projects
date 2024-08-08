// sensor pin assigned
int o1 = 7;
int o2 = 8;
int o3 = 9;
int o4 = 10;
int o5 = 11;
int o6 = 12;

int l2,l1,c1,c2,r1,r2;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(o1,INPUT);
  pinMode(o2,INPUT);
  pinMode(o3,INPUT);
  pinMode(o4,INPUT);
  pinMode(o5,INPUT);
  pinMode(o6,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  l2 = digitalRead(o1);
  l1 = digitalRead(o2);
  c1 = digitalRead(o3);
  c2 = digitalRead(o4);
  r1 = digitalRead(o5);
  r2 = digitalRead(o6);

  delay(1000);
  Serial.print("l2: ");
  Serial.print(l2);
  Serial.print("\t l1: ");
  Serial.print(l1);
  Serial.print("\t C1: ");
  Serial.print(c1);
  Serial.print("\t C2: ");
  Serial.print(c2);
  Serial.print("\t r1: ");
  Serial.print(r1);
  Serial.print("\t r2: ");
  Serial.println(r2);
  
}
