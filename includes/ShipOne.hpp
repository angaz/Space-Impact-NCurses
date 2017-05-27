#ifndef RUSH00_SHIPONE_H
#define RUSH00_SHIPONE_H

#include <iostream>
#inlcude <string>

#include "Player.hpp"

class ShipOne: public Player {

public:
	ShipOne();

	ShipOne(const ShipOne &src);

	~ShipOne();

	ShipOne &operator=(const ShipOne &rhs);

private:
};


#endif //RUSH00_SHIPONE_H
