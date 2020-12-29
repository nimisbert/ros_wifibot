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
#include <std_msgs/Float32.h>
//dev dependencies
#include "wifibot.h"

float user_trame_data = 0;

wifibot::wifibot(){};
wifibot::~wifibot(){};

void M2I_chatterCallback(const std_msgs::Float32::ConstPtr& msg_user)
{
	ROS_INFO("I heard: [%f]", msg_user->data);
	float msgdata = msg_user->data;
	user_trame_data = msg_user->data;
}

void wifibot::ros_module2iic(int argc, char **argv)
{
    std::string module_name;
    int i=0;
    std::string module_identifier;
    int j=0;
    if(argc < 1)
    {	
	    std::cout << "Number of arguments must be two" << std::endl;
    }
    else
    {
	    while(argv[1][i] != NULL)
	    {
		    module_name.push_back(argv[1][i]);
		    i++;
	    }
	    while(argv[2][j] != NULL)
	    {
		    module_identifier.push_back(argv[2][j]);
		    j++;
	    }
	    std::cout << "My module name is "<< module_name << std::endl;
	    std::cout << "My identifier  is "<< module_identifier << std::endl;
	    j=0;
	    i=0;
    }
    std::string topic_name = module_name+"_"+module_identifier+"_topic";
    ros::init(argc,argv,module_name+"_"+module_identifier);
    ros::NodeHandle n;
    ros::Subscriber sub = n.subscribe(module_name+module_identifier+"_chatter", 1000, M2I_chatterCallback);
    ros::Publisher chatter_pub=n.advertise<std_msgs::String>("trame_in",1000);
    ros::Rate loop_rate(10);
    while(ros::ok())
    {
        std_msgs::String trame_msg;
        std::stringstream ss;
	    ss << wifibot::trame_out << std::endl;
        trame_msg.data = ss.str();
        ROS_INFO("%s",trame_msg.data.c_str());
        chatter_pub.publish(trame_msg);
	    wifibot::trame_out = ros_loop_access(user_trame_data, argc, argv);
        ros::spinOnce();
        loop_rate.sleep();
    }
}

