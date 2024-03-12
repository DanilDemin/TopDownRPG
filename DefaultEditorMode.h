#pragma once
#include "EditorMode.h"

class State;
class StateData;
class EditorMode;
class TileMap;
class Tile;



class DefaultEditorMode :
    public EditorMode
{
private:
	sf::Text cursorText;
	sf::RectangleShape sidebar;
	sf::RectangleShape selectorRect;
	gui::TextureSelector* textureSelector;
	sf::IntRect textureRect;

	bool collision;
	short type;
	int layer;
	bool tileAddLock;


	void initVariables();
	void initGui();

public:
    DefaultEditorMode(StateData* state_data, TileMap* tile_map, EditorStateData* editor_state_data);
    virtual ~DefaultEditorMode() override;

	//Functions

	//Update
	void updateInput(const float& dt) override;
	void updateGui(const float& dt) override;
	void update(const float& dt) override;



	//Render
	void renderGui(sf::RenderTarget& target) override;
	void render(sf::RenderTarget& target) override;

};

