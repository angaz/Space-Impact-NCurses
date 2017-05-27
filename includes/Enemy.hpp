#ifndef RUSH00_ENEMY_H
#define RUSH00_ENEMY_H

#include "Bullet.hpp"

struct loc{
    unsigned int    x;
    unsigned int    y;
}

class Enemy : public Bullet
{
public:
        virtual Enemy() = 0;
        virtual Enemy(Enemy const &src) = 0;
        virtual ~Enemy() = 0;

        Enemy   &operator=(Enemy const &rhs);
        virtual Bullet fire( void );
        virtual bool    collision(Bullet &bullet);
        virtual void takeDamage(unsigned int amount);
        virtual void updateEnemy( void );
        virtual loc     getloc(loc _loc);

protected:
        virtual unsigned int    _hp = 0;
        virtual unsigned int    _maxhp = 0;
        virtual int             _shipvelocity = 0;
        virtual std::string     _shipsprite[3] = 0;
        virtual loc             _loc = 0;
};

#endif
