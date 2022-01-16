#include "Tail.h"

//-----------------------------------------------------------
Tail::Tail(sf::Vector2f position) : Gameobj(position){
	Gameobj::m_texture.loadFromFile("tail.png");
	Gameobj::setTexture(&m_texture);
}
//-----------------------------------------------------------
Tail::~Tail(){}

//-----------------------------------------------------------
void Tail::updatePos(double deltaT){}

//-----------------------------------------------------------