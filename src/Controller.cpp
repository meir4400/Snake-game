#include "Controller.h"

//-----------------------------------------------------------
Controller::Controller() :m_window(sf::VideoMode(Utilities::instance()->m_winSize,
	Utilities::instance()->m_winSize), "SnakeGame", sf::Style::Close)
{
	this->m_soundBuffer.loadFromFile("gameSound.wav");//audio init
	this->m_sound.setBuffer(m_soundBuffer);

	this->initModes();								//Initializing All the Modes in the Controller
	m_beginTexture.loadFromFile("beginScreen.jpg");
	m_beginScreen.setTexture(&m_beginTexture);
}
//-----------------------------------------------------------
Controller::~Controller()
{
	for (int i = 0; i < this->m_modes.size(); i++)	//free Memory of Modes
		m_modes.pop(); 
	m_sound.pause();
}
//-----------------------------------------------------------
void Controller::run()
{
	m_sound.setLoop(true);
	m_sound.play();									//play game sound
	begeinScreen();									//print begin screen

	//Main GameLoop
	while (this->m_window.isOpen())
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(Utilities::instance()->m_speed));//slow the game

		sf::Event evnt;								//handle exit if happened
		while (this->m_window.pollEvent(evnt))
		{
			if (evnt.type == sf::Event::Closed)
			{
				this->m_window.close(); 
			}
		}

		this->m_window.clear();
		Controller::updatePos();					//checks changes in head(direction) and food(if was collision, make new)
		Controller::process();					    //Process All Components, check collisions and make changes
		Controller::draw();
		this->m_window.display();
	}

}
//-----------------------------------------------------------
void Controller::updatePos()
{
	if (!this->m_modes.empty())						//Updating the Current Mode	Ensures its not Empty
		this->m_modes.top()->updatePos(this->m_deltaT);
}
//-----------------------------------------------------------
void Controller::draw()
{
	if (!this->m_modes.empty())						//Drawing the Current Mode Ensures its not Empty
		this->m_modes.top()->draw(&this->m_window);
}
//-----------------------------------------------------------
void Controller::process()							//Processing the Current Mode Ensures its not Empty
{
	if (!this->m_modes.empty())

		this->m_modes.top()->process(this->m_deltaT, sf::Vector2f
			(sf::Mouse::getPosition(this->m_window)));  //call prosses of current mode (Mouse position for lost mode)

	this->checkQuit();
}
//-----------------------------------------------------------
void Controller::nextLevel(){						//set settings of new level

	Utilities::instance()->m_winSize += 50;
	Utilities::instance()->m_foodsToWin += 10;
	Utilities::instance()->m_speed -= 20;
	m_level++;

	m_window.create(sf::VideoMode(Utilities::instance()->m_winSize,//remake the window in level change
		Utilities::instance()->m_winSize), "SnakeGame", sf::Style::Close);
}
//-----------------------------------------------------------
void Controller::initModes()						//Initiallizes and push to stack all the Modes
{
	this->m_modes.push(std::make_unique <LostMode>());
	this->m_modes.push(std::make_unique <GameMode>());
}
//-----------------------------------------------------------
void Controller::begeinScreen() {

	m_window.clear();
	m_beginScreen.setSize(sf::Vector2f(m_window.getSize()));
	m_window.draw(m_beginScreen);
	m_window.display();
	std::this_thread::sleep_for(std::chrono::seconds(Utilities::instance()->m_beginTime));//hold the begin screen
}
//-----------------------------------------------------------
void Controller::checkQuit() {

	if (this->m_modes.top()->getQuit() == true) //Check if Quit OR LOST/win THE GAME 
	{
		bool temp = this->m_modes.top()->getLevel();//save the level status before quit
		this->m_score = this->m_modes.top()->Mode::getHolderScore();//Save the Score Before Quit

		this->m_modes.pop();					//Quit and delete the Mode from stack, at first is game mode (newest mode)
		this->m_modes.top()->setLevel(temp);	//insert level status to current mode (lost mode)
	}


	if (this->m_modes.size() <= 1)					//if game mode ended, rearange the game
	{
		this->m_modes.top()->Mode::setHolderScore(this->m_score);

		if (this->m_modes.top()->ifReplay())		//check if user want to play again (or ended level)
		{
			if (this->m_modes.top()->getLevel() == true)//change level if previous ended
				nextLevel();

			if (m_level > 3) {						 //end all game if no more levels
				std::cout << "win all game" << std::endl;
				m_window.close();
				return;
			}

			//if came here it means the user wants to play again, so restart game
			this->m_modes.pop();					//delete the Lost Mode
			this->m_modes.push(std::make_unique <LostMode>()); //Re adding the Lost mode			
			this->m_modes.push(std::make_unique <GameMode>()); //Re adding the game mode
		}
	}
}
//-----------------------------------------------------------