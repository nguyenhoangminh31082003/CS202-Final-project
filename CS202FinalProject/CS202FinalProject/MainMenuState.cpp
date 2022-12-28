#include "MainMenuState.h"
#include "ScoreboardState.h"
#include "PlayMenuState.h"
#include "SettingState.h"

void MainMenuState::initializeBackground() {
	this->background.setSize(sf::Vector2f(1500,1000));
	//std::cout << system("dir")<<"\n";
	this->backgroundTexture.loadFromFile("Data/Images/States/MainMenuState/background.png");
	this->background.setTexture(&this->backgroundTexture);
}

void MainMenuState::initializeButtons() {
	this->buttons["START"] = new Button(1, 600, 200, "Data/Images/States/MainMenuState/start");
	this->buttons["SCOREBOARD"] = new Button(1, 600, 400, "Data/Images/States/MainMenuState/scoreboard");
	this->buttons["SETTING"] = new Button(1, 600, 600, "Data/Images/States/MainMenuState/setting");
	this->buttons["EXIT"] = new Button(1, 600, 800, "Data/Images/States/MainMenuState/exit");

}

MainMenuState::MainMenuState(sf::RenderWindow* const window, std::vector<State*>* states):State(window, states) {
	this->initializeBackground();
	this->initializeButtons();
}

MainMenuState::MainMenuState(sf::RenderWindow* const window, std::vector<State*>* states, GameOptions* gameOptions) :State(window, states,gameOptions) {
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
		this->endAllStates();

	for (auto& keyAndButton : (this->buttons))
		(keyAndButton.second)->updateEvent(this->event, this->mousePositionView);

	if (this->buttons["START"]->checkReleasedLeft()) {
		this->states->push_back(new PlayMenuState(this->window, this->states, this->gameOptions));
		return;
	}

	if (this->buttons["SCOREBOARD"]->checkReleasedLeft()) {
		this->states->push_back(new ScoreboardState(this->window, this->states, this->gameOptions));
		return;
	}

	if (this->buttons["SETTING"]->checkReleasedLeft()) {
		this->states->push_back(new SettingState(this->window, this->states, this->gameOptions));
		return;
	}

	if (this->buttons["EXIT"]->checkReleasedLeft()) {
		this->endState();
		return;
	}
}

void MainMenuState::update() {
	this->updateMousePosition();
}

void MainMenuState::render(sf::RenderWindow * const target) {
	target->draw(this->background);
	for (auto& it : this->buttons) 
		it.second->render(target);
}
