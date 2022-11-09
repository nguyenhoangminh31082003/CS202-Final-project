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

void SimpleCar::movePosition() {
	(this->carImage).move(dx, dy);
};

void SimpleCar::setPosition(const double x, const double y) {
	(this->carImage).setPosition(x, y);
};

void SimpleCar::setVelocity(const double dx, const double dy) {
	(this->dx) = dx;
	(this->dy) = dy;
};

double SimpleCar::getYofNorthBound() const {
	return (this->carImage).getPosition().y;
};

double SimpleCar::getYofSouthBound() const {
	return (this->carImage).getPosition().y + (this->carImage).getSize().y;
};

double SimpleCar::getHeight() const {
	return (this->carImage).getSize().y;
};

double SimpleCar::getWidth() const {
	return (this->carImage).getSize().x;
};