
byte byteRead;
char a;
char b;
char c;


void setup() 
{
    Serial.begin(9600);
    
    Serial.write("Serial echo Test\n");
}
 int function()
{
 if(byteRead==a)
 {
     Serial.write("apple");
 }
 else if(byteRead==b)
 {
   Serial.write("ball");
 }
 else if(byteRead==c)
 {
  Serial.write("cat");
 }
 else
 {
    //sss= Serial.read(byteRead)
 }

}
void loop() 
{
    if( Serial.available() ) 
    {
       //int s =  function();
      byteRead= Serial.read();
      function();
      // function()=Serial.read();
      Serial.write(byteRead);
    
       // Serial.write(byteRead);
        //Serial.write(sss);
    }
}
