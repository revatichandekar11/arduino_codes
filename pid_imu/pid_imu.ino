#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>

#define outputA 2
#define outputB 3
//#define enc_coun_rev 620
#define in1 6
#define in2 22
#define BNO055_SAMPLERATE_DELAY_MS (100)

Adafruit_BNO055 bno = Adafruit_BNO055(-1, 0x28, &Wire);

float  kp=0.009;
float kd=0.0001;
float ki=0;
int pos,dist=0;
float previousMillis = 0;
float currentMillis = 0;
//int  interval=1000;
//float rpm_right;
int setpoint;
int target;
int error;
float  p;
float deltaT,errord,errori=0.0000;
int eprev;
int pwm;


//int a1;

void setup()
{
  //Serial.begin(9600);
  Serial.begin(115200);

  while (!Serial) delay(10);  // wait for serial port to open!

  Serial.println("Orientation Sensor Raw Data Test"); Serial.println("");

  /* Initialise the sensor */
  if(!bno.begin())
  {
    /* There was a problem detecting the BNO055 ... check your connections */
    Serial.print("Ooops, no BNO055 detected ... Check your wiring or I2C ADDR!");
    while(1);
  }

  delay(1000);

  /* Display the current temperature */
  int8_t temp = bno.getTemp();
  Serial.print("Current Temperature: ");
  Serial.print(temp);
  Serial.println(" C");
  Serial.println("");

  bno.setExtCrystalUse(true);

  Serial.println("Calibration status values: 0=uncalibrated, 3=fully calibrated");
  
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

 imu::Quaternion quat = bno.getQuat();

 double rm[3][3];

rm[1][1] = quat.w()*quat.w() + quat.x()*quat.x() - quat.y()*quat.y() - quat.z()*quat.z();   
rm[1][2] = 2*quat.x()*quat.y() - 2*quat.w()*quat.z();            
rm[1][3] = 2*quat.x()*quat.z() + 2*quat.w()*quat.y();
rm[2][1] = 2*quat.x()*quat.y() + 2*quat.w()*quat.z();       
rm[2][2] = quat.w()*quat.w() - quat.x()*quat.x() + quat.y()*quat.y() - quat.z()*quat.z();          
rm[2][3] = 2*quat.y()*quat.z() - 2*quat.w()*quat.x();     
rm[3][1] = 2*quat.x()*quat.z() - 2*quat.w()*quat.y();       
rm[3][2] = 2*quat.y()*quat.z() + 2*quat.w()*quat.x();            
rm[3][3] = quat.w()*quat.w() - quat.x()*quat.x() - quat.y()*quat.y() + quat.z()*quat.z();

/* Create Roll Pitch Yaw Angles from Quaternions */
double yy = quat.y() * quat.y(); // 2 Uses below

//double roll = atan2(2 * (quat.w() * quat.x() + quat.y() * quat.z()), 1 - 2*(quat.x() * quat.x() + yy));
//double pitch = asin(2 * quat.w() * quat.y() - quat.x() * quat.z());
double yaw = atan2(2 * (quat.w() * quat.z() + quat.x() * quat.y()), 1 - 2*(yy+quat.z() * quat.z()));

/*  Convert Radians to Degrees */
//float rollDeg  = 57.2958 * roll;
//float pitchDeg = 57.2958 * pitch;
float yawDeg   = 57.2958 * yaw;

Serial.print(" Radians \t"); Serial.print(yawDeg,2);   Serial.println(" Degrees");




  delay(BNO055_SAMPLERATE_DELAY_MS);
   
  int yaw_t=fabs(yawDeg);
 
// float rev=(pos/enc_coun_rev)*360;
// target=re
 
 
setpoint=yaw_t;
target=30;
  
 //Serial.println(pos);
 
 //pid
currentMillis = micros();
 deltaT= (currentMillis - previousMillis)/1000000.0;
  previousMillis = currentMillis;
   error=target-setpoint;
 errord=(error-eprev)/deltaT;
   errori=errori+error*deltaT;
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
