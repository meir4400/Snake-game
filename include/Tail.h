#pragma once
#include "Gameobj.h"
//-----------------------------------------------------------
class Tail : public Gameobj
{
public:
	Tail(sf::Vector2f position);
	~Tail();

	void updatePos(double deltaT) override;
	
};