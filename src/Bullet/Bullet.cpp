#include "Bullet.hpp"

virtual Bullet::Bullet(){
}

virtual Bullet::Bullet(unsigned int damage, int velocity, loc loc){
	this->_damage = damage;
	this->_velocity = velocity;
	this->loc = loc;
	this->_sprite = {"/ \\",
					 "[O]",
					 "\\ /"};
}

virtual Bullet::Bullet(Bullet const &src){
    *this = src;
    return (this);
}
virtual ~Bullet::Bullet()
{
    std::cout << "Deconstructor Called";
}

Bullet   &operator=(Bullet const &rhs)
{
    this->_damage = rhs._damage;
    this->_bulletvelocity = rhs._bulletvelocity;
    this->_bulletsprite = rhs._bulletsprite;
}
