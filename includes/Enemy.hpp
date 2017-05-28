#ifndef RUSH00_ENEMY_H
#define RUSH00_ENEMY_H

#include "Bullet.hpp"

class Enemy
{
public:
	Enemy();
	Enemy(Enemy const &src);
	virtual ~Enemy();

	Enemy					&operator=(Enemy const &rhs);
	virtual					Bullet& fire(void) const;
	virtual bool			collision(Bullet &bullet);
	virtual void			takeDamage(unsigned int amount);
	virtual loc				updateEnemy(void);
	virtual loc				getLoc() const;
	virtual std::string		*getSprite(void) const;
	virtual unsigned int	getHeight(void) const;

protected:
        loc             _loc;
        unsigned int    _hp;
        unsigned int    _maxhp;
        int             _shipvelocity;
        std::string     *_shipsprite;
        int 			_bVelocity;
        unsigned 		_damage;
        loc				_bLoc;
        unsigned int	_length;
        unsigned int	_height;

	virtual std::string	*setSprite() = 0;
};

#endif
