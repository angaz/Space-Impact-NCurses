#ifndef RUSH00_ZORG_H
#define RUSH00_ZORG_H

#include "Enemy.hpp"

class Zorg : public Enemy
{
public:
        Zorg( void );
        Zorg(int x, int y);
        Zorg(Zorg const &src);
        virtual ~Zorg( void );

        Zorg   &operator=(Zorg const &rhs);
};

#endif
