#ifndef BULLET_H
#define BULLET_H

#include <string>
#include <iostream>
#include <ncurses.h>

struct loc{
    unsigned int    x;
    unsigned int    y;
}

class Bullet{
public:
        virtual Enemy() = 0;
        virtual Enemy(Enemy const &src) = 0;
        virtual ~Enemy() = 0;

        Bullet   &operator=(Bullet const &rhs);

protected:
        virtual unsigned int    _damage;
        virtual int             _bulletvelocity;
        virtual std::string     _bulletsprite[1];
};

#endif
