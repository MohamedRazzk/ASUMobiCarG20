/*
**********************************************************************
* Project           : AsuMobiCar
*
* Program name      : Blink
* 
* File              : Blink.ino
*
* Author            : Mohamed Fathi Mohamed Razzk 
*
* Date created      : 19/2/2018 - 2 PM 
*
* Purpose           : Delayig a led 
* 
* Cource            : CSE271  - System Dynamics & Control Components
*
* Revision History  : ---------------
*
**********************************************************************
*/

void setup() {
  // initialize digital pin 13 as an output.
  pinMode(13, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);              // wait for a second
  digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);              // wait for a second
}
