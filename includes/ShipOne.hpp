#ifndef RUSH00_SHIPONE_H
#define RUSH00_SHIPONE_H

#include <iostream>
#include <string>

#include "Player.hpp"

class ShipOne: public Player {

public:
	ShipOne();

	ShipOne(unsigned int locX, unsigned int locY);

	ShipOne(const ShipOne &src);

	~ShipOne();

private:
	std::string	*setSprite();
};


#endif //RUSH00_SHIPONE_H
