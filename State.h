#pragma once

#include "Entity.h"

class State
{
private:

protected:
	std::stack<State*>* states;

	sf::RenderWindow* window;
	std::map<std::string, int>* supportedKeys;
	std::map<std::string, int> keybinds;
	bool quit;

	//Resoureces
	std::vector<sf::Texture*> textures;

	//Functions
	virtual void initKeybinds() = 0;
	

	sf::Vector2i mousPosScreen;
	sf::Vector2i mousPosWindow;
	sf::Vector2f mousePosView;


public:
	State(sf::RenderWindow* window,
		std::map<std::string, int>* supportedKeys,
		std::stack<State*>* states);
	virtual ~State();

	const bool& getQuit() const;


	
	void endState();

	virtual void updateMousePosition();
	virtual void updateInput(const float& dt) = 0;
	virtual void update(const float& dt) = 0;
	virtual void render(sf::RenderTarget* target = NULL) = 0;

};

