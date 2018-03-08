#include <SoftwareSerial.h>
SoftwareSerial myserial (5,6);

void setup() {
  myserial.begin(9600);
  Serial.begin (9600);
  

}

void loop() {
  if ( myserial.available())
  {
   Serial.println  ( myserial.read());
    }
if(Serial.available() )
{
myserial.write(Serial.read());
  }

}
