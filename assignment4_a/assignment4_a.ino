//declare the necessary variables
unsigned long LEDtimer1,LEDtimer2,LEDtimer3;
int LEDToToggleNext=0;
int LEDOutput1 = 7, LEDOutput2 = 8, LEDOutput3 = 9;
int cutoffLED1=1000,cutoffLED2=1000,cutoffLED3=1000;
int i,intCount,stringCount,flag;
String buffer;

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
  if(digitalRead(LEDOutput1)==LOW)
    digitalWrite(LEDOutput1,HIGH);
  else
    digitalWrite(LEDOutput1,LOW);
  LEDtimer1=millis();
}

void LEDtoggle2()
{
  if(digitalRead(LEDOutput2)==LOW)
    digitalWrite(LEDOutput2,HIGH);
  else
    digitalWrite(LEDOutput2,LOW);
  LEDtimer2=millis();
}

void LEDtoggle3()
{
  if(digitalRead(LEDOutput3)==LOW)
    digitalWrite(LEDOutput3,HIGH);
  else
    digitalWrite(LEDOutput3,LOW);
  LEDtimer3=millis();
}

void serialEvent()
{
    
  while(Serial.available()>0)
  {
    buffer=Serial.readString();
     i=0;
     intCount=0;
     stringCount=0;
     flag=1;
    while(buffer[i]!='\0')
    {
      if((buffer[i]-'a'>=0 && buffer[i]-'a'<=25 ) || (buffer[i]-'A'>=0 && buffer[i]-'A'<=25)) stringCount++;
      if((buffer[i]-'0'>=0 && buffer[i]-'0'<=LEDOutput3)) intCount++;
      i++;
    }
  }
    i=0;
    while(buffer[i]!='\0'){
      buffer[i++]=' ';}
}

void loop() {
  // put your main code here, to run repeatedly:
 
   unsigned long curr=millis();
   serialEvent();
   if(flag==1){
     if((stringCount!=0 && intCount!=0) || (intCount==0 && stringCount<5))
   {
      digitalWrite(LEDOutput1,LOW);
      digitalWrite(LEDOutput2,LOW);
      if(curr-LEDtimer3>cutoffLED3) LEDtoggle3();
      LEDToToggleNext=LEDOutput3;
    }   
   else if(intCount!=0 && stringCount==0)
   {
    digitalWrite(LEDOutput2,LOW);
      digitalWrite(LEDOutput3,LOW);
      if(curr-LEDtimer1>cutoffLED1)  LEDtoggle1();
      LEDToToggleNext=LEDOutput1;
   }
     else   {
      digitalWrite(LEDOutput1,LOW);
      digitalWrite(LEDOutput3,LOW);
      if(curr-LEDtimer2>cutoffLED2) LEDtoggle2();
      LEDToToggleNext=LEDOutput2;
     }
   }
}
