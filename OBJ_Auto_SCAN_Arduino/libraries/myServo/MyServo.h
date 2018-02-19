#ifndef MY_SERVO
#define MY_SERVO
#include <Servo.h>

class MyServo
{
public:
	MyServo(int degree = 0);
	void SetPinNumber(int pinNumber);
	void SetDegree(int degree);
	int GetDegree();

private:
	int _pinNumber;
	int _degree;
	Servo _servo;
};

#endif