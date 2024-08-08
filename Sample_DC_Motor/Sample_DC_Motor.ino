int e1 = A0;
int e2 = A5;
int pin1 = A1;  // Connect to the positive terminal of the motor
int pin2 = A2; // Connect to the negative terminal of the motor
int pin3 = A3;  // Connect to the positive terminal of the motor
int pin4 = A4;  // Connect to the negative terminal of the motor
int pwm = 100;

void setup() {
  pinMode(e1, OUTPUT);
  pinMode(e2, OUTPUT);
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);
  pinMode(pin4, OUTPUT);

}

void reverse(){
  digitalWrite(e1, pwm);
  digitalWrite(e2, pwm);
  digitalWrite(pin1, 1);
  digitalWrite(pin2, 0);
  digitalWrite(pin3, 1);
  digitalWrite(pin4, 0);
}

void forward(){
  digitalWrite(e1, pwm);
  digitalWrite(e2, pwm);
  digitalWrite(pin1, 0);
  digitalWrite(pin2, 1);
  digitalWrite(pin3, 0);
  digitalWrite(pin4, 1);
}

void stop() {
  digitalWrite(e1, pwm);
  digitalWrite(e2, pwm);
  digitalWrite(pin1, 0);
  digitalWrite(pin2, 0);
  digitalWrite(pin3, 0);
  digitalWrite(pin4, 0);
}

void loop() {
  forward(); // For Moving Forward
  delay(1000);
  stop();
  delay(1000);
  reverse();
  delay(1000);
  stop();
  delay(1000);
  
  
  
  // stop();
  // delay(3000);
  // reverse(); // For Reverse
  // delay(200);
  // stop(); // Stop
  // delay(200);
}
