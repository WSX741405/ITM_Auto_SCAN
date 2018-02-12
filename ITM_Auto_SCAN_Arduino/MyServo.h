#ifndef MY_SERVO
#define MY_SERVO
#include <Servo.h>

class MyServo
{
public:
	MyServo();

private:
	int _pos;
	Servo _servo;
};

#endif