#include "actions.hpp"

void			getAction(int c, unsigned int &action) {
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