
char byteRead;
char a,b,c;
void setup() 
{
    Serial.begin(9600);
    
    Serial.write("Serial echo Test\n");
}

void loop() 
{
    if( Serial.available() ) 
    {
        byteRead = Serial.read();
        {
        if(byteRead=a)
        {
          Serial.write("apple");
        }
        else if(byteRead=b)
        {
          Serial.write("ball");
        }
       else  if(byteRead=c)
        {
          Serial.write("cat");
        }
        }
    
        //Serial.write(byteRead);
    }
}
