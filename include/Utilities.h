#pragma once
class Utilities {

public:
	static Utilities* instance();
	~Utilities() = default;

	int
		m_foodsToWin = 20,						//number of foods needed for next level
		m_objSize = 40,							//game object size
		m_speed = 100,							//game speed, the more the more slow
		m_winSize = 600,						//window beginning size (could change later)
		m_giftTime = 2,							//time of delay gift on screen
		m_beginTime = 4;							//time of showing beginning screen

private:
	Utilities();
	Utilities(const Utilities&) = delete;
	Utilities& operator=(const Utilities&) = delete;

	static Utilities m_util;
};