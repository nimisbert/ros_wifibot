/**
 * Project Wifibot
 * version 0.0
 */

#ifndef _MODULES_H
#define _MODULES_H

#include <string>
#include "wifibot.h"

/** @brief Class modules.
 *  @author Nicolas Misbert.
 *  @date December 2020.
 * 
 * This class is used to declare the functions shared by all the modules.
 * For now this function is just the translation of float values send by user nodes into string of hexadecimals.
 */
class modules: public wifibot// Classe modules
{
public:
	/**
	 * Constructor of modules
	 */
	modules();
	/**
	 * Destructor of modules
	 */
	~modules();
	/**
	 * Needs to be declared in order to be used by daughter classes.
	 */
	virtual std::string ros_loop_access(float value,  int argc, char **argv) =0;
	/**
	 * Function used to convert user values in string of hexadecimals.
	 */
	std::string float2hex(float value2fit);
};

#endif //_MODULES_H
