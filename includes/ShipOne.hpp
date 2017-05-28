#ifndef RUSH00_SHIPONE_H
#define RUSH00_SHIPONE_H

#include <iostream>
#inlcude <string>

#include "Player.hpp"

class ShipOne: public Player {

public:
	ShipOne();

	ShipOne(unsigned int locX, unsigned int locY);

	ShipOne(const ShipOne &src);

	~ShipOne();

	ShipOne &operator=(const ShipOne &rhs);

};


#endif //RUSH00_SHIPONE_H
