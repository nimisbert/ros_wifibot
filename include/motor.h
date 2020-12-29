/**
 * Project Wifibot
 * version 0.0
 */

#ifndef _MOTOR_H
#define _MOTOR_H

#include <string>
#include "module.h"

/** @brief Class motor.
 *  @author Nicolas Misbert.
 *  @date December 2020.
 * 
 * Class used to control motor modules.
 * This class is used to receive float32 values sent by a user module and convert them into 8bit pwm values.
 * 
 * VERSION INFORMATION :
 * 
 * The control of the motor in rotation speed or position is yet to be implemented.
 * The addresses of the motors are set within the ros_loop_access which is not right a module handling the different addresses on the i2c bus needs to be added.
 */
class motor: public modules//Class motor
{
public:
	/**
	 * Constructor of motor
	 */
	motor();
	/**
	 * Destructor of motor
	 */
	~motor();
	/*
	 * Calls the ros loop.
	 */
	void motor_launch(int argc, char **argv);
	/*
	 * Used to declare the specific instruction for the motor module :
	 * Interprets the position of the motor as an hexadecimal address on the bus.
	 * For instance motor BL corresponds to the address 0x0b.
	 * Translate a float32 value into trame using the float2hex function.
	 * Creates a trame with the string of hexadecimals.
	 */
	virtual std::string ros_loop_access(float value, int argc, char **argv);

private:
	std::string addr;/**< Address of the motor module on the bus in hexadecimal */
	std::string pos;/**< User friendly name of the motor module BL = backleft, TR = topright (BL, TR, ...) */
};
#endif //_MOTOR_H
