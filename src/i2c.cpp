//C++ dependencies
#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <bitset>
//Raspberry Pi GPIO library dependencies
#include <wiringPiI2C.h>
#include <wiringPi.h>
//ROS dependencies
#include "ros/ros.h"
#include "std_msgs/String.h"
//dev dependencies
#include "i2c.h"

long long MSGS_ENVOYEES = 0;
long long MSGS_RECUS = 0;

i2c::i2c(){};
i2c::~i2c(){};

//
void i2c::decode_trame(std::string str, unsigned char &user_addr, unsigned char &user_data)
{
	char data= '0';
	char addr = '0';
	
	/*std::cout << "str 0 " << str.at(0) << std::endl; 
	std::cout << "str 1 " << str.at(1) << std::endl; 
	std::cout << "str 2 " << str.at(2) << std::endl; 
	std::cout << "str 3 " << str.at(3) << std::endl; 
	std::cout << "str 4 " << str.at(4) << std::endl; 
	std::cout << "str 5 " << str.at(5) << std::endl; 
	std::cout << "str 6 " << str.at(6) << std::endl; 
	std::cout << "str 7 " << str.at(7) << std::endl; 
	std::cout << "str 8 " << str.at(8) << std::endl; 
	std::cout << "str 9 " << str.at(9) << std::endl;*/

        if(str.at(4)<=65){addr = str.at(4)-'0';}else{addr = str.at(4)-'a'+10;}

	std::string binary = std::bitset<8>(addr).to_string(); //to binary
    	//std::cout<< "binary " << binary<<"\n";

	unsigned char decimal_addr = std::bitset<8>(binary).to_ulong();
    	//std::cout<<" decimal " << decimal_addr <<"\n";

        if(str.at(5)<=65){addr = str.at(5)-'0'+(addr<<4);}else{addr = str.at(5)-'a'+10+(addr<<4);}

	binary = std::bitset<8>(addr).to_string(); //to binary
    	//std::cout<< "binary " << binary<<"\n";

	decimal_addr = std::bitset<8>(binary).to_ulong();
    	//std::cout<<" decimal " << decimal_addr <<"\n";

	//
        if(str.at(9)<=65){data = str.at(9)-'0';}else{data = str.at(9)-'a'+10;}

	binary = std::bitset<8>(data).to_string(); //to binary
    	//std::cout<< "binary " << binary<<"\n";

	unsigned char decimal_data = std::bitset<8>(binary).to_ulong();
    	//std::cout<<" decimal " << decimal_data <<"\n";

        if(str.at(10)<=65){data = str.at(10)-'0'+(data<<4);}else{data = str.at(10)-'a'+10+(data<<4);}

	binary = std::bitset<8>(data).to_string(); //to binary
    	//std::cout<< "binary " << binary<<"\n";

	decimal_data = std::bitset<8>(binary).to_ulong();
    	//std::cout<<" decimal " << decimal_data <<"\n";
	
	user_addr=(int)decimal_addr;
	user_data=(int)decimal_data;
}


std::string i2c::ros_loop_access(float value,   int argc, char **argv)
{
	std::cout << "Things to do here if the code was better " << std::endl;
}

void i2c::data_send(std::string str, unsigned char user_addr,unsigned char user_data)
{
	if(str.at(0)=='a')
	{
		int fd = wiringPiI2CSetup(user_addr);
		//std::cout << "Addressing slave" << std::hex << user_addr << std::endl;
		wiringPiI2CWrite(fd,user_addr);
		//std::cout << "Sending data" << std::hex << user_data << std::endl;
		wiringPiI2CWrite(fd,user_data);
		//std::cout<< "Done transmitting" << std::endl;
		close(fd);
		std::cout << "MESSAGE ENVOYEES = " << MSGS_ENVOYEES++ << std::endl;
	}
}

int i2c::data_receive(std::string str, unsigned char user_addr, unsigned char user_data)
{
	if(str.at(0)=='c')
	{
		int fd = wiringPiI2CSetup(user_addr);
		int user_data = wiringPiI2CRead(fd);
		close(fd);
		std::cout << "MESSAGE RECUS = " << MSGS_RECUS++ << std::endl;
		return user_data;
	}
}
