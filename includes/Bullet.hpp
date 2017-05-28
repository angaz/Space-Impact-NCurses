#ifndef RUSH00_BULLET_H
#define RUSH00_BULLET_H

#include <string>
#include <iostream>
#include <ncurses.h>

struct loc {
    int    x;
    int    y;
};

class Bullet {
public:
		virtual Bullet();
        virtual Bullet(unsigned int damage, int velocity, loc loc);
        virtual Bullet(Bullet const &src);
        virtual ~Bullet();

        Bullet   &operator=(Bullet const &rhs);
        virtual loc getLoc( void );

protected:
		unsigned int    _damage;
		int             _velocity;
		loc             _loc;
        std::string 	_sprite[];
};

#endif
