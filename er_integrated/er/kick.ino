void kick()
 {
//   i=1;

//  if(i<130){
//     digitalWrite(in2,HIGH);
//   analogWrite(in1,150);
//   i++;
//  }
//  else if(i>130)
//   analogWrite(in1,0);
// }
  
  
 if(cro==1)
 {
////pvalue(800);
//// errord=error-eprev;
////    rpm_right = (pos* 60 / enc_coun_rev);
   digitalWrite(in2,HIGH);
   analogWrite(in1,150);
//  
 }
//// 
  else
  analogWrite(in1,0);
 }
 
void ReadEncoder()
{
  if(digitalRead(outputA)==HIGH)
  {
    if(digitalRead(outputB)==HIGH)
    {
      pos++;
    }
    else
    {
      pos--;
    }
  }

  else if(digitalRead(outputA)== LOW)
  {
    if(digitalRead(outputB)==HIGH)
    {
      pos--;
    }
    else
    {
      pos++;
    }
  }
} 

void ReadEncoderB()
{
  if(digitalRead(outputB)==HIGH)
  {
    if(digitalRead(outputA)==HIGH)
    {
      pos--;
    }
    else
    {
      pos++;
    }
  }

  else if(digitalRead(outputB)==LOW)
  {
    if(digitalRead(outputA)==HIGH)
    {
      pos++;  
    }
    else
    {
      pos--;
    }
  }
}
