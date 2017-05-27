
#include "gameLoop.hpp"

void gameLoop(void) {
	int 			x, y;
	int 			c;
	unsigned int	tick = 0;
	unsigned int	action = actions::NONE;
	chtype 			**scene;

	scene = generateInitialObstacles();
	drawObstacles(scene);

	while (true) {
		getmaxyx(stdscr, y, x);
		tick++;

		if (y < 32 || x < 128) {
			clear();
			mvprintw(0, 0, "Window needs to be at least 32 chars high and 128 chars long");
			mvprintw(y - 1, x - 7, "%3d %3d", x, y);
		} else {
			if (!(tick % 16)) {
				clear();
				mvprintw(y - 1, x - 25, "%16d %8s", tick, getActionString(action));

				drawObstacles(scene);
				updateObstacles(tick, scene);

				action = actions::NONE;
			}
		}

		refresh();

		c = getch();
		if (c == 27) {
			break;
		}

		getAction(c, action);

		usleep(15625); //64 TPS
	}
}