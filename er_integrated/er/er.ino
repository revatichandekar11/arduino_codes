//#include <HardwareSerial.h>
#include <Servo.h>
Servo s;
//upp downn for belt
//right left feeding
//cross square for kick

#define motor1 5
#define motor2 9
#define motor3 6
#define motor4 10
#define dir1 29
#define dir2 37
#define dir3 35
#define dir4 27
#define outputA 2
#define outputB 3
//#define enc_coun_rev 620
#define in1 7
#define in2 33
#define dir 39
#define pw 4
#define ps 11
#define enc 33
#define pwup 7
#define dirpin 47
#define steppin 45
#define en 43
#define trigPin 9   
#define echoPin  8   
#define s1 A1
#define pn 7

int Buff1,Buff2,BuffP,BuffN;
int indexA,indexB,indexC,indexD,indexE,indexF,indexG,indexH,indexI,indexJ,indexK,indexL,indexM,indexN,indexO,indexP,indexQ,indexR,indexS;
String data1,data2,data3,data4,data5,data6,data7,data8,data9,data10,data11,data12,data13,data14,data15,data16,data17,data18,data19,datain;
int lx,ly,rx,ry,cro,squ,tri,cir,upp,downn,leftt,rightt,ll1,rr1,ll2,rr2,start,options,share;
int fast=255;
// int prevstaterightt=rightt;
// int prevstateleftt=leftt;
// int prevstateupp=upp;
// int prevstatedownn=downn;
// int prevstatecro=cro;
// int prevstatesqu=squ;
// int currstaterightt,currstateleftt,currstateupp,currstatedownn,currstatecro,currstatesqu=0;
int pos=0;
float duration,distance;

void setup()
{
  // Serial.println("Ready.");
  Serial.begin(115200);
  Serial2.begin(57600);
   Buff1=50;
  Buff2=-50;
  BuffP=60;
  BuffN=-60;
  //drive
  pinMode(motor1,OUTPUT);
  pinMode(motor2,OUTPUT);
  pinMode(motor3,OUTPUT);
  pinMode(motor4,OUTPUT);
  pinMode(dir1,OUTPUT);
  pinMode(dir2,OUTPUT);
  pinMode(dir3,OUTPUT);
  pinMode(dir4,OUTPUT);

  //kick
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(outputA,INPUT_PULLUP);
  pinMode(outputB,INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(outputA),ReadEncoder,RISING);
  attachInterrupt(digitalPinToInterrupt(outputB),ReadEncoderB,RISING);

//belt-pulley
 pinMode(enc,OUTPUT);
  pinMode(pwup,OUTPUT);
  // pinMode(dir,OUTPUT);
  // pinMode(step,OUTPUT);
  //pinMode(en,OUTPUT);
  
  //feeding
  //digitalWrite(en,HIGH);
  pinMode(dir,OUTPUT);
  pinMode(pw,OUTPUT);

  //proximity
  pinMode(ps,INPUT);

  //servo
  s.attach(11);

  //stepper
    pinMode(dirpin,OUTPUT);
  pinMode(steppin,OUTPUT);
  pinMode(en,OUTPUT);
  digitalWrite(en,HIGH);

  //ultrasonic
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  //sharp
  pinMode(s1,INPUT);

  //pneumatic
  pinMode(pn,OUTPUT);
  
}
void loop()
{
  // Serial.println("Ready.");
  receivedata();
  //parsedata(datain);
  print();
   navigation();
   encup();
  // kick();
   feeding();
   stepper();
   servo();
   //sharp();
   ultrasonic();
   pneumatic();
   parsedata(datain);
}
