#ifndef RUSH00_OBSTACLES_HPP
#define RUSH00_OBSTACLES_HPP

#include <string>
#include <cstdlib>
#include <ncurses.h>

chtype 	*generateObstacles(unsigned int tick);
chtype	**generateInitialObstacles();
void	updateObstacles(unsigned int tick, chtype **obstacles);
void 	drawObstacles(chtype **obstacles);

#endif //RUSH00_OBSTACLES_HPP
