#include <iostream>
#include <random>

#include "MainProgram.h"
#include "Helper.h"
#include "Box.h"

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

	Box box;

	box.setHeight(200);
	box.setWidth(300);
	box.setColor(sf::Color(Helper::getRandomInteger(1, 250),
  						   Helper::getRandomInteger(1, 250),
				  		   Helper::getRandomInteger(1, 250),
				  		    250));

	while ((this->window)->isOpen()) {
		while ((this -> window)->pollEvent(event)) {
			switch (event.type) {
			case sf::Event::Closed:
				(this->window)->close();
				return;
			}
		}
		std::cerr << "Program is currently running\n";

		box.margin.setTop(Helper::getRandomInteger(1, 250));
		box.margin.setLeft(Helper::getRandomInteger(1, 250));

		window->clear();

		box.render(window);

		window->display();
	}
}