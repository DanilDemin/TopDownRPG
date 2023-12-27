#pragma once


#include "MainMenuState.h"

class Game
{
private:
	//Variables
	sf::RenderWindow* window;
	sf::Event sfEvent;
	std::vector<sf::VideoMode> videoModes;
	sf::ContextSettings windowSettings;
	bool fullscreen;

	sf::Clock dtClock;
	float dt;

	std::stack<State*> states;

	std::map<std::string, int> supportedKeys;

	//Initialization
	void initVariables();
	void initWindow();
	void initStates();
	void initKeys();



public:
	//Con/Des
	Game();
	virtual ~Game();

	//Functions

	//Regular
	void endApplicaton();

	//Update
	void updateDt();
	void updateSFMLEvents();
	void update();

	//Render
	void render();

	//Core
	void run();


};

