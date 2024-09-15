#define led1 28
#define led2 22
#define directionpin 26
#define steppin 7
//#define enablepin 24


unsigned long starttime1=0;
unsigned long blinkdelay=500;
byte ledstate=LOW;

unsigned long starttime2=0;
unsigned long blinkdelay2=1000;
byte ledstate2=LOW;

unsigned long prevStepMicros = 0;
unsigned long microsBetweenSteps = 500;
byte stepstate=LOW;

unsigned long timenow;
unsigned long currmicros;


void setup() {
  Serial.begin(9600);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(directionpin, OUTPUT);
  pinMode(steppin, OUTPUT);
  //pinMode(enablepin, OUTPUT);
  //digitalWrite(enablepin,LOW);
  
}

void loop() {

  timenow=millis();

  if(timenow-starttime1>blinkdelay)
  {
    starttime1+=blinkdelay;
//    if(ledstate==HIGH)
//    ledstate=LOW;
//    else
//    ledstate=HIGH;
    ledstate=!ledstate;
    digitalWrite(led1,ledstate);
  }
  if(timenow-starttime2>blinkdelay2)
  {
    starttime2+=blinkdelay2;
//    if(ledstate2==HIGH)
//    ledstate2=LOW;
//    else
//    ledstate2=HIGH;
     ledstate2=!ledstate2;
    digitalWrite(led2,ledstate2);
  }
  
currmicros=micros();
   
    
 //digitalWrite(enablepin,HIGH);
 digitalWrite(directionpin,HIGH);
 
  
  for(int i=0;i<800;i++)
  {
  if(currmicros-prevStepMicros>microsBetweenSteps)
  {
    prevStepMicros=currmicros;
    stepstate=!stepstate;
    digitalWrite(steppin,stepstate);
    digitalWrite(steppin,!stepstate);
  }
 }
}
