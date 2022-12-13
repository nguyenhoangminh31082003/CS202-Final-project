#include "GameState.h"

void GameState::initializeButtons() {

}

GameState::GameState(sf::RenderWindow* const window, std::stack<State*>* const states): State(window, states) {

};

void GameState::initializeBacktround() {
	const sf::Vector2u size = (this -> window)->getSize();
	(this->background).setSize(sf::Vector2f(1.0 * size.x, 1.0 * size.y));
	(this->background).setFillColor(sf::Color(43, 242, 69)/*green*/);
};

void GameState::updateEvents() {
	/*
	
		The function would be called outside (by MainProgram)
	
	*/
	switch ((this->event).type) {
	case sf::Event::Closed:
		this->endState();
		break;
	default:
		(this->roadCrossingGame).updateWithEvent(this -> event);
		break;
	}
};

void GameState::update() {

	this->updateMousePosition();

	this->updateButtons();

	(this->roadCrossingGame).update();
}

GameState::~GameState() {
}

void GameState::render() {
	this->render(this -> window);
};

void GameState::render(sf::RenderWindow* const target) {
	target->draw(this -> background);
	(this->roadCrossingGame).render(target);
};

void GameState::renderButtons(sf::RenderTarget* const target) {
	for (const auto& keyAndButton : (this->buttons))
		(keyAndButton.second) -> render(target);
};

void GameState::updateButtons() {
	for (auto& keyAndButton : (this->buttons))
		(keyAndButton.second)->update(this -> mousePositionView);
};