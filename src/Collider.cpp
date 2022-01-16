#include "Collider.h"
#include <cmath>
#include <iostream>

//--------------------------------------------------------

Collider::Collider(sf::RectangleShape* body) :m_body(body){}
Collider::~Collider(){}

//--------------------------------------------------------
bool Collider::checkCollision(const Collider& other)		//Returns True If The Two Entities Are colliding
{ 
	sf::Vector2f delta(this->getPos() - other.getPos());	//Distance Between the centers of each Entity

	sf::Vector2f halfSize(this->getHalfSize() + other.getHalfSize());

	if (abs(delta.x) - halfSize.x < 0 && abs(delta.y) - halfSize.y < 0)
		return true;//Objects Colliding 

	//Else 
	return false; //Objects Not Colliding 
}
//Getters--------------------------------------------------

sf::Vector2f Collider::getHalfSize() const
{
	return sf::Vector2f(m_body->getSize().x / 2.0f, m_body->getSize().y / 2.0f);
}
//--------------------------------------------------------
sf::Vector2f Collider::getPos() const
{
	return sf::Vector2f(m_body->getPosition());
}
//--------------------------------------------------------