#ifndef RUSH00_GAMELOOP_HPP
#define RUSH00_GAMELOOP_HPP

#include <string>
#include <zconf.h>
#include <ncurses.h>

namespace actions {
	const unsigned int NONE = 0;
	const unsigned int FIRE = 32;
	const unsigned int DOWN = 258;
	const unsigned int UP = 259;
	const unsigned int LEFT = 260;
	const unsigned int RIGHT = 261;
}

void			gameLoop(void);
void			getAction(int c, unsigned int &action);
const char		*getActionString(int c);

char 	*generateScene(unsigned int tick);
char	**generateInitialScene();
char	**updateScene(unsigned int tick, char **scene);
void 	drawScene(char **scene);

#endif //RUSH00_GAMELOOP_HPP
