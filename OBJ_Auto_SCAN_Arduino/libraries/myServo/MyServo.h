#ifndef MY_SERVO
#define MY_SERVO
#include <Servo.h>

class MyServo
{
public:
	MyServo();
	void SetPosition(int position);
	int GetPosition();

private:
	int _position;
	Servo _servo;
};

#endif