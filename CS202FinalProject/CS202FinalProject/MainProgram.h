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
	sf::Event event;
	std::vector<sf::VideoMode> videoModes;
	sf::ContextSettings windowSettings;
	bool fullscreen;

	sf::Clock dtClock;
	float dt;

	std::stack<State*> states;
	GameOptions* gameOptions;
	std::map<std::string, Button*> buttons;
	sf::Music music;

	void initializeVariables();
	void initializeState();
	void initializeWindow();

public:
	MainProgram();
	~MainProgram();
	
	void render();
	void update();
	void updateMusic();
	void updateSFMLEvents();
	void updateEvents();
	void closeWindow();
	void updateDt();

	void run();

	//for debug
	void test();
};