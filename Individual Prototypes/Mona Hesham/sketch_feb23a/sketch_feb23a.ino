 int led1 = 10 ;
 int led2 =  11 ;
 int led3 = 12 ; 
 int led4 = 14 ;
void setup() {
 
  pinMode (led1,OUTPUT) ;
  pinMode (led2,OUTPUT) ;
  pinMode (led3,OUTPUT) ;
  pinMode (led4,OUTPUT) ;
}

void loop() {

  digitalWrite (led1,HIGH) ;
  digitalWrite (led2,LOW) ;
   digitalWrite (led3,LOW) ;
   digitalWrite (led4,LOW) ;
   delay (1000) ;

     digitalWrite (led2,HIGH) ;
  digitalWrite (led1,LOW) ;
  digitalWrite (led3,LOW) ;
  digitalWrite (led4,LOW) ;
  delay (1000) ;

    digitalWrite (led3,HIGH) ;
  digitalWrite (led1,LOW) ;
  digitalWrite (led2,LOW) ;
  digitalWrite (led4,LOW) ;
 delay (1000) ;
 
 digitalWrite (led4,HIGH) ;
 digitalWrite (led1,LOW) ;
 digitalWrite (led2,LOW) ;
 digitalWrite (led3,LOW) ;
 delay (1000) ;

 digitalWrite (led3,HIGH) ;
 digitalWrite (led1,LOW) ;
 digitalWrite (led2,LOW) ;
 digitalWrite (led4,LOW) ;
 delay (1000) ;

 digitalWrite (led2,HIGH) ;
 digitalWrite (led1,LOW) ;
 digitalWrite (led3,LOW) ;
 digitalWrite (led4,LOW) ;
 delay (1000) ;

 digitalWrite (led1,HIGH) ;
 digitalWrite (led2,LOW) ;
 digitalWrite (led3,LOW) ;
 digitalWrite (led4,LOW) ;


}
