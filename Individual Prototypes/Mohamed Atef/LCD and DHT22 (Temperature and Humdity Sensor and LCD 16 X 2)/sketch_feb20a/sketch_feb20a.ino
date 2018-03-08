#include<LiquidCrystal.h>
#include "DHT.h"
#define DHTPIN 8
#define DHTTYPE DHT22

LiquidCrystal lcd(12,11,4,5,6,7);

DHT dht(DHTPIN,DHTTYPE);
void setup() {
  dht.begin();
  lcd.begin(16,2);
  Serial.begin(9600);
}

void loop() {
  float temp = dht.readTemperature();
  float hum = dht.readHumidity();
  lcd.clear();
  lcd.setCursor(0,0);
  if (isnan(temp) || isnan(hum))
    //Serial.println("Fail to Read");
    lcd.print("Fail to Read");
  else
   {
    lcd.print("temp: ");
    lcd.print(temp);
    lcd.setCursor(0,1);
    lcd.print(" hum: ");
    lcd.print(hum);
   /*Serial.print("temp: ");
   Serial.print(temp);
   Serial.print(" hum: ");
   Serial.println(hum);*/
   }
   delay(1000);
   
  
}
