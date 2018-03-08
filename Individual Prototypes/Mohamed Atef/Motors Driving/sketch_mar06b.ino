//The differential inputs of each motor takes 4 x 2 pins
int m1_high = 8;
int m1_low = 9;
int m2_high = 10;
int m2_low = 11;
int m3_high = 12;
int m3_low = 13;
int m4_high = 6;
int m4_low = 7;

// the push button pin to control the motors movement
int fw = 2;
int left = 3;
int bw = 4;
int right = 5;


// function to move single motor forward if it is given 1,
// backward if -1, no power "spinning with inertia" if 0.
void moveMotor(int motorH,int motorL,int mode){
  switch (mode){
    case 0:
      digitalWrite(motorH,LOW);
      digitalWrite(motorL,LOW);
      break;
    case 1:
      digitalWrite(motorH,HIGH);
      digitalWrite(motorL,LOW);
      break;
    case -1:
      digitalWrite(motorH,LOW);
      digitalWrite(motorL,HIGH);
      break;
  }
}

// function that uses the previous function to move all the motor
// in a given direction       1   2   3
//                            4   5   6
//                            7   8   9
// 2 to move all the motors forward
// 4 to move left
// 6 to move right
// 8 for backward
// 5 for removing the power from all the motors "all spinning 
// with inertia"

void moveAll(int mode){
  switch (mode){
    case 2:
      moveMotor(m1_high,m1_low,1);
      moveMotor(m2_high,m2_low,1);
      moveMotor(m3_high,m3_low,1);
      moveMotor(m4_high,m4_low,1);
      break;
    case 8:
      moveMotor(m1_high,m1_low,-1);
      moveMotor(m2_high,m2_low,-1);
      moveMotor(m3_high,m3_low,-1);
      moveMotor(m4_high,m4_low,-1);
      break;
    case 4:
      moveMotor(m1_high,m1_low,0);
      moveMotor(m3_high,m3_low,0);
      break;
    case 6:
      moveMotor(m2_high,m2_low,0);
      moveMotor(m4_high,m4_low,0);
      break;
    case 5:
      moveMotor(m1_high,m1_low,0);
      moveMotor(m2_high,m2_low,0);
      moveMotor(m3_high,m3_low,0);
      moveMotor(m4_high,m4_low,0);
      break;
  }
}

void setup() {
  pinMode(m1_high,OUTPUT);
  pinMode(m1_low,OUTPUT);
  pinMode(m2_high,OUTPUT);
  pinMode(m2_low,OUTPUT);
  pinMode(m3_high,OUTPUT);
  pinMode(m3_low,OUTPUT);
  pinMode(m4_high,OUTPUT);
  pinMode(m4_low,OUTPUT);
  pinMode(fw,INPUT);
  pinMode(left,INPUT);
  pinMode(bw,INPUT);
  pinMode(right,INPUT);
  digitalWrite(m1_high,LOW);
  digitalWrite(m1_low,LOW);
  digitalWrite(m2_high,LOW);
  digitalWrite(m2_low,LOW);
  digitalWrite(m3_high,LOW);
  digitalWrite(m3_low,LOW);
  digitalWrite(m4_high,LOW);
  digitalWrite(m4_low,LOW);

  //Serial.begin(9600);

}

void loop() {
  int fwMode = digitalRead(fw);
  int leftMode = digitalRead(left);
  int bwMode = digitalRead(bw);
  int rightMode = digitalRead(right);

  if (fwMode || bwMode)
  {
    if (fwMode && bwMode)
    {
      bwMode = 0;
      fwMode = 0;
    }
    if (fwMode)
    {
      moveAll(2);
    }
    if (bwMode)
    {
      moveAll(8);
    }
  }


  if (leftMode || rightMode)
  {
    if (leftMode && rightMode)
    {
      leftMode = 0;
      rightMode = 0;
    }
    if (leftMode)
    {
      moveAll(4);
    }
    if (rightMode)
    {
      moveAll(6);
    }
  }
  if (!fwMode && !bwMode && !leftMode && !rightMode)
    moveAll(5);

  /*Serial.print("fw :");
  Serial.println(fwMode);

  Serial.print("left :");
  Serial.println(leftMode);

  Serial.print("bw :");
  Serial.println(bwMode);

  Serial.print("right :");
  Serial.println(rightMode);

  delay(2000);*/

}
