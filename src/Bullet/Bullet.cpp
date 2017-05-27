#include "Bullet.hpp"

virtual Bullet::Bullet() = 0;
{
    default;
}
virtual Bullet::Enemy(Enemy const &src) = 0
{
    *this = src;
    return (this);
}
virtual ~Bullet::Bullet() = 0;
{
    std::cout << "Deconstructor Called";
}

Bullet   &operator=(Bullet const &rhs)
{
    this->_damage = rhs._damage;
    this->_bulletvelocity = rhs._bulletvelocity;
    this->_bulletsprite = rhs._bulletsprite;
}
