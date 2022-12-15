#include "GameState.h"

void GameState::deleteAllButtons() {
	for (auto& keyAndButton : (this->buttons))
		delete keyAndButton.second;
	(this->buttons).clear();
};

void GameState::initializeButtons() {
	(this->buttons)["REPLAY"] = new Button(1, 0, 850, "Data/Images/States/GameState/replay");
	(this->buttons)["QUIT"] = new Button(1, 0, 950, "Data/Images/States/GameState/quit");
	(this->buttons)["SAVE_AND_QUIT"] = new Button(1, 0, 750, "Data/Images/States/GameState/save_and_quit");
	(this->buttons)["PAUSE"] = new Button(1, 0, 650, "Data/Images/States/GameState/pause");
	(this->buttons)["CONTINUE"] = new Button(1, 0, 650, "Data/Images/States/GameState/continue");
}

GameState::GameState(sf::RenderWindow* const window, std::stack<State*>* const states): State(window, states) {
	this->initializeBacktround();

	this->initializeButtons();
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
	this->deleteAllButtons();
}

void GameState::render() {
	this->render(this -> window);
};

void GameState::render(sf::RenderWindow* const target) {
	target->draw(this -> background);
	this->renderButtons(target);
	(this->roadCrossingGame).render(target);
};

void GameState::renderButtons(sf::RenderTarget* const target) {
	for (const auto& keyAndButton : (this->buttons)) {
		if (keyAndButton.first == "PAUSE") {
			if ((this->roadCrossingGame).getGameStatus() != GAME_STATUS::CURRENT_PLAYED)
				continue;
		} else if (keyAndButton.first == "CONTINUE") {
			if ((this->roadCrossingGame).getGameStatus() != GAME_STATUS::PAUSED)
				continue;
		}
		(keyAndButton.second)->render(target);
	}
};

void GameState::updateButtons() {
	for (auto& keyAndButton : (this->buttons))
		(keyAndButton.second)->update(this -> mousePositionView);

	if ((this->buttons)["REPLAY"] -> checkPressedLeft()) {
		(this->roadCrossingGame).resetCurrentLevel();
	}

	if ((this->buttons)["QUIT"] -> checkPressedLeft()) {
		this->endState();
	}

	if ((this->buttons)["SAVE_AND_QUIT"]->checkPressedLeft()) {
		(this->roadCrossingGame).saveGameToTextFile();
		this->endState();
	}

	if ((this->roadCrossingGame).getGameStatus() == GAME_STATUS::CURRENT_PLAYED) {
		if ((this->buttons)["PAUSE"]->checkPressedLeft())
			(this->roadCrossingGame).pauseGame();
	} else if ((this->roadCrossingGame).getGameStatus() == GAME_STATUS::PAUSED) {
		if ((this->buttons)["CONTINUE"]->checkPressedLeft())
			(this->roadCrossingGame).continueGame();
	}
};