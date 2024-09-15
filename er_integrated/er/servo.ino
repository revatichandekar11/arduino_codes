void servo()
{
  int pos=0;
  if(squ==1)
  {
    for (pos = 0; pos <= 180; pos += 1) {
    s.write(pos);  
    Serial.println(pos);            
    delay(15);                       
  }
  }
  
  
}
