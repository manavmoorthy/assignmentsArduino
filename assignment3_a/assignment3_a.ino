//declare necessary variables
int buttonInput = 4, LEDOutput1 = 7, LEDOutput2 = 8, LEDOutput3 = 9;
long int counter=0;

void setup() {
  // put your setup code here, to run once:
  pinMode(buttonInput,INPUT);
  pinMode(LEDOutput1,OUTPUT);
  pinMode(LEDOutput2,OUTPUT);
  pinMode(LEDOutput3,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int buttonState=digitalRead(buttonInput);
  if(buttonState==HIGH){
    delay(2000);
    counter++;
    Serial.println("1");
  }
  if(counter%LEDOutput2==0)
  {
     digitalWrite(LEDOutput1,LOW);
     digitalWrite(LEDOutput2,LOW);
     digitalWrite(LEDOutput3,LOW);
  }
  if(counter%LEDOutput2==1)
  {
     digitalWrite(LEDOutput2,LOW);
     digitalWrite(LEDOutput1,LOW);
     digitalWrite(LEDOutput3,HIGH);
  }
  if(counter%LEDOutput2==2)
  {
     digitalWrite(LEDOutput3,LOW);
     digitalWrite(LEDOutput1,HIGH);
     digitalWrite(LEDOutput2,LOW);
  }
  if(counter%LEDOutput2==3)
  {
     digitalWrite(LEDOutput2,LOW);
     digitalWrite(LEDOutput3,HIGH);
     digitalWrite(LEDOutput1,HIGH);
  }
  if(counter%LEDOutput2==4)
  {
     digitalWrite(LEDOutput2,HIGH);
     digitalWrite(LEDOutput3,LOW);
     digitalWrite(LEDOutput1,LOW);
  }
  if(counter%LEDOutput2==5)
  {
     digitalWrite(LEDOutput2,HIGH);
     digitalWrite(LEDOutput1,LOW);
     digitalWrite(LEDOutput3,HIGH);
  }
  if(counter%LEDOutput2==6)
  {
     digitalWrite(LEDOutput2,HIGH);
     digitalWrite(LEDOutput1,HIGH);
     digitalWrite(LEDOutput3,LOW);
  }
  if(counter%LEDOutput2==7)
  {
     digitalWrite(LEDOutput3,HIGH);
     digitalWrite(LEDOutput2,HIGH);
     digitalWrite(LEDOutput1,HIGH);
  }
}
