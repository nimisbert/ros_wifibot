/**
 * Project Wifibot
 * version 0.0
 */

#ifndef _I2C_H
#define _I2C_H

#include <string>
#include "wifibot.h"

/** @brief Class i2c.
 *  @author Nicolas Misbert.
 *  @date December 2020.
 * 
 * This class is used to handle the link between ROS and the physical i2c bus using the WiringPI librairie made by Gordon Henderson.
 * This class is used to create a ROS node which listens to strings called "Trames" published on the topic "/trame_in".
 * "Trames" is the mean found to make sure that the node only listens to an unique topic. This topic is a string.
 * This string is standardized in the following manner :
 * "type_of_module;address_of_module_in_hexadecimal;data_to_be_sent_in_hexadecimal"
 * Due to the uncanny modularity of our ros loop function receiving the value of a sensor is similar to sending a data.
 * The node will listen to a trame and publish the requested value on a topic called float_out.
 * There is a problem with the way these requested values are published because for now a value requested by a sensor addressed at 0x08 and one addressed at 0xAB can't be differenciated.
 *
 * Examples :
 * 
 * To send the pwm value 255 to a motor link to the i2c by a module for which the address is 09 the following trame must be listened :
 * "a;0x09;0xFF"
 * To send a value request to a module connected to a sharp the following trame must be listened :
 * "c;0x09;0x00" -- the data value is unused for sensors module value requests.
 * 
 * VERSION INFORMATION :
 * 
 * Knowing wich sensor replied is to be added.
 * 
 */
class i2c: public wifibot// Class i2c
{
public:
	/**
	 * Constructor of i2c
	 */
	i2c();
	/**
	 * Destructor of i2c
	 */
	~i2c();
	/**
	 * Not to be used in this class.
	 */
	virtual std::string ros_loop_access(float value,   int argc, char **argv);
	/**
	 * This function is used to translate a string called "Trame" in 8bit values to be sent on the physical i2c bus.
	 */
	void decode_trame(std::string str, unsigned char &user_addr, unsigned char &user_data);
	/**
	 * This function is used to send the translated values of decode_trame on the physical bus.
	 */
	void data_send(std::string str, unsigned char user_addr, unsigned char user_data);
	/**
	 * This function is used to send a value request on the physical i2c bus.
	 */
	int data_receive(std::string str, unsigned char user_addr,unsigned char user_data);
	/**
	 * Don't know if this function is still relevant.
	 */
	std::string get_trame_in(void){return trame_in;};

protected:
	std::string trame_in;/**< Don't know if still relevant*/
	std_msgs::Float32 node_data_out;/**< Don't know if still relevant*/
	unsigned char addr_in_bus;/**< Don't know if still relevant*/
	unsigned char data_bus_in;/**< Don't know if still relevant*/
	unsigned char data_bus_out;/**< Don't know if still relevant*/
};
#endif //_I2C_H
