#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Collider.h"									//Gives Collision Detection to All Entities
#include "Utilities.h"
#include <memory>

class Gameobj
{
protected:

	sf::RectangleShape m_body;							//The Body of the Entity
	Collider* m_colide;									//Collider Used For Collision Detection

public:
	Gameobj(sf::Vector2f position);
	~Gameobj();

	enum DIRECTION { RIGHT = 0, DOWN = 90, LEFT = 180, UP = 270 };//snake head direction to rotate
	sf::Texture m_texture;

	virtual void draw(sf::RenderWindow *w);				//Drawing function for Entity 
	virtual void updatePos(double deltaT) = 0;			//Update Function for Entity Pure Virutal Function
	void setFillCol(sf::Color newColor);				//Changes the Bodies Fill Colorr

	//getters
	sf::Vector2f getPos();
	Collider getCollider();
	sf::RectangleShape getBody();
	sf::Vector2f getSize();

	//Setter
	void setRotate(DIRECTION direc);
	void setPos(sf::Vector2f newPos);
	void setSize(sf::Vector2f newSize);
	void setTexture(sf::Texture* txtr);
};

