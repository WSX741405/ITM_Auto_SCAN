#include "MyServo.h"

MyServo::MyServo()
{
}

void MyServo::SetPosition(int position)
{
	_position = position;
}

int MyServo::GetPosition()
{
	return _position;
}