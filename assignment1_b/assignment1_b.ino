//define the necessary variables
int outputPin = 9;
int UPPER_BOUND = 255, LOWER_BOUND = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(outputPin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int analogValue;
 char buffer[] = {' ',' ',' '}; 
 while (Serial.available()==0); // Wait for characters
 Serial.readBytesUntil('\n', buffer, 3);
 analogValue = atoi(buffer);
 Serial.println(analogValue);
  if(analogValue <= UPPER_BOUND && analogValue > LOWER_BOUND)
  {
    analogWrite(outputPin,analogValue);
    Serial.println("LED GLOWING");
  }
  else if(analogValue == LOWER_BOUND)
  {
    analogWrite(outputPin,0);
    Serial.println("LED OFF");
  }
  else
  {
    Serial.println("Invalid!");
  }
}

