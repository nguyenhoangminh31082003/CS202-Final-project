#include "Obstacle.h"
#include "Helper.h"

Obstacle::Obstacle() {
	(this->carImage).setSize(sf::Vector2f(100, 100));
	(this->carImage).setFillColor(sf::Color(Helper::getRandomInteger(0, 255), Helper::getRandomInteger(0, 255), Helper::getRandomInteger(0, 255)));
	dx = Helper::getRandomInteger(1, 5);
	dy = Helper::getRandomInteger(1, 5);
};

void Obstacle::render(sf::RenderTarget* const window) const {
	window->draw(this -> carImage);
};

void Obstacle::movePosition() {
	(this->carImage).move(dx, dy);
};

void Obstacle::setPosition(const double x, const double y) {
	(this->carImage).setPosition(x, y);
};

void Obstacle::setVelocity(const double dx, const double dy) {
	(this->dx) = dx;
	(this->dy) = dy;
};

double Obstacle::getYofNorthBound() const {
	return (this->carImage).getPosition().y;
};

double Obstacle::getYofSouthBound() const {
	return (this->carImage).getPosition().y + (this->carImage).getSize().y;
};

double Obstacle::getXofWestBound() const {
	return (this->carImage).getPosition().x;
};

double Obstacle::getXofEastBound() const {
	return (this->carImage).getPosition().x + (this->carImage).getSize().x;
};

double Obstacle::getHeight() const {
	return (this->carImage).getSize().y;
};

double Obstacle::getWidth() const {
	return (this->carImage).getSize().x;
};