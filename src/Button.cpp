#include "Button.h"
//--------------------------------------------------------

Button::Button(sf::Vector2f position, sf::Texture * texture, sf::Vector2f size,
	sf::Color idleColor, sf::Color hoverColor, sf::Color pressedColor, sf::Font * font,
	std::string value, int textSize, sf::Color textColor)
	: Gameobj(position)
{
	Gameobj::setTexture(texture);
	Gameobj::setSize(size);										//Updating the Buttons Size 

	this->m_mode = IDLE;										//Initially the Button is in Idle Mode

	//Setting the Colors 
	this->m_idleColor = idleColor;
	this->m_hoverColor = hoverColor;
	this->m_pressedColor = pressedColor;

	//Setting the Buttons Text
	this->m_text.setFont(*font);
	this->m_text.setCharacterSize(textSize);
	this->m_text.setString(value);
	this->m_text.setFillColor(textColor);
	//Centering the Text in the Middle of the Button
	this->m_text.setPosition(Gameobj::getSize()); 
}
//--------------------------------------------------------
Button::~Button(){}
//--------------------------------------------------------
void Button::updatePos(double deltaT){}
//--------------------------------------------------------
void Button::draw(sf::RenderWindow* w)					//Draws the Body and Text
{
	w->draw(Gameobj::getBody());						//Drawing the Body
	w->draw(this->m_text);								//Drawing the Text
}
//--------------------------------------------------------
void Button::checkMode(sf::Vector2f mousePos)			//Checks if the Button is Idle,Hover, or Pressed
{
	this->m_mode = IDLE;								//Default Button is Idle

	//If the Mouse is Hovering Over the Button then its Hover
	if (Gameobj::getBody().getGlobalBounds().contains(mousePos))
	{
		this->m_mode = HOVER;							//Then its Hovered
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
			this->m_mode = PRESSED;						//Then its Pressed
	}

	switch (this->m_mode)
	{
	case IDLE:
		Gameobj::setFillCol(this->m_idleColor);
		break;
	case HOVER:
		Gameobj::setFillCol(this->m_hoverColor);
		break;
	case PRESSED:
		Gameobj::setFillCol(this->m_pressedColor);
		break;
	default:
		Gameobj::setFillCol(sf::Color::Red);			//SHOULDNT HAPPEN 
	}
}
//--------------------------------------------------------
bool Button::isPressed()
{
	if (this->m_mode == PRESSED)
		return true;

	//Else
	return false;
}

//Setter---------------------------------------------------

void Button::setTextPos(sf::Vector2f newPos)
{
	this->m_text.setPosition(newPos);
}
//--------------------------------------------------------
void Button::setText(std::string newText)
{
	this->m_text.setString(newText);
}
//Getter-------------------------------------------------
std::string Button::getText() const
{
	return this->m_text.getString();					//Returning the String
}