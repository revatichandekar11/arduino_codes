void feeding()
{
  if(right==1)
  {
  // if(digitalRead(ps)==LOW)
  // {
  //   Serial.println("object detected");
  // digitalWrite(dir,LOW);
  // digitalWrite(pw,LOW);
  // //delay(500);
  // }
  //  else if(digitalRead(ps)==HIGH)
  //  {
  //   Serial.println("object not detected");
    digitalWrite(dir,HIGH);
  analogWrite(pw,220);
   //}
  }
  if(left==1)
  {
  //   if(digitalRead(ps)==LOW)
  // {
  //   Serial.println("object detected");
  // digitalWrite(dir,LOW);
  // digitalWrite(pw,LOW);
  // //delay(500);
  // }
  //  else if(digitalRead(ps)==HIGH)
  //  {
  //   Serial.println("object not detected");
    digitalWrite(dir,LOW);
  analogWrite(pw,220);
  // }
  }
}
