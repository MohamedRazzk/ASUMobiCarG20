int LED4=4;
int LED5=5;
int LED6=6;
int LED7=7;
void setup() {
  // put your setup code here, to run once:
pinMode(LED4,OUTPUT);
pinMode(LED5,OUTPUT);
pinMode(LED6,OUTPUT);
pinMode(LED7,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(LED4,HIGH);
delay(1000);
digitalWrite(LED4,LOW);
digitalWrite(LED5,HIGH);
delay(1000);
digitalWrite(LED5,LOW);
digitalWrite(LED6,HIGH);
delay(1000);
digitalWrite(LED6,LOW);
digitalWrite(LED7,HIGH);
delay(1000);
digitalWrite(LED7,HIGH);
delay(1000);
digitalWrite(LED7,LOW);
digitalWrite(LED6,HIGH);
delay(1000);
digitalWrite(LED6,LOW);
digitalWrite(LED5,HIGH);
delay(1000);
digitalWrite(LED5,LOW);
digitalWrite(LED4,HIGH);
delay(1000);
digitalWrite(LED4,LOW);
}
