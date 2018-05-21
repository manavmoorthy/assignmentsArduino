//declare the necessary variables
int redPin=9;
int greenPin=7;
int yellowPin=8;
int sensorValue;
int sensor=A5;
int redYellowCutoff = 650, yellowGreenCutoff = 800;

void setup() {
  // put your setup code here, to run once:
  pinMode(redPin,OUTPUT);
  pinMode(yellowPin,OUTPUT);
  pinMode(greenPin,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  sensorValue=analogRead(sensor);
  Serial.println(sensorValue);
  if(sensorValue < redYellowCutoff)
  {
    digitalWrite(redPin,HIGH);
    digitalWrite(greenPin,LOW);
    digitalWrite(yellowPin,LOW);
    delay(5);
  }
  else if(sensorValue > yellowGreenCutoff)
  {
    digitalWrite(redPin,LOW);
    digitalWrite(greenPin,HIGH);
    digitalWrite(yellowPin,LOW);
    delay(5);
  }
  else
  {
    digitalWrite(redPin,LOW);
    digitalWrite(greenPin,LOW);
    digitalWrite(yellowPin,HIGH);
    delay(5);
  }
}
