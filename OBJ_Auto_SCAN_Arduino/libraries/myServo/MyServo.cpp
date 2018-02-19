#include "MyServo.h"

MyServo::MyServo(int degree) : _degree(degree)
{
}

void MyServo::SetPinNumber(int pinNumber)
{
	_pinNumber = pinNumber;
	_servo.attach(_pinNumber);
}

void MyServo::SetDegree(int degree)
{
	_degree = degree;
	_servo.write(_degree);
}

int MyServo::GetDegree()
{
	return _degree;
}