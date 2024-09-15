void ultrasonic(){
  
  if(downn==1)
  {
//    long start_time = micros();
//
//
//
//long end_time = micros();
//
//
//long duration = end_time - start_time;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  Serial.print("Distance: ");
  Serial.println(distance);
  }

  else 
  {
     digitalWrite(trigPin, LOW);
  }
  
}
