
#define ps 9

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ps,INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(ps)==HIGH)
  Serial.println("object detected");
  if(digitalRead(ps)==LOW)
  Serial.println("object not detected");
}
