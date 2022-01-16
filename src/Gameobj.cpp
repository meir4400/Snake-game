#include "Gameobj.h"
#include <iostream>

//--------------------------------------------------------
Gameobj::Gameobj(sf::Vector2f position)
{
	this->m_colide = new Collider(&this->m_body);
	this->m_body.setSize(sf::Vector2f(Utilities::instance()->m_objSize, Utilities::instance()->m_objSize));

	//Setting the Origin For All Entities
	this->m_body.setOrigin(this->m_body.getSize().x / 2.0f, this->m_body.getSize().y / 2.0f); 
	this->m_body.setPosition(position);
}
//--------------------------------------------------------
Gameobj::~Gameobj()
{
	std::cout << "Deallocating Collider" << std::endl;
	delete m_colide;											 //Deallocate Memory  
}
//--------------------------------------------------------
void Gameobj::draw(sf::RenderWindow* w)
{
	w->draw(this->m_body);										//Drawing the Body to the Window
}
//Getters--------------------------------------------------
sf::Vector2f Gameobj::getPos() 
{
	return this->m_body.getPosition();
}
//--------------------------------------------------------
Collider Gameobj::getCollider()
{
	return* m_colide;
}
//--------------------------------------------------------
sf::RectangleShape Gameobj::getBody()
{
	return m_body;
}
//--------------------------------------------------------
sf::Vector2f Gameobj::getSize()
{
	return m_body.getSize();
}
//Setters--------------------------------------------------
void Gameobj::setPos(sf::Vector2f newPos)
{
	this->m_body.setPosition(newPos);
}
//--------------------------------------------------------
void Gameobj::setSize(sf::Vector2f newSize)
{
	this->m_body.setSize(newSize);
}
//--------------------------------------------------------
void Gameobj::setRotate(DIRECTION direc)
{
	m_body.setRotation(direc);
}
//--------------------------------------------------------
void Gameobj::setTexture(sf::Texture* txtr)
{
	m_body.setTexture(txtr);
}
//--------------------------------------------------------
//Changes the Bodies Fill Color
void Gameobj::setFillCol(sf::Color newColor)
{
	this->m_body.setFillColor(newColor);
}
//--------------------------------------------------------
