#include "Snake.h"
#include <iostream>

//-----------------------------------------------------------
Snake::Snake(sf::Vector2f position)
	:Gameobj(position)
{
	this->m_texture[0].loadFromFile("closed.png");				 //load Snake texture
	this->m_texture[1].loadFromFile("mid.png");
	this->m_texture[2].loadFromFile("open.png");

	this->m_dir = RIGHT;										//Initially The Direction is to the RIGHT 

	this->m_tail.push_back(std::make_unique <Tail>(Gameobj::getPos()));	//By default The First Tail is the Snake
}
//-----------------------------------------------------------
Snake::~Snake(){}
//-----------------------------------------------------------
void Snake::draw(sf::RenderWindow* w)							//Drawing Snake And Tail
{			
	static int i = 0;											//set head sprite for animation
	Gameobj::setTexture(&m_texture[i % 3]);
	i++;
	w->draw(Gameobj::getBody());								//Drawing the Snake

	for (int i = 1; i < m_tail.size(); i++)
		w->draw(m_tail[i]->Gameobj::getBody());					//Drawing the Tail
}
//----------------------------------------------------------- 
void Snake::updatePos(double deltaT)							//Creating an Update position for the Snake
{
	Snake::keyboardInput();										//Edits the Heads Direction Depending on the User input

	if (this->m_dir == UP)										//SNAKE DIRECTION
	{
		Gameobj::setPos(Gameobj::getPos() + sf::Vector2f(0, -Gameobj::getSize().y));
		Gameobj::setRotate(UP);
	}
	if (this->m_dir == RIGHT)
	{
		Gameobj::setPos(Gameobj::getPos() + sf::Vector2f(Gameobj::getSize().x, 0));
		Gameobj::setRotate(RIGHT);
	}
	if (this->m_dir == DOWN)
	{
		Gameobj::setPos(Gameobj::getPos() + sf::Vector2f(0, Gameobj::getSize().y));
		Gameobj::setRotate(DOWN);
	}
	if (this->m_dir == LEFT)
	{
		Gameobj::setPos(Gameobj::getPos() + sf::Vector2f(-Gameobj::getSize().x, 0));
		Gameobj::setRotate(LEFT);
	}
	this->updateTailPos();											//Updates the Tails Position

}
//-----------------------------------------------------------
bool Snake::ifOutside()												//return true if new head position is outside the game
{
	return (Gameobj::getPos().x > (Utilities::instance()->m_winSize - Utilities::instance()->m_objSize) || Gameobj::getPos().x < 0 ||
		Gameobj::getPos().y > (Utilities::instance()->m_winSize - Utilities::instance()->m_objSize) || Gameobj::getPos().y < 0);
}
//-----------------------------------------------------------
void Snake::keyboardInput()											//Edits the Heads direction depending on what Key is pressed
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		m_dir = UP;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		m_dir = RIGHT; 
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		m_dir = DOWN;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		m_dir = LEFT;
	}
}
//-----------------------------------------------------------
void Snake::updateTailPos()											//Updates Tail Position so that they follow the head 
{
	for (auto i = m_tail.size() - 1; i > 0; i--)					//Start at the back. each part gets the prev position
		m_tail[i]->setPos(m_tail[i - 1]->getPos());

	if (m_tail.size() >= 1)											//And the First One Follows the head
		m_tail[0]->setPos(Gameobj::getPos());
}
//-----------------------------------------------------------
void Snake::growTail()
{
	this->m_tail.push_back(std::make_unique< Tail >(this->m_tail[this->m_tail.size()-1]->getPos()));
}
//-----------------------------------------------------------
bool Snake::headToTail()											//Checks if the Snake is touching the tail
{
	if (this->m_tail.size() > 2)									//Only Check if a tail exists
	{
		for (int i = 1; i < this->m_tail.size(); i++)
			if (Gameobj::getCollider().checkCollision(this->m_tail[i]->getCollider()) == true)
				return true;
	}

	//Else 
	return false;
}