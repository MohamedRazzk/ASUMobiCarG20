#include <WString.h>
#include <Ethernet.h> 
#include <EEPROM.h>
#include <SoftwareSerial.h>
#include <AFMotor.h>

int dist = 0;
int c_speed = 60;
int l_speed = 120;
int ll_speed = 100;
int cl_speed = 100;

int r_speed = l_speed + 20;
int rr_speed = ll_speed + 20;
int cr_speed = cl_speed + 20;

int photo_val = 0;

int bcounter = 0;

int w = 0;
int b = 1;
const int bdelay = 35;            //speed delation for bluetooth medule 
const int inf_delay = 10;        //speed delation for infinity function
int last_state = 0;
SoftwareSerial mySerial(50, 52); //rx -tx  for hc-05

AF_DCMotor M_FR(3, MOTOR12_64KHZ); AF_DCMotor M_FL(4, MOTOR12_64KHZ); AF_DCMotor M_BL(1, MOTOR12_64KHZ); AF_DCMotor M_BR(2, MOTOR12_64KHZ); // motor driver speed

const int left_pin = 14; const int center_pin = 15; const int right_pin = 16; const int cen_r_pin = 49;  const int cen_l_pin = 51; // infra red pin define 

const int echo2 = 17; const int trig2 = 18;const int echo1 = 19; const int trig1 = 20; // ultra sonice pin define 

long duration1; int distance1 = 40; int ultraone_distance = 40; int ultratwo_distance = 40; // ultrasonic distance define 

int center_state = 0; int right_state = 0; int cin_r_state = 0;  int cin_l_state = 0;  int left_state = 0;// first state of infra red 

const int photo = 26;

int speedSet = 0;
char Bdata = '0';

