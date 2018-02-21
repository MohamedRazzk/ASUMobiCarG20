int switchPin = 8;
int openPin = 7;
void setup() {
  pinMode(openPin,OUTPUT);
  pinMode(switchPin,INPUT);
}

void loop() {
  int switchMode = digitalRead(switchPin);
  if (switchMode == HIGH)
    digitalWrite(openPin,HIGH);
   else
    digitalWrite(openPin,LOW);
}
