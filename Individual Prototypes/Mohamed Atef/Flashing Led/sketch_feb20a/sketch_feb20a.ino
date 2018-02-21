int led = 7;
int switchPen = 2;
void setup() {
  pinMode(led,OUTPUT);
  
}

void loop() {
  digitalWrite(led,HIGH);
  delay(500);
  digitalWrite(led,LOW);
  delay(500);

}
