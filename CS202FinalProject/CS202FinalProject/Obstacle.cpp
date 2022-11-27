#include "Obstacle.h"
#include "Helper.h"

Obstacle::Obstacle() {
	(this->image).setSize(sf::Vector2f(100, 100));
	(this->image).setFillColor(sf::Color(Helper::getRandomInteger(0, 255), Helper::getRandomInteger(0, 255), Helper::getRandomInteger(0, 255)));
	dx = Helper::getRandomInteger(1, 5);
	dy = Helper::getRandomInteger(1, 5);
};

void Obstacle::render(sf::RenderTarget* const window) const {
	window->draw(this -> image);
};

void Obstacle::movePosition() {
	(this->image).move(dx, dy);
};

void Obstacle::setPosition(const double x, const double y) {
	(this->image).setPosition(x, y);
};

void Obstacle::setVelocity(const double dx, const double dy) {
	(this->dx) = dx;
	(this->dy) = dy;
};

double Obstacle::getYofNorthBound() const {
	return (this->image).getPosition().y;
};

double Obstacle::getYofSouthBound() const {
	return (this->image).getPosition().y + (this->image).getSize().y;
};

double Obstacle::getXofWestBound() const {
	return (this->image).getPosition().x;
};

double Obstacle::getXofEastBound() const {
	return (this->image).getPosition().x + (this->image).getSize().x;
};

double Obstacle::getHeight() const {
	return (this->image).getSize().y;
};

double Obstacle::getWidth() const {
	return (this->image).getSize().x;
};


sf::FloatRect Obstacle::getBounds() const {
	return (this->image).getGlobalBounds();
};

bool Obstacle::checkCollision(const Obstacle& obstacle) const {
	return (this->image).getGlobalBounds().intersects((obstacle.image).getGlobalBounds());
};

double Obstacle::getSpeedX() const {
	return this->dx;
}; 

double Obstacle::getSpeedY() const {
	return this->dy;
};

void Obstacle::saveToTextFile(std::ofstream& outputFile) const {
	outputFile << (this -> image).getPosition().x << ' ' << (this->image).getPosition().x << ' ' << (this->dx) << ' ' << (this->dy) << '\n';
};

void Obstacle::readFromTextFile(std::ifstream& inputFile) {
	double x, y;
	inputFile >> x >> y >> (this->dx) >> (this->dy);
	(this->image).setPosition(x, y);
};