//declare the necessary variables 
unsigned long LEDtimer1,LEDtimer2,LEDtimer3;
int LEDOutput1 = 7, LEDOutput2 = 8, LEDOutput3 = 9;
int cutoffLED1 = 1000,cutoffLED2 = 1000,cutoffLED3 = 1000;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LEDOutput1,OUTPUT);
  pinMode(LEDOutput2,OUTPUT);
  pinMode(LEDOutput3,OUTPUT);
  LEDtimer1=millis();
  LEDtimer2=millis();
  LEDtimer3=millis();
}

void LEDtoggle1()
{
  if(digitalRead(LEDOutput1)==HIGH)
    digitalWrite(LEDOutput1,LOW);
  else
    digitalWrite(LEDOutput1,HIGH);
  LEDtimer1=millis();
}

void LEDtoggle2()
{
  if(digitalRead(LEDOutput2)==HIGH)
    digitalWrite(LEDOutput2,LOW);
  else
    digitalWrite(LEDOutput2,HIGH);
  LEDtimer2=millis();
}

void LEDtoggle3()
{
  if(digitalRead(LEDOutput3)==HIGH)
    digitalWrite(LEDOutput3,LOW);
  else
    digitalWrite(LEDOutput3,HIGH);
  LEDtimer3=millis();
}

void serialEvent()
{
 char bufferLED1[] = {' ',' ',' ',' ',' '};
char bufferLED2[] = {' ',' ',' ',' ',' '};
char bufferLED3[] = {' ',' ',' ',' ',' '};
 while (Serial.available()>0){
 Serial.readBytesUntil(' ', bufferLED1, 5);
 cutoffLED1 = atoi(bufferLED1);
 Serial.readBytesUntil(' ', bufferLED2, 5);
 cutoffLED2= atoi(bufferLED2);
 Serial.readBytesUntil('\n', bufferLED3, 5);
 cutoffLED3 = atoi(bufferLED3);}
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long currentmillis=millis();
  if(currentmillis-LEDtimer1 > cutoffLED1) LEDtoggle1();
  if(currentmillis-LEDtimer2 > cutoffLED2) LEDtoggle2();
  if(currentmillis-LEDtimer3 > cutoffLED3) LEDtoggle3();
  serialEvent();
}

