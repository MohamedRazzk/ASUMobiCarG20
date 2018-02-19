/*
**********************************************************************
* Project           : AsuMobiCar
*
* Program name      : Serial Read 
* 
* File              : Serialread.ino
*
* Author            : Mohamed Fathi Mohamed Razzk 
*
* Date created      : 19/2/2018 - 2:30 PM 
*
* Purpose           : Reading input from computer 
* 
* 
* Cource            : CSE271  - System Dynamics & Control Components
*
* Revision History  : ---------------
*
**********************************************************************
*/
// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Serial Read Screen");
  Serial.begin(9600);
}

void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  lcd.print(millis() / 1000);
    lcd.print(Serial.read());

}

