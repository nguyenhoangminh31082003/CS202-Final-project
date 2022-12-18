#include "OptionsState.h"

void OptionsState::initializeBackground() {
	this->background.setSize(sf::Vector2f(1500, 1000));
	//std::cout << system("dir")<<"\n";
	this->backgroundTexture.loadFromFile("Data/Backgrounds/bg1.png");
	this->background.setTexture(&this->backgroundTexture);
}

void OptionsState::initializeButtons() {
	this->buttons["SOUND"] = new Button(0.25, 600, 200, "../Resources/Button/Start/");
	this->buttons["MUSIC"] = new Button(0.5, 600, 250, "../Resources/Button/Rank/");
	this->buttons["RESET_HIGHSCORE"] = new Button(0.5, 600, 400, "../Resources/Button/Options/");
	this->buttons["EXIT"] = new Button(0.5, 600, 500, "../Resources/Button/Exit/");

}

OptionsState::OptionsState(sf::RenderWindow* window, std::stack<State*>* states) :State(window, states) {
	this->initializeBackground();
	this->initializeButtons();
}

OptionsState::OptionsState(sf::RenderWindow* window, std::stack<State*>* states, GameOptions* gameOptions) :State(window, states, gameOptions) {
	this->initializeBackground();
	this->initializeButtons();
}

OptionsState::~OptionsState() {
	for (auto it = this->buttons.begin(); it != this->buttons.end(); ++it) {
		delete it->second;
	}
}

void OptionsState::updateEvents() {
	if ((this->event).type == sf::Event::Closed)
		this->endState();
}

void OptionsState::updateButtons() {
	for (auto& it : (this->buttons)) {
		it.second->updateStateByMouse(*(this->window));
	}

	
	if (this->buttons["SOUND"]->getButtonState() == 2) {
		
	}

	if (this->buttons["MUSIC"]->getButtonState() == 2) {

	}

	if (this->buttons["RESET_HIGHSCORE"]->getButtonState() == 2) {

	}

	if (this->buttons["EXIT"]->getButtonState() == 2) {
		this->endState();
	}
	
}

void OptionsState::update() {
	this->updateMousePosition();
	this->updateButtons();
}

void OptionsState::render(sf::RenderWindow* const target) {
	target->draw(this->background);
	for (auto& it : this->buttons)
		it.second->render(target);
}
