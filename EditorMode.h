#pragma once
#include "State.h"
#include "Gui.h"
#include "Tile.h"
#include "TileMap.h"

class State;
class StateData;
class TileMap;
class Tile;
class EditorStateData;

class EditorStateData
{
private:

public:
	EditorStateData() {}

	//Variables
	sf::View* view;

	sf::Font* font;

	float* keyTime;
	float* keyTimeMax;

	std::map<std::string, int>* keybinds;


	sf::Vector2i* mousPosScreen;
	sf::Vector2i* mousPosWindow;
	sf::Vector2f* mousePosView;
	sf::Vector2i* mousePosGrid;
};


class EditorMode
{
private:

protected:
	StateData* stateData;
	EditorStateData* editorStateData;
	TileMap* tileMap;
	 
public:
	//Con / Des
	EditorMode(StateData* state_data, TileMap* tile_map, EditorStateData* editor_state_data);
	virtual ~EditorMode();



	//Functions
	const bool getKeytime();

	//Update
	virtual void updateInput(const float& dt) = 0;
	virtual void updateGui(const float& dt) = 0;
	virtual void update(const float& dt) = 0;



	//Render
	virtual void renderGui(sf::RenderTarget& target) = 0 ;
	virtual void render(sf::RenderTarget& target) = 0;
};

