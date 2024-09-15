//int ms;

void forward()
  {
    //ms=map(ly, Buff1, 127, 0, fast);
    //frontleft
    digitalWrite(dir1,LOW);
    analogWrite(motor1,lf);
    //frontright
    digitalWrite(dir2,HIGH);
     analogWrite(motor2,rf);
     //backleft
    digitalWrite(dir3,LOW);
     analogWrite(motor3,rb);
     //backright
    digitalWrite(dir4,HIGH);
     analogWrite(motor4,lb);
  }
void backward()
{
    //ms= map(ly, Buff2, -128, 0, fast);
    //frontleft
    digitalWrite(dir1,HIGH);
    analogWrite(motor1,lf);
    //frontright
    digitalWrite(dir2,LOW);
     analogWrite(motor2,rf);
     //backleft
    digitalWrite(dir3,HIGH);
     analogWrite(motor3,rb);
     //backright
    digitalWrite(dir4,LOW);
     analogWrite(motor4,lb);
  

}
void rightm()
{
  //ms=map(lx, Buff1, 127, 0, fast);
  //frontleft
    digitalWrite(dir1,LOW);
    analogWrite(motor1,lf);
    //frontright
    digitalWrite(dir2,LOW);
     analogWrite(motor2,rf);
     //backleft
    digitalWrite(dir3,LOW);
     analogWrite(motor3,rb);
     //backright
    digitalWrite(dir4,LOW);
     analogWrite(motor4,lb);
}
void leftm()
{
  //ms=map(lx, Buff2, -128, 0, fast);
  //frontleft
    digitalWrite(dir1,HIGH);
    analogWrite(motor1,lf);
    //frontright
    digitalWrite(dir2,HIGH);
     analogWrite(motor2,rf);
     //backleft
    digitalWrite(dir3,HIGH);
     analogWrite(motor3,rb);
     //backright
    digitalWrite(dir4,HIGH);
     analogWrite(motor4,lb);
}
void clockwise()
{
  //ms=map(rx, Buff1, 127, 0, fast);
  //frontleft
    digitalWrite(dir1,LOW);
    analogWrite(motor1,lf);
    //frontright
    digitalWrite(dir2,LOW);
     analogWrite(motor2,rf);
     //backleft
    digitalWrite(dir3,HIGH);
     analogWrite(motor3,rb);
     //backright
    digitalWrite(dir4,HIGH);
     analogWrite(motor4,lb);
}
void anticlockwise()
{
  //ms=map(rx, Buff2, -128, 0,fast);
    //frontleft
    digitalWrite(dir1,HIGH);
    analogWrite(motor1,lf);
    //frontright
    digitalWrite(dir2,HIGH);
     analogWrite(motor2,rf);
     //backleft
    digitalWrite(dir3,LOW);
     analogWrite(motor3,rb);
     //backright
    digitalWrite(dir4,LOW);
     analogWrite(motor4,lb);
}
void stopmotor()
{
  
  //frontleft
    //digitalWrite(motor1,LOW);
    analogWrite(motor1,0);
    //frontright
    //digitalWrite(motor2,LOW);
     analogWrite(motor2,0);
     //backleft
    //digitalWrite(motor3,LOW);
    analogWrite(motor3,0);
     //backright
    //digitalWrite(motor4,LOW);
     analogWrite(motor4,0);
  
}
