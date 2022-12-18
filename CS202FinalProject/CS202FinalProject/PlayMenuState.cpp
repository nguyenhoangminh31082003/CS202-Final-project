#include "PlayMenuState.h"
#include "GameState.h"

void PlayMenuState::initializeBackground() {
	this->background.setSize(sf::Vector2f(1500, 1000));
	//std::cout << system("dir")<<"\n";
	this->backgroundTexture.loadFromFile("Data/Images/States/PlayMenuState/background.png");
	this->background.setTexture(&this->backgroundTexture);
}

void PlayMenuState::initializeButtons() {
	this->buttons["NEW_GAME"] = new Button(1, 600, 200, "Data/Images/States/PlayMenuState/play");
	this->buttons["INFINITY"] = new Button(1, 600, 400, "Data/Images/States/PlayMenuState/infinity");
	this->buttons["RELOAD_OLD_GAME"] = new Button(1, 600, 600, "Data/Images/States/PlayMenuState/reload_old_game");
	this->buttons["BACK"] = new Button(1, 600, 800, "Data/Images/States/PlayMenuState/back");
}

PlayMenuState::PlayMenuState(sf::RenderWindow* window, std::stack<State*>* states): State(window, states) {
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

	for (auto& keyAndButton : (this->buttons))
		(keyAndButton.second)->updateEvent(this->event, this->mousePositionView);

	if (this->buttons["NEW_GAME"]->checkReleasedLeft()) {
		(this->states)->push(new GameState(this->window, this->states));
	}

	if (this->buttons["INFINITY"]->checkReleasedLeft()) {
		/*

			Comming soon

		*/
	}

	if (this->buttons["RELOAD_OLD_GAME"]->checkReleasedLeft()) {
		(this->states)->push(new GameState(this->window, this->states));
	}

	if (this->buttons["BACK"]->checkReleasedLeft())
		this->endState();
}

void PlayMenuState::updateButtons() {
}

void PlayMenuState::update() {
	this->updateMousePosition();
	this->updateButtons();
}

void PlayMenuState::render(sf::RenderWindow* target) {
	target->draw(this->background);
	for (auto& it : this->buttons)
		it.second->render(target);
}
