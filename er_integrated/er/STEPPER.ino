//#define dirpin 30
//#define steppin 4
//#define enable 25
//
//void setup() {
//  pinMode(dirpin,OUTPUT);
//  pinMode(steppin,OUTPUT);
//  pinMode(enable,OUTPUT);
//  digitalWrite(enable,HIGH);
//
//}

void stepper() {
  if(cro==1)
  {
digitalWrite(en,LOW);
    //digitalWrite(enable2,HIGH);
    digitalWrite(dirpin,HIGH);
    //digitalWrite(dirpin2,HIGH);
    
    for(int i=0;i<400;i++)
    {
      digitalWrite(steppin,HIGH);
      delayMicroseconds(500);
      digitalWrite(steppin,LOW);
      delayMicroseconds(500);
      // digitalWrite(steppin2,HIGH);
      // delayMicroseconds(500);
      // digitalWrite(steppin2,LOW);
      // delayMicroseconds(500);
    }
  }
  else
  digitalWrite(en,HIGH);
}
