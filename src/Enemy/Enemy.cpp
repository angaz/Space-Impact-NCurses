#include "Enemy.hpp"

Enemy::Enemy()
{
    return;
}
Enemy::Enemy(Enemy const &src)
{
    *this = src;
}
Enemy::~Enemy()
{
    return;
}

Enemy   &Enemy::operator=(Enemy const &rhs)
{
    this->_hp = rhs._hp;
    this->_maxhp = rhs._maxhp;

	return *this;
}

Bullet& Enemy::fire(void) const
{
	loc		bulletLoc = {this->_loc.x - 1, this->_loc.y + 1};
    Bullet *bullet = new Bullet(this->_damage, this->_bVelocity, bulletLoc);
    return *bullet;
}

void Enemy::takeDamage(unsigned int amount)
{
    this->_hp -= amount;
}

bool    Enemy::collision(Bullet &bullet)
{
    loc				bulletLoc = bullet.getLoc();
	unsigned int	bulletDamage = bullet.getDamage();

	for (unsigned int i = 0; i < this->_length; i++) {
		for (unsigned int j = 0; j < this->_height; j++) {
			if ((bulletLoc.x == (this->_loc.x + i)) && (bulletLoc.y == (this->_loc.y + j))) {
				this->_hp -= bulletDamage;

				return true;
			}
		}
	}

	return false;
}

loc     Enemy::getLoc() const {
    return this->_loc;
}

loc   Enemy::updateEnemy(void)
{
    this->_loc.x += this->_shipvelocity;
    return this->_loc;
}

std::string *Enemy::getSprite() const {
	return this->_shipsprite;
}

unsigned int Enemy::getHeight() const {
	return this->_height;
}
