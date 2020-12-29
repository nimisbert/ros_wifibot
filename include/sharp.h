/**
 * Project Wifibot
 * version 0.0
 */

#ifndef _SHARP_H
#define _SHARP_H

#include <string>
#include "module.h"

/** @brief Class sharp.
 *  @author Nicolas Misbert.
 *  @date December 2020.
 * 	
 * Class used to send value request to a sharp module.
 */
class sharp: public modules// Class Sharp
{
public:
	/**
	 * Constructor of sharp
	 */
	sharp();
	/**
	 * Destructor of sharp
	 */
	~sharp();
	/**
	 * Calls ros_module2iic.
	 */
	void sharp_launch(int argc, char **argv);
	/**
	 * Used to modify the address of the sharp module.
	 */
	void set_sharp_addr(std::string modified_addr);
	/**
	 * Functions used to send value request for sharp modules.
	 */
	virtual std::string ros_loop_access(float value, int argc, char **argv);

private:
	std::string addr;/**< Address of the sharp module to send a request to*/
};
#endif //_SHARP_H
