#include "stdafx.h"
#include "SettingsState.h"

//Initializer functions
void SettingsState::initVariables()
{
	this->modes = sf::VideoMode::getFullscreenModes();
}

 

void SettingsState::initFonts()
{
	if (!this->font.loadFromFile("Fonts/Aller_BdIt.ttf"))
	{
		throw("ERROR::MAINMENUSTATE::COULD NOT LOAD FONT");
	}
}

void SettingsState::initKeybinds()
{

	std::ifstream ifs("Config/mainmenustate_keybinds.ini");

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

void SettingsState::initGui()
{

	const sf::VideoMode& vm = this->stateData->gfxSettings->resolution;

	//Background
	this->background.setSize(
		sf::Vector2f
		(
			static_cast<float>(vm.width),
			static_cast<float>(vm.height)
		)
	);
	if (!this->backgroundTexture.loadFromFile("Resources/Images/Backgrounds/bg1.png"))
	{
		throw "ERROR::MAINMENUSTATE::FAILD_TO_DOWNLOAD_BACKGEOUNG_TEXTURE";
	}
	this->background.setTexture(&this->backgroundTexture);

	
	//Buttons
	buttons["BACK"] = new gui::Button(
		gui::p2pX(67.8f, vm), gui::p2pY(83.4f, vm),
		gui::p2pX(13.f, vm), gui::p2pY(9.3f, vm), &font,
		"Back", gui::calcCharSize(vm),
		sf::Color(70, 70, 70, 200),
		sf::Color(250, 250, 250, 250),
		sf::Color(20, 20, 20, 50),

		sf::Color(100, 100, 100, 0),
		sf::Color(150, 150, 150, 0),
		sf::Color(20, 20, 20, 0));


	buttons["APPLY"] = new gui::Button(
		gui::p2pX(78.1f, vm), gui::p2pY(83.4f, vm),
		gui::p2pX(13.f, vm), gui::p2pY(9.3f, vm), &font,
		"Apply", gui::calcCharSize(vm),
		sf::Color(70, 70, 70, 200),
		sf::Color(250, 250, 250, 250),
		sf::Color(20, 20, 20, 50),

		sf::Color(100, 100, 100, 0),
		sf::Color(150, 150, 150, 0),
		sf::Color(20, 20, 20, 0));


	//Modes
	std::vector<std::string> modes_str;
	
	for (auto& i : this->modes)
	{
		modes_str.push_back(std::to_string(i.width) + 'x' + std::to_string(i.height));
	}

	//Drop dewon list
	this->dropDownLists["RESOLUTION"] = new gui::DropDownList(
		gui::p2pX(31.3f, vm), gui::p2pY(23.1f, vm), gui::p2pX(13.f, vm), gui::p2pY(4.7f, vm), font, modes_str.data(), static_cast<unsigned int>(modes_str.size()));

	//Text
	this->optionsText.setFont(this->font);

	this->optionsText.setPosition(sf::Vector2f(gui::p2pX(5.2f, vm), gui::p2pY(9.3f, vm)));
	this->optionsText.setCharacterSize(gui::calcCharSize(vm, 70));
	this->optionsText.setFillColor(sf::Color(255, 255, 255, 200));
	this->optionsText.setString(
		"Resolution  \nFullscreen \nVsync \nAntializing \n"
	);

}

void SettingsState::resetGui()
{
	/*
	Clears the GUI elemets and re-initialies the GUI

	@return void 

	*/
	auto it = this->buttons.begin();
	for (it = this->buttons.begin(); it != this->buttons.end(); ++it)
	{
		delete it->second;
	}
	this->buttons.clear();

	auto it2 = this->dropDownLists.begin();
	for (it2 = this->dropDownLists.begin(); it2 != this->dropDownLists.end(); ++it2)
	{
		delete it2->second;
	}
	this->dropDownLists.clear();

	this->initGui();
}


//Con/Des
SettingsState::SettingsState(StateData* state_data)
	: State(state_data)
{
	this->initVariables();
	this->initFonts();
	this->initKeybinds();
	this->initGui();
}

SettingsState::~SettingsState()
{
	auto it = buttons.begin();
	for (auto it = buttons.begin(); it != buttons.end(); ++it)
	{
		delete it->second;
	}
	
	auto it2 = dropDownLists.begin();
	for (auto it2 = dropDownLists.begin(); it2 != dropDownLists.end(); ++it2)
	{
		delete it2->second;
	}
}

//Accessors


//Functions
void SettingsState::updateInput(const float& dt)
{

}

void SettingsState::updateGui(const float& dt)
{
	//updates all the gui elements in the state and	handles their funcionality
	//Button
	for (auto& it : this->buttons)
	{
		it.second->update(this->mousPosWindow);
	}

	//Settings
	
	//Button functionality
	//Quit the game
	if (buttons["BACK"]->isPressed())
	{
		this->endState();
	}

	//Apply selected settings
	if (buttons["APPLY"]->isPressed())
	{	
		//Test remove later
		this->stateData->gfxSettings->resolution = this->modes[this->dropDownLists["RESOLUTION"]->getActiveElementId()];
		this->window->create(
			this->stateData->gfxSettings->resolution,
			this->stateData->gfxSettings->title,
			sf::Style::Default
		);
		this->resetGui();
	}



	//Dropdown lists
	for (auto& it : this->dropDownLists)
	{
		it.second->update(this->mousPosWindow, dt);
	}

	//Dropdown lists functioonality


}

void SettingsState::update(const float& dt)
{
	updateMousePosition();
	updateInput(dt);
	updateGui(dt);
}

void SettingsState::renderGui(sf::RenderTarget& target)
{	
	//Render Buttons
	for (auto& it : this->buttons)
	{
		it.second->render(target);
	}

	//Render Dropdown lists
	for (auto& it : this->dropDownLists)
	{
		it.second->render(target);
	}

}

void SettingsState::render(sf::RenderTarget* target)
{

	if (!target)
	{
		target = this->window;
	}

	target->draw(this->background);

	this->renderGui(*target);

	target->draw(this->optionsText);
	
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
