#include "LostMode.h"
#include <iostream>

//-----------------------------------------------------------
LostMode::LostMode()
{
    this->m_font.loadFromFile("C:/Windows/Fonts/david.ttf");
	this->m_backgroundTexture.loadFromFile("lost.png");

	this->m_score = nullptr;										//Initially Pointing to Nothing

	//Initializing the Player Score Text 
	this->m_playerScore.setPosition(sf::Vector2f(Utilities::instance()->m_winSize /2-20, Utilities::instance()->m_winSize /2-150));
	this->m_playerScore.setFillColor(sf::Color::Black);
	this->m_playerScore.setFont(this->m_font);
	this->m_playerScore.setCharacterSize(80);


	//Initializing the Play Button Text 
	this->m_playAgain = new Button(sf::Vector2f(Utilities::instance()->m_winSize / 2-120, Utilities::instance()->m_winSize / 2),nullptr,sf::Vector2f(300,100),
		sf::Color(200,200,200), sf::Color(140,140,140), sf::Color(100,100,100), &this->m_font, "Play Again",
		45,sf::Color::Black);
	this->m_playAgain->setTextPos(sf::Vector2f(Utilities::instance()->m_winSize / 2-100, Utilities::instance()->m_winSize / 2));

	//Initializing the BackGround 
	this->m_background.setSize(sf::Vector2f(Utilities::instance()->m_winSize, Utilities::instance()->m_winSize));
	this->m_background.setTexture(&this->m_backgroundTexture);
}
//-----------------------------------------------------------
LostMode::~LostMode()
{
	delete this->m_playAgain; //Deallocates Memory 
}
//-----------------------------------------------------------
void LostMode::updatePos(double deltaT)						//Updates the Components in the Mode
{
	this->checkStop(deltaT);								//Checking if the User wants to Quit the Mode 
}
//-----------------------------------------------------------
void LostMode::draw(sf::RenderWindow* w)					//Draws the Components in the Mode
{
	w->draw(this->m_background);							//Drawing the Background FIRST 
	
	w->draw(this->m_playerScore);							//Draws the Player Score to the Window
	this->m_playAgain->draw(w);								//Draws the Play Again Button
}
//-----------------------------------------------------------
void LostMode::process(double deltaT, sf::Vector2f mousePos)//Processes the Components in the Mode 
{
	//Updates the Text Score
	this->m_playerScore.setString(std::to_string(Mode::getHolderScore()));
	this->m_playAgain->checkMode(mousePos);
}
//-----------------------------------------------------------
void LostMode::checkStop(double deltaT)
{
	Mode::checkForQuit();									//Checks if the User Wants to Quit
}
//-----------------------------------------------------------
bool LostMode::ifReplay()
{
	if (Mode::getLevel() == true)
		return true;										//true if level ended

	return (this->m_playAgain->isPressed());				//set if to play again
}
//-----------------------------------------------------------
void LostMode::setScore(std::string newScore)				//Updates the Players Score Text 
{
	this->m_playerScore.setString(newScore);
}
//-----------------------------------------------------------