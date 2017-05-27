#include "Player.hpp"

Player::Player() {
}

Player::Player(const Player &src) {
}

Player::~Player() {
}

Player &operator=(const Player &rhs) {
	this->_hp = rhs._hp;
	this->_maxHp = rhs._maxHp;
	this->_nShots = rhs._nShots;
	this->_damage = rhs._damage;
	this->_shotSpeed = rhs._shotSpeed;
	this->_player = rhs._player;
	this->_moveSpeed = rhs._moveSpeed;

	return *this;
}

void Player::moveDown() {
	this->_loc.y -= 1;
}

void Player::moveUp() {
	this->_loc.y += 1;
}

void Player::takeDamage(unsigned int amount) {
	this->_hp -= amount;
	if (this->_hp == 0) {
		this->die();
		return true;
	}
	return false;
};

void Player::die() {
	delete(this);
};

//Bullet* Player::fire() {
//	return new Bullet(velocity = positive)
//}

loc Player::getLoc() {
	return this->_loc;
}

std::string* Player::getSprite() {
	return _sprite;
};