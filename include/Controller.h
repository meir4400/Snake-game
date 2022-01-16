#pragma once
#include <stdlib.h>
#include <time.h>
#include <thread>
#include <chrono>
#include <stack>
#include "GameMode.h"
#include "LostMode.h" 
#include "Utilities.h"

class Controller
{
	void updatePos();							//Updates all components in game
	void draw();								//Draws all Components in game
	void process();								//Processes all components in game
	void checkQuit();
	void initModes();							//Initiallizes all the Modes of the Controller
	void nextLevel();							//call next level when previous done
	void begeinScreen();						//print begin scren

	sf::Sound m_sound;						//audio stuff
	sf::SoundBuffer m_soundBuffer;

	sf::Texture m_beginTexture;					//begin screen texture
	sf::RectangleShape m_beginScreen;

	sf::RenderWindow m_window;

	std::stack<std::unique_ptr<Mode>> m_modes; //Holds all the Modes in the Controller

	double m_deltaT = 0;						//delta time
	int m_score = 0;							//Saves the Score
	int m_level = 0;							//the current level

public:
	Controller();
	~Controller();
	void run(); //Main Loop 
};

