#include <AFMotor.h>
#include <SoftwareSerial.h>

AF_DCMotor motor(1);
SoftwareSerial bt(10,11);
String device;

void setup() {
  // put your setup code here, to run once:
motor.setSpeed(255);
bt.begin(9600);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
while(bt.available())
{
  delay(10);
  char c=bt.read();
  device+=c;
}
if(device.length()>0)
{
  Serial.println(device);
}
if(device=="f")
{
  motor.run(FORWARD);
}
else if(device=="b")
{
   motor.run(BACKWARD);
}

device="";
}
