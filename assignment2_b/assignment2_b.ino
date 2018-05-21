//declare servo header files
#include<Servo.h>

//declare the necessary variables
Servo servoMotor;
int sensor=A5;
int sensorValue;
int outputPin = 10;
int LOWER_BOUND = 0, UPPER_BOUND = 180;
int LOWER_SENSOR_READING = 0, UPPER_SENSOR_READING = 1023;
void setup() {
  // put your setup code here, to run once:
  servoMotor.attach(outputPin);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  sensorValue=analogRead(sensor);
   Serial.println(sensorValue);
  int degree=map(sensorValue,LOWER_SENSOR_READING,UPPER_SENSOR_READING,LOWER_BOUND,UPPER_BOUND);
  servoMotor.write(degree);
  delay(50);
}
