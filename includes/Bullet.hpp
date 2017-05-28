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
		Bullet();
        Bullet(unsigned int damage, int velocity, loc loc);
        Bullet(Bullet const &src);
        virtual ~Bullet();

        Bullet   &operator=(Bullet const &rhs);
        virtual loc getLoc( void );
	virtual unsigned int	getDamage(void);
	virtual std::string		getSprite(void);
	virtual void			update();

protected:
		unsigned int    _damage;
		int             _velocity;
		loc             _loc;
        std::string 	_sprite;
};

#endif
