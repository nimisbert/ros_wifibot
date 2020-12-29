//C++ dependencies
#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
//Raspberry Pi GPIO library dependencies
#include <wiringPiI2C.h>
#include <wiringPi.h>
//ROS dependencies
#include "ros/ros.h"
#include "std_msgs/String.h"
#include "std_msgs/Int8.h"
//dev dependencies
#include "servo.h"
#include "module.h"

servo::servo(){};
servo::~servo(){};

void servo::servo_launch(int argc, char **argv)
{
	wifibot::ros_module2iic(argc,argv);
}

void servo::set_servo_addr(std::string modified_addr)
{
	addr=modified_addr;
}

std::string servo::ros_loop_access(float value, int argc, char **argv)
{
	std::string hexstring_val = modules::float2hex(value);
	std::string hexstring_addr = addr;
	std::string trame_user = "a;"+hexstring_addr+";"+hexstring_val+";";
	return trame_user;	
};
