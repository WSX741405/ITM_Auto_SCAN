#include "MyServoFactory.h"

MyServoFactory::MyServoFactory(int numberOfServo)
{
	int counter;
	for (counter = 0; counter < numberOfServo; counter++)
	{
		MyServo myServo = new MyServo();
		_servos.push_back(myServo);
	}
}

MyServo MyServoFactory::GetServo(int servoId)
{
	if (this->IsServoExist(servoId))
		return _servos[servoId];
	return NULL;
}

bool MyServoFactory::IsServoExist(int servoId)
{
	if (_servos.size() < servoId)
		return false;
	return true;
}