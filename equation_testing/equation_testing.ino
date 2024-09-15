#include <ps5Controller.h>
#include<HardwareSerial.h>

int lx,ly,rx,ry,tri,squ,circle,cross,l1,l2,r1,r2,up,down,left,right;
#define rx2 16
#define tx2 17

//void senddata(int a,int b,int c,int d,int e,int f,int g,int h,int i,int j,int k,int l,int m,int n,int o,int p)
//{
//  Serial2.print(a);
//  Serial2.print("A");
//  Serial2.print(b);
//  Serial2.print("B");
//  Serial2.print(c);
//  Serial2.print("C");
//  Serial2.print(d);
//  Serial2.print("D");
//  Serial2.print(e);
//  Serial2.print("E");
//  Serial2.print(f);
//  Serial2.print("F");
//  Serial2.print(g);
//  Serial2.print("G");
//  Serial2.print(h);
//  Serial2.print("H");
//  Serial2.print(i);
//  Serial2.print("I");
//  Serial2.print(j);
//  Serial2.print("J");
//  Serial2.print(k);
//  Serial2.print("K");
//  Serial2.print(l);
//  Serial2.print("L");
//  Serial2.print(m);
//  Serial2.print("M");
//  Serial2.print(n);
//  Serial2.print("N");
//  Serial2.print(o);
//  Serial2.print(p);
//  Serial2.print("P");
////  Serial2.print(q);
////  Serial2.print("Q");
//  Serial2.print("!");
//}
//
//void setup()
//{
//  Serial.begin(115200);
//  Serial2.begin(57600,SERIAL_8N1,rx2,tx2);
//  ps5.begin("7c:66:ef:78:76:f0");
////  ps5.begin("bc:c7:46:33:5b:8d");
// }
//
// void loop()
// {
//  if(ps5.isConnected()==true)
//  {
//    Serial.println("Connected");
//    lx=ps5.LStickX();
//    ly=ps5.LStickY();
//    rx=ps5.RStickX();
//    ry=ps5.RStickY();
//    tri=ps5.Triangle();
//    squ=ps5.Square();
//    circle=ps5.Circle();    
//   cross=ps5.Cross();
//    l1=ps5.L1();
//    l2=ps5.L2();
//    r1=ps5.R1();
//    r2=ps5.R2();
//    up=ps5.Up();
//    down=ps5.Down();
//   left=ps5.Left();
//    right=ps5.Right();    
//     
//  }
//  senddata(lx,ly,rx,ry,cross,squ,tri,circle,up,down,left,right,l1,l2,r1,r2);
// }

void setup()
{
  Serial.begin(115200);
//  ps5.begin("7c:66:ef:78:76:f0");
//   ps5.begin("bc:c7:46:33:5b:8d");
  ps5.begin("e8:47:3a:5a:a3:66");
}

void loop()
{
 if(ps5.isConnected()==true)
 {
  lx=ps5.LStickX();
  ly=ps5.LStickY();
  int vel1,vel2;
double theta=atan2(abs(ly),abs(lx));
//  double angle=atan2(ly,lx);
int leftx=abs(ly+lx);
int lefty=abs(ly-lx);
 int map_speed=150;
 int buf;
 int maxx;
 float pi=22/7;
 if(theta>=0 && theta<=pi/4)
 {
  maxx=map(theta,0,pi/4,127,179);
  // Serial.print(maxx);
  // Serial.print(" ");
  
  buf=map(theta,0,pi/4,50,70);
  // Serial.print(buf);
  // Serial.print(" ");
 }
 else if(theta>pi/4 && theta<=pi/2)
 {
   maxx=map(theta,pi/4,pi/2,179,127);
  //  Serial.print(maxx);
  // Serial.print(" ");
   buf=map(theta,pi/4,pi/2,70,50);
  //  Serial.print(buf);
  // Serial.print(" ");
 }

// if((ly>buff1 && lx<buff1) || (ly>buff1 && lx>buff2) || (ly<buff2 && lx>buff2) || (ly<buff2 && lx<buff1)|| (lx<buff2 && ly<buff1) || (lx<buff2 && ly>buff2) || (lx>buff1 && ly<buff1) || (lx>buff1 && ly>buff2))
//{
//  vel1=map(abs(ly+lx),buff1,127,0,map_speed);
//  vel2=map(abs(ly-lx),buff1,127,0,map_speed);
//  navigations();
//}
// if(ly>buf && lx>buf) || (lx<-buf && ly<-buf) || (lx>buf && ly<-buf) || (ly>buf && lx<-buf))
// {


  //  if((lx<0 && ly>=0) || (lx<=0 && ly<0))
  //  {
  //   angle=angle+pi;
  //  }
  //  else if(lx>0 && ly<=0)
  //  {
  //   angle=angle+(2*pi);
  //  }
  vel1=map(leftx,50,127,0,map_speed);
  vel2=map(lefty,50,127,0,map_speed);
Serial.print(vel1);
Serial.print(vel2);
Serial.println();
  // Serial.print(ly);
  // Serial.print(" ");
  // Serial.print(lx);
  // Serial.print(",");
  //  Serial.print(leftx);
  // Serial.print(" ");
  //  Serial.print(lefty);
  // Serial.print(" ");
  // Serial.print(vel1);
  // Serial.print(" ");
  // Serial.println(vel2);
 }
}
