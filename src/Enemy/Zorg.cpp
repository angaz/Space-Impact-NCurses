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
    this->_velocity = -5;
    this->_ship = { "000",
                    "000",
                    "000"};
    this->_sprite = {"<"};
    this->loc.x = x;
    this->loc.y = y;
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
    this->_maxhp = rhs._maxhp;
    this->_hp = rhs._hp;
    this->_damage = rhs._damage;
    this->_velocity = rhs._velocity;
    this->_sprite = rhs._sprite;
    this->_ship = rhs._ship;
    this->loc.x = rhs.loc.x;
    this->loc.y = ths.loc.y;
}
