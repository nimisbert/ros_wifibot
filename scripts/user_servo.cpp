#include <iostream>
#include "ros/ros.h"
#include <std_msgs/Float32.h>

int main(int argc, char **argv)
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
    ros::init(argc,argv,module_name+"_"+module_identifier+"_user");
    ros::NodeHandle n;
    ros::Publisher chatter_pub=n.advertise<std_msgs::Float32>(module_name+module_identifier+"_chatter",1000);
    ros::Rate loop_rate(10);
    while(ros::ok())
    {
        std_msgs::Float32 msg;
	msg.data = 0.0+i++;
	if(i==255){i=0;};
	ROS_INFO("%f", msg.data);
	chatter_pub.publish(msg);
        ros::spinOnce();
        loop_rate.sleep();
    }
    return 0;
}

