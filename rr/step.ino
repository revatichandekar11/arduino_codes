//#define dirpin 30
//#define steppin 4

void stepper()
{
  if(up==1)
  {
    digitalWrite(enable,LOW);
    digitalWrite(enable2,LOW);
    digitalWrite(dirpin,HIGH);
    digitalWrite(dirpin2,HIGH);
    
    for(int i=0;i<800;i++)
    {
      digitalWrite(steppin,HIGH);
      delayMicroseconds(500);
      digitalWrite(steppin,LOW);
      delayMicroseconds(500);
      digitalWrite(steppin2,HIGH);
      delayMicroseconds(500);
      digitalWrite(steppin2,LOW);
      delayMicroseconds(500);
    }
  }
  if(down==1)
  {
    digitalWrite(enable,LOW);
    digitalWrite(enable2,LOW);
    digitalWrite(dirpin,LOW);
    digitalWrite(dirpin2,LOW);
    
    for(int i=0;i<800;i++)
    {
      digitalWrite(steppin,HIGH);
      delayMicroseconds(500);
      digitalWrite(steppin,LOW);
      delayMicroseconds(500);
      digitalWrite(steppin2,HIGH);
      delayMicroseconds(500);
      digitalWrite(steppin2,LOW);
      delayMicroseconds(500);
    }
  }
  if(cir==1)
  {
    digitalWrite(enable,LOW);
    digitalWrite(enable2,LOW);
    digitalWrite(dirpin,HIGH);
    digitalWrite(dirpin2,HIGH);
    
    for(int i=0;i<1;i++)
    {
      digitalWrite(steppin,HIGH);
      delayMicroseconds(500);
      digitalWrite(steppin,LOW);
      delayMicroseconds(500);
      digitalWrite(steppin2,HIGH);
      delayMicroseconds(500);
      digitalWrite(steppin2,LOW);
      delayMicroseconds(500);
    }
  }
}
