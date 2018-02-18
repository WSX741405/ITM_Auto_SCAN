/*
 Name:		OBJ_Auto_SCAN_Arduino.ino
 Created:	2018/2/14 上午 03:44:01
 Author:	qaz74
*/

#include <Servo.h>
#include <ArduinoSTL.h>
#include <MyServo.h>
#include <MyServoFactory.h>

MyServoFactory* servoFactory;
MyServo* servo;
int servoId;
int degree;

void setup() {
	Serial.begin(9600);
	servoFactory = new MyServoFactory(3);
}

void loop() {
	if (Serial.available() >= 2)
	{
		servoId = Serial.read() - 48;
		degree = Serial.readString().toInt();
		if (servoFactory->IsServoExist(servoId))
		{
			servo = servoFactory->GetServo(servoId);
			servo->SetDegree(degree);
			Serial.print(servoId);
			Serial.print(servo->GetDegree());
		}
	}
}