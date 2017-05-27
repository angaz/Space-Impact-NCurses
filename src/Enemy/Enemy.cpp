#include "Enemy.hpp"

virtual Enemy::Enemy() = 0
{
    return;
}
virtual Enemy::Enemy(Enemy const &src) = 0
{
    *this = src;
    return (this);
}
virtual Enemy::~Enemy() = 0
{
    return;
}

Enemy   &operator=(Enemy const &rhs)
{
    this->_hp = rhs._hp;
    this->_maxhp = rhs._maxhp;
}

virtual Bullet Enemy::fire( void )
{
    Bullet bullet = new Bullet;
    bullet._damage = this->_damage;
    bullet._bulletvelocity = this->_bulletvelocity;
    bullet._bulletsprite = this->_bulletsprite;
    bullet.loc.x = this.loc.x;
    bullet.loc.y = this.loc.y;
    return (bullet);
}
virtual loc Enemy::move()
{
    return (this->loc);
}

virtual void Enemy::takeDamage(unsigned int amount)
{
    this->_hp = _hp - amount;
}

virtual bool    collision(Bullet &bullet)
{
    if ((bullet.loc.x == this->loc.x) && (bullet.loc.y == this->loc.y))
        return true;
    else
        return false;
}
