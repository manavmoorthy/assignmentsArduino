//declare the necessary variables
int current,prevLED,nextLED,leftBound,rightBound;
int flag=0;
boolean button1,lastButton1,button2,lastButton2;

void setup() {
  // put your setup code here, to run once:
  pinMode(inputButton1,INPUT);
  pinMode(inputButton2,INPUT);
  pinMode(LEDOutput1,OUTPUT);
  pinMode(LEDOutput2,OUTPUT);
  pinMode(LEDOutput3,OUTPUT);
  
  //initial configurations
  
  prevLED=LEDOutput3;
  nextLED=LEDOutput2;
  leftBound=LEDOutput1;
  rightBound=LEDOutput3;
  lastButton1=LOW;
  lastButton2=LOW;
}

void toggleRight()
{
  digitalWrite(current,LOW); 
 current=nextLED;
   nextLED=current+1;
  prevLED=current-1;
  if(nextLED>rightBound) nextLED=leftBound;
  if(prevLED<leftBound) prevLED=rightBound;
 digitalWrite(current,HIGH);
}

void toggleLeft()
{
  digitalWrite(current,LOW); 
  current=prevLED;
   nextLED=current+1;
  prevLED=current-1;
  if(nextLED>rightBound) nextLED=leftBound;
if(prevLED<leftBound) prevLED=rightBound;
 digitalWrite(current,HIGH);
}

boolean debounce1(boolean last)
{
  boolean current=digitalRead(inputButton1);
  if(last!=current)
  {
    delay(5);
    current=digitalRead(inputButton1);
  }
  return current;
}

boolean debounce2(boolean last)
{
  boolean current=digitalRead(inputButton2);
  if(last!=current)
  {
    delay(5);
    current=digitalRead(inputButton2);
  }
  return current;
}

void loop() {
  // put your main code here, to run repeatedly:
  if(flag==0)
  {
    digitalWrite(LEDOutput2,LOW);
    digitalWrite(LEDOutput3,LOW);
    digitalWrite(LEDOutput1,HIGH);
    delay(100);
    flag=1;
    current=LEDOutput1;
  }
  button1=debounce1(lastButton1);
  button2=debounce2(lastButton2);
 if(button1==HIGH && lastButton1==LOW){
   toggleLeft();
  }
  if(button2==HIGH && lastButton2==LOW){
    toggleRight();
  }
    lastButton1=button1;
    lastButton2=button2;
}
 
