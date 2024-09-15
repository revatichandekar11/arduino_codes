//#define motor1 6
//#define motor2 7
//#define motor3 9
//#define motor4 10
//#define dir1 22
//#define dir2 24
//#define dir3 26
//#define dir4 28

int ms;

void forward()
  {
    //frontleft
    digitalWrite(dir1,HIGH);
    analogWrite(motor1,ms);
    //frontright
    digitalWrite(dir2,HIGH);
     analogWrite(motor2,ms);
     //backleft
    digitalWrite(dir3,HIGH);
     analogWrite(motor3,ms);
     //backright
    digitalWrite(dir4,HIGH);
     analogWrite(motor4,ms);
  }
void backward()
{
 
    //frontleft
    digitalWrite(dir1,LOW);
    analogWrite(motor1,ms);
    //frontright
    digitalWrite(dir2,LOW);
     analogWrite(motor2,ms);
     //backleft
    digitalWrite(dir3,LOW);
     analogWrite(motor3,ms);
     //backright
    digitalWrite(dir4,LOW);
     analogWrite(motor4,ms);
  

}
void rightm()
{
  //frontleft
    digitalWrite(dir1,HIGH);
    analogWrite(motor1,ms);
    //frontright
    digitalWrite(dir2,LOW);
     analogWrite(motor2,ms);
     //backleft
    digitalWrite(dir3,LOW);
     analogWrite(motor3,ms);
     //backright
    digitalWrite(dir4,HIGH);
     analogWrite(motor4,ms);
}
void leftm()
{
  //frontleft
    digitalWrite(dir1,LOW);
    analogWrite(motor1,ms);
    //frontright
    digitalWrite(dir2,HIGH);
     analogWrite(motor2,ms);
     //backleft
    digitalWrite(dir3,HIGH);
     analogWrite(motor3,ms);
     //backright
    digitalWrite(dir4,LOW);
     analogWrite(motor4,ms);
}
void clockwise()
{
  //frontleft
    digitalWrite(dir1,HIGH);
    analogWrite(motor1,ms);
    //frontright
    digitalWrite(dir2,LOW);
     analogWrite(motor2,ms);
     //backleft
    digitalWrite(dir3,HIGH);
     analogWrite(motor3,ms);
     //backright
    digitalWrite(dir4,LOW);
     analogWrite(motor4,ms);
}
void anticlockwise()
{
    //frontleft
    digitalWrite(dir1,LOW);
    analogWrite(motor1,ms);
    //frontright
    digitalWrite(dir2,HIGH);
     analogWrite(motor2,ms);
     //backleft
    digitalWrite(dir3,LOW);
     analogWrite(motor3,ms);
     //backright
    digitalWrite(dir4,HIGH);
     analogWrite(motor4,ms);
}
void stopmotor()
{
  //digitalWrite(dir1,LOW);
  digitalWrite(motor1,LOW);
    //analogWrite(motor1,255);
    //frontright
    //digitalWrite(dir2,LOW);
  digitalWrite(motor2,LOW);
     //analogWrite(motor1,255);
     //backleft
   // digitalWrite(dir3,LOW);
  digitalWrite(motor3,LOW);
     //analogWrite(motor1,255);
     //backright
    //digitalWrite(dir4,LOW);
  digitalWrite(motor4,LOW);
     //analogWrite(motor1,255);
}
