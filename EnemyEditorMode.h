#pragma once
#include "EditorMode.h"
#include "EnemySpawnerTile.h"

class State;
class StateData;
class EditorMode;
class TileMap;
class Tile;
class EnemySpawnerTile;


class EnemyEditorMode :
    public EditorMode
{
private:
	sf::Text cursorText;
	sf::RectangleShape sidebar;
	sf::RectangleShape selectorRect;
	sf::IntRect textureRect;


	int type;
	int amount;
	int timeToSpawn;
	float maxDistance;

	//Initializer functions	
	void initVariables();
	void initGui();


public:
	//Con / Des
    EnemyEditorMode(StateData* state_data, TileMap* tile_map, EditorStateData* editor_state_data);
    virtual ~EnemyEditorMode() override;



	//Functions

	//Update
	void updateInput(const float& dt) override;
	void updateGui(const float& dt) override;
	void update(const float& dt) override;

	//Render
	void renderGui(sf::RenderTarget& target) override;
	void render(sf::RenderTarget& target) override;

};

