#include "Eatable.h"

Eatable::Eatable(sf::Vector2f position)
	:Gameobj(position)
{
	srand(time(0));											 //Random Seed
	auto randNum = (unsigned)rand() % (Utilities::instance()->m_winSize - Utilities::instance()->m_objSize - 30);
	Gameobj::setPos(sf::Vector2f(randNum, randNum));

	this->m_collided = false;								 //Initially False

}
//--------------------------------------------------------
Eatable::~Eatable() {}
//--------------------------------------------------------
void Eatable::updatePos(double deltaT)
{
	if (this->m_collided == true)
	{
		auto randNum = (unsigned)rand() % (Utilities::instance()->m_winSize - Utilities::instance()->m_objSize);
		Gameobj::setPos(sf::Vector2f(randNum, randNum));
		this->m_collided = false;							//Resetting it
	}
}
//Setter--------------------------------------------------
void Eatable::setCollide(bool newCollide)
{
	this->m_collided = newCollide;
}
//--------------------------------------------------------
