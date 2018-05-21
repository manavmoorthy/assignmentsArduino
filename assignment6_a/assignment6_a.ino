//declare the necessary variables
boolean button,lastButton;
long buttonOn,buttonOff;
int LEDOutput = 7;
int sequenceButton = 2, toggleButton = 3;
int prevIndex,index;
int count=0;
long arrayOfDelays[300];
unsigned long curr;

void setup() {
  // put your setup code here, to run once:
  pinMode(LEDOutput,OUTPUT);
  pinMode(sequenceButton,INPUT);
  pinMode(toggleButton,INPUT);
  lastButton=LOW;
   buttonOn=buttonOff=0;
   prevIndex=0;
   Serial.begin(9600);
   index=0;
}

boolean debounce(boolean last)
{
  boolean current=digitalRead(sequenceButton);
  if(last!=current)
  {
    delay(5);
    current=digitalRead(sequenceButton);
  }
  return current;
}

void toggle()
{
  if(digitalRead(LEDOutput)==HIGH) digitalWrite(LEDOutput,LOW);
  else digitalWrite(LEDOutput,HIGH);
}

void showSequence()
{
  while(index<=prevIndex){
     toggle();
     index++;
     Serial.println(arrayOfDelays[index]);
     delay(arrayOfDelays[index]);
     //delay(100);
  }
  index=prevIndex;
} 

void loop() {
  // put your main code here, to run repeatedly:
  button=debounce(lastButton);
  if(button==LOW && lastButton==HIGH) count++;
  lastButton=button;
  if(count%sequenceButton==1){
    Serial.println(count);
    boolean toggleRead=digitalRead(toggleButton);
    if(toggleRead==HIGH){
     while(toggleRead!=LOW){
      toggleRead=digitalRead(toggleButton);
      button=debounce(lastButton);
  if(button==LOW && lastButton==HIGH) count++;
  lastButton=button;
  if(count%sequenceButton==0) goto showSequenceLabel;}
      if(toggleRead==LOW){
      buttonOff=millis();
      arrayOfDelays[prevIndex]=(buttonOn-buttonOff)>=0?(buttonOn-buttonOff):(buttonOff-buttonOn);
      Serial.println(arrayOfDelays[prevIndex]);
     prevIndex++;
   }
    }
   if(toggleRead==LOW){
     while(toggleRead!=HIGH){
      toggleRead=digitalRead(toggleButton);
      button=debounce(lastButton);
  if(button==LOW && lastButton==HIGH) count++;
  lastButton=button;
  if(count%sequenceButton==0) goto showSequenceLabel;}
     toggleRead=digitalRead(toggleButton);
     if(toggleRead==HIGH){
     buttonOn=millis();
      arrayOfDelays[prevIndex]=(buttonOff-buttonOn)<=0?(buttonOn-buttonOff):(buttonOff-buttonOn);
      Serial.println(arrayOfDelays[prevIndex]);
     prevIndex++;
   }
    }
 }

 showSequenceLabel:
  if(count%sequenceButton==0 && count!=0){
  showSequence(); 
  if(digitalRead(LEDOutput)==HIGH) toggle();
  count=0;
  }
}
