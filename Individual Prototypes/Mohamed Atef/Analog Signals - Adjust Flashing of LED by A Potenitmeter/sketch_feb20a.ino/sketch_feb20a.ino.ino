
int led = 7;
void setup() {
  pinMode(led,OUTPUT);
}

void loop() {
  int reading = analogRead(A0);
  digitalWrite(led,HIGH);
  delay(reading * 4);
  digitalWrite(led,LOW);
  delay(reading * 4);
}
