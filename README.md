# assignmentsArduino

Basic assignments were solved using the Arduino microcontroller. These assignments are detailed below:

## Assignment 1

### A
Vary the brightness of the LED according to the LDR value.

### B
Vary the brightness of an LED using user’s input given through serial input. (User should enter PWM value within range of 0-255 and this value should be the PWM given to the LED)

## Assignment 2

### A
Read the LDR value and perform the following:
- Red LED should glow if the light falling on the LDR is maximum.
- White LED should glow if the light falling on the LDR is minimum.
- Blue LED should glow for other values in between.

### B
Read the potentiometer value connected to the Arduino and control the rotation of the servo motor. For example for a full swipe of the potentiometer from 0 to maximum value,the servo should rotate 0 to 180.

## Assignment 3

### A
Count the number of times the button is pressed and display the count value in binary format using the 3 LEDs present onboard.

### B1
Make 3 LEDs blink continuously with the following delays:	
- LED 1 : 10ms
- LED 2 : 100ms
- LED 3 : 1000ms

### B2
Make three LEDs blink based on the blink interval given by user (the delays should be given individually for each LED).For default state, all 3 LEDs should blink with a delay of 1000ms.

## Assignment 4

### A
Read the serial input from the user and perform the following operation:		
- Red LED should blink if the user provides number input (integers)
- Blue LED should blink if the user provides string input (string size minimum 5 characters)
- White LED should blink for any other garbage input from the user with any delay.

### B
Make the LED blink according to the delay given by the user (in milliseconds) through the serial input screen and at every 10 second interval the program should update the Serial output screen with the current delay of the LED

## Assignment 5

### A
Write a program that does the following using the 2 buttons and 3 LEDs
onboard:
- Pressing button 1 should toggle right to the next LED.
- Pressing button 2 should left to the previous LED.

### B
Make three LED’s glow according to delay (in ms) and sequences entered by the user. For example, the sequence "L1 200 L2 400 L3 500" should make LED1 blink for 200ms, followed by LED2 for 400ms and followed by LED3 for 500ms.

## Assignment 6

### A
Write an Arduino Program with 1 LEDs and 2 buttons:
- Button 1 : pressing the button Starts or stops reading the status of Button2.
- Button 2 : Tap the button for any number of times.            
The ON/OFF sequence of Button 2 should be the sequence seen in the LED.
E.g. If Button2 is pressed in following sequence ON-600 OFF-400 ON-500 OFF-3000, the LED should blink with same sequence.

### B
Vary the brightness of an LED using a transistor as an interface.The range of brightness should be divided into 5 levels. The user can input either 'one', two' ...'five' to get the brightness of the corresponding levels. For example, say the maximum brightness is 100, each level should be 20. If the user enters three, the brightness should be corresponding to level three i.e., 60.