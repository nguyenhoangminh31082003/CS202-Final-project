#include "PlayMenuState.h"

void PlayMenuState::initializeBackground() {
	this->background.setSize(sf::Vector2f(1500, 1000));
	//std::cout << system("dir")<<"\n";
	this->backgroundTexture.loadFromFile("Data/Backgrounds/bg1.png");
	this->background.setTexture(&this->backgroundTexture);
}

void PlayMenuState::initializeButtons() {
	this->buttons["NEW GAME"] = new Button(0.25, 600, 200, "../Resources/Button/Start/");
	this->buttons["LOAD GAME"] = new Button(0.5, 600, 300, "../Resources/Button/Options/");

}

PlayMenuState::PlayMenuState(sf::RenderWindow* window, std::stack<State*>* states) :State(window, states) {
	this->initializeBackground();
	this->initializeButtons();
}

PlayMenuState::PlayMenuState(sf::RenderWindow* window, std::stack<State*>* states, GameOptions* gameOptions) :State(window, states, gameOptions) {
	this->initializeBackground();
	this->initializeButtons();
}

PlayMenuState::~PlayMenuState() {
	for (auto it = this->buttons.begin(); it != this->buttons.end(); ++it) {
		delete it->second;
	}
}

void PlayMenuState::updateEvents() {
	if ((this->event).type == sf::Event::Closed)
		this->endState();
}

void PlayMenuState::updateButtons() {
	for (auto& it : this->buttons) {
		it.second->updateStateByMouse(*this->window);
	}

	if (this->buttons["NEW GAME"]->getButtonState() == 2) {

	}

	if (this->buttons["LOAD GAME"]->getButtonState() == 2) {

	}

}

void PlayMenuState::update() {
	this->updateMousePosition();
	this->updateButtons();
}

void PlayMenuState::render(sf::RenderWindow* target) {
	if (!target) {
		target = this->window;
	}

	target->draw(this->background);
	for (auto& it : this->buttons)
		it.second->render(target);
}
