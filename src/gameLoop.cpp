#include <cstdlib>
#include <iostream>
#include "gameLoop.hpp"

void gameLoop(void) {
	int 			x, y;
	int 			c;
	unsigned int	tick = 0;
	unsigned int	action = actions::NONE;
	char 			**scene;

	scene = generateInitialScene();
	drawScene(scene);

	while (true) {
		getmaxyx(stdscr, y, x);
		tick++;

		if (y < 32 || x < 128) {
			mvprintw(0, 0, "Window needs to be at least 32 chars high and 128 chars long");
			mvprintw(y - 1, x - 7, "%3d %3d", x, y);
		} else {
			if (!(tick % 16)) {
				clear();
				mvprintw(y - 1, 0, "%d\t%s", tick, getActionString(action));

				drawScene(scene);
				updateScene(tick, scene);

				mvprintw(y - 1, x - 7, "%3d %3d", x, y);

				action = actions::NONE;
			}
		}

		refresh();

		timeout(0);
		c = getch();
		if (c == 27) {
			break;
		}

		getAction(c, action);

		usleep(15625); //64 FPS
	}
}

int 	randPercent() {
	return static_cast<int>((static_cast<double>(rand()) / static_cast<double>(RAND_MAX)) * 100);
}

char 	*generateScene(unsigned int tick) {
	srand(tick * static_cast<unsigned int>(time(NULL)));

	int gen = randPercent();

	char	*scene = new char[16];
	for(int i = 0; i < 8; i++) {
			scene[i] = static_cast<char>((gen < ((static_cast<double>(i) / 8.0) * 100)) ? 'X' : ' ');
	}

	gen = randPercent();
	for(int i = 8; i < 16; i++) {
		scene[i] = static_cast<char>((gen < ((static_cast<double>(i - 8) / 8.0) * 100)) ? 'X' : ' ');
	}

	return scene;
}

char	**generateInitialScene() {
	char	**scene = new char*[128];

	for (unsigned int i = 0; i < 128; i++) {
		scene[i] = generateScene(i);
	}

	return scene;
}

char	**updateScene(unsigned int tick, char **scene) {
	delete scene[0];

	for(int i = 1; i < 127; i++) {
		scene[i - 1] = scene[i];
	}

	scene[127] = generateScene(tick);

	return scene;
}

void 	drawScene(char **scene) {
	for(int i = 0; i < 128; i++) {
		for(int j = 0; j < 8; j++) {
			std::cout << scene[i][j] << std::endl;
			mvaddch(j, i, scene[i][j]);
		}

		for(int j = 8; j < 16; j++) {
			mvaddch(15+j, i, scene[i][j]);
		}
	}
}

void getAction(int c, unsigned int &action) {
	using namespace actions;
	switch (c) {
		case FIRE:
			action = FIRE;
			break;
		case DOWN:
			action = DOWN;
			break;
		case UP:
			action = UP;
			break;
		case LEFT:
			action = LEFT;
			break;
		case RIGHT:
			action = RIGHT;
			break;
		default:
			break;
	}
}

const char 		*getActionString(int c) {
	using namespace actions;

	std::string action;
	switch (c) {
		case FIRE:
			action = "FIRE";
			break;
		case DOWN:
			action = "DOWN";
			break;
		case UP:
			action = "UP";
			break;
		case LEFT:
			action = "LEFT";
			break;
		case RIGHT:
			action = "RIGHT";
			break;
		default:
			action = "NONE";
	}

	return action.c_str();
}