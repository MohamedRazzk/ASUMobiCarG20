#include <AFMotor.h>

class car
{
int x1;  int x2;  int x3;  int x4;            //dool el pin el car btrkab 3leha 
public:
car(int y1,int y2,int y3,int y4)
  {
    x1=y1; x2=y2; x3=y3; x4=y4;
    /*hena ana fared ane msah8al el motor 3la freq=1khz     
     */
    AF_DCMotor motor1(x1);
    AF_DCMotor motor2(x2);
    AF_DCMotor motor3(x3);
    AF_DCMotor motor4(x4);
    motor1.setSpeed(255);
    motor2.setSpeed(255);
    motor3.setSpeed(255);
    motor4.setSpeed(255);
    motor1.run(RELEASE);
    motor2.run(RELEASE);
    motor3.run(RELEASE);
    motor4.run(RELEASE);
  }
void forward()
{
    AF_DCMotor motor1(x1);
    AF_DCMotor motor2(x2);
    AF_DCMotor motor3(x3);
    AF_DCMotor motor4(x4);
    motor1.run(FORWARD);
    motor2.run(FORWARD);
    motor3.run(FORWARD);
    motor4.run(FORWARD);
}
void back()
{
    AF_DCMotor motor1(x1);
    AF_DCMotor motor2(x2);
    AF_DCMotor motor3(x3);
    AF_DCMotor motor4(x4);
    motor1.run(BACKWARD);
    motor2.run(BACKWARD);
    motor3.run(BACKWARD);
    motor4.run(BACKWARD);
}
//assume car  motor    1  2
//                     3   4

void left()
{
    AF_DCMotor motor1(x1);
    AF_DCMotor motor2(x2);
    AF_DCMotor motor3(x3);
    AF_DCMotor motor4(x4);
    motor1.run(FORWARD);
    motor2.run(RELEASE);
    motor3.run(FORWARD);
    motor4.run(RELEASE);
}
void right()
{
    AF_DCMotor motor1(x1);
    AF_DCMotor motor2(x2);
    AF_DCMotor motor3(x3);
    AF_DCMotor motor4(x4);
    motor1.run(RELEASE);
    motor2.run(FORWARD);
    motor3.run(RELEASE);
    motor4.run(FORWARD);
}

};

car sabk_w_la7ek(1,2,3,4);





void setup() {
  // put your setup code here, to run once:
}
void loop() {
 
sabk_w_la7ek.forward();
delay(10000);

sabk_w_la7ek.back();
delay(10000);



}
