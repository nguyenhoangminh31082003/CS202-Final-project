#include "Helper.h"

#include "Train.h"

Train::Train() : Obstacle() {
	this->dx = 15 + Helper::getRandomInteger(0, 20);
	this->dy = 0;
	(this->texture).loadFromFile("Data/Images/Roads/RailwayRoads/train.png");
	(this->image).setTexture(&(this->texture));
	(this->image).setSize(sf::Vector2f(1000, 100));
};

Train::Train(const double vx, const double vy) {
	this->dx = vx;
	this->dy = vy;
	(this->texture).loadFromFile("Data/Images/Roads/RailwayRoads/train.png");
	(this->image).setTexture(&(this->texture));
	(this->image).setSize(sf::Vector2f(1000, 100));
};

void Train::render(sf::RenderTarget* const target) const {
	target->draw(this->image);
};

double Train::getWidth() const {
	return (this->image).getGlobalBounds().width;
};

sf::FloatRect Train::getBounds() const {
	return (this->image).getGlobalBounds();
};

Train::~Train() {};

void Train::saveToTextFile(std::ofstream& outputFile) const {
	outputFile << (this->image).getPosition().x << ' ' << (this->image).getPosition().y << ' ' << (this->dx) << ' ' << (this->dy) << '\n';
};

void Train::readFromTextFile(std::ifstream& inputFile) {
	double x, y;
	inputFile >> x >> y >> (this->dx) >> (this->dy);
	(this->image).setPosition(x, y);
};