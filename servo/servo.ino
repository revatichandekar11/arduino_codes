#include <Servo.h>
Servo s;
void setup() {
 s.attach(6);
}

void loop() {
  //s.write(0);
 // s.write(90);
 // s.write(135);
  s.write(90);
}
  
