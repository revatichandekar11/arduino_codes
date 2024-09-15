//#include <HardwareSerial.h>
//upp downn for belt
//right left feeding
//cross square for kick


//#define enc_coun_rev 620

#define dirpin 30
#define steppin 4
#define enable 25


int Buff1,Buff2,BuffP,BuffN;
int indexA,indexB,indexC,indexD,indexE,indexF,indexG,indexH,indexI,indexJ,indexK,indexL,indexM,indexN,indexO,indexP,indexQ,indexR,indexS;
String data1,data2,data3,data4,data5,data6,data7,data8,data9,data10,data11,data12,data13,data14,data15,data16,data17,data18,data19,datain;
int lx,ly,rx,ry,cro,squ,tri,cir,upp,downn,leftt,rightt,ll1,rr1,ll2,rr2,start,options,share;
//int fast=175;
// int prevstaterightt=rightt;
// int prevstateleftt=leftt;
// int prevstateupp=upp;
// int prevstatedownn=downn;
// int prevstatecro=cro;
// int prevstatesqu=squ;
// int currstaterightt,currstateleftt,currstateupp,currstatedownn,currstatecro,currstatesqu=0;
//int pos;
//int i=1;
//kick
//float  kp=0.08;
//float kd=0.0009;
//float ki=0;
//int dist=0;
// float previousMillis = 0;
// float currentMillis = 0;
//int  interval=1000;
//float rpm_right;
//int setpoint;
//int targetnew=5;
//int error;
//float  p;
//float errord,errori=0.0000;
//int eprev=0;
//int pwm=0;


//int a1;

void setup()
{
  // Serial.println("Ready.");
  Serial.begin(115200);
  Serial2.begin(57600);
   Buff1=50;
  Buff2=-50;
  BuffP=60;
  BuffN=-60;
  
   pinMode(dirpin,OUTPUT);
  pinMode(steppin,OUTPUT);
  pinMode(enable,OUTPUT);
  digitalWrite(enable,HIGH);

}
void loop()
{
  // Serial.println("Ready.");
  receivedata();
 //parsedata(datain);
  print();
  //navigation();
 // encup();
 
 stepper();
  //kick();
  //feeding();
   parsedata(datain);

}
