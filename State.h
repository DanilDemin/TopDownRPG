#pragma once

#include "Player.h"
#include "GraphicsSettings.h"

//for a speed of compile I think
class Player;
class GraphicsSetting;
class State;


class StateData
{
public:
	StateData() {}

	//Variables
	float gridSize;
	sf::RenderWindow* window;
	GraphicsSetting* gfxSettings;
	std::map<std::string, int>* supportedKeys;
	std::stack<State*>* states;
};


class State
{
private:

protected:
	StateData* stateData;
	std::stack<State*>* states;
	sf::RenderWindow* window;
	std::map<std::string, int>* supportedKeys;
	std::map<std::string, int> keybinds;
	bool quit;
	bool paused;
	float keyTime;
	float keyTimeMax;
	float gridSize;

	sf::Vector2i mousPosScreen;
	sf::Vector2i mousPosWindow;
	sf::Vector2f mousePosView;
	sf::Vector2i mousePosGrid;


	//Resources
	std::map<std::string, sf::Texture> textures;

	//Functions
	virtual void initKeybinds() = 0;

public:
	State(StateData* state_data);
	virtual ~State();


	//Accessors
	const bool& getQuit() const;
	const bool getKeytime();

	//Functions
	void endState();
	void pauseState();
	void unpauseState();

	virtual void updateMousePosition(sf::View* view = NULL);
	virtual void updateKeytime(const float& dt);
	virtual void updateInput(const float& dt) = 0;
	virtual void update(const float& dt) = 0;
	virtual void render(sf::RenderTarget* target = NULL) = 0;
};

