void encup()
{
  if(upp==1)
  {
    digitalWrite(enc,HIGH);
    analogWrite(pwup,100);
    if(digitalRead(ps)==LOW)
    digitalWrite(pwup,LOW);
    //currstateupp=prevstateupp;
  }
  
//  else if(downn==1 )
//  {
//    digitalWrite(enc,LOW);
//    analogWrite(pwup,100);
//   //currstatedownn=prevstatedownn; 
//  }
  
  else{
    digitalWrite(pwup,LOW);
  }
}
