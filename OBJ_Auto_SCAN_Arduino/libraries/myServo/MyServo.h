#ifndef MY_SERVO
#define MY_SERVO
#include <Servo.h>

class MyServo
{
public:
	MyServo(int degree = 0);
	void SetDegree(int degree);
	int GetDegree();

private:
	int _degree;
	Servo _servo;
};

#endif