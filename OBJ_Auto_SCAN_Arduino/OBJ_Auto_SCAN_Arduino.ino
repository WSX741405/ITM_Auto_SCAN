/*
 Name:		OBJ_Auto_SCAN_Arduino.ino
 Created:	2018/2/14 上午 03:44:01
 Author:	qaz74
*/

#include <ArduinoSTL.h>
#include <Servo.h>
int data;

void setup() {
	Serial.begin(9600);
}

void loop() {
	if (Serial.available() > 0)
	{
		data = Serial.read();
		Serial.write(data);
	}
}