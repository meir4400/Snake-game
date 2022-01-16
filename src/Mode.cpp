#include "Mode.h"
#include <iostream>

int Mode::m_level = 0;
//--------------------------------------------------------
Mode::Mode()
{
	this->m_quit = false;								//Initially False
	this->m_levelFinish = false;
	this->m_holderScore = 0; 
}
//--------------------------------------------------------
Mode::~Mode(){}
//--------------------------------------------------------
void Mode::checkForQuit()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		setQuit(true);									//Setting Quit to True if pressed
}
//--------------------------------------------------------
void Mode::setQuit(bool newQuit)
{
	this->m_quit = newQuit;
}
//---------------------------------------------------------
bool Mode::getQuit() const
{
	return this->m_quit;
}
//---------------------------------------------------------
void Mode::setLevel(bool newLevel)
{
	m_levelFinish = newLevel;
}
//---------------------------------------------------------
void Mode::incLevel() 
{
	m_level++;
}
//---------------------------------------------------------
bool Mode::getLevel()
{
	return m_levelFinish;
}
//---------------------------------------------------------
void Mode::setHolderScore(int newScore)
{
	this->m_holderScore = newScore;
}
//---------------------------------------------------------
int Mode::getHolderScore() const
{
	return this->m_holderScore;
}
//---------------------------------------------------------
bool Mode::ifReplay()
{
	return false; 
}
//---------------------------------------------------------
