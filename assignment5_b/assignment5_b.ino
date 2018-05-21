//declare the necessary variables
unsigned long LEDtimer1,LEDtimer2,LEDtimer3;
int flag;
unsigned int LEDdelay1,LEDdelay2,LEDdelay3;

void setup() {
  // put your setup code here, to run once:
  pinMode(LEDoutput1,OUTPUT);
  pinMode(LEDoutput2,OUTPUT);
  pinMode(LEDoutput3,OUTPUT);
  Serial.begin(9600);
  LEDtimer1=LEDtimer2=LEDtimer3=millis();
  flag=0;
}

void toggle1()
{
  if(digitalRead(LEDoutput1)==HIGH)
    digitalWrite(LEDoutput1,LOW);
  else
    digitalWrite(LEDoutput1,HIGH);
  LEDtimer1=millis();
  Serial.println(LEDdelay1);
}

void toggle2()
{
  if(digitalRead(LEDoutput2)==HIGH)
    digitalWrite(LEDoutput2,LOW);
  else
    digitalWrite(LEDoutput2,HIGH);
  LEDtimer2=millis();
  Serial.println(LEDdelay2);
}

void toggle3()
{
  if(digitalRead(LEDoutput3)==HIGH)
    digitalWrite(LEDoutput3,LOW);
  else
    digitalWrite(LEDoutput3,HIGH);
  LEDtimer3=millis();
  Serial.println(LEDdelay3);
}

unsigned long extractTimeData(int i,String buffer)
{
  
           int j=buffer.indexOf(' ',i+3);
          char modifiedBuffer[] = {' ',' ',' ',' ',' ',' '};
          int a=0;
          for(int k=i+3;k<j;k++)
            modifiedBuffer[a++]=buffer[k];
            return(atol(modifiedBuffer));
}

void serialEvent()
{
   String buffer;
  int i=0;
  while(Serial.available()>0)
  {
    buffer=Serial.readString();
    while(buffer[i]!='\0')
    {
      if(buffer[i]=='L')
      {
        if(buffer[i+1]=='1')
        {
          LEDdelay1=extractTimeData(i,buffer);
        }
        if(buffer[i+1]=='2')
        {
          LEDdelay2=extractTimeData(i,buffer);
        }
        if(buffer[i+1]=='3')
        {
          char modifiedBuffer[] = {' ',' ',' ',' ',' ',' '};
          int a=0;
          for(int k=i+3;buffer[k]!='\0';k++)
            modifiedBuffer[a++]=buffer[k];
          LEDdelay3=atol(modifiedBuffer);
          
        }
      }
      i++;
      flag=1;
    }
  }
}

void loop() {
  // put your main code here, to run repeatedly:
   unsigned long currentmillis=millis();
 if(flag==1){
  if(currentmillis-LEDtimer1>LEDdelay1) toggle1();
  if(currentmillis-LEDtimer2>LEDdelay2) toggle2();
  if(currentmillis-LEDtimer3>LEDdelay3) toggle3();
      serialEvent();
}
}
