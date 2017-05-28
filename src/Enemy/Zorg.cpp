#include "Zorg.hpp"

Zorg::Zorg( void )
{
    return;
}

Zorg::Zorg(int x, int y)
{
    this->_maxhp = 100;
    this->_hp = 100;
    this->_damage = 20;
    this->_bVelocity = -5;
    this->_shipsprite = { "000","000","000"};
    this->_shipvelocity = -1;
    this->_loc.x = x;
    this->_loc.y = y;
    this->_length = 3;
    this->_height = 3;
    this->_bLoc.x = this->_loc.x + this->_length - 1;
	this->_bLoc.y = this->_loc.y - 2;
}

Zorg::Zorg(Zorg const &src)
{
    *this = src;
}

Zorg::~Zorg( void )
{
    return;
}

Zorg   &Zorg::operator=(Zorg const &rhs)
{
    this->_maxhp = rhs._maxhp;
    this->_hp = rhs._hp;
    this->_damage = rhs._damage;
    this->_velocity = rhs._velocity;
    this->_sprite = rhs._sprite;
    this->_shipvelocity = rhs._shipvelocity;
    this->_shipsprite = rhs._shipsprite;
    this->_loc.x = rhs._loc.x;
    this->_loc.y = rhs._loc.y;
    
    return *this;
}
