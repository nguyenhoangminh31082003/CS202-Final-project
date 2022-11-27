#include <iostream>
#include <random>

#include "MainProgram.h"
#include "Helper.h"
#include "Box.h"
#include "Road.h"
#include "RoadCrossingGame.h"
#include "Button.h"

void MainProgram::initializeVariables() {
	this->window = nullptr;
	/*
	this->dt = 0.f;
	this->fullscreen = false;
	*/
	this->gameOptions = new GameOptions();
	music.setLoop(true);
	music.openFromFile("Data/Music/Music.wav");
	this->music.setVolume(20);
	this->music.play();
}

void MainProgram::initializeWindow() {
	(this->videoMode).height = SCREEN_HEIGHT;
	(this->videoMode).width = SCREEN_WIDTH;
	(this->window) = new sf::RenderWindow(videoMode, "Road crossing game", sf::Style::Titlebar | sf::Style::Close);
	//(this -> window) ->setFramerateLimit(120);
};

void MainProgram::initializeState() {
	this -> states.push(new MainMenuState(this->window, &this->states, gameOptions));
};

MainProgram::MainProgram() {
	this -> initializeVariables();
	this -> initializeWindow();
	this -> initializeState();
	srand(time(NULL));
};

MainProgram::~MainProgram() {
	delete (this -> window);

	while (!(this->states.empty())) {
		delete (this->states).top();
		(this->states).pop();
	}
};

/*
void MainProgram::updateDt() {
	this->dt = this->dtClock.restart().asSeconds();
}
*/

void MainProgram::run() {
	while ((this -> window) ->isOpen()) {
		/*
		this->updateDt();
		*/
		this->update();
		this->render();
	}
}

void MainProgram::test() {
	/*
	
		This function is used for debugging 
	
	*/
	sf::Event event;

	//Button startButton(0.25, 300, 600, "../Resources/Button/Start/");
	//Button startButton2(100, 200, 400, 600, "../Resources/Button/Start/");
	//Button startButton(50, 60, "../Resources/Button/Start/");
	//startButton.setPosition(sf::Vector2f(600, 600));

	RoadCrossingGame game;

	while ((this->window)->isOpen()) {
		while ((this -> window)->pollEvent(event)) {
			switch (event.type) {
			case sf::Event::Closed:
				(this->window)->close();
				return;
			default:
				game.updateWithEvent(event);
				std::cout << 0;
			}
		}

		
		game.update();

		window->clear();

		//startButton.render(this->window);
		//startButton2.render(this->window);
		game.render(window);

		window->display();
	}
}

void MainProgram::updateEvents() {
	if ((this -> event).type == sf::Event::Closed) 
		this -> closeWindow();
}

void MainProgram::updateMusic() {
	if (this->gameOptions->checkMusic()) {
		this->music.setVolume(20);
	} else if (!(this -> gameOptions) -> checkMusic()) {
		this->music.setVolume(0);
	}
}

void MainProgram::closeWindow() {
	(this -> window) -> close();
}

void MainProgram::render() {
	(this -> window) -> clear();
	if (!(this->states).empty())
		(this->states).top()->render();
	(this -> window) -> display();
}

void MainProgram::updateSFMLEvents() {
	if (!this->states.empty()) {
		while (this->window->pollEvent(this->states.top()->event)) this->states.top()->updateEvents();
	} else {
		while (this->window->pollEvent(this->event)) this->updateEvents();
	}
}

void MainProgram::update() {

	this->updateSFMLEvents();

	this->updateMusic();

	if (!this->states.empty()) {
		this->states.top()->update();
		if (this->states.top()->getQuit()) {
			this->states.top()->endState();
			delete this->states.top();
			this->states.pop();

		}
	} else {
		this->window->close();
	}
}