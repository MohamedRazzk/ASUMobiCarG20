#include <string.h> 
#include <SoftwareSerial.h>
#include <AFMotor.h> 

int bdelay = 35 ;

SoftwareSerial mySerial(50,52); //rx -tx  for hc-05
AF_DCMotor M_FR(1,MOTOR12_64KHZ);
AF_DCMotor M_FL(2,MOTOR12_64KHZ);
AF_DCMotor M_BL(3,MOTOR12_64KHZ);
AF_DCMotor M_BR(4,MOTOR12_64KHZ);

 
int speedSet = 0;
char Bdata = '0' ; 

void setup(){
  
Serial.begin(9600); // Establish Serial connection between PC and Arduino
mySerial.begin(9600); // Establish Serial connection between HC-05 and Phone


M_FR.setSpeed(255); 
M_FL.setSpeed(255);
M_BR.setSpeed(255);
M_BL.setSpeed(255);
M_FR.run(RELEASE); 
M_FL.run(RELEASE); 
M_BR.run(RELEASE); 
M_BL.run(RELEASE); 

}
void speedset () {
  
M_FR.setSpeed(255); 
M_FL.setSpeed(255);
M_BR.setSpeed(255);
M_BL.setSpeed(255);

  }
void stopmode (){
  M_FL.run(RELEASE);
        M_FR.run(RELEASE);
        M_BL.run(RELEASE);
        M_BR.run(RELEASE);
  
  }
void forward (){
  
    M_FL.run(FORWARD);
        M_FR.run(FORWARD);
        M_BL.run(FORWARD);
     M_BR.run(FORWARD); 
     delay (bdelay);
     stopmode();
     
     /*
      for (speedSet = 0; speedSet < 255; speedSet +=2) // slowly bring the speed up to avoid loading down the batteries too quickly
  {
    M_FL.setSpeed(speedSet);
    M_FR.setSpeed(speedSet);
    M_BL.setSpeed(speedSet); 
    M_BR.setSpeed(speedSet);
    delay(5);
    
    
  }*/
       
  
  }
void backward(){

      M_FL.run(BACKWARD);
        M_FR.run(BACKWARD);
        M_BL.run(BACKWARD);
        M_BR.run(BACKWARD);
        delay (bdelay);
     stopmode();
   /*
      for (speedSet = 0; speedSet < 255; speedSet +=2) // slowly bring the speed up to avoid loading down the batteries too quickly
  {
    M_FL.setSpeed(speedSet);
    M_FR.setSpeed(speedSet);
    M_BL.setSpeed(speedSet); 
    M_BR.setSpeed(speedSet);
    delay(5);
    
  }*/
}
void right(){

      M_FL.run(FORWARD);
        M_FR.run(BACKWARD);
        M_BL.run(FORWARD);
        M_BR.run(BACKWARD);
        delay (bdelay);
     stopmode();
   /*
      for (speedSet = 0; speedSet < 255; speedSet +=2) // slowly bring the speed up to avoid loading down the batteries too quickly
  {
    M_FL.setSpeed(speedSet);
    M_FR.setSpeed(speedSet);
    M_BL.setSpeed(speedSet); 
    M_BR.setSpeed(speedSet);
    delay(5);
    
  }*/
}
void left(){
  

      M_FL.run(BACKWARD);
        M_FR.run(FORWARD);
        M_BL.run(BACKWARD);
        M_BR.run(FORWARD);
        delay (bdelay);
     stopmode();
   /*
      for (speedSet = 0; speedSet < 255; speedSet +=2) // slowly bring the speed up to avoid loading down the batteries too quickly
  {
    M_FL.setSpeed(speedSet);
    M_FR.setSpeed(speedSet);
    M_BL.setSpeed(speedSet); 
    M_BR.setSpeed(speedSet);
    delay(5);
    
  }*/
}

void forward_right(int c_speed ) // c_speed is  a cervatiuare speed  
{
  M_FR.setSpeed(c_speed ) ; 
  M_BR.setSpeed(c_speed ) ; 
  
  M_FL.run(FORWARD);
        M_FR.run(FORWARD);
        M_BL.run(FORWARD);
        M_BR.run(FORWARD);
        delay (100);
      
     stopmode();
       speedset(); 
  }
  void forward_left(int c_speed ) // c_speed is  a cervatiuare speed  
{
  M_FL.setSpeed(c_speed) ; 
  M_BL.setSpeed(c_speed) ; 
  
  M_FL.run(FORWARD);
        M_FR.run(FORWARD);
        M_BL.run(FORWARD);
        M_BR.run(FORWARD);
        delay (100);
      
     stopmode();
       speedset() ; 
  }
  

void line_follower () ;


void loop(){
  
if (mySerial.available()){ // If the bluetooth module has some incoming data from the phone
    Bdata=mySerial.read(); // Read the data, one character at a time
    Serial.write(Bdata); // Write char received via Bluetooth to the Serial Monitor of Arduino IDE
      
if (Bdata == '1' ,'2' ,'3' ,'4' )
{ 
      switch (Bdata) {
     case '1':forward();break; 
     case '2':backward(); break; 
     case '3':right() ; break ; 
     case '4':left() ; break ; 
     case 'A':forward_right(50) ; 
     case 'b':forward_left (50); 

      }
}

 

  }




}