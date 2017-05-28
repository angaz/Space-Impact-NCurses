#include "Bullet.hpp"

Bullet::Bullet() {
}

Bullet::Bullet(unsigned int damage, int velocity, loc loc) {
	this->_damage = damage;
	this->_velocity = velocity;
	this->_loc = loc;
	this->_sprite = "o";
}

Bullet::Bullet(Bullet const &src) {
    *this = src;
}

Bullet::~Bullet() {}

loc	Bullet::getLoc() {
	return (this->_loc);
}
Bullet   &Bullet::operator=(Bullet const &rhs)
{
    this->_damage = rhs._damage;
    this->_velocity = rhs._velocity;
    this->_sprite = rhs._sprite;

	return *this;
}

unsigned int Bullet::getDamage() {
	return this->_damage;
}

std::string Bullet::getSprite() {
	return this->_sprite;
}

void Bullet::update() {
	this->_loc.x += this->_velocity;
}