char name;

void setup() 
{
    Serial.begin(9600);
    
    Serial.write("Serial echo Test\n");
}

void loop() 
{
    if( Serial.available() ) 
    {
       
        name = Serial.read();
        Serial.write(name);
    }
}
