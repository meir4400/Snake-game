#include "Gift.h"

Gift::Gift(sf::Vector2f position)
	:Eatable(position)
{
	m_texture[0].loadFromFile("gift1.png");
	m_texture[1].loadFromFile("gift2.png");
	m_texture[2].loadFromFile("gift3.png");
	m_texture[3].loadFromFile("gift4.png");
	m_texture[4].loadFromFile("gift5.png");
	m_texture[5].loadFromFile("gift6.png");
}
//--------------------------------------------------------
Gift::~Gift() {}
//--------------------------------------------------------
void Gift::draw(sf::RenderWindow* w)
{
	static int i = 0;										//set head sprite for animation
	Eatable::setTexture(&m_texture[i % 6]);
	w->draw(Eatable::getBody());

	i++;
}
//---------------------------------------------------------
