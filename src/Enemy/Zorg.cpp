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
    this->_bulletvelocity = -5;
    this->_shipsprite = { "000",
                    "000",
                    "000"};
    this->_bulletsprite = {"<"};
    this->_shipvelocity = -1;
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
    this->_bulletvelocity = rhs._bulletvelocity;
    this->_bulletsprite = rhs._bulletsprite;
    this->_shipvelocity = rhs._shipvelocity;
    this->_shipsprite = rhs._shipsprite;
    this->loc.x = rhs.loc.x;
    this->loc.y = ths.loc.y;
}
