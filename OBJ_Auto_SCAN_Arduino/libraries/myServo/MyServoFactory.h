#ifndef MY_SERVO_FACTORY
#define MY_SERVO_FACTORY

#include "MyServo.h"
#include <ArduinoSTL.h>

class MyServoFactory
{
public:
	MyServoFactory(int numberOfServo = 0);
	MyServo* GetServo(int servoId);		//	Servo Id is 0 ... n
	bool IsServoExist(int servoId);
	int GetNumberOfServo();

private:
	int _numberOfServo;
	std::vector<MyServo*> _servos;
};

#endif