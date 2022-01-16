#pragma once
#include <SFML/Graphics.hpp>


class Collider
{
public:
	Collider(sf::RectangleShape* body);

	~Collider();

	bool checkCollision(const Collider & other);


	//Getters
	sf::Vector2f getHalfSize() const;
	sf::Vector2f getPos() const;

private:
	sf::RectangleShape* m_body;
};

