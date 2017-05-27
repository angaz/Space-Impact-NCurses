#include "ShipOne.hpp"

ShipOne::ShipOne() {
	this->_hp = 100;
	this->_maxHp = 100;
	this->_nShots = 1;
	this->_damage = 20;
	this->_shotSpeed = 1;
	this->_player = 1;
	this->_moveSpeed = 1;
	this->_loc.x = 0;
	this->_loc.y = 0;
	this->_sprite = {"top of ship", "bottom of ship"};

	std::cout << "ShipOne constructed";
};

ShipOne::ShipOne(const ShipOne &src) {
	*this = src;
};

ShipOne::~ShipOne() {
	std::cout << "ShipOne destructed";
};
