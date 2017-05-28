#include "ShipOne.hpp"

ShipOne::ShipOne(unsigned int locX, unsigned int locY) {
	this->_hp = 3;
	this->_maxHp = 3;
	this->_damage = 20;
	this->_player = 1;
	this->_loc.x = locX;
	this->_loc.y = locY;
	this->_height = 3;
	this->_length = 3;
	this->_gunLoc.x = this->_loc.x + this->_length - 1;
	this->_gunLoc.y = this->_loc.y + + 1;
	this->_bVelocity = 3;
	this->_sprite = {">=\\",
					 "==]",
					 ">=/"};

	std::cout << "ShipOne constructed";
};

ShipOne::ShipOne(const ShipOne &src) {
	*this = src;
};

ShipOne::~ShipOne() {
	std::cout << "ShipOne destructed";
};
