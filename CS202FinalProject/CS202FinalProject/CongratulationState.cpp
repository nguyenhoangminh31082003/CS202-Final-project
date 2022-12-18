#include "CongratulationState.h"

void CongratulationState::initializeFont() {
	if ((this->font).loadFromFile("Data/Fonts/Roboto/Roboto-Light.ttf")) {
		std::cerr << "Font is successfully loaded\n";
	} else {
		std::cerr << "Font is not successfully loaded\n";
	}
}

void CongratulationState::initializeMessage() {
	(this->message).setFillColor(sf::Color::White);
	(this->message).setFont(this -> font);
	(this->message).setCharacterSize(100);
	(this->message).setString("Message");
};

void CongratulationState::initializeNameBox() {
	(this->nameBox).setBoxSize(1000, 100);
	(this->nameBox).setPosition(250, 500);
	(this->nameBox).setLimit(20);
	(this->nameBox).setBoxColor(sf::Color::White, sf::Color::Green);
	(this->nameBox).setText(this -> font, 100, sf::Color::Black);
};

void CongratulationState::initializeBackground() {
	this->background.setSize(sf::Vector2f(1500, 1000));
	//std::cout << system("dir")<<"\n";
	this->backgroundTexture.loadFromFile("Data/Images/States/CongratulationState/background.png");
	this->background.setTexture(&this->backgroundTexture);
}

void CongratulationState::initializeButtons() {

}

CongratulationState::CongratulationState(sf::RenderWindow* window, std::stack<State*>* states, RoadCrossingGame const& roadCrossingGame) :State(window, states), roadCrossingGame(roadCrossingGame) {
	this->initializeFont();
	this->initializeBackground();
	this->initializeButtons();
	this->initializeNameBox();
	this->initializeMessage();
}

CongratulationState::~CongratulationState() {
	for (auto& keyAndButton : (this->buttons))
		delete keyAndButton.second;
	(this->buttons).clear();
}

void CongratulationState::updateEvents() {
	if ((this->event).type == sf::Event::Closed)
		this->endState();

	(this->nameBox).update(this -> event);

	for (auto& keyAndButton : (this->buttons))
		(keyAndButton.second)->updateEvent(this->event, this->mousePositionView);
}

void CongratulationState::update() {
	this->updateMousePosition();
}

void CongratulationState::render(sf::RenderWindow* const target) {
	target->draw(this->background);
	
	target -> draw(this->message);

	(this->nameBox).render(target);

	for (auto& it : this->buttons)
		it.second->render(target);
}