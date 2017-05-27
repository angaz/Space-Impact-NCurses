#ifndef RUSH00_ACTIONS_HPP
#define RUSH00_ACTIONS_HPP

#include <string>

namespace actions {
	const unsigned int NONE = 0;
	const unsigned int FIRE = 32;
	const unsigned int DOWN = 258;
	const unsigned int UP = 259;
	const unsigned int LEFT = 260;
	const unsigned int RIGHT = 261;
}

void			getAction(int c, unsigned int &action);
const char		*getActionString(int c);

#endif //RUSH00_ACTIONS_HPP
