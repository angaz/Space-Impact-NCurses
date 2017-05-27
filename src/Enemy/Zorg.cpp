#include "Zorg.hpp"

Zorg::Zorg( void )
{
    this->_maxhp = 100;
    this->_hp = 100;
    this->_damage = 20;
    this->_velocity = -5;
    this->_sprite[0] = "<<<";
    this->_sprite[1] = "<<<";
    this->_sprite[2] = "<<<";
}

Zorg::Zorg(Zorg const &src)
{
    *this = src;
    return (this);
}

virtual ~Zorg( void );
{
    return;
}

Zorg   &operator=(Zorg const &rhs);
{

}
