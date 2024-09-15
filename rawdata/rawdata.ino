#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>

/* This driver reads raw data from the BNO055

   Connections
   ===========
   Connect SCL to analog 5
   Connect SDA to analog 4
   Connect VDD to 3.3V DC
   Connect GROUND to common ground

   History
   =======
   2015/MAR/03  - First release (KTOWN)
*/

/* Set the delay between fresh samples */
#define BNO055_SAMPLERATE_DELAY_MS (100)

// Check I2C device address and correct line below (by default address is 0x29 or 0x28)
//                                   id, address
Adafruit_BNO055 bno = Adafruit_BNO055(-1, 0x28, &Wire);

/**************************************************************************/
/*
    Arduino setup function (automatically called at startup)
*/
/**************************************************************************/
void setup(void)
{
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
}

/**************************************************************************/
/*
    Arduino loop function, called once 'setup' is complete (your own code
    should go here)
*/
/**************************************************************************/
void loop(void)
{
  // Possible vector values can be:
  // - VECTOR_ACCELEROMETER - m/s^2
  // - VECTOR_MAGNETOMETER  - uT
  // - VECTOR_GYROSCOPE     - rad/s
  // - VECTOR_EULER         - degrees
  // - VECTOR_LINEARACCEL   - m/s^2
  // - VECTOR_GRAVITY       - m/s^2
  imu::Vector<3> euler = bno.getVector(Adafruit_BNO055::VECTOR_EULER);

  /* Display the floating point data */
//  Serial.print("X: ");
//  Serial.print(euler.x());
//  Serial.print(" Y: ");
//  Serial.print(euler.y());
//  Serial.print(" Z: ");
//  Serial.print(euler.z());
//  Serial.print("\t\t");

//  /*
//  Quaternion data
  imu::Quaternion quat = bno.getQuat();
//  Serial.print("qW: ");
//  Serial.print(quat.w(), 4);
//  Serial.print(" qX: ");
//  Serial.print(quat.x(), 4);
//  Serial.print(" qY: ");
//  Serial.print(quat.y(), 4);
//  Serial.print(" qZ: ");
//  Serial.print(quat.z(), 4);
//  Serial.print("\t\t");
  

  /* Display calibration status for each sensor. */
//  uint8_t system, gyro, accel, mag = 0;
//  bno.getCalibration(&system, &gyro, &accel, &mag);
//  Serial.print("CALIBRATION: Sys=");
//  Serial.print(system, DEC);
//  Serial.print(" Gyro=");
//  Serial.print(gyro, DEC);
//  Serial.print(" Accel=");
//  Serial.print(accel, DEC);
//  Serial.print(" Mag=");
//  Serial.println(mag, DEC);

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

/* Display Rotation Matrix */
//Serial.print(rm[1][1],5);Serial.print("  \t");
//Serial.print(rm[1][2],5);Serial.print("  \t");
//Serial.println(rm[1][3],5);
//Serial.print(rm[2][1],5);Serial.print("  \t");
//Serial.print(rm[2][2],5);Serial.print("  \t");
//Serial.println(rm[2][3],5);
//Serial.print(rm[3][1],5);Serial.print("  \t");
//Serial.print(rm[3][2],5);Serial.print("  \t");
//Serial.println(rm[3][3],5);

/* Create Roll Pitch Yaw Angles from Quaternions */
double yy = quat.y() * quat.y(); // 2 Uses below

double roll = atan2(2 * (quat.w() * quat.x() + quat.y() * quat.z()), 1 - 2*(quat.x() * quat.x() + yy));
double pitch = asin(2 * quat.w() * quat.y() - quat.x() * quat.z());
double yaw = atan2(2 * (quat.w() * quat.z() + quat.x() * quat.y()), 1 - 2*(yy+quat.z() * quat.z()));

/*  Convert Radians to Degrees */
float rollDeg  = 57.2958 * roll;
float pitchDeg = 57.2958 * pitch;
float yawDeg   = 57.2958 * yaw;

/*  Display Roll, Pitch, and Yaw in Radians and Degrees*/
//Serial.print("Roll:");  Serial.print(roll,5); 
//Serial.print(" Radians \t"); Serial.print(rollDeg,2);  Serial.println(" Degrees");
//Serial.print("\tPitch:"); 
//Serial.print(pitch,5); 
//Serial.print(" Radians \t"); Serial.print(pitchDeg,2); Serial.println(" Degrees");
//Serial.print("\tYaw:");  
//Serial.println(yaw,5);  
Serial.print(" Radians \t"); Serial.print(yawDeg,2);   Serial.println(" Degrees");




  delay(BNO055_SAMPLERATE_DELAY_MS);
}
