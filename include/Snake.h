#pragma once
#include <vector>
#include "Tail.h"

class Snake : public Gameobj
{
	DIRECTION m_dir;										//Heads Direction

	std::vector <std::unique_ptr<Tail>> m_tail;				//the tail
	sf::Texture m_texture[3];							//head texture

public:
	Snake(sf::Vector2f position);
	~Snake();

	void draw(sf::RenderWindow* w) override;
	void updatePos(double deltaT) override;	
	void keyboardInput();									//Edits the Heads Direction Depending on the Key Pressed
	void growTail();										//Grows a Tail When Called 
	void updateTailPos();									//Updates the Tails Position so that they follow the head
	bool headToTail();										//Checks if the Snake is touching the tail
	bool ifOutside();										//return true if new head position is outside the game
};