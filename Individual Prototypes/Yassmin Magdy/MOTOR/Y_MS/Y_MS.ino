
int EN2= 9 ;
void setup() {
   (EN2,OUTPUT) ;
  pinMode (5, OUTPUT) ;
  pinMode (6, OUTPUT) ;
  pinMode (9, OUTPUT) ;
 
  pinMode (EN2,OUTPUT);
  pinMode (10, OUTPUT) ;
  }

void forward ()
{
  analogWrite (5,100) ;
   analogWrite (6,0) ;
   analogWrite (9,0) ;
   analogWrite (10,100) ;
  
  }
  void backward ()
  {
  analogWrite (5,0) ;
 analogWrite (6,100) ;
  analogWrite (9,100) ;
  analogWrite (10,0) ;
  
    }
    void left ()
    {
   analogWrite (5,100) ;
   analogWrite (6,0) ;
   analogWrite (9,100) ;
   analogWrite (10,0) ;
  
      }
      void right ()
      {
   analogWrite (5,0) ;
   analogWrite (6,100) ;
   analogWrite (9,0) ;
   analogWrite (10,100) ;
  
        }
        void stop1 ()
        {
   analogWrite (5,0) ;
  analogWrite (6,0) ;
  analogWrite (9,0) ;
   analogWrite (10,0) ;
  
          }







void loop() {
  
  
  digitalWrite(EN2,HIGH) ;
  forward();
  delay (200) ;
  stop1() ;
  delay (200) ;
  left() ;
  delay (200);
  forward ();
  delay (200) ;
  right() ; 
  delay (200) ;
  backward() ;
  delay (200) ;

}
