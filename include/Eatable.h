#pragma once
#include "Gameobj.h"
#include <time.h>
#include <stdlib.h> 

class Eatable : public Gameobj {

protected:

	bool m_collided; 									//Determines if the object is Collided with the snake

public:

	Eatable(sf::Vector2f position);
	~Eatable();

	virtual void updatePos(double deltaT) ;
	virtual void draw(sf::RenderWindow* w) =0;
	void setCollide(bool newCollide);

};