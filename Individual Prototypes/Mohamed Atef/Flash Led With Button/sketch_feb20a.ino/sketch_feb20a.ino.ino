int led = 7;
int switchPen = 2;
void setup() {
  pinMode(led,OUTPUT);
  pinMode(switchPen,INPUT);
}

void loop() {
  int switchMode = digitalRead(switchPen);
  if (switchMode == HIGH)
    digitalWrite(led,HIGH);
   else
    digitalWrite(led,LOW);

}
