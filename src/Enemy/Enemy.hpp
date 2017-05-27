#ifndef ENEMY_H
#define ENEMY_H

#include "../Bullet.hpp"

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
        virtual Bullet fire(unsigned int dmg, int vlc, unsigned int x, unsigned int y, std::string sprite);
        virtual loc move();
        virtual void takeDamage(unsigned int amount);

protected:
        virtual unsigned int    _hp;
        virtual unsigned int    _maxhp;
};

#endif
