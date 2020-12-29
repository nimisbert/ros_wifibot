//C++ dependencies
#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <math.h>
//Raspberry Pi GPIO library dependencies
#include <wiringPiI2C.h>
#include <wiringPi.h>
//ROS dependencies
#include "ros/ros.h"
#include "std_msgs/String.h"
//dev dependencies
#include "module.h"


modules::modules(){};
modules::~modules(){};

//----------------------------------------------------------
//        FONCTION DE CONVERSION FLOATTANT EN HEXA
//----------------------------------------------------------
std::string modules::float2hex(float value2fit)
{
	int value = (int) value2fit;
	std::ostringstream oss;
	oss<<std::hex<<value;
	if(oss.str().length()>1)
	{
		return "0x"+oss.str();
	}
	else
	{
		return "0x0"+oss.str();
	}
}
