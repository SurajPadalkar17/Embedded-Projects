#include <dht.h>

dht DHT;

#define DHT11_PIN 2
#define RELAY_PIN_T 4
#define RELAY_PIN_H 5

void setup(){
  Serial.begin(9600);
  pinMode(RELAY_PIN_T , OUTPUT);
  pinMode(RELAY_PIN_H , OUTPUT);
}

void loop(){
  int chk = DHT.read11(DHT11_PIN);
  int temp = DHT.temperature;
  int humi = DHT.humidity;
  Serial.print("Temperature = ");
  Serial.println(temp);
  Serial.print("Humidity = ");
  Serial.println(humi);
  delay(1000);

  if ( temp>24 || humi>80)
  {
    Serial.println("spray WATER ON");
    digitalWrite(RELAY_PIN_T, LOW);
  }

  else if ( temp<18 || humi<40 )
  {
    Serial.println("On Bulb");
    digitalWrite(RELAY_PIN_H, LOW);
  }
  else 
  {
    Serial.println("Normal");
    digitalWrite(RELAY_PIN_T, HIGH);
    digitalWrite(RELAY_PIN_H, HIGH);
  }
}
