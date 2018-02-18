#include "MyServoFactory.h"

MyServoFactory::MyServoFactory(int numberOfServo) : _numberOfServo(numberOfServo)
{
	for (int counter = 0; counter < _numberOfServo; counter++)
	{
		MyServo* tempServo = new MyServo(counter);
		_servos.push_back(tempServo);
	}
}

MyServo* MyServoFactory::GetServo(int servoId)
{
	return _servos[servoId];
}

bool MyServoFactory::IsServoExist(int servoId)
{
	if (servoId < _numberOfServo && servoId >= 0)
		return true;
	return false;
}

int MyServoFactory::GetNumberOfServo()
{
	return _numberOfServo;
}