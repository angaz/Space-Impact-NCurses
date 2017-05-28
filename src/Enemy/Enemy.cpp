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
//Send details of the bullet, most importantly the location
Bullet& Enemy::fire(void) const
{
    Bullet *bullet = new Bullet(this->_damage, this->_bVelocity, this->_bLoc);
    return *bullet;
}

void Enemy::takeDamage(unsigned int amount)
{
    this->_hp -= amount;
}
/*Check if front of the bullet (bullet._loc.y) collides with either of the front most hitboxes of the ship (100,5)    -->***
                                                                                                          (100,5 + 1)-->***
                                                                                                          (100,5 + 2)-->***
Add death if Angus doesn't implement;
*/
bool    Enemy::collision(Bullet &bullet)
{
    loc				bulletLoc = bullet.getLoc();
	unsigned int	bulletDamage = bullet.getDamage();

	for (int i = 0; i < this->_length; i++) {
		for (int j = 0; j < this->_height; j++) {
			if ((bulletLoc.x == this->_loc.x + i) && (bulletLoc.y == this->_loc.y + j)) {
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
