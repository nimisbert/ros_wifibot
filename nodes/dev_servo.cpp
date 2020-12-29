#include "servo.h"

int main(int argc, char **argv)
{
	servo S;
	S.set_servo_addr("0x0b");
	S.servo_launch(argc, argv);
}
