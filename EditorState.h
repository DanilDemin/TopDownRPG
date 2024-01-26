#pragma once
#include "State.h"
#include "Gui.h"
#include "PauseMenu.h"
#include "TileMap.h"

//For a speed of compile I think
class State;
class Gui;
class PauseMenu;
class TileMap;


class EditorState :
    public State
{
private:

	//Variables
	sf::Font font;
	PauseMenu* pmenu;
	std::map<std::string, gui::Button*> buttons;

	TileMap* tileMap;

	sf::RectangleShape selectorRect;



	//Initializer functions
	void initVariables();
	void initBackground();
	void initFonts();
	void initKeybinds();
	void initPauseMenu();
	void initButtons();
	void initGui();
	void initTileMap();

public:

	//Con/Des
	EditorState(StateData* state_data);

	virtual ~EditorState();

	//Functions

	//Update
	void updateInput(const float& dt);
	void updateEditorInput(const float& dt);
	void updateButtons();
	void updateGui();
	void updatePauseMenuButtons();
	void update(const float& dt);


	//Render
	void renderButtons(sf::RenderTarget& target);
	void renderGui(sf::RenderTarget& target);
	void render(sf::RenderTarget* target = NULL);
};

