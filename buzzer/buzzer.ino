const int buzz = 8;


void setup() {
  // put your setup code here, to run once:
  pinMode(buzz, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(buzz, HIGH);
      Serial.println("ON");
      delay(2000);
      digitalWrite(buzz, LOW);
      Serial.println("OFF");
      delay(1000);
}
