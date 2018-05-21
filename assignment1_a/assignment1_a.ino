//define the necessary variables
int sensor=A5;
int sensorValue=0;
int LEDOutput = 9;
int LOWER_BOUND = 440, UPPER_BOUND = 900;
int LEDMax = 255, LEDMin = 0;
void setup() {
  // put your setup code here, to run once:

Serial.begin(9600);
pinMode(LEDOutput,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

sensorValue=analogRead(sensor);
if(sensorValue<LOWER_BOUND) sensorValue=LOWER_BOUND;
if(sensorValue>UPPER_BOUND) sensorValue=UPPER_BOUND;
Serial.println(sensorValue);
int output=map(sensorValue,LOWER_BOUND,UPPER_BOUND,LEDMax,LEDMin);
analogWrite(LEDOutput,output);
}
