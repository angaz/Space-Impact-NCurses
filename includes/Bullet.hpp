#ifndef RUSH00_BULLET_H
#define RUSH00_BULLET_H

#include <string>
#include <iostream>
#include <ncurses.h>

struct loc{
    unsigned int    x;
    unsigned int    y;
};

class Bullet : public Update{
public:
		virtual Bullet();
        virtual Bullet(unsigned int damage, int velocity, loc loc);
        virtual Bullet(Bullet const &src);
        virtual ~Bullet();

        Bullet   &operator=(Bullet const &rhs);

protected:
        virtual unsigned int    _damage;
        virtual int             _velocity;
        virtual std::string     _sprite[3];
        virtual loc             _loc;
};

#endif
