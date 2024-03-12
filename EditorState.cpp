#include "stdafx.h"
#include "EditorState.h"

 
//Initializer functions
void EditorState::initVariables()
{
	this->cameraSpeed = 500.f;
}

void EditorState::initEditorStateData()
{
	this->editorStateData.view = &this->view;
	this->editorStateData.font = &this->font;
	this->editorStateData.keyTime = &this->keyTime;
	this->editorStateData.keyTimeMax = &this->keyTimeMax;
	this->editorStateData.keybinds = &this->keybinds;
	this->editorStateData.mousePosGrid = &this->mousePosGrid;
	this->editorStateData.mousePosView = &this->mousePosView;
	this->editorStateData.mousPosScreen = &this->mousPosScreen;
	this->editorStateData.mousPosWindow = &this->mousPosWindow;
}

void EditorState::initView()
{
	this->view.setSize(
		sf::Vector2f(
			static_cast<float>(this->stateData->gfxSettings->resolution.width),
			static_cast<float>(this->stateData->gfxSettings->resolution.height)
		)
	);

	this->view.setCenter(
		static_cast<float>(this->stateData->gfxSettings->resolution.width) / 2.f,
		static_cast<float>(this->stateData->gfxSettings->resolution.height) / 2.f
	);


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
	const sf::VideoMode& vm = this->stateData->gfxSettings->resolution;

	this->pmenu = new PauseMenu(this->stateData->gfxSettings->resolution, this->font);

	this->pmenu->addButton("QUIT", gui::p2pY(83.3f, vm), gui::p2pX(13.f, vm), gui::p2pY(6.f, vm), gui::calcCharSize(vm), "Quit");
	this->pmenu->addButton("SAVE", gui::p2pY(46.3f, vm), gui::p2pX(13.f, vm), gui::p2pY(6.f, vm), gui::calcCharSize(vm), "Save");
	this->pmenu->addButton("LOAD", gui::p2pY(37.f, vm), gui::p2pX(13.f, vm), gui::p2pY(6.f, vm), gui::calcCharSize(vm), "Load");
}

void EditorState::initButtons()
{
	 
}

void EditorState::initGui()
{	

}

void EditorState::initTileMap()
{
	this->tileMap = new TileMap(static_cast<int>(this->stateData->gridSize), 100, 100, "Resources/Images/Tiles/texturesheet2.png");
}

void EditorState::initModes()
{
	this->modes.push_back(new DefaultEditorMode(this->stateData, this->tileMap, &this->editorStateData));
	this->modes.push_back(new EnemyEditorMode(this->stateData, this->tileMap, &this->editorStateData));


	this->activeMode = EditorModes::DEFAULT_EDITOR_MODE;
}

EditorState::EditorState(StateData* state_data)
	: State(state_data)
{
	this->initVariables();
	this->initEditorStateData();
	this->initView();
	this->initFonts();
	this->initKeybinds();
	this->initButtons();
	this->initPauseMenu();
	this->initTileMap();
	this->initGui();

	this->initModes();	
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

	

	for (size_t i = 0; i < this->modes.size(); i++)
	{
		delete this->modes[i];
	}




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
	//Move view
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_CAMERA_UP"))))
	{
		this->view.move(0.f, -this->cameraSpeed * dt);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_CAMERA_DOWN"))))
	{
		this->view.move(0.f, this->cameraSpeed * dt);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_CAMERA_RIGHT"))))
	{
		this->view.move(this->cameraSpeed * dt, 0.f);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_CAMERA_LEFT"))))
	{
		this->view.move(-this->cameraSpeed * dt, 0.f);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MODE_UP"))))
	{
		if (this->activeMode < this->modes.size() - 1)
		{
			this->activeMode++;
		}
		else
		{
			std::cout << "ERROR::EDITORSTATE::CANNOT CNAGE MODE UP!" << "\n";
		}

	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MODE_DOWN"))))
	{
		if (this->activeMode > 0)
		{
			this->activeMode--;
		}
		else
		{
			std::cout << "ERROR::EDITORSTATE::CANNOT CNAGE MODE DOWN!" << "\n";
		}
	}


}

void EditorState::updateButtons()
{
	//updates all the buttons in the state and	handles their funcionality
	for (auto& it : buttons)
	{
		it.second->update(this->mousPosWindow);
	}

}

void EditorState::updateGui(const float& dt)
{

}

void EditorState::updatePauseMenuButtons()
{
	if (this->pmenu->isButtonPressed("QUIT"))
	{
		this->endState();
	}

	// we be able to make .slmp extension
	if (this->pmenu->isButtonPressed("SAVE"))
	{
		this->tileMap->saveToFile("text.txt");
	}

	if (this->pmenu->isButtonPressed("LOAD"))
	{
		this->tileMap->loadFromFile("text.txt");
	}
}

void EditorState::updateModes(const float& dt)
{
	this->modes[this->activeMode]->update(dt);
}

void EditorState::update(const float& dt)
{
	this->updateMousePosition(&this->view);
	this->updateKeytime(dt);
	this->updateInput(dt);

	if (!this->paused) // UNpaused
	{	
		this->updateGui(dt);
		this->updateButtons();
		this->updateEditorInput(dt);
		this->updateModes(dt);
	
	}
	else //Paused
	{
		this->pmenu->update(mousPosWindow);
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
	
}

void EditorState::renderModes(sf::RenderTarget& target)
{
	this->modes[this->activeMode]->render(target);
}

void EditorState::render(sf::RenderTarget* target)
{

	if (!target)
	{
		target = this->window;
	}

	target->setView(this->view);

	this->tileMap->render(*target, this->mousePosGrid, true);
	this->tileMap->renderDeferred(*target);


	target->setView(this->window->getDefaultView());


	this->renderButtons(*target);
	this->renderGui(*target);
	this->renderModes(*target);


	if (this->paused)//Paused menu render
	{
		target->setView(this->window->getDefaultView());
		this->pmenu->render(*target);
	}


	//Remove later!!!!
}
