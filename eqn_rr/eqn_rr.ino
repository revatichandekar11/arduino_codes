 //#include <HardwareSerial.h>
//upp downn for belt
//right left feeding
//cross square for kick

#define motor1 6              
#define motor2 10
#define motor3 9
#define motor4 5
#define dir1 35
#define dir2 27
#define dir3 37
#define dir4 29
// #define outputA 2
// #define outputB 3
// //#define enc_coun_rev 620
// #define in1 7
// #define in2 33
// #define dir 39
// #define pw 4
// #define ps 11
// #define enc 31
// #define pwup 8

double sine,cosine,turn,lf,rf,lb,rb,power,theta,x,y,maximum=0;
double Buff=0.25 ;
//double BuffN=-0.25;
int maxsp=225;

int Buff1,Buff2,BuffP,BuffN;
int indexA,indexB,indexC,indexD,indexE,indexF,indexG,indexH,indexI,indexJ,indexK,indexL,indexM,indexN,indexO,indexP,indexQ,indexR,indexS;
String data1,data2,data3,data4,data5,data6,data7,data8,data9,data10,data11,data12,data13,data14,data15,data16,data17,data18,data19,datain;
int lx,ly,rx,ry,cro,squ,tri,cir,upp,downn,leftt,rightt,ll1,rr1,ll2,rr2,start,options,share;
int fast=175;
// int prevstaterightt=rightt;
// int prevstateleftt=leftt;
// int prevstateupp=upp;
// int prevstatedownn=downn;
// int prevstatecro=cro;
// int prevstatesqu=squ;
// int currstaterightt,currstateleftt,currstateupp,currstatedownn,currstatecro,currstatesqu=0;
int pos=0;

void setup()
{
  // Serial.println("Ready.");
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
//   pinMode(in1,OUTPUT);
//   pinMode(in2,OUTPUT);
//   pinMode(outputA,INPUT_PULLUP);
//   pinMode(outputB,INPUT_PULLUP);
//   attachInterrupt(digitalPinToInterrupt(outputA),ReadEncoder,RISING);
//   attachInterrupt(digitalPinToInterrupt(outputB),ReadEncoderB,RISING);
//  pinMode(enc,OUTPUT);
//   pinMode(pwup,OUTPUT);
  // pinMode(dir,OUTPUT);
  // pinMode(step,OUTPUT);
  //pinMode(en,OUTPUT);
  
  //digitalWrite(en,HIGH);
  // pinMode(dir,OUTPUT);
  // pinMode(pw,OUTPUT);
  // pinMode(ps,INPUT);
  
}
void loop()
{
  // Serial.println("Ready.");
  receivedata();
  // navigation();
  //parsedata(datain);
  //print();

  x=lx;
  y=ly;
  turn=rx;

  power=hypot(x,y);
  theta=atan2(x,y);
  sine=sin(theta-radians(45));
  cosine=cos(theta-radians(45));
  maximum=max(abs(sine),abs(cosine));

  lf=(power*cosine)/maximum+turn;
  rf=(power*sine)/maximum-turn;
  lb=(power*sine)/maximum+turn;
  rb=(power*cosine)/maximum-turn;

 if((power+(turn))>-128)
 {
   lf /= power+abs(turn);
   rf /= power+abs(turn);
   lb /= power+abs(turn);
   rb /= power+abs(turn);
 }
//  if ((power + Math.abs(turn)) > 1) {
//    lf   /= power + Math.abs(turn);
//    rf /= power + Math.abs(turn);
//    lb    /= power + Math.abs(turn);
//    rb  /= power + Math.abs(turn);
// }
// Serial.print("leftfront  ");
//    Serial.print(lf);
//    Serial.print("rightfront  ");
//    Serial.print(rf);
//     Serial.print("leftback  ");
//    Serial.print(lb);
//    Serial.print("rightback  ");
//    Serial.println(rb);

// if((lf>BuffP||lf<BuffN)||(rf>BuffP||rf<BuffN)||(lb>BuffP||lb<BuffN)||(rb>BuffP||rb<BuffN))
// {
 if(lf>Buff)
 {
   //digitalWrite(dir1,LOW);
   lf=lf*maxsp;
   
 }
 else if(lf<0)
 {
   //digitalWrite(dir1,HIGH);
   lf=-lf*maxsp;
    
 }
if(rf>Buff)
 {
  // digitalWrite(dir2,LOW);
   rf=rf*maxsp;
   
 }
 else if(rf<0)
 {
  // digitalWrite(dir2,HIGH);
   rf=-rf*maxsp;
   
 }
 if(lb>Buff)
 {
   //digitalWrite(dir4,LOW);
   lb=lb*maxsp;
  
 }
 else if(lb<0)
 {
   //digitalWrite(dir4,HIGH);
   lb=-lb*maxsp;
   
 }
 if(rb>Buff)
 {
   //digitalWrite(dir3,LOW);
   rb=rb*maxsp;
   
 }
 else if(rb<0)
 {
   //digitalWrite(dir3,HIGH);
   rb=-rb*maxsp;

 }
//  Serial.print("leftfront  ");
//    Serial.print(lf);
//    Serial.print("rightfront  ");
//    Serial.print(rf);
//     Serial.print("leftback  ");
//    Serial.print(lb);
//    Serial.print("rightback  ");
//    Serial.println(rb);
// analogWrite(motor1,(int)lf);
// analogWrite(motor2,(int)rf);
// analogWrite(motor3,(int)rb);
// analogWrite(motor4,(int)lb);
// }
// else
// {
//   analogWrite(motor1,0);
// analogWrite(motor2,0);
// analogWrite(motor3,0);
// analogWrite(motor4,0);
// }Serial.print("leftfront  ");
//    Serial.print(lf);
//    Serial.print("rightfront  ");
//    Serial.print(rf);
//     Serial.print("leftback  ");
//    Serial.print(lb);
//    Serial.print("rightback  ");
//    Serial.println(rb);
  // navigation();
  // encup();
  // kick();
  // feeding();
  // parsedata(datain);
  receivedata();
  navigation();
  parsedata(datain);
  print();
}
