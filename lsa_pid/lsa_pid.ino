//#include <LSA08.h>
//
//LSA08 L;

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



 
//const byte junctionPulse = 4;   
//  
//
//float readVal,positionVal;    
//unsigned int junctionCount = 0;  
float ms=50;

float setpoint;
float error;
float  p=0;
float errord,errori=0.0000;
float eprev=0;
//int pwm=0;


void setup() 
{
  // Begin Serial Communication for the Debugger.
  Serial.begin(9600);
  // Attach Analog Pin to the LSA. 
  //L.AttachAnalogPin(A0);
  // Enable Debugger for the LSA.
  //L.debugger.Initialize("LSA", &Serial);

  pinMode(pwm1,OUTPUT);
  pinMode(pwm2,OUTPUT);
  pinMode(pwm3,OUTPUT);
  pinMode(pwm4,OUTPUT);
  pinMode(dir1,OUTPUT);
  pinMode(dir2,OUTPUT);
  pinMode(dir3,OUTPUT);
  pinMode(dir4,OUTPUT);

  // Uncomment the following to Disable Debugger -
//   L.debugger.disableDebugger();
//  pinMode(junctionPulse,INPUT);

  // Setting pin 10 - 13 as digital output pin
//  for(byte i=10;i<=13;i++) 
//    pinMode(i,OUTPUT);
}

void loop() 
{
 // L.ReadLSA();
//  if(digitalRead(junctionPulse)) {
//    while(digitalRead(junctionPulse)) {
//      wait();
//      delay(1000);
//      forward();
//    }
   
//    junctionCount++;
//  }

//  readVal = analogRead(A0); 
// 
//  
//  positionVal = ((float)readVal/921)*70;
   // positionVal = ((float)readVal*4.5)/70;
 // Serial.println(positionVal);
 


//error=setpoint-positionVal;
// if(error!=0)
// {
//   errord=(error-eprev);
//   errori=errori+error;
//   p=(kp*error)+(kd*errord)+(ki*errori);  
//   
//   eprev=error;  
//
////   forward();
// }
//setpoint=35;

// if(error!=0)
// {
//   errord=(error-eprev);
//   errori=errori+error;
//   p=(kp*error)+(kd*errord)+(ki*errori);  
//   
//   eprev=error;  
   

//   forward();
// }
// if(p>=70)
// p=70;
//  if(positionVal>65)
// {
  //setpoint=positionVal;
//  wait();
// }
// else
 forward();
}


//void forward() {
//  
//  //frontleft
//    digitalWrite(dir1,LOW);
//    analogWrite(pwm1,int(ms-p));
//    //frontright
//    digitalWrite(dir2,HIGH);
//     analogWrite(pwm2,int(ms+p));
//     //backleft
//    digitalWrite(dir3,HIGH);
//     analogWrite(pwm3,int(ms-p));
//     //backright
//    digitalWrite(dir4,LOW);
//     analogWrite(pwm4,int(ms+p));
//     
//}
void forward() {
  
  //frontleft
    digitalWrite(dir1,LOW);
    analogWrite(pwm1,int(ms));
    //frontright
    digitalWrite(dir2,HIGH);
     analogWrite(pwm2,int(ms));
     //backleft
    digitalWrite(dir3,HIGH);
     analogWrite(pwm3,int(ms));
     //backright
    digitalWrite(dir4,LOW);
     analogWrite(pwm4,int(ms));
     
}

void wait() {
 
  analogWrite(pwm1,0);
  analogWrite(pwm2,0);
  analogWrite(pwm3,0);
  analogWrite(pwm4,0);
}
