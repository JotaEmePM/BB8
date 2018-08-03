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

Serial.begin(9600);
Servo servo1; // Servo for testing.

int angle = 90;
int jump = 3;
int xAxis = A1;
int yAxis = A2;

int button = 4, LED = 12;

void setup() {
	Serial.write("setup");
	servo1.attach(6);
	pinMode(button, INPUT_PULLUP);
}

void loop() {
	int px = analogRead(A1);
	int py = analogRead(A2);

	Serial.write("{ X: '" + px + "', Y: '" + py + "' }");

	if(px < 400) {
		angle = angle - salto;
	} else if(px > 600) {
		angle = angle + jump;
	}

	servo1.write(angulo); // Movimiento de servo segun angulo

	//Boton de joystick
	if(!digitalRead(button)){
		digitalWrite(LED, HIGH);
	} else {
		digitalWrite(LED, LOW);
	}
	delay(250);
}