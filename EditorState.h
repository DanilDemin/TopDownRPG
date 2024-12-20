#pragma once
#include "State.h"
#include "Gui.h"
#include "PauseMenu.h"
#include "TileMap.h"
#include "EditorModes.h"

//For a speed of compile I think
class State;
class Gui;
class PauseMenu;
class TileMap;
class Tile;
class EditorMode;
class DefaultEditorMode;
class EnemyEditorMode;
class EditorStateData;

enum EditorModes {
	DEFAULT_EDITOR_MODE = 0,
	ENEMY_EDITOR_MODE
};


class EditorState :
    public State
{
private:
	//Variables
	EditorStateData editorStateData;


	sf::View view;
	float cameraSpeed;

	sf::Font font;

	PauseMenu* pmenu;
	
	std::map<std::string, gui::Button*> buttons;

	TileMap* tileMap;

	std::vector<EditorMode*> modes;
	unsigned activeMode;


	//Initializer functions
	void initVariables();
	void initEditorStateData();
	void initView();
	void initFonts();
	void initKeybinds();
	void initPauseMenu();
	void initButtons();
	void initGui();
	void initTileMap();

	void initModes();

public:

	//Con/Des
	EditorState(StateData* state_data);

	virtual ~EditorState() override;

	//Functions

	//Update
	void updateInput(const float& dt);
	void updateEditorInput(const float& dt);
	void updateButtons();
	void updateGui(const float& dt);
	void updatePauseMenuButtons();
	void updateModes(const float& dt);
	void update(const float& dt);


	//Render
	void renderButtons(sf::RenderTarget& target);
	void renderGui(sf::RenderTarget& target);
	void renderModes(sf::RenderTarget& target);
	void render(sf::RenderTarget* target = NULL);
};

