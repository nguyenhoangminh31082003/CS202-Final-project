#include <iostream>
#include <random>

#include "MainProgram.h"
#include "Helper.h"
#include "Box.h"
#include "Road.h"
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

	Button startButton(0.25, 300, 600, "../Resources/Button/Start/");
	Button startButton2(100, 200, 400, 600, "../Resources/Button/Start/");
	//Button startButton(50, 60, "../Resources/Button/Start/");
	startButton.setPosition(sf::Vector2f(600, 600));

	RoadCrossingGame game;

	while ((this->window)->isOpen()) {
		while ((this -> window)->pollEvent(event)) {
			switch (event.type) {
			case sf::Event::Closed:
				(this->window)->close();
				return;
			default:
				//game.updateWithEvent(event);
				std::cout << 0;
			}
		}
		
		//std::cerr << "Program is currently running\n";

		//game.update();

		window->clear();

		startButton.render(this->window);
		startButton2.render(this->window);
		//game.render(window);

		window->display();
	}
}

/*
void MainProgram::initVariables()
{
	this->window = nullptr;
	this->dt = 0.f;
	this->fullscreen = false;
	this->gameOptions = new GameOptions();
	music.setLoop(true);
	music.openFromFile("Data/Music/Music.wav");
	this->music.setVolume(20);
	this->music.play();
}

void MainProgram::initWindow()
{
	this->videoModes = sf::VideoMode::getFullscreenModes();
	this->videoMode.height = 1000;
	this->videoMode.width = 1500;
	unsigned antialiasing_level = 0;

	this->fullscreen = false;
	this->windowSettings.antialiasingLevel = antialiasing_level;
	if (this->fullscreen) {
		this->window = new sf::RenderWindow(this->videoMode, "RoadCrossingGame", sf::Style::Fullscreen, windowSettings);
	}
	else {


		std::string name;
		name += "Minesweeper";
		this->window = new sf::RenderWindow(this->videoMode, "RoadCrossingGame", sf::Style::Titlebar | sf::Style::Close, windowSettings);
		sf::Image icon;
		icon.loadFromFile("Data/Icon/icon.png");
		this->window->setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

	}
	this->window->setFramerateLimit(120);
	this->window->setVerticalSyncEnabled(false);
}

void MainProgram::initState()
{
	this->states.push(new MainMenuState(this->window, &this->states, gameOptions));
}

MainProgram::MainProgram()
{
	this->initVariables();
	this->initWindow();
	this->initState();
}

MainProgram::~MainProgram()
{
	delete this->window;

	while (!this->states.empty()) {
		delete this->states.top();
		this->states.pop();
	}
}

const bool MainProgram::running() const
{
	return this->window->isOpen();
}

void MainProgram::updateEvents()
{
	if (this->ev.type == sf::Event::Closed)
	{
		closeWindow();
	}
}

void MainProgram::updateDt()
{
	this->dt = this->dtClock.restart().asSeconds();
}

void MainProgram::updateMusic()
{
	if (this->gameOptions->checkMusic())
	{
		this->music.setVolume(20);
	}
	else if (!this->gameOptions->checkMusic())
	{
		this->music.setVolume(0);
	}
}

void MainProgram::updateSFMLEvents()
{
	if (!this->states.empty()) {
		while (this->window->pollEvent(this->states.top()->ev)) this->states.top()->updateEvents();
	}
	else {
		while (this->window->pollEvent(this->ev)) this->updateEvents();
	}
}

void MainProgram::update()
{

	this->updateSFMLEvents();

	this->updateMusic();

	if (!this->states.empty()) {
		this->states.top()->update();
		if (this->states.top()->getQuit()) {
			this->states.top()->endState();
			delete this->states.top();
			this->states.pop();

		}
	}
	else {
		this->window->close();
	}
}

void MainProgram::render()
{
	this->window->clear();
	if (!this->states.empty()) {
		this->states.top()->render();
	}
	this->window->display();
}

void MainProgram::run()
{
	while (this->running())
	{
		this->updateDt();
		this->update();
		this->render();
	}
}


void MainProgram::closeWindow()
{
	this->window->close();
}
*/