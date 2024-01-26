#pragma once
class GraphicsSetting
{
public:
	GraphicsSetting();
	 
	//Variavles
	std::string title;
	sf::VideoMode resolution;
	bool fullscreen;
	bool verticalSync;
	unsigned frameRateLimit;
	sf::ContextSettings contexSettings;
	std::vector<sf::VideoMode> videoModes;


	//Functions
	void saveToFile(const std::string path);
	void loadFromFile(const std::string path);
};