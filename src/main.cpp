#include <iostream>
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
	raw();
	keypad(stdscr, true);
	noecho();
	curs_set(false);
}

void exitGame() {
	std::cout << "Exiting\n";

	endwin();
}