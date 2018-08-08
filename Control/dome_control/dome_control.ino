
#include <SPI.h>
#include <nRF24L01.h>
#include <printf.h>
#include <RF24.h>
#include <RF24_config.h>

/*
	Project BB-8 - Head control
	Author: José Miguel Pérez
	Email: perezmjosem@gmail.com
	
	Features:
		- NRF24L01 connection. - OK
		- Button controller - OK
		- Pasive mode. - OK
		
	Changes:
	2018-07-24 - Initial checkin
*/

// Configuration CE and CSN pins for NRF24L01
#define CE_PIN 9
#define CSN_PIN 10

// left and right buttons for dome
const int leftButtonPin = 2;
const int rightButtonPin = 3;

int leftButtonState = 0;
int rightButtonState = 0;

// channel for read and write NRF24L01
byte channel[5] = {'B','B','8','J','M'};

// data for sending
/*
 * [0] Left = {0, 1}
 * [1] Right = {0, 1}
 * [2] Pasive = {0, 1}
 * [3] Action = {} //ToDo: actions.
 */
float data[4];

// pasiveMode
bool pasiveMode = true;
int timer = 0;


RF24 radio(CE_PIN, CSN_PIN);

void setup() {
  Serial.begin(9600);
	Serial.write("setup");

  pinMode(leftButtonPin, INPUT);
  pinMode(rightButtonPin, INPUT);
  
  radio.begin();
  radio.openWritingPipe(channel);    
}

void loop() {  
	leftButtonState = digitalRead(leftButtonPin);
  rightButtonState = digitalRead(rightButtonPin);

  if (leftButtonState == HIGH) {
    data[0] = 1;
    timer = 0;
  } else {
    data[0] = 0;
  }

  if (rightButtonState == HIGH) {
    data[1] = 1;
    timer = 0;
  } else {
    data[1] = 0;
  }

  // Check pasive timer
  if(leftButtonState == LOW && rightButtonState == LOW) {
    timer = timer + 1;
  }

  if(timer >= 150) {
    data[2] = 1;
  } else {
    data[2] = 0;
  }  
  
  // ToDo: Actions function.
  data[3] = 0;

  bool ok = radio.write(data, sizeof(data));
  if(ok){
    Serial.print("DataSendingOK");
  }
  delay(200);
}
  
  

