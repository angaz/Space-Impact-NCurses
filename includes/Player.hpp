#ifndef RUSH00_PLAYER_H
#define RUSH00_PLAYER_H

#include <string>
#include <iostream>

struct loc {
	unsigned int x;
	unsigned int y;
};

class Player {

public:
	virtual Player() = 0;
	virtual Player(const Player &src) = 0;
	virtual ~Player() = 0;
	Player &operator=(const Player &rhs);

	virtual void moveUp();
	virtual void moveDown();
	virtual void fire();
	virtual bool takeDamage(int amount);
	virtual void die();

	virtual loc getLoc();
	virtual std::string[] getSprite();

private:
	virtual unsigned int _hp = 0;
	virtual unsigned int _maxHp = 0;
	virtual unsigned int _nShots = 0;
	virtual unsigned int _damage = 0;
	virtual unsigned int _shotSpeed = 0;
	virtual unsigned int _player = 0;
	virtual unsigned int _moveSpeed = 0;
	virtual loc _loc = 0;
	virtual std::string* _sprite = 0;
};


#endif //RUSH00_PLAYER_H
