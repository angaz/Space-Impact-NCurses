#include "gameLoop.hpp"

void gameLoop(void) {
	int 			x, y;
	int 			c;
	unsigned int	tick = 0;
	unsigned int	action = actions::NONE;
	chtype 			**scene;
	unsigned int	score = 0;
	unsigned int	lives = 3;
	bool 			pause = false;

	scene = generateInitialObstacles();
	drawObstacles(scene);

	while (true) {
		getmaxyx(stdscr, y, x);

		if (y < 32 || x < 128) {
			clear();
			mvprintw(0, 0, "Window needs to be at least 32 chars high and 128 chars long");
			mvprintw(y - 1, x - 7, "%3d %3d", x, y);
		} else if (!pause) {
			tick++;

			if (!(tick % 16)) {
				clear();
				mvprintw(y - 1, 0, "SCORE %6u        LIVES %u", score, lives);
				mvprintw(y - 1, x - 25, "%16d %8s", tick, getActionString(action));

				drawObstacles(scene);
				updateObstacles(tick, scene);

				action = actions::NONE;
			}
		} else {
			/*
			 ____   __   _  _  ____  ____  ____		1
			(  _ \ / _\ / )( \/ ___)(  __)(    \	2
			 ) __//    \) \/ (\___ \ ) _)  ) D (	3
			(__)  \_/\_/\____/(____/(____)(____/	4
			123456789012345678901234567890123456
					 1         2         3
			*/
			mvprintw(y/2-1, x/2-18, " ____   __   _  _  ____  ____  ____");
			mvprintw(y/2-0, x/2-18, "(  _ \\ / _\\ / )( \\/ ___)(  __)(    \\");
			mvprintw(y/2+1, x/2-18, " ) __//    \\) \\/ (\\___ \\ ) _)  ) D (");
			mvprintw(y/2+2, x/2-18, "(__)  \\_/\\_/\\____/(____/(____)(____/");
		}

		refresh();

		c = getch();
		if (c == 113) { // keycode Q
			break;
		} else if (c == 112) { // keycode P
			pause = !pause;
		} else if (c == 120 || lives == 0) { // keycode X
			gameOver(x, y);
			break;
		}

		getAction(c, action);
		usleep(15625); //64 TPS
	}
}

void	gameOver(int x, int y) {
	/*
	  ___   __   _  _  ____     __   _  _  ____  ____ 	1
	 / __) / _\ ( \/ )(  __)   /  \ / )( \(  __)(  _ \	2
	( (_ \/    \/ \/ \ ) _)   (  O )\ \/ / ) _)  )   /	3
	 \___/\_/\_/\_)(_/(____)   \__/  \__/ (____)(__\_)	4
	12345678901234567890123456789012345678901234567890
	         1         2         3         4         5
	*/

	mvprintw(y/2-1, x/2-25, "  ___   __   _  _  ____     __   _  _  ____  ____ ");
	mvprintw(y/2-0, x/2-25, " / __) / _\\ ( \\/ )(  __)   /  \\ / )( \\(  __)(  _ \\");
	mvprintw(y/2+1, x/2-25, "( (_ \\/    \\/ \\/ \\ ) _)   (  O )\\ \\/ / ) _)  )   /");
	mvprintw(y/2+2, x/2-25, " \\___/\\_/\\_/\\_)(_/(____)   \\__/  \\__/ (____)(__\\_)");

	refresh();
	usleep(2500000);
}