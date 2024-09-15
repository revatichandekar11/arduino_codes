#define outputA 2
#define outputB 3

int pos=0;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(outputA,INPUT_PULLUP);
  pinMode(outputB,INPUT_PULLUP);
   attachInterrupt(digitalPinToInterrupt(outputA),ReadEncoder,CHANGE);
   attachInterrupt(digitalPinToInterrupt(outputB),ReadEncoderB,CHANGE);
}

void loop() {
  // put your main code here, to run repeatedly:
Serial.println(pos);
}
void ReadEncoder(){
  if(digitalRead(outputA)==HIGH)
  {
    if(digitalRead(outputB)==HIGH)
    {
      pos++;
    }
    else
    {
      pos--;
    }
  }

  else if(digitalRead(outputA)== LOW)
  {
    if(digitalRead(outputB)==HIGH)
    {
      pos--;
    }
    else
    {
      pos++;
    }
  }
} 

void ReadEncoderB()
{
  if(digitalRead(outputB)==HIGH)
  {
    if(digitalRead(outputA)==HIGH)
    {
      pos--;
    }
    else
    {
      pos++;
    }
  }

  else if(digitalRead(outputB)==LOW)
  {
    if(digitalRead(outputA)==HIGH)
    {
      pos++;  
    }
    else
    {
      pos--;
    }
  }
}
