#pragma once
#include "Utilities.h"
#include <SFML/Graphics.hpp>

class Mode
{
	bool m_quit;										 //Determines if the Mode Should Quit Initially False
	bool m_levelFinish;									 //if true, user ended level
	int m_holderScore;									 //Holds the Score from the GameMode the LostMode

public:
	Mode();
	~Mode();
	
    virtual void updatePos(double deltaT) = 0;			//Updates the Components of the Mode
	virtual void draw(sf::RenderWindow* w) = 0;			//Draws the Components of the Mode
	virtual void process(double deltaT , sf::Vector2f mousePos) = 0;//Process The Components in the Mode

	virtual void checkStop(double deltaT) = 0;			//All Key Binds Of Mode go in here 

	virtual void checkForQuit();						//Predefined Quit Key

	void setQuit(bool newQuit);							//get set the quit status
	bool getQuit() const;								

	void incLevel();									//go to next level
	void setLevel(bool newLevel);						//set the exit level status
	bool getLevel();

	void setHolderScore(int newScore);					//get and set the score
	int getHolderScore() const;

	virtual bool ifReplay();							//if re play the game

	static int m_level;									//current level
};