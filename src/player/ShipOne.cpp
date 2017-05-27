#include "ShipOne.hpp"

ShipOne::ShipOne(unsigned int locX, unsigned int locY) {
	this->_hp = 100;
	this->_maxHp = 100;
	this->_nShots = 1;
	this->_damage = 20;
	this->_shotSpeed = 1;
	this->_player = 1;
	this->_moveSpeed = 1;
	this->_loc.x = locX;
	this->_loc.y = locY;
	this->_height = 3;
	this->_length = 3;
	this->_sprite = {">=\\",
					 "=====>"
					 ">=/"};

	std::cout << "ShipOne constructed";
};

ShipOne::ShipOne(const ShipOne &src) {
	*this = src;
	return this;
};

ShipOne::~ShipOne() {
	std::cout << "ShipOne destructed";
};
