#include "MyServo.h"

MyServo::MyServo(int degree) : _degree(degree)
{
}

void MyServo::SetDegree(int degree)
{
	_degree = degree;
}

int MyServo::GetDegree()
{
	return _degree;
}