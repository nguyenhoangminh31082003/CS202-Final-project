#include "MainMenuState.h"

void MainMenuState::initializeBackground() {
	this->background.setSize(sf::Vector2f(1500,1000));
	//std::cout << system("dir")<<"\n";
	this->backgroundTexture.loadFromFile("Data/Backgrounds/bg1.png");
	this->background.setTexture(&this->backgroundTexture);
}

void MainMenuState::initializeButtons() {
	this->buttons["PLAY"] = new Button(0.25,600,600, "../Resources/Button/Start/");
}

MainMenuState::MainMenuState(sf::RenderWindow* window, std::stack<State*>* states):State(window, states) {
	this->initializeBackground();
	this->initializeButtons();
}

MainMenuState::MainMenuState(sf::RenderWindow* window, std::stack<State*>* states, GameOptions* gameOptions) :State(window, states,gameOptions) {
	this->initializeBackground();
	this->initializeButtons();
}

MainMenuState::~MainMenuState() {
	for (auto it = this->buttons.begin(); it != this->buttons.end(); ++it) {
		delete it->second;
	}
}

void MainMenuState::updateEvents() {
	if ((this->event).type == sf::Event::Closed) 
		this->endState();
}

void MainMenuState::updateButtons() {
	for (auto& it : this->buttons) {
		it.second->updateStateByMouse(*this->window);
	}

	if (this->buttons["PLAY"]->getButtonState() == 2) {
		
	}
}

void MainMenuState::update() {
	this->updateMousePosition();
	this->updateButtons();
}

void MainMenuState::render(sf::RenderWindow * target) {
	if (!target) {
		target = this->window;
	}

	target->draw(this->background);
	for (auto& it : this->buttons) 
		it.second->render(target);
}
