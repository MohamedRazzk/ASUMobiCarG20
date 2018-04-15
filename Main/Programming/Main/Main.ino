#include <string.h>
#include <SoftwareSerial.h>
#include <AFMotor.h>

int bdelay = 35 ;

SoftwareSerial mySerial(50, 52); //rx -tx  for hc-05
AF_DCMotor M_FR(1, MOTOR12_64KHZ);
AF_DCMotor M_FL(2, MOTOR12_64KHZ);
AF_DCMotor M_BL(3, MOTOR12_64KHZ);
AF_DCMotor M_BR(4, MOTOR12_64KHZ);

const int left_pin = 14 ;
const int center_pin = 15 ;
const int right_pin = 16 ;

const int echo2 = 17 ;
const int trig2 = 18 ;
const int echo1 = 19 ;
const int trig1 = 20 ;




long duration1;
int distance1 = 40;
int ultraone_distance = 40;
int ultratwo_distance = 40 ;
int left_state = 0  ;
int center_state = 0 ;
int right_state = 0 ;

int speedSet = 0;
char Bdata = '0' ;

int Car_Mode = 0 ;  //automatic to bluetooth medule

void setup() {


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

  pinMode(left_pin, INPUT) ;
  pinMode(center_pin, INPUT) ;
  pinMode(right_pin, INPUT) ;

  pinMode(trig1, OUTPUT); // Sets the trigPin as an Output
  pinMode(echo1, INPUT); // Sets the echoPin as an Input
  pinMode(trig2, OUTPUT); // Sets the trigPin as an Output
  pinMode(echo2, INPUT); // Sets the echoPin as an Input
}

int ultraone() {// ulttasonic one calculations
  digitalWrite(trig1, LOW);
  delayMicroseconds(2);

  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trig1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig1, LOW);

  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration1 = pulseIn(echo1, HIGH);

  // Calculating the distance
  distance1 = duration1 * 0.034 / 2;

  //Serial.print("Distance One = " ) ; 
  //Serial.println(distance1) ; 
  return distance1 ;

}
int ultratwo() { // ulttasonic two calculations
  digitalWrite(trig2, LOW);
  delayMicroseconds(2);

  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trig2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig2, LOW);

  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration1 = pulseIn(echo2, HIGH);

  // Calculating the distance
  distance1 = duration1 * 0.034 / 2;

  //Serial.print("Distance two = " ) ; 
  //Serial.println(distance1) ; 
  return distance1 ;

}
void speedset () {

  M_FR.setSpeed(255);
  M_FL.setSpeed(255);
  M_BR.setSpeed(255);
  M_BL.setSpeed(255);

}
void stopmode () {
  M_FL.run(RELEASE);
  M_FR.run(RELEASE);
  M_BL.run(RELEASE);
  M_BR.run(RELEASE);

}
void inf_forward (int R_speed , int L_speed) {
  M_FR.setSpeed(R_speed);
  M_FL.setSpeed(L_speed);
  M_BR.setSpeed(R_speed);
  M_BL.setSpeed(L_speed);

  M_FL.run(FORWARD);
  M_FR.run(FORWARD);
  M_BL.run(FORWARD);
  M_BR.run(FORWARD);
}
void forward () {

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
void backward() {

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
void right() {

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
void left() {


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
void forward_right(int c_speed ) { // c_speed is  a cervatiuare speed

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
void forward_left(int c_speed ) { // c_speed is  a cervatiuare speed
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


void loop() {
  ultraone_distance = ultraone() ;
  ultratwo_distance = ultratwo() ;

  Serial.print("Distance1 = " ) ;
  Serial.println(ultraone_distance) ; 
  Serial.print("Distance2 =  " ) ;  
 Serial.println(ultratwo_distance) ; 
 
  Car_Mode = 0; 
  ///Serial.println(ultraone_distance) ;
  //Serial.println(ultratwo_distance) ;
  if (ultraone_distance <= 15   ) {stopmode();}
  if (ultratwo_distance <=15  ) {stopmode();}
  if (Car_Mode == 0 ) { //bluetooth Mode




    if (mySerial.available()) { // If the bluetooth module has some incoming data from the phone
      Bdata = mySerial.read(); // Read the data, one character at a time
      Serial.write(Bdata); // Write char received via Bluetooth to the Serial Monitor of Arduino IDE




      if (Bdata == '1' , '2' , '3' , '4' )
      {
        switch (Bdata) {
          case '1': forward(); break;
          case '2': backward(); break;
          case '3': right() ; break ;
          case '4': left() ; break ;
            //  case 'A':forward_right(50) ;
            // case 'b':forward_left (50);

        }
      }

    }
  }

  else if (Car_Mode == 1) { //car in line follow mode


    left_state = digitalRead(left_pin);
    center_state = digitalRead(center_pin);
    right_state = digitalRead(right_pin);

    if (left_state == HIGH ) {
      Serial.print("L_black");
      forward_left(255);
      inf_forward(50, 255);
    }
    //if(left_state==LOW ) {Serial.print("L_white") ;}

    if (center_state == HIGH ) {
      Serial.print("C_black");
      inf_forward(255, 255);
    }
    if (center_state == LOW ) {
      Serial.print("C_white");
      stopmode();
    }


    if (right_state == HIGH ) {
      Serial.print("R_black");
      forward_right(255);
      inf_forward(255, 50);
    }
    // if(right_state==LOW ) {Serial.print("R_white") ;}


  }

  
}



