#include "MainMenuState.h"

void MainMenuState::initializeBackground() {
	this->background.setSize(sf::Vector2f(1500,1000));
	//std::cout << system("dir")<<"\n";
	this->backgroundTexture.loadFromFile("Data/Backgrounds/bg1.png");
	this->background.setTexture(&this->backgroundTexture);
}

void MainMenuState::initializeButtons() {
	this->buttons["START"] = new Button(0.25,600,200, "../Resources/Button/Start/");
	this->buttons["RANK"] = new Button(0.5, 600, 300, "../Resources/Button/Options/");
	this->buttons["OPTIONS"] = new Button(0.5, 600, 400, "../Resources/Button/Options/");
	this->buttons["EXIT"] = new Button(0.5, 600, 500, "../Resources/Button/Options/");

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
	for (auto& it : (this->buttons)) {
		it.second->updateStateByMouse(*(this->window));
	}

	/*
	if (this->buttons["START"]->getButtonState() == 2) {
		this->states->push(new PlayMenuState(this->window, this->states, this->gameOptions));
	}

	if (this->buttons["RANK"]->getButtonState() == 2) {

	}

	if (this->buttons["OPTIONS"]->getButtonState() == 2) {

	}

	if (this->buttons["OPTIONS"]->getButtonState() == 2) {

	}
	*/
}

void MainMenuState::update() {
	this->updateMousePosition();
	this->updateButtons();
}

void MainMenuState::render(sf::RenderWindow * const target) {
	target->draw(this->background);
	for (auto& it : this->buttons) 
		it.second->render(target);
}
