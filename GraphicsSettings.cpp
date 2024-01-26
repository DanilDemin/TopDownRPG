#include "stdafx.h"
#include "GraphicsSettings.h"

GraphicsSetting::GraphicsSetting()
{
	this->title = "DEFAULT";
	this->resolution = sf::VideoMode::getDesktopMode();
	this->fullscreen = false;
	this->verticalSync = false;
	this->frameRateLimit = 90;
	this->contexSettings.antialiasingLevel = 0;
	this->videoModes = sf::VideoMode::getFullscreenModes();
}

//Functions
void  GraphicsSetting::saveToFile(const std::string path)
{
	std::ofstream ofs(path);


	//writing settings in the file windwow.ini
	if (ofs.is_open())
	{
		ofs << this->title;
		ofs << this->resolution.width << " " << this->resolution.height;
		ofs << this->fullscreen;
		ofs << this->frameRateLimit;
		ofs << this->verticalSync;
		ofs << this->contexSettings.antialiasingLevel;
	}

	ofs.close();
}
void GraphicsSetting::loadFromFile(const std::string path)
{
	std::ifstream ifs(path);


	//writing settings in the file windwow.ini
	if (ifs.is_open())
	{
		std::getline(ifs, this->title);
		ifs >> this->resolution.width >> this->resolution.height;
		ifs >> this->fullscreen;
		ifs >> this->frameRateLimit;
		ifs >> this->verticalSync;
		ifs >> this->contexSettings.antialiasingLevel;
	}

	ifs.close();
}