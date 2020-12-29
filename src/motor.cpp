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
#include "motor.h"
#include "module.h"

motor::motor(){};
motor::~motor(){};

void motor::motor_launch(int argc, char **argv)
{
	wifibot::ros_module2iic(argc,argv);
}

std::string motor::ros_loop_access(float value, int argc, char **argv)
{
	int j = 0;
	while(argv[2][j] != NULL)
	{
		pos.push_back(argv[2][j]);
		j++;
	}
	if(pos=="TL"||pos=="TR"||pos=="BL"||pos=="BR")
	{
		if(pos=="TL"){addr="0x09";}
		if(pos=="TR"){addr="0x0a";}
		if(pos=="BL"){addr="0x0b";}
		if(pos=="BR"){addr="0x0c";}
	}
	std::string hexstring_val = modules::float2hex(value);
	std::string hexstring_addr = addr;

	std::string trame_user = "a;"+hexstring_addr+";"+hexstring_val+";";
	return trame_user;	
};
