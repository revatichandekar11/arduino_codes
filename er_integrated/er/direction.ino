int ms;
float mapCubic(float x, float inMin, float inMax, float outMin, float outMax) {
  float normalizedX = (x - inMin) / (inMax - inMin);
  float mappedValue = normalizedX * normalizedX * normalizedX * (outMax - outMin) + outMin;
  return mappedValue;
}

void forward()
  {
    ms=mapCubic(ly, Buff1, 127, 0, fast);
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
    digitalWrite(dir4,HIGH);
     analogWrite(motor4,ms);
  }
void backward()
{
    ms= mapCubic(ly, Buff2, -128, 0, fast);
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
    digitalWrite(dir4,LOW);
     analogWrite(motor4,ms);
  

}
void rightm()
{
  ms=mapCubic(lx, Buff1, 127, 0, fast);
  //frontleft
    digitalWrite(dir1,LOW);
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
void leftm()
{
  ms=mapCubic(lx, Buff2, -128, 0, fast);
  //frontleft
    digitalWrite(dir1,HIGH);
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
void clockwise()
{
  ms=mapCubic(rx, Buff1, 127, 0, fast);
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
    digitalWrite(dir4,HIGH);
     analogWrite(motor4,ms);
}
void anticlockwise()
{
  ms=mapCubic(rx, Buff2, -128, 0,fast);
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
    digitalWrite(dir4,LOW);
     analogWrite(motor4,ms);
}
void stopmotor()
{
  ms=0;
  //frontleft
    //digitalWrite(motor1,LOW);
    analogWrite(motor1,ms);
    //frontright
    //digitalWrite(motor2,LOW);
     analogWrite(motor2,ms);
     //backleft
    //digitalWrite(motor3,LOW);
    analogWrite(motor3,ms);
     //backright
    //digitalWrite(motor4,LOW);
     analogWrite(motor4,ms);
  
}
