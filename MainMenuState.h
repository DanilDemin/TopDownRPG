#pragma once
#include "GameState.h"
#include "EditorState.h"
#include "SettingsState.h"
#include "Gui.h" 



class MainMenuState :
    public State
{
private:
	
	//Variables
	sf::Texture backgroundTexture;
	sf::RectangleShape background;
	sf::Font font;

	std::map<std::string, gui::Button*> buttons;



	//Initializer functions
	void initVariables();
	void initFonts();
	void initKeybinds();
	void initGui();
	void resetGui();


public:


	MainMenuState(StateData* state_data);
	 
	virtual ~MainMenuState();

	//Functions

	void updateInput(const float& dt);
	void updateButtons();
	void update(const float& dt);
	void renderButtons(sf::RenderTarget& target);
	void render(sf::RenderTarget* target = NULL);
};

