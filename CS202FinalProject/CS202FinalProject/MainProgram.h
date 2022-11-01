#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class MainProgram {
private:

	const int SCREEN_WIDTH = 1500, SCREEN_HEIGHT = 1000;

	sf::RenderWindow* window;
	sf::VideoMode videoMode;

public:
	MainProgram();
	~MainProgram();

	void run();

	//for debug
	void test();
};