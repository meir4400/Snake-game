#include "GameMode.h"

//-----------------------------------------------------------
GameMode::GameMode()
{
	this->m_foodBuffer.loadFromFile("foodSound.wav");			//init audio stuff
	this->m_foodSound.setBuffer(m_foodBuffer);
	this->m_giftBuffer.loadFromFile("giftSound.wav");
	this->m_giftSound.setBuffer(m_giftBuffer);
	this->m_winBuffer.loadFromFile("winSound.wav");
	this->m_winSound.setBuffer(m_winBuffer);

	this->m_snake = std::make_unique<Snake>(sf::Vector2f(Utilities::instance()//make snake
		->m_winSize /2, Utilities::instance()->m_winSize /2));

	this->m_food = std::make_unique<Food>(sf::Vector2f(0,0));	//make food and gift
	this->m_gift = std::make_unique<Gift>(sf::Vector2f(0,0));

	m_backgroundTxtr[0].loadFromFile("back1.jpg");				//Initializing the Background
	m_backgroundTxtr[1].loadFromFile("back2.jpg");
	m_backgroundTxtr[2].loadFromFile("back3.jpg");
	m_backgroundTxtr[3].loadFromFile("back4.jpg");

	for(int i=0; i<4; i++)
		m_background[i].setTexture(&m_backgroundTxtr[i]);		//insert textures to sprites

	//the time button setting
	this->m_timeButton = new Button(sf::Vector2f(80, 60), &this->m_scoreTexture, sf::Vector2f(100, 40), sf::Color::Magenta,
		sf::Color::Cyan, sf::Color::Cyan, &this->m_font, std::to_string(0), 30, sf::Color::Magenta);
	this->m_timeButton->setTextPos(sf::Vector2f(5, Utilities::instance()->m_winSize - 35));

	this->m_font.loadFromFile("C:/Windows/Fonts/david.ttf");	//pause text settings
	this->m_pause = false;										
	this->m_pauseText.setString("Pause");
	this->m_pauseText.setPosition(sf::Vector2f(Utilities::instance()->m_winSize /2-50, Utilities::instance()->m_winSize /2));
	this->m_pauseText.setFont(m_font);
	this->m_pauseText.setCharacterSize(60);
	this->m_pauseText.setColor(sf::Color::White);
	this->m_pauseText.setOutlineColor(sf::Color::Black);
	this->m_pauseText.setOutlineThickness(2);

	this->m_scoreTexture.loadFromFile("blank.png");				//Setting the ScoreButton
	this->m_scoreButton = new Button(sf::Vector2f(80,60), &this->m_scoreTexture, sf::Vector2f(100, 40), sf::Color::Cyan,
		sf::Color::Cyan, sf::Color::Cyan, &this->m_font, std::to_string(Mode::getHolderScore()) , 40, sf::Color::Red);
	this->m_scoreButton->setTextPos(sf::Vector2f(Utilities::instance()->m_winSize -40, 20));
}
//-----------------------------------------------------------
GameMode::~GameMode()
{
	std::cout << "Deleting Snake" << std::endl;
	std::cout << "Deleting Food" << std::endl;
	std::cout << "Deleting Gift" << std::endl;
	delete this->m_timeButton;									//free the clock button
	delete this->m_scoreButton;									//free Button Memory 
}
//-----------------------------------------------------------
void GameMode::updatePos(double deltaT)							//Updates all the Components of the Mode
{
	this->checkStop(deltaT);									//Check if the User Wants to Quit or pouse the GameMode
	
	if (this->m_pause == false)									//Update the head gift and food If the game is not paused
	{
		this->m_snake->updatePos(deltaT);
		this->m_food->updatePos(deltaT);
		this->m_gift->updatePos(deltaT);
		this->m_timeButton->setText(std::to_string(m_clock.getElapsedTime().asSeconds()));
	}
}
//-----------------------------------------------------------
void GameMode::draw(sf::RenderWindow* w)						//Draws all the Components of the Mode
{
	//fit background texture and size to current level and draw
	this->m_background[m_level].setSize(sf::Vector2f(w->getSize().x, w->getSize().y));
	w->draw(this->m_background[m_level]);

	this->m_snake->draw(w);
	this->m_food->draw(w);
	if( (int)(m_clock.getElapsedTime().asSeconds()) % Utilities::instance()->m_giftTime == 0 )	//put gift every 5 seconds
		this->m_gift->draw(w);
	
	if (m_pause == true)										//Draw PauseText		
		w->draw(this->m_pauseText); 

	this->m_timeButton->draw(w);								//Drawing the time Button to the Screen

	this->m_scoreButton->draw(w);								//Drawing the Score Button to the Screen

}
//-----------------------------------------------------------
void GameMode::process(double deltaT, sf::Vector2f mousePos)
{

	if (this->m_snake->getCollider().checkCollision(this->m_food->getCollider()) == true)// handle fruit head collisions
	{
		std::cout << "Snake And Fruit Are Colliding " << std::endl;
		this->m_snake->growTail();								//Grows the Snake Tail
		this->m_food->setCollide(true);							//set food as collided
		Mode::setHolderScore(Mode::getHolderScore() + 1);
		this->m_scoreButton->setText(std::to_string(Mode::getHolderScore())); //Updating the ScoreBoard
		m_foodSound.setLoop(true);
		m_foodSound.play();
		m_foodSound.setLoop(false);
	}


	if (this->m_snake->getCollider().checkCollision(this->m_gift->getCollider()) == true)// handle Gift head collisions
	{
		std::cout << "Snake And Gift Are Colliding " << std::endl;
		this->m_gift->setCollide(true);							//set food as collided
		Mode::setHolderScore(Mode::getHolderScore() + 3);
		this->m_scoreButton->setText(std::to_string(Mode::getHolderScore())); //Updating the ScoreBoard
		m_giftSound.setLoop(true);
		m_giftSound.play();
		m_giftSound.setLoop(false);
	}


	if (this->m_snake->headToTail() == true)					//handle tail head collisions
	{
		std::cout << "Snake Touched Tail " << std::endl;
		Mode::setQuit(true);									//Game Over 
	}


	if (this->m_snake->ifOutside()) {							//handle going outside window
		std::cout << "Snake is Touching the Border " << std::endl;
		Mode::setQuit(true);									//Game Over
	}


	if (Mode::getHolderScore() >= Utilities::instance()->m_foodsToWin) {//if user ended level, needs quit and begin new level
		std::cout << "win level " << std::endl;
		Mode::setQuit(true);									//set m_quit to true
		Mode::setLevel(true);									//set m_levelFinish to true and icrease levels
		Mode::incLevel();
		m_winSound.setLoop(true);
		m_winSound.play();
		m_winSound.setLoop(false);
	}
}
//-----------------------------------------------------------
void GameMode::checkStop(double deltaT)							//check if needds to quit level
{
	Mode::checkForQuit();										//check if user pressed escape 

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) || sf::Mouse::isButtonPressed(sf::Mouse::Right))//pause game if pressed
	{
		if (this->m_pause == false) {
			this->m_pause = true;
			m_deltaT = m_clock.restart().asSeconds();
			this->m_timeButton->setText(std::to_string(m_deltaT));
		}
		else
			this->m_pause = false;								//Resetting it 

		std::cout << "Pausing Screen: " << this->m_pause<<  std::endl;
	}
}