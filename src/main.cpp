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

/*
	        ___          	1
	    . -^   `--,      	2
	   /# =========`-_   	3
	  /# (--====___====\ 	4
	 /#   .- --.  . --.| 	5
	/##   |  * ) (   * ),	6
	|##   \    /\ \   / |	7
	|###   ---   \ ---  |	8
	|####      ___)    #|	9
	|######           ##|	10
	 \##### ---------- / 	11
	  \####           (  	12
	   `\###          |  	13
	     \###         |  	14
	      \##        |   	15
	       \###.    .)   	16
	        `======/     	17
	123456789012345678901
	         1         2
*/
	int plus = 8;
	bool neg = false;
	for (int i = 0; i < 16; i++) {
		if (neg) plus++;
		else plus--;
		if (!(i % 8)) neg = !neg;

		clear();
		mvprintw( 0 + plus, 0, "        ___          ");
		mvprintw( 1 + plus, 0, "    . -^   `--,      ");
		mvprintw( 2 + plus, 0, "   /# =========`-_   ");
		mvprintw( 3 + plus, 0, "  /# (--====___====\\ ");
		mvprintw( 4 + plus, 0, " /#   .- --.  . --.| ");
		mvprintw( 5 + plus, 0, "/##   |  * ) (   * ),");
		mvprintw( 6 + plus, 0, "|##   \\    /\\ \\   / |");
		mvprintw( 7 + plus, 0, "|###   ---   \\ ---  |");
		mvprintw( 8 + plus, 0, "|####      ___)    #|       SHOW ME WHAT YOU GOT!!!");
		mvprintw( 9 + plus, 0, "|######           ##|");
		mvprintw(10 + plus, 0, " \\##### ---------- / ");
		mvprintw(11 + plus, 0, "  \\####           (  ");
		mvprintw(12 + plus, 0, "   `\\###          |  ");
		mvprintw(13 + plus, 0, "     \\###         |  ");
		mvprintw(14 + plus, 0, "      \\##        |   ");
		mvprintw(15 + plus, 0, "       \\###.    .)   ");
		mvprintw(16 + plus, 0, "        `======/     ");

		refresh();
		usleep(15625 * 16); //64 TPS
	}

}

void exitGame() {
	endwin();
}