
int EN1= 12 ;
int EN2= 13 ;
void setup() {
  pinMode (EN1,OUTPUT) ;
  pinMode (EN2,OUTPUT) ;
  pinMode (5, OUTPUT) ;
  pinMode (6, OUTPUT) ;
  pinMode (9, OUTPUT) ;
  pinMode (10, OUTPUT) ;
}
void forward ()
{
  analogWrite (5,1) ;
   analogWrite (6,0) ;
   analogWrite (9,0) ;
   analogWrite (10,1) ;
  
  }
  void backward ()
  {
   digitalWrite (5,0) ;
   digitalWrite (6,1) ;
   digitalWrite (9,1) ;
   digitalWrite (10,0) ;
  
    }
    void left ()
    {
   digitalWrite (5,1) ;
   digitalWrite (6,0) ;
   digitalWrite (9,1) ;
   digitalWrite (10,0) ;
  
      }
      void right ()
      {
   digitalWrite (5,0) ;
   digitalWrite (6,1) ;
   digitalWrite (9,0) ;
   digitalWrite (10,1) ;
  
        }
        void stop1 ()
        {
   digitalWrite (5,0) ;
   digitalWrite (6,0) ;
   digitalWrite (9,0) ;
   digitalWrite (10,0) ;
  
          }
void loop() {
  digitalWrite(EN1,HIGH) ;
  digitalWrite(EN2,HIGH) ;
  forward;
  delay (200) ;
  stop1 ;
  delay (200) ;
  left ;
  delay (200);
  forward ;
  delay (200) ;
  right ; 
  delay (200) ;
  backward ;
  delay (200) ;

}
