#include "stdafx.h"
#include "EditorState.h"

 
//Initializer functions
void EditorState::initVariables()
{

}

void EditorState::initBackground()
{

}

void EditorState::initFonts()
{
	if (!this->font.loadFromFile("Fonts/Aller_BdIt.ttf"))
	{
		throw("ERROR::EDDITORSTATE::COULD NOT LOAD FONT");
	}
}

void EditorState::initKeybinds()
{

	std::ifstream ifs("Config/editorstate_keybinds.ini");

	if (ifs.is_open())
	{
		std::string key = "";
		std::string  key2 = "";


		while (ifs >> key >> key2)
		{
			keybinds[key] = supportedKeys->at(key2);
		}

	}

	ifs.close();
}

void EditorState::initPauseMenu()
{
	this->pmenu = new PauseMenu(*this->window, this->font);
	this->pmenu->addButton("QUIT", 900.f, "Quit");
}

void EditorState::initButtons()
{
	
}

void EditorState::initGui()
{	
	this->selectorRect.setSize(sf::Vector2f(this->stateData->gridSize,
		this->stateData->gridSize));
	this->selectorRect.setFillColor(sf::Color::Transparent);
	this->selectorRect.setOutlineThickness(1.f);
	this->selectorRect.setOutlineColor(sf::Color::Green);


}

void EditorState::initTileMap()
{
	this->tileMap = new TileMap(this->stateData->gridSize, 10, 10);
}

EditorState::EditorState(StateData* state_data)
	: State(state_data)
{
	this->initVariables();
	this->initBackground();
	this->initFonts();
	this->initKeybinds();
	this->initButtons();
	this->initGui();
	this->initPauseMenu();
	this->initTileMap();
}

EditorState::~EditorState()
{
	auto it = buttons.begin();
	for (auto it = buttons.begin(); it != buttons.end(); ++it)
	{
		delete it->second;
	}

	delete this->pmenu;

	delete this->tileMap;
}

//Functions
void EditorState::updateInput(const float& dt)
{	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("CLOSE"))) && this->getKeytime())
	{
		if (!this->paused)
		{
			this->pauseState();
		}
		else
		{
			this->unpauseState();
		}
	}
}

void EditorState::updateEditorInput(const float& dt)
{	
	//Add a tile to the tileMap
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && this->getKeytime())
	{
		this->tileMap->addTile(this->mousePosGrid.x, this->mousePosGrid.y, 0);
	}
}

void EditorState::updateButtons()
{
	//updates all the buttons in the state and	handles their funcionality
	for (auto& it : buttons)
	{
		it.second->update(mousePosView);
	}

}

void EditorState::updateGui()
{
	this->selectorRect.setPosition(
		this->mousePosGrid.x * this->stateData->gridSize,
		this->mousePosGrid.y * this->stateData->gridSize
	);
}

void EditorState::updatePauseMenuButtons()
{
	if (this->pmenu->isButtonPressed("QUIT"))
	{
		this->endState();
	}
}

void EditorState::update(const float& dt)
{
	this->updateMousePosition();
	this->updateKeytime(dt);
	this->updateInput(dt);

	if (!this->paused) // UNpaused
	{	
		this->updateGui();
		this->updateButtons();
		this->updateEditorInput(dt);
	}
	else //Paused
	{
		this->pmenu->update(this->mousePosView);
		this->updatePauseMenuButtons();
	}

	

}

void EditorState::renderButtons(sf::RenderTarget& target)
{
	for (auto& it : this->buttons)
	{
		it.second->render(target);
	}
}

void EditorState::renderGui(sf::RenderTarget& target)
{
	target.draw(this->selectorRect);
}

void EditorState::render(sf::RenderTarget* target)
{

	if (!target)
	{
		target = this->window;
	}

	this->renderButtons(*target);
	this->renderGui(*target);

	this->tileMap->render(*target);


	if (this->paused)//Paused menu render
	{
		this->pmenu->render(*target);
	}


	//Remove later!!!!
	sf::Text mouseText;
	mouseText.setPosition(this->mousePosView.x, this->mousePosView.y - 50);
	mouseText.setFont(this->font);
	mouseText.setCharacterSize(12);
	std::stringstream ss;
	ss << this->mousePosView.x << " " << mousePosView.y << " \n";
	mouseText.setString(ss.str());


	target->draw(mouseText);

}
