

void color(int rpot, int gpot, int bpot, int Red, int Green, int Blue) {
  // put your main code here, to run repeatedly:
  int red = analogRead(rpot);
  red = map(red,0,1024,0,255);
  analogWrite(Red,red);
  
  int green = analogRead(gpot);
  green = map(green,0,1024,0,255);
  analogWrite(Green,green);
  
  int blue = analogRead(bpot);
  blue = map(blue,0,1024,0,255);
  analogWrite(Blue,blue);
  
  delay(1000);
}
