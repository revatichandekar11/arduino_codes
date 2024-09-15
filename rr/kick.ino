//#define outputA 2
//#define outputB 3
////#define enc_coun_rev 620
//#define in1 8
//#define in2 23

float  kp=0.009;
float kd=0.0001;
float ki=0;
int pos,dist=0;
float previousMillis = 0;
float currentMillis = 0;
//int  interval=1000;
//float rpm_right;
//int setpoint=1000;
//int targetnew=5;
int error;
float  p;
float deltaT,errord,errori=0.0000;
int eprev;
int pwm;


//int a1;

//void setup()
//{
//  Serial.begin(9600);
//  pinMode(outputA,INPUT_PULLUP);
//   pinMode(outputB,INPUT_PULLUP);
//   pinMode(in1,OUTPUT);
//   pinMode(in2,OUTPUT);
//   
//   //a1=digitalRead(outputA);
//   attachInterrupt(digitalPinToInterrupt(outputA),ReadEncoder,RISING);
//  attachInterrupt(digitalPinToInterrupt(outputB),ReadEncoderB,RISING);
// 
//}
//void loop()
//{

 
   
 
 //float rev=pos*360;

  
 //Serial.println(pos);
 void kick()
 {
 if(cro==1)
 {
pvalue(1000);
// errord=error-eprev;
   // rpm_right = (pos* 60 / enc_coun_rev);
   
  dirsp();
   

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

  
   //int pwm=int(220*(p));
// int pwm=abs(p);
 

 }
 if(squ==1)
 {
   //target=0;
   pvalue(0);
   dirsp();

}
 }
void pvalue(int setpoint){
  currentMillis = micros();
 deltaT= (currentMillis - previousMillis)/1000000.0;
  previousMillis = currentMillis;
   error=setpoint-pos;
 errord=(error-eprev)/deltaT;
   errori=errori+error*deltaT;
   p=(kp*error)+(kd*errord)+(ki*errori);  
   
   eprev=error;   
    Serial.print(" p value: ");
   Serial.print(p);
  Serial.print("  error:  ");
   Serial.print(error);
   Serial.print(" position:  ");
   Serial.println(pos);
   
}
void dirsp()
{
  int pwm=(int)(220*p);

/*Serial.println(" pwm ");
   Serial.print(pwm);*/
// if(cross==1)
// {
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
void ReadEncoder()
{
  //int c=digitalRead(outputB);

 if(digitalRead(outputA)==LOW)
  pos--;
  else
  pos++;
 
}
void ReadEncoderB()
{
 if(digitalRead(outputB)==LOW)
  pos--;
  else
  pos++;
}
