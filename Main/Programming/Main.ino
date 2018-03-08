#include <SoftwareSerial.h>


SoftwareSerial mySerial(50,52); //rx -tx  for hc-05
 char Bdata = '0' ; 

void setup(){
  
Serial.begin(9600); // Establish Serial connection between PC and Arduino
mySerial.begin(9600); // Establish Serial connection between HC-05 and Phone



}
 
void loop(){
  
if (mySerial.available()){ // If the bluetooth module has some incoming data from the phone
    Bdata=mySerial.read(); // Read the data, one character at a time
    
     if(Bdata=='1') // 1 received
      {
      Serial.print("Go forward");       //Print Value inside data in Serial monitor
      }     
  else if(Bdata=='2') // 2 received
      {
      Serial.print("Go Back " );        //Print Value inside data in Serial monitor
      }
  else if(Bdata=='3') // 3 received
      {
      Serial.print("Go Right " );        //Print Value inside data in Serial monitor
      }
  else if(Bdata=='4') //  4 received
      {
      Serial.print("Go Left" );        //Print Value inside data in Serial monitor
      }
      
  else if(Bdata=='L') // L received
      {
      Serial.print("Line Follower Mode " );        //Print Value inside data in Serial monitor
      }
      
  else if(Bdata=='A') // a received
      {
      Serial.print("Auto Barking Mode" );        //Print Value inside data in Serial monito
      }
      
  else if(Bdata=='B') // s received
      {
      Serial.print(" Safty Sensor Mode " );        //Print Value inside data in Serial monitor
      }

  else if(Bdata=='D') // s received
      {
      Serial.print(" Dancing Mode  " );        //Print Value inside data in Serial monitor
      }

      Serial.write(Bdata); // Write char received via Bluetooth to the Serial Monitor of Arduino IDE
}
}
