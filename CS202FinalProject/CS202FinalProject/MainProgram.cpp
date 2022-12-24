#include <iostream>
#include <random>

#include "MainProgram.h"
#include "Helper.h"
#include "Box.h"
#include "Road.h"
#include "RoadCrossingGame.h"
#include "Button.h"
#include "GameState.h"
#include "VehicleRoad.h"

void MainProgram::initializeVariables() {
	this->window = nullptr;
	/*
	this->dt = 0.f;
	this->fullscreen = false;
	*/
	this->gameOptions = new GameOptions();
	music.setLoop(true);
	music.openFromFile("Data/Music/music.ogg");
	this->music.setVolume(20);
	this->music.play();
	std::ifstream fin;
	fin.open("Data/MusicFile/music.txt");
	if (fin.is_open())
	{
		int n;
		fin >> n;
		if (n == 0)
		{
			this->gameOptions->setMuteMusic();
		}
		else if (n == 1)
		{
			this->gameOptions->setMusic();
		}
		fin.close();
	}
	else
	{
		std::cout << "Can not open Data/MusicFile/music.txt" << std::endl;
	}
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

	while ((this->window)->isOpen()) {
		/*
		this->updateDt();
		*/
		this->update();
		this->render();
	}

	return;

	VehicleRoad vehicleRoad;

	vehicleRoad.setRoadPosition(sf::Vector2f(0, 200));
	
	while ((this->window)->isOpen()) {
		/*
		this->update();
		this->render();
		*/
		(this->window)->clear();
		vehicleRoad.render(this -> window);
		(this->window)->display();
	}
}

void MainProgram::updateEvents() {
	if ((this -> event).type == sf::Event::Closed) 
		this -> closeWindow();
}

void MainProgram::updateMusic() {
	if (this->gameOptions->checkMusic()) {
		this->music.setVolume(20);
		return;
	}
	if (!(this -> gameOptions) -> checkMusic()) {
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
	if (!this->states.empty())  {
		while (this->window->pollEvent(this->states.top()->event)) 
			this->states.top()->updateEvents();
		return;
	} 
	while (this->window->pollEvent(this->event)) 
		this->updateEvents();
}

void MainProgram::update() {

	this->updateSFMLEvents();

	this->updateMusic();

	if (!(this->states).empty()) {
		(this->states).top()->update();
		if ((this->states).top()->getQuit()) {
			delete (this->states).top();
			this->states.pop();
		}
		return;
	} 
	this->window->close();
}