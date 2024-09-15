#define outputA 2
#define outputB 3
//#define enc_coun_rev 620
#define in1 7
#define in2 33
float  kp=0.0001;
float kd=0.0000;
float ki=0;
int pos,dist=0;
float previousMillis = 0;
float currentMillis = 0;
//int  interval=1000;
//float rpm_right;
int setpoint=800;
//int targetnew=5;
int error;
float  p;
float deltaT,errord,errori=0.0000;
int eprev;
int pwm;




//int a1;

void setup()
{
  Serial.begin(9600);
  pinMode(outputA,INPUT_PULLUP);
   pinMode(outputB,INPUT_PULLUP);
   pinMode(in1,OUTPUT);
   pinMode(in2,OUTPUT);
   
   //a1=digitalRead(outputA);
   attachInterrupt(digitalPinToInterrupt(outputA),ReadEncoder,RISING);
  attachInterrupt(digitalPinToInterrupt(outputB),ReadEncoderB,RISING);
 
}
void loop()
{

 
   
 
 //float rev=pos*360;

  
 //Serial.println(pos);
 
 
//currentMillis = micros();
// deltaT= (currentMillis - previousMillis)/1000000.0;
//  previousMillis = currentMillis;
   error=setpoint-pos;
 //errord=(error-eprev)/deltaT;
 errord=(error-eprev);
   //errori=errori+error*deltaT;
   errori=errori+error;
// errord=error-eprev;
   // rpm_right = (pos* 60 / enc_coun_rev);
 p=(kp*error)+(kd*errord)+(ki*errori);  
   
   eprev=error;     
  
   

 /*if(error<0)
  {
    
   // targetnew=error-targetnew;
    setpoint=targetnew;
    error=setpoint-pos;
    //errord=error;
    errord=(error-eprev)/deltaT;
    Serial.print(" target new ");
    Serial.print( setpoint );
    
  }*/


 // pvalue();

   Serial.print(" p value: ");
   Serial.print(p);
  Serial.print("  error:  ");
   Serial.print(error);
   Serial.print(" position:  ");
   Serial.println(pos);
   
   //int pwm=int(220*(p));
// int pwm=abs(p);
 int pwm=(int)(220*p);

/*Serial.println(" pwm ");
   Serial.print(pwm);*/
 
if(error>0)
{
   
   digitalWrite(in2,HIGH);
   // digitalWrite(in1,LOW);
   //analogWrite(in1,pwm); 
    
}
 else if(error<0)
  {
   
//    setpoint=abs(error);
//    pos=pos-setpoint;
    
     digitalWrite(in2,LOW);
   // digitalWrite(in1,HIGH);
    
//analogWrite(in1,pwm);
  }
else 
{
 // p=0;
 
  digitalWrite(in1,LOW);
   digitalWrite(in2,LOW);
//  pwm=0; 
}
 
if(pwm>220){
 //pwm=220;

 analogWrite(in1,220);}
 else if(pwm>0)
{
  analogWrite(in1,pwm);
}
else if(pwm<=0)
{
  analogWrite(in1,pwm);
}

/*else if(p<0)
{
   
   digitalWrite(in2,LOW);
    digitalWrite(in1,HIGH);
    
 // analogWrite(in1,pwm);
    
}*/



}
//void ReadEncoder()
//{
//  //int c=digitalRead(outputB);
//
// if(digitalRead(outputA)==LOW)
//  pos++;
//  else
//  pos--;
// 
//}
//void ReadEncoderB()
//{
// if(digitalRead(outputB)==LOW)
//  pos--;
//  else
//  pos++;
//}
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
