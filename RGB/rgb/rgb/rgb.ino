#include"rgb.h"

int rpot =A3;
int gpot =A2;
int bpot =A1;
int Red  =A4;
int Green=A5;
int Blue= A6;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(rpot,INPUT);
  pinMode(gpot,INPUT);
  pinMode(bpot,INPUT);
  pinMode(Red,OUTPUT);
  pinMode(Green,OUTPUT);
  pinMode(Blue,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  color(rpot, gpot, bpot, Red, Green, Blue);
}
