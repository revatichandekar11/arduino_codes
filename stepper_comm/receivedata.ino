void receivedata()
{
  while(Serial2.available()>0)
  {
    datain=Serial2.readStringUntil('!');
  }
}
