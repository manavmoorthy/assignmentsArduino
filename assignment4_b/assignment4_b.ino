//declare the necessary variables
unsigned long timer,timer2;
unsigned long bufferToInt = 0;
int LEDOutput = 8;
int flag=0;
int flag2=0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LEDOutput,OUTPUT);
  timer=millis();
}

unsigned long serialEvent()
{
  char buffer[]={' ',' ',' ',' ',' '};
  while(Serial.available()>0){
    flag=1;
      Serial.readBytesUntil('\n',buffer,5);
      bufferToInt=atoi(buffer);
  }
}

void toggle(){
  if(digitalRead(LEDOutput)==LOW)
    digitalWrite(LEDOutput,HIGH);
  else
    digitalWrite(LEDOutput,LOW);
 timer=millis();
}

void loop() {
  // put your main code here, to run repeatedly
  serialEvent();

  if(flag==1){
      unsigned long currentTime = millis();
    if(flag2==0){
      timer2 = current + 10000;
      flag2 = 1;
    }
  if(currentTime-timer > bufferToInt) toggle();
  if(currentTime > timer2 && currentTime !=0){
    Serial.print("The delay is: ");
    Serial.println(bufferToInt);
    timer2 += 10000;
  }  
}
}
