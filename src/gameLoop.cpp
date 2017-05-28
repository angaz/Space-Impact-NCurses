#include "gameLoop.hpp"

void gameLoop(void) {
	int 				x, y;
	int 				c;
	unsigned int		tick = 0;
	unsigned int		action = actions::NONE;
	chtype 				**scene;
	unsigned int		score = 0;
	unsigned int		lives = 3;
	bool 				pause = false;
	Bullet				**bullets = new Bullet*[1000];
	Enemy				**enemies = new Enemy*[1000];
	Player				*player = new ShipOne(1, 16);

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

			if (!(tick % 2)) {
				clear();

				// Update obstacles and entities
				updateObstacles(tick, scene);
				drawObstacles(scene);

				if (action == actions::DOWN && player->getLoc().y < 21)
					player->moveDown();
				else if (action == actions::UP && player->getLoc().y > 7)
					player->moveUp();
				else if (action == actions::FIRE)
					addBullet(bullets, player->fire());

				if (!(tick % 152)) {
					addEnemy(enemies, new Zorg(128, (tick % 12) + 8));
				}

				updateEnemies(enemies, bullets, score, *player);
				updateBullets(bullets);
				if (updatePlayerCollision(*player, bullets, enemies, lives)) {
					gameOver(x, y);
					break;
				}


				// Draw info, obstacles, and entities
				mvprintw(y - 1, 0, "SCORE %6u        LIVES %u", score, lives);


				drawPlayer(*player);
				drawEnemies(enemies);
				drawBullets(bullets);


				// Reset action to stop multiple actions per frame
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
		} else if (c == 120) { // keycode X
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

void 	drawPlayer(Player &player) {
	std::string	*sprite = player.getSprite();
	loc			playerLoc = player.getLoc();
	for(int i = 0; i < player.getHeight(); i++) {
		mvprintw(playerLoc.y + i, playerLoc.x, sprite[i].c_str());
	}
}

//void	drawBullets(LinkedList<Bullet> &bulletList) {
//	Bullet	*bullet = &bulletList.getData();
//
//	while (bullet != NULL) {
//		loc	bulletLoc = bullet->getLoc();
//		mvprintw(bulletLoc.y, bulletLoc.x, bullet->getSprite().c_str());
//	}
//}

void 	drawBullets(Bullet **bullet) {
	for (int i = 0; i < 1000; i++) {
		if (bullet[i] != NULL) {
			loc	bulletLoc = bullet[i]->getLoc();
			if (bulletLoc.x <= 128)
				mvaddch(bulletLoc.y, bulletLoc.x, ACS_CKBOARD);
//				mvprintw(bulletLoc.y, bulletLoc.x, /*bullet[i]->getSprite().c_str()*/);
		}
	}
}

void 	addBullet(Bullet **bullet, Bullet *newBullet) {
	int i = 0;
	while (bullet[i++]) {}

	bullet[--i] = newBullet;
}

void 	updateBullets(Bullet **bullet) {
	for (int i = 0; i < 1000; i++) {
		if (bullet[i] != NULL)
			bullet[i]->update();
	}
}

void	drawEnemies(Enemy **enemy) {
	for (int i = 0; i < 1000; i++) {
		if (enemy[i] != NULL) {
			loc enemyLoc = enemy[i]->getLoc();
			std::string *sprite = enemy[i]->getSprite();

			for (unsigned int j = 0; j < enemy[i]->getHeight(); j++) {
				mvprintw(enemyLoc.y + j, enemyLoc.x, sprite[j].c_str());
			}
		}
	}
}

void 	addEnemy(Enemy **enemy, Enemy *newEnemy) {
	int i = 0;

	while (enemy[i++]) {}

	enemy[--i] = newEnemy;
}

void 	updateEnemies(Enemy **enemy, Bullet **bullets, unsigned int &score, Player &player) {
	for (int i = 0; i < 1000; i++) {
		if (enemy[i]) {
			enemy[i]->updateEnemy();

			for (int j = 0; j < 1000; j++) {
				if (bullets[j] && enemy[i]->collision(*bullets[j])) {
					delete enemy[i];
					enemy[i] = NULL;
					delete bullets[j];
					bullets[j] = NULL;

					score += 20;
					mvprintw(player.getLoc().y - 1, player.getLoc().x + 1, "+20");
					break;
				}
			}
		}
	}
}

bool 	updatePlayerCollision(Player &player, Bullet **bullet, Enemy **enemy, unsigned int &lives) {
	for (int i = 0; i < 1000; i++) {
		if (bullet[i] && player.isCollided(*bullet[i])) {
			lives--;
		}

		if (!lives) return true;

		if (enemy[i] && player.isCollided(*enemy[i])) {
			lives--;
		}

		if (!lives) return true;
	}

	return false;
}