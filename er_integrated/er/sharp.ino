void sharp()
{
  if(downn==1)
  {
float sensor_value1=analogRead(s1)*(5./1023.);
Serial.println(sensor_value1);
  }
}
