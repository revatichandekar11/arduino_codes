#include <LSA08.h>

#define LSASerial Serial2

LSA08 L;

float  kp=0.5;
float kd=0;
float ki=0;

#define dir1 29
#define dir2 37
#define dir3 35
#define dir4 27
#define pwm1 5
#define pwm2 9
#define pwm3 6
#define pwm4 10
//#define RXp2 16
//#define TXp2 17
#define uen 10
#define outputA 2
#define outputB 3

int pos=0;

const byte junctionPulse = 4;   
  

float readVal1,positionVal1,readVal2,positionVal2;    
unsigned int junctionCount = 0;  
float ms=30;

float setpoint;
float error;
float  p=0;
float errord,errori=0.0000;
float eprev=0;
//int pwm=0;

void setup() {
  // Begin Serial Communication for the Debugger.
  Serial.begin(9600);
  // Begin Serial Communication for the LSA.
  LSASerial.begin(38400);
  // Attach Serial Line to the LSA.
  L.AttachSerial(&LSASerial);
  // Enable Debugger for the LSA.
  L.debugger.Initialize("LSA", &Serial);

    // Uncomment the following to Disable Debugger -
  // L.debugger.disableDebugger();
   

   
    pinMode(pwm1,OUTPUT);
  pinMode(pwm2,OUTPUT);
  pinMode(pwm3,OUTPUT);
  pinMode(pwm4,OUTPUT);
  pinMode(dir1,OUTPUT);
  pinMode(dir2,OUTPUT);
  pinMode(dir3,OUTPUT);
  pinMode(dir4,OUTPUT);

  pinMode(outputA,INPUT_PULLUP);
  pinMode(outputB,INPUT_PULLUP);
   attachInterrupt(digitalPinToInterrupt(outputA),ReadEncoder,RISING);
   attachInterrupt(digitalPinToInterrupt(outputB),ReadEncoderB,RISING);

  // Uncomment the following to Disable Debugger -
//   L.debugger.disableDebugger();
  pinMode(junctionPulse,INPUT);
  pinMode(uen,OUTPUT);

  // Setting pin 10 - 13 as digital output pin
  for(byte i=10;i<=13;i++) 
    pinMode(i,OUTPUT);
   
}

void loop() {
  // put your main code here, to run repeatedly:
  L.ReadLSA();

  readVal1 = analogRead(A0); 

  
  positionVal1 = ((float)readVal1/921)*70;
// Serial.println(pos);
 Serial.println(positionVal1);

  error=setpoint-positionVal1;

  setpoint=35;

 if(error!=0)
 {
   errord=(error-eprev);
   errori=errori+error;
   p=(kp*error)+(kd*errord)+(ki*errori);  
   
   eprev=error;  
 }
 //forward();
// if(pos>15000)
// {
//    anticlockwise();
//    if(pos>=17491)
//    wait();
// }
//if(positionVal1<70)
//forward();
//
//wait();

}
void forward() {
  
  //frontleft
    digitalWrite(dir1,LOW);
    analogWrite(pwm1,int(ms-p));
    //frontright
    digitalWrite(dir2,HIGH);
     analogWrite(pwm2,int(ms+p));
     //backleft
    digitalWrite(dir3,HIGH);
     analogWrite(pwm3,int(ms-p));
     //backright
    digitalWrite(dir4,LOW);
     analogWrite(pwm4,int(ms+p));
     
}
void anticlockwise() {
  
  //frontleft
    digitalWrite(dir1,HIGH);
    analogWrite(pwm1,ms);
    //frontright
    digitalWrite(dir2,HIGH);
     analogWrite(pwm2,ms);
     //backleft
    digitalWrite(dir3,LOW);
     analogWrite(pwm3,ms);
     //backright
    digitalWrite(dir4,LOW);
     analogWrite(pwm4,ms);
     
}
void wait() {
 
  analogWrite(pwm1,0);
  analogWrite(pwm2,0);
  analogWrite(pwm3,0);
  analogWrite(pwm4,0);
}
void ReadEncoder(){
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
