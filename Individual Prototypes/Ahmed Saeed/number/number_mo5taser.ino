int numb[]={B00111111,B00000110,B01011011,B01001111,B01100110,B01101101,B01011110,B00000111,B01111111,B01100111};
int x;
void setup() {
  // put your setup code here, to run once:
DDRD=B11111111;
}

void loop() {
  // put your main code here, to run repeatedly:
for(x=0;x<10;x++)
{
  PORTD=numb[x];
  delay(1000);
}
 
 
}
