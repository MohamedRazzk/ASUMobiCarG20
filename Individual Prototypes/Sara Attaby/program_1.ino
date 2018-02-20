
int pulse=12;
void setup() {
  // put your setup code here, to run once:


pinMode(pulse,OUTPUT);
}
void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(pulse,HIGH);
delay(500);
digitalWrite(pulse,LOW);
delay(1500);
}
