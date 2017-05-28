#ifndef RUSH00_OBSTACLES_HPP
#define RUSH00_OBSTACLES_HPP

#include <string>
#include <cstdlib>
#include <ncurses.h>

chtype 	*generateObstacles();
chtype	**generateInitialObstacles();
int 	randPercent();
void	updateObstacles(chtype **obstacles);
void 	drawObstacles(chtype **obstacles);

#endif //RUSH00_OBSTACLES_HPP
