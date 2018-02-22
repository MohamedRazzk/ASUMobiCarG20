
int lm35 = A0;
int fan = 7;
int comingValue = 26;

void swapValues(){
  if (comingValue == 26){
    comingValue = 30;
    digitalWrite(fan,LOW);
    }
   else if (comingValue == 30){
    comingValue = 26;
    digitalWrite(fan,LOW);
    }
  else
    return;
  }
void setup() {
  pinMode(fan,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int tempReading = analogRead(lm35) * 5.0 / 1023.0 * 100;
  Serial.println(tempReading);
  if (tempReading ==  comingValue)
    swapValues();
  delay(1000);
}
