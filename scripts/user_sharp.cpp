#include <iostream>
#include "ros/ros.h"
#include <std_msgs/Float32.h>

void chatterCallback(const std_msgs::Float32::ConstPtr& msg)
{
    ROS_INFO("Front sharp (0x0b) = [%f]",msg->data);
}

int main(int argc, char **argv)
{
    ros::init(argc,argv,"user_sharp_08");
    ros::NodeHandle n;
    ros::Subscriber sub = n.subscribe("float_out",1000,chatterCallback);
    ros::spin();
    return 0;
}

