#pragma once
#include "Gameobj.h"//A Button is a Entity
#include <string>

enum ButtonMode{IDLE = 0, HOVER, PRESSED};

class Button : public Gameobj
{
	sf::Text m_text;										//The Text of the Button
	ButtonMode m_mode;										//Determines what Mode the Button is in 

	sf::Color m_idleColor;									
	sf::Color m_hoverColor;
	sf::Color m_pressedColor;

public:
	Button(sf::Vector2f position, sf::Texture* texture, sf::Vector2f size,
		sf::Color idleColor, sf::Color hoverColor, sf::Color pressedColor,sf::Font * font,
		std::string value, int textSize, sf::Color textColor);
	~Button();

	void updatePos(double deltaT) override;
	void draw(sf::RenderWindow * w) override;

	void checkMode(sf::Vector2f mousePos);					//Checks if the Button is Idle,Hover, or Pressed

	bool isPressed();										//if the Button is Pressed 

	//Setter
	void setTextPos(sf::Vector2f newPos);
	void setText(std::string newText);						//Changes the Strings Text

	//Getters
	std::string getText() const;							//Returns the text
};

