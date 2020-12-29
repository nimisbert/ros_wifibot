/**
 * Project Wifibot
 * version 0.0
 */

#ifndef _SERVO_H
#define _SERVO_H

#include <string>
#include "module.h"

/** @brief Class servo.
 *  @author Nicolas Misbert.
 *  @date December 2020.
 * 
 * Used to declare a specific set of instructions for servomotors.
 * 
 * VERSION INFORMATION :
 * 
 * The final version of the module should be able to convert a angle value in degrees (-90.0° ; 90.0°) and map it to a set of values of pwm used to control a servo (0 - 255).
 */
class servo: public modules
{
public:
	/*!
	 * Constructor of servo
	 */
	servo();
	/*!
	 * Destructor of servo
	 */
	~servo();
	/*
	 * Calls the function ros_module2iic.
	 */
	void servo_launch(int argc, char **argv);
	/*
	 * Used to modify the address of the servo module.
	 */
	void set_servo_addr(std::string modified_addr);
	/*
	 * Set of instructions to be done within the ros loop in the case of a servo module :
	 * Translate a float value into an hexadecimal string.
	 * Build a trame string to send to the i2c node.
	 */
	virtual std::string ros_loop_access(float value, int argc, char **argv);

private:
	std::string addr;/**< Adress of the servomotor module */
};
#endif //_SERVO_H
