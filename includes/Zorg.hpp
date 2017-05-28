#ifndef RUSH00_ZORG_H
#define RUSH00_ZORG_H

#include "Enemy.hpp"

class Zorg : public Enemy
{
public:
        Zorg( void );
        Zorg(unsigned int x, unsigned int y);
        Zorg(Zorg const &src);
        virtual ~Zorg(void);

        Zorg   &operator=(Zorg const &rhs);

private:
	std::string	*setSprite();
};

#endif
