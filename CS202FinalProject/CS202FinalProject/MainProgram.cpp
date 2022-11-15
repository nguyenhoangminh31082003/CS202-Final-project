#include <iostream>
#include <random>

#include "MainProgram.h"
#include "Helper.h"
#include "Box.h"
#include "SimpleRoad.h"
#include "RoadCrossingGame.h"
#include "Button.h"

MainProgram::MainProgram(): videoMode(SCREEN_WIDTH, SCREEN_HEIGHT) {
	(this -> window) = new sf::RenderWindow(videoMode, "Road crossing game", sf::Style::Titlebar | sf::Style::Close);
	srand(time(NULL));
};

MainProgram::~MainProgram() {
	delete (this -> window);
};

void MainProgram::run() {
	while ((this -> window) ->isOpen()) {

	}
}

void MainProgram::test() {
	/*
	
		This function is used for debugging 
	
	*/
	sf::Event event;

	Button startButton(0.25, "../Resources/Button/Start/");
	//Button startButton(50, 60, "../Resources/Button/Start/");
	startButton.setPosition(sf::Vector2f(600, 600));

	RoadCrossingGame game();

	while ((this->window)->isOpen()) {
		while ((this -> window)->pollEvent(event)) {
			switch (event.type) {
			case sf::Event::Closed:
				(this->window)->close();
				return;
			default:
				game.updateWithEvent(event);
			}
		}
		
		//std::cerr << "Program is currently running\n";

		game.update();

		window->clear();

		startButton.render(this->window);
		game.render(window);

		window->display();
	}
}