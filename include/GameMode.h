#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Mode.h"
#include "Food.h"
#include "Gift.h"
#include "Snake.h"
#include "Button.h"

class GameMode : public Mode
{
	sf::Sound m_foodSound;								//audio stuff
	sf::SoundBuffer m_foodBuffer;
	sf::Sound m_giftSound;
	sf::SoundBuffer m_giftBuffer;
	sf::Sound m_winSound;
	sf::SoundBuffer m_winBuffer;

	sf::Clock m_clock;									//the game time
	double m_deltaT;									//delta time

	std::unique_ptr<Snake> m_snake;						//Snake head Stuff					
	std::unique_ptr<Food> m_food;						//food stuff
	std::unique_ptr<Gift> m_gift;						//gift

	sf::Texture m_backgroundTxtr[4];					//background stuff
	sf::RectangleShape m_background[4];

	sf::Text m_pauseText;								//Pause screen Text
	sf::Font m_font;
	
	sf::Texture m_scoreTexture;							//the button of Score and time
	Button* m_scoreButton, * m_timeButton;

	bool m_pause;										//Pauses the Screen

public:
	GameMode();
	~GameMode();
	void updatePos(double deltaT) override;				//checks changes in head(direction) and food(if was collision, make new)
	void draw(sf::RenderWindow* w) override;			//Draws all the Components of the Mode
	void process(double deltaT, sf::Vector2f mousePos) override; //checks Collisions)
	void checkStop(double deltaT) override;				//Defines all the Keyboard Stuff for that Mode
};


