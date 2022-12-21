#include <iostream>

#include "State.h"

State::State(sf::RenderWindow* window, std::stack<State*>* states) {
	this->window = window;
	this->states = states;
	this->quit = false;
}

State::State(sf::RenderWindow* window, std::stack<State*>* states, GameOptions* gameOptions) {
	this->window = window;
	this->states = states;
	this->quit = false;
	this->gameOptions = gameOptions;
}

State::~State() {}

const bool& State::getQuit() const {
	return this->quit;
}

void State::endState() {
	this->quit = true;
}


void State::updateMousePosition() {
	this->mousePositionScreen = sf::Mouse::getPosition();
	this->mousePositionWindow = sf::Mouse::getPosition(*this->window);
	this->mousePositionView = this->window->mapPixelToCoords(sf::Mouse::getPosition(*this->window));
}

std::ostream& operator << (std::ostream& outputStream, const State& state) {
	outputStream << "State's information\n";
	return outputStream;
};

void State::render() {
	this->render(this -> window);
}