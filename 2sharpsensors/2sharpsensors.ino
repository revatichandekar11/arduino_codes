#define s1 A1
#define s2 A2
#define outputA 2
#define outputB 3
#define in1 7
#define in2 33

float kp=0.01;
float kd=0.00001;
int pos,dist=0;
long previousMillis = 0;
long currentMillis = 0;
//int  interval=1000;
//float rpm_right;
int setpoint=0;
int error;
float p;
float deltaT,errord=0.0;
int eprev;
int pwm;
float distance1,distance2;
int buff1=2;
int buff2=-2;

void setup() {
   Serial.begin(9600);
   pinMode(s1,INPUT);
   pinMode(s2,INPUT);
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
  //sensor
  float sensor_value1=analogRead(s1)*(5./1023.);
  float sensor_value2=analogRead(s2)*(5./1023.);
  distance1=13*pow(sensor_value1,-1);
  distance2=13*pow(sensor_value2,-1);
//  Serial.println("distance1:");
//  Serial.print(distance1);
//  Serial.print("\tdistance2:");
//  Serial.print(distance2);
// if(distance<=30)
// Serial.println(distance);

  //setpoint
 //if(distance1>distance2)
 // setpoint=distance1;
//  else if(distance1<distance2)
//  setpoint=(distance2-distance1);

 //pid
 currentMillis = micros();
 deltaT= (float)(currentMillis - previousMillis)/1000000.0;
  previousMillis = currentMillis;
   error=distance1-distance2;
 errord=(error-eprev)/deltaT;
  p=(kp*error)+(kd*errord);  
   eprev=error;
// errord=error-eprev;
   // rpm_right = (pos* 60 / enc_coun_rev);
   
//   Serial.println("error\t");
//   Serial.print(error);
Serial.println(pos);
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
//    
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
else if(pwm<0)
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

 if(digitalRead(outputA)==HIGH)
  pos++;
  else
  pos--;
  


}
void ReadEncoderB()
{
 if(digitalRead(outputB)==HIGH)
  pos--;
  else
  pos++;
}
