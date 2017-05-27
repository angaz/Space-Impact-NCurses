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
    bullet._velocity = this->_velocity;
    bullet._sprite = this->_sprite;
    bullet.BulletLoc.x = this.BulletLoc.x;
    bullet.BulletLoc.y = this.BulletLoc.y;
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
