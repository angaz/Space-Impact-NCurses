#ifndef RUSH00_BULLET_H
#define RUSH00_BULLET_H

#include <string>
#include <iostream>
#include <ncurses.h>

struct loc{
    unsigned int    x;
    unsigned int    y;
}

class Bullet : public Update{
public:
        virtual Enemy() = 0;
        virtual Enemy(Enemy const &src) = 0;
        virtual ~Enemy() = 0;

        Bullet   &operator=(Bullet const &rhs);

protected:
        virtual unsigned int    _damage = 0;
        virtual int             _bulletvelocity = 0;
        virtual std::string     _bulletsprite[1] = 0;
        virtual loc             _loc = 0;
};

#endif
