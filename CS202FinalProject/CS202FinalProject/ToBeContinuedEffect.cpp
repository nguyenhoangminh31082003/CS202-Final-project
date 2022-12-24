#include "ToBeContinuedEffect.h"

ToBeContinuedEffect::ToBeContinuedEffect() {
	(this->texture).loadFromFile("Data/images/States/GameState/to_be_continued.png");
	(this ->toBeContinuedImage).setTexture(this -> texture, true);
	(this->toBeContinuedImage).setPosition(sf::Vector2f(600, 450));
	(this->theme).setFillColor(sf::Color(247, 195, 22, 100));
	(this->theme).setSize(sf::Vector2f(1500, 1000));
};

ToBeContinuedEffect::~ToBeContinuedEffect() {};

bool ToBeContinuedEffect::checkFinished() const {
	return false;
};

void ToBeContinuedEffect::update() {};

void ToBeContinuedEffect::render(sf::RenderTarget* const target) {
	target->draw(this -> theme);
	target->draw(this->toBeContinuedImage);
};