
#include <HardwareSerial.h>

#define motor1 6
#define motor2 7
#define motor3 9
#define motor4 10
#define dir1 22
#define dir2 24
#define dir3 26
#define dir4 28
#define outputA 2
#define outputB 3
//#define enc_coun_rev 620
#define in1 8
#define in2 23
#define dirpin 30
#define steppin 4
#define enable 25
#define dirpin2 27
#define steppin2 5
#define enable2 29
#define dir 32
#define pw 4
#define ps 11

int Buff1,Buff2,BuffP,BuffN;
int indexA,indexB,indexC,indexD,indexE,indexF,indexG,indexH,indexI,indexJ,indexK,indexL,indexM,indexN,indexO,indexP,indexQ,indexR,indexS;
String data1,data2,data3,data4,data5,data6,data7,data8,data9,data10,data11,data12,data13,data14,data15,data16,data17,data18,data19,datain;
int lx,ly,rx,ry,cro,squ,tri,cir,up,down,left,right,ll1,rr1,ll2,rr2,start,options,share;


void setup()
{
  
  Serial.begin(115200);
  Serial2.begin(57600);
   Buff1=50;
  Buff2=-50;
  BuffP=60;
  BuffN=-60;
  pinMode(motor1,OUTPUT);
  pinMode(motor2,OUTPUT);
  pinMode(motor3,OUTPUT);
  pinMode(motor4,OUTPUT);
  pinMode(dir1,OUTPUT);
  pinMode(dir2,OUTPUT);
  pinMode(dir3,OUTPUT);
  pinMode(dir4,OUTPUT);
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(outputA,INPUT_PULLUP);
  pinMode(outputB,INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(outputA),ReadEncoder,RISING);
  attachInterrupt(digitalPinToInterrupt(outputB),ReadEncoderB,RISING);
  pinMode(dirpin,OUTPUT);
  pinMode(steppin,OUTPUT);
  pinMode(enable,OUTPUT);
  pinMode(dirpin2,OUTPUT);
  pinMode(steppin2,OUTPUT);
  pinMode(enable2,OUTPUT);
  // pinMode(dir,OUTPUT);
  // pinMode(step,OUTPUT);
  //pinMode(en,OUTPUT);
  digitalWrite(enable,HIGH);
  digitalWrite(enable2,HIGH);
  //digitalWrite(en,HIGH);
  pinMode(dir,OUTPUT);
  pinMode(pw,OUTPUT);
  pinMode(ps,INPUT);
  
}
void loop()
{
  receivedata();
  print();
  navigation();
  //stepper();
  //kick();
  //feeding();
  parsedata(datain);
}
float mapCubic(float x, float inMin, float inMax, float outMin, float outMax) {
  float normalizedX = (x - inMin) / (inMax - inMin);
  float mappedValue = normalizedX * normalizedX * normalizedX * (outMax - outMin) + outMin;
  return mappedValue;
}
