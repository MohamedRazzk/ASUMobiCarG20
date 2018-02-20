 int green = 13 ;
 int yellow =  12 ;
 int red = 11 ; 
void setup() {
 
  pinMode (green,OUTPUT) ;
  pinMode (yellow,OUTPUT) ;
  pinMode (red,OUTPUT) ;

}

void loop() {

  digitalWrite (red,HIGH) ;
  digitalWrite (yellow,LOW) ;
   digitalWrite (green,LOW) ;
   delay (4000) ;

     digitalWrite (yellow,HIGH) ;
  digitalWrite (red,LOW) ;
  digitalWrite (green,LOW) ;
  delay (4000) ;

    digitalWrite (green,HIGH) ;
  digitalWrite (red,LOW) ;
  digitalWrite (yellow,LOW) ;
  delay (4000) ;


}
