#include <iostream>
#include <ncurses.h>

void initGame();
void gameLoop();
void exitGame();

int main() {
	initGame();
	gameLoop();
	exitGame();

	return 0;
}

void gameLoop() {
	int x, y;
	getmaxyx(stdscr, y, x);

	while (int c = wgetch(stdscr) != 27) {
		move(x/2, y/2);
		printw("You pressed %c", c);
		refresh();
	}
}

void initGame() {
	initscr();
	cbreak();
	keypad(stdscr, true);
	noecho();
}

void exitGame() {
	std::cout << "Exiting\n";

	endwin();
}