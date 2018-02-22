int led = 10 ;
int switch1 =4;
int switchstate =0;

void setup() {
  pinMode (led,OUTPUT);
  pinMode (switch1,INPUT);

}

void loop() {
  switchstate = digitalRead (switch1);
  if (switchstate == HIGH)
  digitalWrite (led,HIGH);
  else
  digitalWrite (led,LOW);

}
