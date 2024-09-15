void feeding()
{
  if(rightt==1 )
  {
//   if(digitalRead(ps)==LOW)
//   {
    //Serial.println("object detected");
  // digitalWrite(dir,LOW);
  // digitalWrite(pw,LOW);
  // //delay(500);
  // }
  //  else if(digitalRead(ps)==HIGH)
  //  {
   // Serial.println("object not detected");
    digitalWrite(dir,HIGH);
  analogWrite(pw,100);
//currstaterightt=prevstaterightt;
  // }
  }
  //currstaterightt=prevstaterightt;
//  else if(leftt==1 )
//  {
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
//    digitalWrite(dir,LOW);
//  analogWrite(pw,100);
  // }
 // currstateleftt=prevstateleftt;
 // }
  // currstateleftt=prevstateleftt;
  else
  {
    digitalWrite(pw,LOW);
  }
}
