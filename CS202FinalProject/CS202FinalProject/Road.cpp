#include <iostream>
#include <vector>

#include "Road.h"
#include "Helper.h"

Road::Road() {
	(this -> roadImage).setSize(sf::Vector2f(100, 1000));
	(this -> roadImage).setFillColor(sf::Color(159, 159, 159));
};

Road::Road(const sf::Vector2f& position) {
	(this->roadImage).setSize(sf::Vector2f(100, 1000));
	(this->roadImage).setPosition(position);

	const int color = ((int)position.x) % 255;

	(this->roadImage).setFillColor(sf::Color(color, color, color));
};

void Road::clearAllObstacles() {
	while (!((this->obstacles).empty())) {
		delete obstacles.back();
		obstacles.pop_back();
	}
};

Road::~Road() {
	this->clearAllObstacles();
}

void Road::setRoadPosition(const sf::Vector2f &position) {
	(this->roadImage).setPosition(position);

	const int color = ((int)position.x) % 255;

	(this->roadImage).setFillColor(sf::Color(color, color, color));

};

void Road::render(sf::RenderTarget* const window) {
	window -> draw(this -> roadImage);
	for (Obstacle * const & obstacle : (this -> obstacles))
		obstacle -> render(window);
};

void Road::update() {

	const double northY = (this->roadImage).getPosition().y, 
				 southY = northY + (this->roadImage).getSize().y,
				 westX = (this->roadImage).getPosition().x;

	for (Obstacle* const& obstacle : (this->obstacles)) {
		obstacle -> movePosition();
		if (obstacle -> getYofNorthBound() > southY)
			obstacle -> setPosition(westX, northY - (obstacle -> getHeight()));
		else if (obstacle -> getYofSouthBound() < northY)
			obstacle -> setPosition(westX, southY);
	}
};


bool Road::appendObstaclesWithSpeed(const double speed, const int numberOfObstacles) {

	if (numberOfObstacles > MAXIMUM_NUMBER_OF_OBSTACLES)
		return false;

	const double northY = (this->roadImage).getPosition().y, westX = (this->roadImage).getPosition().x;

	std::vector<double>positions(6);

	Obstacle* obstacle = nullptr;

	this->clearAllObstacles();

	for (int i = 0; i < positions.size(); ++i)
		positions[i] = northY + i * 150;

	std::random_shuffle(positions.begin(), positions.end());

	for (int i = 0; i < numberOfObstacles; ++i) {
		obstacle = new Obstacle;
		obstacle->setVelocity(0, speed);
		obstacle->setPosition(westX, positions[i]);
		(this->obstacles).push_back(obstacle);
	}

	return true;
};

bool Road::checkCollision(const Player& player) const {
	for (Obstacle* const& obstacle : (this->obstacles))
		if (player.checkCollision(*obstacle))
			return true;
	return false;
};


bool Road::checkValid() const {
	const int numberOfObstacles = (this -> obstacles).size();
	for (int i = 0, j; i < numberOfObstacles; ++i)
		for (j = 0; j < i; ++j)
			if (((this -> obstacles)[j] -> getSpeedY()) * ((this->obstacles)[i]->getSpeedY()) < 0)
				return false;
	return true;
};

void Road::saveToTextFile(std::ofstream& outputFile) const {
	outputFile << (this -> roadImage).getPosition().x << ' ' << (this->roadImage).getPosition().y << '\n' << (this -> obstacles).size() << '\n';
	for (Obstacle* const& obstacle : (this->obstacles))
		obstacle->saveToTextFile(outputFile);
};

void Road::readFromTextFile(std::ifstream& inputFile) {
	int numberOfObstacles;
	sf::Vector2f position;
	inputFile >> position.x >> position.y >> numberOfObstacles;
	this->setRoadPosition(position);
	this->clearAllObstacles();
	(this->obstacles).resize(numberOfObstacles, nullptr);
	for (Obstacle*& obstacle : (this->obstacles)) {
		obstacle = new Obstacle;
		obstacle->readFromTextFile(inputFile);
	}
};

std::ostream& operator << (std::ostream& outputStream, const Road& road) {
	const auto position = (road.roadImage).getPosition();
	const auto size = (road.roadImage).getSize();
	outputStream << "Road information\n";
	outputStream << "Top left corner: (" << position.x << ", " << position.y << ")\n";
	outputStream << "Size: (" << size.x << ", " << size.y << ")\n";
	outputStream << "Number of obstacles: " << road.obstacles.size() << '\n';
	return outputStream;
};