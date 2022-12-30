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
#include "Generator.h"

void MainProgram::initializeVariables() {
	this->window = nullptr;
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
};

void MainProgram::initializeState() {
	(this -> states).push_back(new MainMenuState(this->window, &this->states, gameOptions));
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
		delete (this->states).back();
		(this->states).pop_back();
	}
};



void MainProgram::run() {
	while ((this -> window) ->isOpen()) {
		this->update();
		this->render();
	}
}

void MainProgram::test() {

	const sf::Time TimePerFrame = sf::seconds(1.f / 60.f);
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;

	//Generator::generateLevelTxt("Data/Levels", 10, 10, 300, 750, 100);

	//exit(0);

	while ((this->window)->isOpen()) {
		/*
		this->updateDt();
		*/

		sf::Time elapsedTime = clock.restart();
		timeSinceLastUpdate += elapsedTime;
		while (timeSinceLastUpdate > TimePerFrame)
		{
			timeSinceLastUpdate -= TimePerFrame;
			this->update();
			this->render();
		}
	}
	return;
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
		(this->states).back()->render();
	(this -> window) -> display();
}

void MainProgram::updateSFMLEvents() {
	if (!this->states.empty())  {
		while (this->window->pollEvent(this->states.back()->event)) 
			this->states.back()->updateEvents();
		return;
	} 
	while (this->window->pollEvent(this->event)) 
		this->updateEvents();
}

void MainProgram::update() {

	this->updateSFMLEvents();

	this->updateMusic();

	if (!(this->states).empty()) {
		(this->states).back()->update();
		if ((this->states).back()->getQuit()) {
			delete (this->states).back();
			this->states.pop_back();
		}
		return;
	} 
	this->window->close();
}