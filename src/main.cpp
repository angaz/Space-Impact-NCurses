#include <ncurses.h>
#include "gameLoop.hpp"

void initGame();
void exitGame();

int main() {
	initGame();
	gameLoop();
	exitGame();

	return 0;
}

void initGame() {
	initscr();
	cbreak();
	nodelay(stdscr, true);
	keypad(stdscr, true);
	noecho();
	curs_set(false);
}

void exitGame() {
	endwin();
}