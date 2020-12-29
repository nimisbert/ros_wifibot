/**
 * Project Wifibot
 * version 0.0
 */

#ifndef _WIFIBOT_H
#define _WIFIBOT_H

#include <string>
#include <std_msgs/Float32.h>
#include <string>

/** @brief Class wifibot.
 *  @author Nicolas Misbert.
 *  @date December 2020.
 * 
 * This library uses a ROS to make a robot work. The robot is made to be modular and uses an i2c as a mean of communication between a raspberry pi and modules.
 * All the modules and the i2c will be handle with ROS. 
 * In order to prevent the rewritting of the ROS loop we decided to put it in the mother class.
 * Then in order to handle the morphism of the instructions to be executed in the ROS loop of a module we use a virtual function called ros_loop_access.
 * Therefore this mother class Wifibot is used to declare the ros loop of any modules as well as a virtual function to handle the morphism of those modules.
 * 
 * VERSION INFORMATION :
 * 
 * Some problems were encountered with the chatter callbacks and templates of ros types. 
 * Therefore our function used to instanciate the ros loop cannot handle any module.
 * For now it can only listen to float32 values and publish strings.
 * 
 * Therefore it is only called ros_module2iic but a final version should be a ros_loop function.
 * 
 * One of the encountered problem is the declaration of the chatter callback in the header file.
 */
class wifibot// Class wifibot
{
public:
	/**
	 * Constructor of wifibot
	 */
	wifibot();
	/**
	 * Destructor of wifibot
	 */
	~wifibot();
	/**
	 * Function used 
	 */
	void ros_module2iic(int argc, char **argv);
	/**
	 * Allows the use of a different set of instructions declared by daugther classes (especially the modules).
	 */
	virtual std::string ros_loop_access(float value,  int argc, char **argv) =0;
	
private:
	std::string trame_out = "0x0b;0x00;";/**< Don't know if it is still relevant*/
	std::string trame_in ="0x0b;0x00;";/**< Don't know if it is still relevant*/
	float user_rosdata_in = 0;/**< Don't know if it is still relevant*/
};
#endif //_WIFIBOT_H
