#include <SoftwareSerial.h>
SoftwareSerial myserial (5,6); // bluetooth : Tx = 5 , Rx = 6
int x=12 ; // LED

void setup() {
  myserial.begin (9600) ; // speed
  pinMode (x,OUTPUT) ; 

}

void loop() {
  if (myserial.available() )
  {
    if (myserial.read () == 'n' ) // when we enter n on the phone the LED will turn on
    {
      digitalWrite (x,HIGH);
      }
      else {
        digitalWrite (x,LOW);
        }
    }
   
}
