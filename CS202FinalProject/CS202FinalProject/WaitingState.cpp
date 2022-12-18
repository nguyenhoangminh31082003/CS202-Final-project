#include "WaitingState.h"

void WaitingState::initializeBackground() {
	this->background.setSize(sf::Vector2f(1500, 1000));
	//std::cout << system("dir")<<"\n";
	this->backgroundTexture.loadFromFile("Data/Images/States/WaitingState/background.png");
	this->background.setTexture(&this->backgroundTexture);
}

WaitingState::WaitingState(sf::RenderWindow* window, std::stack<State*>* states) :State(window, states) {
	this->initializeBackground();

	(this -> timer).stop();
	(this -> timer).run();
}

WaitingState::~WaitingState() {
}

void WaitingState::updateEvents() {
	if ((this->event).type == sf::Event::Closed)
		this->endState();

}

void WaitingState::updateButtons() {
}

void WaitingState::update() {
	this->updateMousePosition();
	this->updateButtons();

	if ((this->timer).getRecordTime() > 2)
		this->endState();
}

void WaitingState::render(sf::RenderWindow* const target) {
	target->draw(this->background);
}
