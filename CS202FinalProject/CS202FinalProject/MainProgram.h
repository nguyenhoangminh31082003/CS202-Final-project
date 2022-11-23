#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include "MainMenuState.h"

class MainProgram {
private:

	const int SCREEN_WIDTH = 1500, SCREEN_HEIGHT = 1000;

	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event ev;
	std::vector<sf::VideoMode> videoModes;
	sf::ContextSettings windowSettings;
	bool fullscreen;

	sf::Clock dtClock;
	float dt;

	std::stack<State*> states;
	GameOptions* gameOptions;
	std::map<std::string, Button*> buttons;
	sf::Music music;


	void initVariables();
	void initWindow();
	void initState();

public:
	MainProgram();
	~MainProgram();
	const bool running() const;
	void updateEvents();
	void updateDt();
	void updateMusic();
	void updateSFMLEvents();
	void update();
	void render();
	void closeWindow();


	void run();

	//for debug
	void test();
};