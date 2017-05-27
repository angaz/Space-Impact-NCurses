#ifndef ZORG_H
#define ZORG_H

#include "Enemy.hpp"

class Zorg : public Enemy
{
public:
        Zorg( void );
        Zorg(Zorg const &src);
        virtual ~Zorg( void );

        Zorg   &operator=(Zorg const &rhs);
};

#endif
