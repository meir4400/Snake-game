#include <iostream>
#include "Controller.h"

Utilities* m_utilities =Utilities::instance()->instance();

int main()
{
	Controller snakeGame;

	snakeGame.run();

	return 0;
}
//-----------------------------------------------------------