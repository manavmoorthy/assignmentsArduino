//declare the necessary variables
unsigned long currentTime;
int LEDOutput1 = 7, LEDOutput2 = 8, LEDOutput3 = 9;

void setup() {
  // put your setup code here, to run once:
  pinMode(LEDOutput1,OUTPUT);
  pinMode(LEDOutput2,OUTPUT);
  pinMode(LEDOutput3,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  currentTime = millis();
  if(currentTime%10==0)
  {
     digitalWrite(LEDOutput1,HIGH);
     digitalWrite(LEDOutput2,LOW);
     digitalWrite(LEDOutput3,LOW);
  }
  if(currentTime%100==0)
  {
    digitalWrite(LEDOutput1,HIGH);
    digitalWrite(LEDOutput2,HIGH);
    digitalWrite(LEDOutput3,LOW);
  }
  if(currentTime%1000==0)
  {
    digitalWrite(LEDOutput1,HIGH);
    digitalWrite(LEDOutput2,HIGH);
    digitalWrite(LEDOutput3,HIGH);
  }
  if(currentTime%1000!=0)
  {
    digitalWrite(LEDOutput1,LOW);
    digitalWrite(LEDOutput2,LOW);
    digitalWrite(LEDOutput3,LOW);
  }
}
