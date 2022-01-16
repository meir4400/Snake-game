#pragma once
#include"Eatable.h"

class Gift : public Eatable{

	sf::Texture m_texture[6];							//the animation gift texture and texture pointers

public:

	Gift(sf::Vector2f position);
	~Gift();

	virtual void draw(sf::RenderWindow* w) override;
};