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
<<<<<<< Updated upstream
	this->buttons["PLAY"] = new Button(1, 600, 200, "Data/Images/States/MainMenuState/play");
	this->buttons["SCOREBOARD"] = new Button(1, 600, 400, "Data/Images/States/MainMenuState/scoreboard");
	this->buttons["SETTING"] = new Button(1, 600, 600, "Data/Images/States/MainMenuState/setting");
	this->buttons["EXIT"] = new Button(1, 600, 800, "Data/Images/States/MainMenuState/exit");
=======
	this->buttons["START"] = new Button(0.25,600,200, "../Resources/Button/Start/");
	this->buttons["RANK"] = new Button(0.5, 600, 300, "../Resources/Button/Rank/");
	this->buttons["OPTIONS"] = new Button(0.5, 600, 400, "../Resources/Button/Options/");
	this->buttons["EXIT"] = new Button(0.5, 600, 500, "../Resources/Button/Exit/");
>>>>>>> Stashed changes

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

	for (auto& keyAndButton : (this->buttons))
		(keyAndButton.second)->updateEvent(this->event, this->mousePositionView);

<<<<<<< Updated upstream
	if (this->buttons["PLAY"]->checkReleasedLeft()) {
		this->states->push(new PlayMenuState(this->window, this->states));
		return;
=======
	
	if (this->buttons["START"]->getButtonState() == 2) {
		this->states->push(new PlayMenuState(this->window, this->states, this->gameOptions));
>>>>>>> Stashed changes
	}

	if (this->buttons["SCOREBOARD"]->checkReleasedLeft()) {
		this->states->push(new ScoreboardState(this->window, this->states));
		return;
	}

<<<<<<< Updated upstream
	if (this->buttons["SETTING"]->checkReleasedLeft()) {
		this->states->push(new SettingState(this->window, this->states));
		return;
	}

	if (this->buttons["EXIT"]->checkReleasedLeft())
		this->endState();
=======
	if (this->buttons["OPTIONS"]->getButtonState() == 2) {
		this->states->push(new OptionsState(this->window, this->states, this->gameOptions));
	}

	if (this->buttons["EXIT"]->getButtonState() == 2) {
		this->endState();
	}
	
>>>>>>> Stashed changes
}

void MainMenuState::update() {
	this->updateMousePosition();
}

void MainMenuState::render(sf::RenderWindow * const target) {
	target->draw(this->background);
	for (auto& it : this->buttons) 
		it.second->render(target);
}
