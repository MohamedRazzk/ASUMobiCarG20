
int ldr = A0;
int led = 7;
void setup() {
  pinMode(led,OUTPUT);
}

void loop() {
  int ldrReading = analogRead(ldr);
  if (ldrReading <=  341)
    digitalWrite(led,HIGH);
  else
    digitalWrite(led,LOW);
  delay(1000);
}
