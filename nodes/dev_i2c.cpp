#include "ros/ros.h"
#include "std_msgs/String.h"
#include "std_msgs/Float32.h"
#include "i2c.h"
#include <iostream>

unsigned data_capteur;

void i2cchatterCallback(const std_msgs::String::ConstPtr& msg)
{
	ROS_INFO("I heard: [%s]", msg->data.c_str());
	//C++ INIT
	i2c IIC;//insancie la classe i2c au nom WIFIBOT_I2C
	unsigned char address_received;
	unsigned char data_received;
	IIC.decode_trame(msg->data.c_str(),address_received,data_received);
	printf("address : %d \n",(int)address_received);
	printf("data    : %d \n",(int)data_received);
	IIC.data_send(msg->data.c_str(),address_received,data_received);
	data_capteur = IIC.data_receive(msg->data.c_str(), address_received, data_capteur);
}

int main(int argc, char **argv)
{
	ros::init(argc, argv, "i2c");
	ros::NodeHandle i;

	ros::Subscriber chatter_sub = i.subscribe("trame_in",1000,i2cchatterCallback);
	ros::Publisher chatter_pub= i.advertise<std_msgs::Float32>("float_out",1000);

    	ros::Rate loop_rate(10);
    	while(ros::ok())
    	{
		std_msgs::Float32 msg;
		msg.data = data_capteur;
		ROS_INFO("%f",msg.data);
		chatter_pub.publish(msg);
        	ros::spinOnce();

        	loop_rate.sleep();
    	}
	return 0;
}
