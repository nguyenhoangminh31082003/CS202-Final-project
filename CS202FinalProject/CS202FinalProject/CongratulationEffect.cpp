#include "CongratulationEffect.h"

CongratulationEffect::CongratulationEffect() {
	(this->texture).loadFromFile("Data/images/States/GameState/congratulation.png");
	(this->congratulationImage).setTexture(this->texture, true);
	(this->congratulationImage).setPosition(sf::Vector2f(0, 300));
	(this->theme).setFillColor(sf::Color(255, 0, 127, 100));
	(this->theme).setSize(sf::Vector2f(1500, 1000));
};

CongratulationEffect::~CongratulationEffect() {};

bool CongratulationEffect::checkFinished() const {
	return false;
};

void CongratulationEffect::update() {};

void CongratulationEffect::render(sf::RenderTarget* const target) {
	target->draw(this->theme);
	target->draw(this->congratulationImage);
};