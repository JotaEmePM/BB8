#include <SPI.h>
#include <nRF24L01.h>
#include <printf.h>
#include <RF24.h>
#include <RF24_config.h>

/*
	Project BB-8 - Dome
	Author: Jose Miguel Perez
	Email: perezmjosem@gmail.com
	
	Features:
		- NRF24L01 connection.
		- Servo Control.
		- Light Control.
		- Sound control.		
		- Sound Locator.
		- Pasive mode.
		
	Changes:
	2018-07-24 - Initial checkin

  https://naylampmechatronics.com/blog/16_tutorial-basico-nrf24l01-con-arduino.html
*/

// Configuration CE and CSN pins for NRF24L01
#define CE_PIN 9
#define CSN_PIN 10

// channel for read and write NRF24L01
byte channel[5] = {'B','B','8','J','M'};

// data for reading
/*
 * [0] Left = {0, 1}
 * [1] Right = {0, 1}
 * [2] Pasive = {0, 1}
 * [3] Action = {} //ToDo: actions.
 */
float data[4];

// pasiveMode
bool pasiveMode = true;

RF24 radio(CE_PIN, CSN_PIN);

void setup() {
	
}

void loop() {
	
}
