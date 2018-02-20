int ledpins[] ={4,5,6,7};
int k=0;
void setup() {
  // put your setup code here, to run once:
for(int index=0;index<4;index++)

  pinMode (ledpins[index],OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
for(int k=0;k<4;k++);
{
  if(k==3)
  {
    for(int x=3;x>0;x--)
    {
      digitalWrite (ledpins[x],HIGH);
      delay(1000);
      digitalWrite (ledpins[x],LOW);
      
    }
  }
else
{
  digitalWrite (ledpins[k],HIGH);
  delay(1000);
  digitalWrite (ledpins[k],LOW);
  
}
}
 
}
