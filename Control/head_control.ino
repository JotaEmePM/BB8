/*
	Project BB-8 - Head control
	Author: José Miguel Pérez
	Email: perezmjosem@gmail.com
	
	Features:
		- Bluetooth or Zigbee connection.
		- Joystick.				
		- Battery Control.		
		- Pasive mode.
		
	Changes:
	2018-07-24 - Initial checkin
*/

#include <Servo.h>
Servo servo1; // Servo for testing.

int angle = 0;
int xAxis = A1;
int yAxis = A2;

int button = 4, LED = 12;

void setup() {
	servo1.attach(6);
	
}

void loop() {
	angle 
}