int Car_Mode = 0;  //automatic to bluetooth medule

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

  pinMode(left_pin, INPUT);
  pinMode(center_pin, INPUT);
  pinMode(right_pin, INPUT);
  pinMode(cen_r_pin, INPUT);
  pinMode(cen_l_pin, INPUT);

  pinMode(trig1, OUTPUT); // Sets the trigPin as an Output
  pinMode(echo1, INPUT); // Sets the echoPin as an Input
  pinMode(trig2, OUTPUT); // Sets the trigPin as an Output
  pinMode(echo2, INPUT); // Sets the echoPin as an Input

  pinMode(photo, INPUT);
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
  return distance1;

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
  return distance1;

}
void speedset() {

  M_FR.setSpeed(255);
  M_FL.setSpeed(255);
  M_BR.setSpeed(255);
  M_BL.setSpeed(255);

}
void stopmode() {
  M_FL.run(RELEASE);
  M_FR.run(RELEASE);
  M_BL.run(RELEASE);
  M_BR.run(RELEASE);

}
void inf_forward(int R_speed, int L_speed, int del) {
  M_FR.setSpeed(R_speed);
  M_FL.setSpeed(L_speed);
  M_BR.setSpeed(R_speed);
  M_BL.setSpeed(L_speed);

  M_FL.run(FORWARD);
  M_FR.run(FORWARD);
  M_BL.run(FORWARD);
  M_BR.run(FORWARD);
  delay(del);
  stopmode();
}
void forward() {

  M_FL.run(FORWARD);
  M_FR.run(FORWARD);
  M_BL.run(FORWARD);
  M_BR.run(FORWARD);
  delay(bdelay);
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
  delay(bdelay);
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
  delay(bdelay);
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
  delay(bdelay);
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
void forward_right(int c_speed) { // c_speed is  a cervatiuare speed

  M_FR.setSpeed(c_speed);
  M_BR.setSpeed(c_speed);

  M_FL.run(FORWARD);
  M_FR.run(FORWARD);
  M_BL.run(FORWARD);
  M_BR.run(FORWARD);
  delay(100);

  stopmode();
  speedset();
}
void forward_left(int c_speed) { // c_speed is  a cervatiuare speed
  M_FL.setSpeed(c_speed);
  M_BL.setSpeed(c_speed);

  M_FL.run(FORWARD);
  M_FR.run(FORWARD);
  M_BL.run(FORWARD);
  M_BR.run(FORWARD);
  delay(100);

  stopmode();
  speedset();
}
void inf_backward(int R_speed, int L_speed, int del) {
  M_FR.setSpeed(R_speed);
  M_FL.setSpeed(L_speed);
  M_BR.setSpeed(R_speed);
  M_BL.setSpeed(L_speed);

  M_FL.run(BACKWARD);
  M_FR.run(BACKWARD);
  M_BL.run(BACKWARD);
  M_BR.run(BACKWARD);
  delay(del);
  stopmode();
}
void line_follower() {
  left_state = digitalRead(left_pin);
  center_state = digitalRead(center_pin);
  right_state = digitalRead(right_pin);
  cin_r_state = digitalRead(cen_r_pin);
  cin_l_state = digitalRead(cen_l_pin);
  cin_l_state = !cin_l_state;
  cin_r_state = !cin_r_state;


  /*
  Serial.print("  ") ;  Serial.print(left_state) ; Serial.print("  ") ;
  Serial.print("  ") ;  Serial.print(cin_l_state); Serial.print("  ") ;
  Serial.print("  ") ; Serial.print(center_state); Serial.print("  ") ;
  Serial.print("  ") ; Serial.print(cin_r_state) ; Serial.print("  ") ;
  Serial.print("  ") ; Serial.print(right_state);Serial.print("  ") ;
  Serial.print("  ") ; Serial.print("  ") ;
  Serial.println();


  */
repeat:


  if (left_state == b &&  cin_l_state == w && center_state == w && cin_r_state == w  &&  right_state == w) { inf_forward(r_speed, 0, 10); last_state = 1; } // first left 

  else if (left_state == w &&  cin_l_state == b && center_state == w && cin_r_state == w  &&  right_state == w) { inf_forward(rr_speed, 0, 10); last_state = 2; } //second lefr 

  else if (left_state == b &&  cin_l_state == b && center_state == w && cin_r_state == w &&  right_state == w) { inf_forward(rr_speed, 0, 10);last_state = 3; } //left lefr 

  else if (left_state == w &&  cin_l_state == b && center_state == b && cin_r_state == w  &&  right_state == w) { inf_forward(cr_speed, 0, 10);last_state = 4; } //  center left 

  else if (left_state == b &&  cin_l_state == b && center_state == b && cin_r_state == w  &&  right_state == w) { inf_forward(cr_speed, 0, 10);last_state = 5; } // center left left 


  else if (left_state == b &&  cin_l_state == w && center_state == b && cin_r_state == w  &&  right_state == w) { inf_forward(rr_speed, 0, 10);last_state = 6; } // center first left 


  else if (left_state == w &&  cin_l_state == b && center_state == b && cin_r_state == b  &&  right_state == w) { inf_forward(c_speed, c_speed, 10);last_state = 7; } //center 
  else if (left_state == w &&  cin_l_state == w && center_state == b && cin_r_state == w  &&  right_state == w) { inf_forward(c_speed, c_speed, inf_delay);last_state = 8; } //center 



  else if (left_state == w &&  cin_l_state == w && center_state == w && cin_r_state == w  &&  right_state == b) { inf_forward(0, l_speed, 10);last_state = 9; } // first right

  else if (left_state == w &&  cin_l_state == w && center_state == w && cin_r_state == b  &&  right_state == w) { inf_forward(0, ll_speed, 10);last_state = 10; } // second righ 

  else if (left_state == w &&  cin_l_state == w && center_state == w && cin_r_state == b  &&  right_state == b) { inf_forward(0, ll_speed, 10);last_state = 11; }  //right right

  else if (left_state == w &&  cin_l_state == b && center_state == b && cin_r_state == b  &&  right_state == b) { inf_forward(0, cl_speed, inf_delay);last_state = 12; }  //center right 

  else if (left_state == w &&  cin_l_state == w && center_state == b && cin_r_state == b  &&  right_state == b) { inf_forward(0, cl_speed, inf_delay);last_state = 13; }    //center right right


  else if (left_state == w &&  cin_l_state == w && center_state == b && cin_r_state == w  &&  right_state == b) { inf_forward(0, ll_speed, inf_delay);last_state = 14; } // center first right



  else if (left_state == b &&  cin_l_state == b && center_state == b  && cin_r_state == b &&  right_state == b) { inf_forward(120, 100, inf_delay); }    //out of line back action 2

  else if (left_state == w &&  cin_l_state == w && center_state == w  && cin_r_state == w &&  right_state == w)
  {


    switch (last_state)
    {
    case 1: inf_forward(r_speed, 0, 10); last_state = 1; break;
    case 2: inf_forward(rr_speed, 0, 10);break;
    case 3: inf_forward(rr_speed, 0, 10); break;
    case 4: inf_forward(cr_speed, 0, 10);; break;
    case 5: inf_forward(cr_speed, 0, 10);break;
    case 6: inf_forward(rr_speed, 0, 10); break;
    case 7: inf_forward(c_speed, c_speed, 10); break;
    case 8: inf_forward(c_speed, c_speed, 10); break;
    case 9: inf_forward(0, l_speed, 150); break;
    case 10: inf_forward(0, ll_speed, 100); break;
    case 11: inf_forward(0, ll_speed, 100); break;
    case 12: inf_forward(0, cl_speed, inf_delay); break;
    case 13: inf_forward(0, cl_speed, inf_delay); break;
    case 14: inf_forward(0, ll_speed, inf_delay); break;
    }

  }

  else { inf_forward(60, 60, inf_delay); }


}
void forwardgo() {

  M_FL.run(FORWARD);
  M_FR.run(FORWARD);
  M_BL.run(FORWARD);
  M_BR.run(FORWARD);
  delay(5);
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
void backwardgo() {

  M_FL.run(BACKWARD);
  M_FR.run(BACKWARD);
  M_BL.run(BACKWARD);
  M_BR.run(BACKWARD);
  delay(5);
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
void rightgo() {

  M_FL.run(FORWARD);
  M_FR.run(BACKWARD);
  M_BL.run(FORWARD);
  M_BR.run(BACKWARD);
  delay(5);
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
void distance_forward(int dist) {

  //Serial.println (dist);

  int turnes = dist / 0.9;
  Serial.println(turnes);

  int rpm = 0;
  for (;;)
  {
    forwardgo();
    photo_val = digitalRead(photo); // photo inturput digital read 
    if (photo_val == 1) { rpm++; }
    if (rpm == turnes) { break; }

  }
  stopmode();
}
void distance_backward(int dist) {


  int turnes = dist / 0.9;
  Serial.println(turnes);

  int rpm = 0;
  for (;;)
  {
    Serial.println("goo");
    backwardgo();
    photo_val = digitalRead(photo); // photo inturput digital read 
    if (photo_val == 1) { rpm++; }
    if (rpm == turnes) { break; }

  }
  stopmode();

}
void rotation(int angel) {


  int turnes = angel / 4.5;
  Serial.println(turnes);

  int rpm = 0;
  for (;;)
  {
    Serial.println("goo");
    rightgo();
    photo_val = digitalRead(photo); // photo inturput digital read 
    if (photo_val == 1) { rpm++; }
    if (rpm == turnes) { break; }

  }
  stopmode();
} 
void forward_c(int R_speed, int L_speed ) {
  M_FR.setSpeed(R_speed);
  M_FL.setSpeed(L_speed);
  M_BR.setSpeed(R_speed);
  M_BL.setSpeed(L_speed);

  M_FL.run(FORWARD);
  M_FR.run(FORWARD);
  M_BL.run(FORWARD);
  M_BR.run(FORWARD);
  delay(5);
}
void loop() {
  /* // ultrasonic code callculations
  *
  *
  *
  ultraone_distance = ultraone() ;
  ultratwo_distance = ultratwo() ;

  Serial.print("Distance1 = " ) ;
  Serial.println(ultraone_distance) ;
  Serial.print("Distance2 =  " ) ;
  Serial.println(ultratwo_distance) ;

  Serial.println(ultraone_distance) ;
  Serial.println(ultratwo_distance) ;
  // if (ultraone_distance <= 15   ) {stopmode();}
  // if (ultratwo_distance <=15  ) {stopmode();}
  */

  //Serial.println (photo_val); // photo inturupt value checker 
  if (mySerial.available()) { // If the bluetooth module has some incoming data from the phone
    Bdata = mySerial.read(); // Read the data, one character at a time
  //  Serial.println(Bdata); // Write char received via Bluetooth to the Serial Monitor of Arduino IDE


    if (Bdata == 'd') { // getting string form user  bluetooth  forward distance 

      char order[100] = "";

      for (;;) { // getting input from user terminal 
        if (mySerial.available()) { // If the bluetooth module has some incoming data from the phone
          Bdata = mySerial.read(); // Read the data, one character at a time
          if (Bdata == 'e') { bcounter = 0; Serial.println(order);break; }
          order[bcounter] = Bdata;
          bcounter++;
        }
      }

      dist = atoi(order);
      //Serial.println (dist);


      distance_forward(dist);
    }
    else if (Bdata == 'b') { // getting string form user  bluetooth backward distance 

      char order[100] = "";

      for (;;) { // getting input from user terminal 
        if (mySerial.available()) { // If the bluetooth module has some incoming data from the phone
          Bdata = mySerial.read(); // Read the data, one character at a time
          if (Bdata == 'e') { bcounter = 0; Serial.println(order);break; }
          order[bcounter] = Bdata;
          bcounter++;
        }
      }

      dist = atoi(order);

      distance_backward(dist);
    }
    else if (Bdata == 'a') {// getting string form user  bluetooth angel routaion 

      char order[100] = "";

      for (;;) { // getting input from user terminal 
        if (mySerial.available()) { // If the bluetooth module has some incoming data from the phone
          Bdata = mySerial.read(); // Read the data, one character at a time
          if (Bdata == 'e') { bcounter = 0; Serial.println(order);break; }
          order[bcounter] = Bdata;
          bcounter++;
        }
      }

      int angel = atoi(order);
      //Serial.println (dist);
      rotation(angel);

    }
    else if (Bdata == 'r') { //getting regtangular shape 


      char order[100] = "";

      for (;;) { // getting input from user terminal 
        if (mySerial.available()) { // If the bluetooth module has some incoming data from the phone
          Bdata = mySerial.read(); // Read the data, one character at a time
          if (Bdata == 'e') { bcounter = 0; Serial.println(order);break; }
          order[bcounter] = Bdata;
          bcounter++;
        }
      }

      dist = atoi(order);
      //Serial.println (dist);


      for (int n = 0; n <= 3; n++) {
        M_FR.setSpeed(150);
        M_FL.setSpeed(150);
        M_BR.setSpeed(150);
        M_BL.setSpeed(150);

        distance_forward(dist);
        delay(320);

        M_FR.setSpeed(222);
        M_FL.setSpeed(222);
        M_BR.setSpeed(222);
        M_BL.setSpeed(222);
        if (n == 3) { break; }
        rotation(92);
      }

    }
    else if (Bdata == 'c') {
  char order[100] = "";

      for (;;) { // getting input from user terminal 
        if (mySerial.available()) { // If the bluetooth module has some incoming data from the phone
          Bdata = mySerial.read(); // Read the data, one character at a time
          if (Bdata == 'e') { bcounter = 0; break; }
          order[bcounter] = Bdata;
          bcounter++;
        }
      }

      dist = atoi(order);
      
   //  float ceta = 0.15 ;
  //int rspeed = (dist+8)*ceta ;  
//int lspeed = (dist-8)*ceta ; 








  int circule_dist = 2*3.14*dist ;
  int turnes =  circule_dist/ 0.9;
   turnes = turnes +(0.3 * turnes);
  int rpm = 0;

  for(;;){
    photo_val = digitalRead(photo); // photo inturput digital read 
    Serial.println(photo_val);
    if (photo_val == 1) { rpm++; Serial.println(rpm);}
    if (rpm == turnes) { stopmode(); Bdata ='0' ;Serial.println("stop"); break;}
    forward_c ( dist ,  200) ; 
  }
    }
    else if (Bdata == 'i') {
  char order[100] = "";

      for (;;) { // getting input from user terminal 
        if (mySerial.available()) { // If the bluetooth module has some incoming data from the phone
          Bdata = mySerial.read(); // Read the data, one character at a time
          if (Bdata == 'e') { bcounter = 0; break; }
          order[bcounter] = Bdata;
          bcounter++;
        }
      }

      dist = atoi(order);
      
   //  float ceta = 0.15 ;
  //int rspeed = (dist+8)*ceta ;  
//int lspeed = (dist-8)*ceta ; 








  int circule_dist = 2*3.14*dist ;
  int turnes =  circule_dist/ 0.9;
  // turnes = turnes +(0.3 * turnes);
  int rpm = 0;

  for(;;){
    photo_val = digitalRead(photo); // photo inturput digital read 
    Serial.println(photo_val);
    if (photo_val == 1) { rpm++; Serial.println(rpm);}
    if (rpm == turnes) { stopmode(); Bdata ='0' ;Serial.println("stop"); break;}
    forward_c ( dist ,  200) ; 
    
  }
dist = dist - 15;
  rpm =0 ; 
     //turnes = turnes +(0. * turnes);

  for(;;){
    photo_val = digitalRead(photo); // photo inturput digital read 
    Serial.println(photo_val);
    if (photo_val == 1) { rpm++; Serial.println(rpm);}
    if (rpm == turnes) { stopmode(); Bdata ='0' ;Serial.println("stop"); break;}
    
    forward_c ( 220 ,  dist) ; 
    }
     }
    else if (Bdata == 1, 2, 3, 4) {
      switch (Bdata) { // arrows directions 
      case '1': forward(); break;
      case '2': backward(); break;
      case '3': right(); break;
      case '4': left(); break;
        //  case 'A':forward_right(50) ;
        // case 'b':forward_left (50);

      }
    }
    else if (Bdata == 5) { line_follower(); }//car in line follow mode 

  }
}









