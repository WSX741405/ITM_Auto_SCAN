/*
 Name:		OBJ_Auto_SCAN_Arduino.ino
 Created:	2018/2/14 上午 03:44:01
 Author:	qaz74
*/

#include <Servo.h>
#include <ArduinoSTL.h>
#include <MyServo.h>
#include <MyServoFactory.h>

#define MAX_DEGREE 180
#define MIN_DEGREE 0

MyServoFactory* servoFactory;
MyServo* servo;
int servoId;
int degree;

void setup() {
	Serial.begin(9600);
	servoFactory = new MyServoFactory(3);
	servoFactory->GetServo(0)->SetPinNumber(9);
	servoFactory->GetServo(1)->SetPinNumber(10);
	servoFactory->GetServo(2)->SetPinNumber(11);
}

void loop() {
	if (Serial.available() >= 2)
	{
		servoId = Serial.read() - 48;
		degree = Serial.readString().toInt();
		if (servoFactory->IsServoExist(servoId))	//	Check servo exist
		{
			if (degree <= MAX_DEGREE && degree >= MIN_DEGREE)	//	Check degree is 0~180
			{
				servo = servoFactory->GetServo(servoId);
				servo->SetDegree(degree);
				Serial.print(servoId);
				Serial.print(servo->GetDegree());
			}
		}
	}
}