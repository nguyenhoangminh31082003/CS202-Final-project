#include "SimpleCar.h"
#include "Helper.h"

SimpleCar::SimpleCar() {
	(this->carImage).setSize(sf::Vector2f(100, 100));
	(this->carImage).setFillColor(sf::Color(Helper::getRandomInteger(0, 255), Helper::getRandomInteger(0, 255), Helper::getRandomInteger(0, 255)));
	dx = Helper::getRandomInteger(1, 5);
	dy = Helper::getRandomInteger(1, 5);
};

void SimpleCar::render(sf::RenderTarget* const window) {
	window->draw(this -> carImage);
};