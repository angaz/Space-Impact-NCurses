#ifndef RUSH00_PLAYER_H
#define RUSH00_PLAYER_H

#include <string>
#include <iostream>

#include "Bullet.hpp"
#include "Enemy.hpp"

class Player {

public:
	virtual Player() = 0;
	virtual Player(const Player &src) = 0;
	virtual ~Player() = 0;
	Player &operator=(const Player &rhs);

	virtual void moveUp();
	virtual void moveDown();
	virtual Bullet* fire();
	virtual bool takeDamage(unsigned int amount);
	virtual void die();
	virtual loc getLoc();
	virtual std::string* getSprite();
	virtual unsigned int getLength();
	virtual unsigned int getHeight();
	virtual bool isCollided(Bullet &bullet);
	virtual bool isCollided(Enemy &enemy);

protected:
	unsigned int _hp;
	unsigned int _maxHp;
	unsigned int _damage;
	unsigned int _player;
	unsigned int _length;
	unsigned int _height;
	loc _loc;
	std::string _sprite[];
	loc _gunLoc;
	int _bVelocity;

	bool isPointOnShape(int x, int y);
	bool isPointInShape(int x, int y);
};


#endif //RUSH00_PLAYER_H
