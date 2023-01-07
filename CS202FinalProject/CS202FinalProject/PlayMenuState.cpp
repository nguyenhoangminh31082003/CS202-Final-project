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
	this->buttons["LOAD_GAME"] = new Button(1, 600, 400, "Data/Images/States/PlayMenuState/load_game");
	this->buttons["RELOAD_OLD_GAME"] = new Button(1, 600, 600, "Data/Images/States/PlayMenuState/reload_old_game");
	this->buttons["BACK"] = new Button(1, 600, 800, "Data/Images/States/PlayMenuState/back");
}

PlayMenuState::PlayMenuState(sf::RenderWindow* const window, std::vector<State*>* states): State(window, states) {
	this->initializeBackground();
	this->initializeButtons();
}

PlayMenuState::PlayMenuState(sf::RenderWindow* const window, std::vector<State*>* states, GameOptions* gameOptions) :State(window, states, gameOptions) {
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
		this->endAllStates();

	for (auto& keyAndButton : (this->buttons))
		(keyAndButton.second)->updateEvent(this->event, this->mousePositionView);

	if (this->buttons["NEW_GAME"]->checkReleasedLeft()) {
		(this->states)->push_back(new GameState(this->window, this->states, this->gameOptions));
		return;
	}

	if (this->buttons["LOAD_GAME"]->checkReleasedLeft()) {
		(this->states)->push_back(new GameState(this->window, this->states, "loadGame", this->gameOptions));
		return;
	}

	if (this->buttons["RELOAD_OLD_GAME"]->checkReleasedLeft()) {
		(this->states)->push_back(new GameState(this->window, this->states, "savedOldGame", this->gameOptions));
		return;
	}

	if (this->buttons["BACK"]->checkReleasedLeft())
		this->endState();
}

void PlayMenuState::update() {
	this->updateMousePosition();
}

void PlayMenuState::render(sf::RenderWindow* target) {
	target->draw(this->background);
	for (auto& it : this->buttons)
		it.second->render(target);
}
