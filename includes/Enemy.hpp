#ifndef RUSH00_ENEMY_H
#define RUSH00_ENEMY_H

#include "Bullet.hpp"

class Enemy : public Bullet
{
public:
        virtual Enemy() = 0;
        virtual Enemy(Enemy const &src) = 0;
        virtual ~Enemy() = 0;

        Enemy   &operator=(Enemy const &rhs);
        virtual Bullet& fire( void );
        virtual bool    collision(Bullet &bullet);
        virtual void takeDamage(unsigned int amount);
        virtual loc updateEnemy( void );
        virtual loc     getloc(loc _loc);

protected:

        loc             _loc;
        unsigned int    _hp;
        unsigned int    _maxhp;
        int             _shipvelocity;
        std::string     _shipsprite[];
        int 			_bVelocity;
        unsigned 		_damage;
        loc				_bLoc;
        unsigned int	_length;
        unsigned int	_height;

};

#endif
