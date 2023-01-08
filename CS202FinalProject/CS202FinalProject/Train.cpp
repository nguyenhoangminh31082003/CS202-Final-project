#include "Helper.h"

#include "Train.h"

Train::Train() : Obstacle() {
	this->dx = 15 + Helper::getRandomInteger(0, 20);
	this->dy = 0;
	(this->texture).loadFromFile("Data/Images/Roads/RailwayRoads/train.png");
	(this->image).setTexture(&(this->texture));
	(this->image).setSize(sf::Vector2f(1000, 100));
	(this->trainSound).openFromFile("Data/Music/train_sound.wav");
	(this->trainSound).setLoop(true);
	(this->trainSound).pause();
};

Train::Train(const double vx, const double vy) {
	this->dx = vx;
	this->dy = vy;
	(this->texture).loadFromFile("Data/Images/Roads/RailwayRoads/train.png");
	(this->image).setTexture(&(this->texture));
	(this->image).setSize(sf::Vector2f(1000, 100));
	(this->trainSound).openFromFile("Data/Music/train_sound.wav");
	(this->trainSound).setLoop(true);
	(this->trainSound).pause();
};

void Train::startSound() {
	(this->trainSound).play();
};

void Train::endSound() {
	(this->trainSound).pause();
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
	std::cerr << "Train's information is successfully read\n";
	std::cerr << x << ' ' << y << ' ' << (this->image).getPosition().x << ' ' << (this->image).getPosition().y << '\n';
};

sf::Vector2f Train::getPosition() const {
	return (this->image).getPosition();
};

std::ostream& operator << (std::ostream& outputStream, const Train& train) {
	outputStream << "Train({velocity = (" << train.dx << ", " << train.dy << ")})";
	return outputStream;
};