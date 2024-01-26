#pragma once
#include "MainMenuState.h"


class Game
{
private:
	
	//Variables
	GraphicsSetting gfxSettings;
	StateData stateData;
	sf::RenderWindow* window;
	sf::Event sfEvent;

	sf::Clock dtClock;
	float dt;

	std::stack<State*> states;

	std::map<std::string, int> supportedKeys;

	float gridSize;

	//Initialization
	void initVariables();
	void initGraphicsSettings();
	void initWindow();
	void initKeys();
	void initStateData();
	void initStates();



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

