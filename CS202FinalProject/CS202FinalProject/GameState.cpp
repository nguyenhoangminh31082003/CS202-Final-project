#include "GameState.h"

void GameState::deleteAllButtons() {
	for (auto& keyAndButton : (this->buttons))
		delete keyAndButton.second;
	(this->buttons).clear();
};

void GameState::initializeButtons() {
	(this->buttons)["SAVE_AND_QUIT"] = new Button(1, 1400, 0, "Data/Images/States/GameState/save_and_quit_icon");
	(this->buttons)["REPLAY"] = new Button(1, 1300, 0, "Data/Images/States/GameState/replay_icon");
	(this->buttons)["QUIT"] = new Button(1, 1200, 0, "Data/Images/States/GameState/quit_icon");
	(this->buttons)["PAUSE"] = new Button(1, 1100, 0, "Data/Images/States/GameState/pause_icon");
	(this->buttons)["CONTINUE"] = new Button(1, 1100, 0, "Data/Images/States/GameState/continue_icon");
}

GameState::GameState(sf::RenderWindow* const window, std::vector<State*>* const states): State(window, states), roadCrossingGame(*window) {
	this->initializeBacktround();

	this->initializeButtons();
};

GameState::GameState(sf::RenderWindow* const window, std::vector<State*>* const states, const bool savedOldGame): State(window, states), roadCrossingGame(*window, savedOldGame) {
	this->initializeBacktround();

	this->initializeButtons();
};

void GameState::initializeBacktround() {
	const sf::Vector2u size = (this -> window)->getSize();
	(this->background).setSize(sf::Vector2f(1.0 * size.x, 1.0 * size.y));
	(this->background).setFillColor(sf::Color(0, 12, 118)/*dark blue*/);
};

void GameState::updateEvents() {
	/*
	
		The function would be called outside (by MainProgram)
	
	*/

	for (auto& keyAndButton : (this->buttons))
		(keyAndButton.second)->updateEvent(this->event, this->mousePositionView);
	
	/*
	for (auto& keyAndButton : (this->buttons))
		std::cerr << (keyAndButton.second->getButtonState()) << ' ';
	std::cerr << '\n';
	*/

	switch ((this->event).type) {
	case sf::Event::Closed:
		this->endAllStates();
		break;
	default:
		(this->roadCrossingGame).updateWithEvent(this -> event);
		break;
	}

	if ((this->roadCrossingGame).getGameStatus() == GAME_STATUS::WIN && sf::Keyboard::isKeyPressed(sf::Keyboard::Y)) {
		(this->roadCrossingGame).moveNextLevel();
		std::cerr << "Move to next level\n";
		return;
	}

	if ((this->roadCrossingGame).getGameStatus() == GAME_STATUS::LOSE && sf::Keyboard::isKeyPressed(sf::Keyboard::Y)) {
		(this->roadCrossingGame).resetCurrentLevel();
		std::cerr << "Replay level\n";
		return;
	}

	if ((this->buttons)["REPLAY"]->checkReleasedLeft()) {
		(this->roadCrossingGame).resetCurrentLevel();
	}

	if ((this->buttons)["QUIT"]->checkReleasedLeft()) {
		this->endState();
		return;
	}

	if ((this->buttons)["SAVE_AND_QUIT"]->checkReleasedLeft()) {
		(this->roadCrossingGame).saveGameToTextFile();
		this->endState();
		return;
	}

	if ((this->roadCrossingGame).getGameStatus() == GAME_STATUS::CURRENT_PLAYED) {
		if ((this->buttons)["PAUSE"]->checkReleasedLeft())
			(this->roadCrossingGame).pauseGame();
	} else if ((this->roadCrossingGame).getGameStatus() == GAME_STATUS::PAUSED) {
		if ((this->buttons)["CONTINUE"]->checkReleasedLeft())
			(this->roadCrossingGame).continueGame();
	}

};

void GameState::update() {
	(this->roadCrossingGame).update();

	this->updateMousePosition();
}

GameState::~GameState() {
	this->deleteAllButtons();
}

void GameState::render() {
	this->render(this -> window);
};

void GameState::render(sf::RenderWindow* const target) {
	target->draw(this -> background);
	(this->roadCrossingGame).render(target);
	this->renderButtons(target);
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