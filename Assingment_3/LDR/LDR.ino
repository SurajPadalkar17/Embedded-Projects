
int ldr = A0;

void setup() {
  // put your setup code here, to run once:
  pinMode(ldr,INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int result = analogRead(ldr);
  Serial.print("LDR Value =");
  Serial.println(result);
  delay(1000);
}
