#include "obstacles.hpp"

int 	randPercent() {
	return static_cast<int>((static_cast<double>(rand()) / static_cast<double>(RAND_MAX)) * 100);
}

chtype 	*generateObstacles(unsigned int tick) {
	srand(tick * static_cast<unsigned int>(time(NULL)));

	int gen = randPercent();

	chtype	*obstacles = new chtype[16];
	for(int i = 0; i < 8; i++) {
		obstacles[7 - i] = (gen < ((static_cast<double>(i) / 8.0) * 100)) ? ACS_CKBOARD : ' ';
	}

	gen = randPercent();
	for(int i = 8; i < 16; i++) {
		obstacles[i] = (gen < ((static_cast<double>(i - 8) / 8.0) * 100)) ? ACS_CKBOARD : ' ';
	}

	return obstacles;
}

chtype	**generateInitialObstacles() {
	chtype	**obstacles = new chtype*[128];

	for (unsigned int i = 0; i < 128; i++) {
		obstacles[i] = generateObstacles(i);
	}

	return obstacles;
}

void	updateObstacles(unsigned int tick, chtype **obstacles) {
	delete obstacles[0];

	for(int i = 0; i < 127; i++) {
		obstacles[i] = obstacles[i + 1];
	}

	obstacles[127] = generateObstacles(tick);
}

void 	drawObstacles(chtype **obstacles) {
	for(int i = 0; i < 128; i++) {
		for(int j = 0; j < 8; j++) {
			mvaddch(j, i, obstacles[i][j]);
		}

		for(int j = 8; j < 16; j++) {
			mvaddch(15+j, i, obstacles[i][j]);
		}
	}
}