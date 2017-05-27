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
//Send details of the bullet, most importantly the location
virtual Bullet Enemy::fire( void )
{
    Bullet bullet = new Bullet;
    bullet._damage = this->_damage;
    bullet._bulletvelocity = this->_bulletvelocity;
    bullet._bulletsprite = this->_bulletsprite;
    bullet._loc.x = this->_loc.x - 1;
    bullet._loc.y = this->_loc.y + 1;
    return (bullet);
}
//Send gameloop location to process
virtual _loc Enemy::move()
{
    return (this->_loc);
}

virtual void Enemy::takeDamage(unsigned int amount)
{
    this->_hp -= amount;
}
/*Check if front of the bullet (bullet._loc.y) collides with either of the front most hitboxes of the ship (100,5)    -->***
                                                                                                          (100,5 + 1)-->***
                                                                                                          (100,5 + 2)-->***
Add death if Angus doesn't implement;
*/
virtual bool    Enemy::collision(Bullet &bullet)
{
    if ((bullet._loc.x == (this->_loc.x)) && (bullet._loc.y == this->_loc.y))
    {
        this->_hp -= bullet._damage;
        return true;
    }
    else if (if ((bullet._loc.x == (this->_loc.x)) && (bullet._loc.y == this->_loc.y + 1)))
    {
        this->_hp -= bullet._damage;
        return true;
    }
    else if (if ((bullet._loc.x == (this->_loc.x)) && (bullet._loc.y == this->_loc.y + 2)))
    {
        this->_hp -= bullet._damage;
        return true;
    }
    else
        return false;
}

virtual loc     getloc(loc _loc){
    return (this->loc);
}

virtual void    Enemy::update( void )
{
    this->_loc.x += this->_shipvelocity;
}
