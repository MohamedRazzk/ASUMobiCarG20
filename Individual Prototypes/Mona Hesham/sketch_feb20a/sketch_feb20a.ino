#include <SoftwareSerial.h>

//Change these to whatever pins you're using
SoftwareSerial blueSerial(0, 1); // RX, TX

void setup()
{
  Serial.begin(9600);
  blueSerial.begin(38400);
  pinMode(9, OUTPUT);
  digitalWrite(9, HIGH);
}

void loop()
{
  if (blueSerial.available())
  {
    Serial.write(blueSerial.read());
  }
  if (Serial.available())
  {
    blueSerial.write(Serial.read());
  }
}
