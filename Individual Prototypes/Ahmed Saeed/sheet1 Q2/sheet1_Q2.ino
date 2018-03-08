int led[]={B00010000,B00100000,B01000000,B10000000,B01000000,B00100000,B00010000};
void setup() {
  // put your setup code here, to run once:
DDRD=B11110000;
}

void loop() {
  // put your main code here, to run repeatedly:
for(int x=0;x<=6;x++)
{
  PORTD=led[x];
  delay(1000);
}

}
