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
}
//Send details of the bullet, most importantly the location
Bullet& Enemy::fire( void )
{
    Bullet *bullet = new Bullet(this->_damage, this->_bVelocity, this->_bLoc);
    return (*bullet);
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
    if ((bullet._loc.x == (this->_loc.x)) && (bullet._loc.y == this->_loc.y))
    {
        this->_hp -= bullet._damage;
        return true;
    }
    else if ((bullet._loc.x == (this->_loc.x)) && (bullet._loc.y == this->_loc.y + 1))
    {
        this->_hp -= bullet._damage;
        return true;
    }
    else if ((bullet._loc.x == (this->_loc.x)) && (bullet._loc.y == this->_loc.y + 2))
    {
        this->_hp -= bullet._damage;
        return true;
    }
    else
        return false;
}

loc     Enemy::getloc(loc _loc){
    return (this->_loc);
}

loc   Enemy::updateEnemy( void )
{
    this->_loc.x += this->_shipvelocity;
    return this->_loc;
}
