#pragma once
#include "Eatable.h"

class Food : public Eatable
{
	sf::Texture m_textures[3];

public:
	Food(sf::Vector2f position);
	~Food();

	virtual void draw(sf::RenderWindow* w) override;
};


