#include "ScoreboardState.h"

void ScoreboardState::initializeBackground() {
	this->background.setSize(sf::Vector2f(1500, 1000));
	
	this->backgroundTexture.loadFromFile("Data/Images/States/ScoreboardState/background.png");
	this->background.setTexture(&this->backgroundTexture);
}

void ScoreboardState::initializeButtons() {
	this->buttons["BACK"] = new Button(0.6, 50, 900, "Data/Images/States/ScoreboardState/back");
	this->buttons["RESET"] = new Button(0.6, 1390, 900, "Data/Images/States/ScoreboardState/Replay_icon");

}

void ScoreboardState::loadScore()
{

}

void ScoreboardState::saveScore()
{

}

ScoreboardState::ScoreboardState(sf::RenderWindow* const window, std::stack<State*>* const states) : State(window, states) {
	this->initializeBackground();
	this->initializeButtons();
};

void ScoreboardState::updateEvents() {
	if ((this->event).type == sf::Event::Closed)
		this->endState();

	for (auto& keyAndButton : (this->buttons))
		(keyAndButton.second)->updateEvent(this->event, this->mousePositionView);

	if (this->buttons["RESET"]->checkReleasedLeft()) {
		this->endState();
		return;
	}

	if (this->buttons["BACK"]->checkReleasedLeft()) {
		saveScore();
		this->endState();
		return;
	}

};

void ScoreboardState::update() {
	this->updateMousePosition();
};

void ScoreboardState::render(sf::RenderWindow* const target) {
	target->draw(this->background);
	for (auto& it : this->buttons)
		it.second->render(target);
};

ScoreboardState::~ScoreboardState() {
	for (auto it = this->buttons.begin(); it != this->buttons.end(); ++it) {
		delete it->second;
	}
}