#include "Food.h"

//--------------------------------------------------------
Food::Food(sf::Vector2f position)
	: Eatable(position)										  //position is temporarly, will change soon
{
	m_textures[0].loadFromFile("food1.png");				  //Initializing Fruit
	m_textures[1].loadFromFile("food2.png");
	m_textures[2].loadFromFile("food3.png");
}
//--------------------------------------------------------
Food::~Food(){}
//--------------------------------------------------------
void Food::draw(sf::RenderWindow* w)
{
	static int i = 0;										//set head sprite for animation
	Gameobj::setTexture(&m_textures[i % 3]);
	w->draw(Gameobj::getBody());

	i++;
}
//---------------------------------------------------------
