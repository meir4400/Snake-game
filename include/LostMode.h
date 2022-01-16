#pragma once
#include "Mode.h"
#include "Button.h"
#include <string>

class LostMode : public Mode
{
	sf::Font m_font;										//Default Font
	int* m_score;											//The Score of the User 

	sf::Text m_playerScore;									//Displays the Players Score
	Button* m_playAgain;									//the play again button 

	sf::RectangleShape m_background;						 //LostMode's Background
	sf::Texture m_backgroundTexture;

public:

	LostMode();
	~LostMode();

	void updatePos(double deltaT) override;					//Updates the Components in the Mode
	void draw(sf::RenderWindow* w) override;				//Draws the Components in the Mode
	void process(double deltaT, sf::Vector2f mousePos) override;//Processes the Components in the Mode 
	void checkStop(double deltaT) override;
	bool ifReplay() override;								//if the User wants to Play Again 
	void setScore(std::string newScore);					//sets the Score to Displays 
};