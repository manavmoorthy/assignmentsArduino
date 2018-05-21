//declare the necessary variables
int flag=0,value;
int output = 6;
byte byteVal=48;
int LOWER_BOUND = 0,UPPER_BOUND = 255, LOWER_LEVEL = 0, UPPER_LEVEL = 5;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(output,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  String buffer;
 while(Serial.available()>0){ // Wait for characters
 buffer=Serial.readString();}
 if(buffer.equals("one")) byteVal=1+48;
 if(buffer.equals("two")) byteVal=2+48;
 if(buffer.equals("three")) byteVal=3+48;
 if(buffer.equals("four")) byteVal=4+48;
 if(buffer.equals("five")) byteVal=5+48;
 value = byteVal-48;
 if(value>UPPER_LEVEL) value=UPPER_LEVEL;
 int mappedValue=map(value,LOWER_LEVEL,UPPER_LEVEL,LOWER_BOUND,UPPER_BOUND);
 //Serial.println(mappedValue);
 analogWrite(output,mappedValue);
}
