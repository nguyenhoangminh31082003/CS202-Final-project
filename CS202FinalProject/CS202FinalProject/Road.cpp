#include <iostream>

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

void Road::clearAllActiveObstacles() {
	while (!((this->obstacles).empty())) {
		delete obstacles.back();
		obstacles.pop_back();
	}
};

void Road::clearAllWaitingObstacles() {
	while (!((this->waitingObstacles).empty())) {
		delete obstacles.back();
		obstacles.pop_back();
	}
};

void Road::clearAllObstacles() {
	this->clearAllActiveObstacles();
	this->clearAllWaitingObstacles();
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


bool Road::startObstacleFromWaitingList() {
	if ((this->waitingObstacles).empty())
		return false;

	if (!(this->obstacles).empty()) {
		if (rand() % 2000)
			return false;
	}

	for (Obstacle* const& obstacle : (this->obstacles))
		if (obstacle->checkCollision(*(this->waitingObstacles).back()))
			return false;

	(this -> obstacles).push_back((this->waitingObstacles).back());
	(this->waitingObstacles).pop_back();

	return true;
};

void Road::update() {

	const double northY = (this->roadImage).getPosition().y, 
				 southY = northY + (this->roadImage).getSize().y,
				 westX = (this->roadImage).getPosition().x;

	this->startObstacleFromWaitingList();

	for (Obstacle* const& obstacle : (this->obstacles)) {
		obstacle -> movePosition();
		if (obstacle -> getYofNorthBound() > southY)
			obstacle -> setPosition(westX, northY - (obstacle -> getHeight()));
		else if (obstacle -> getYofSouthBound() < northY)
			obstacle -> setPosition(westX, southY);
	}
};


void Road::appendObstaclesWithSpeed(const double speed, const int numberOfObstacles) {

	const double northY = (this->roadImage).getPosition().y, westX = (this->roadImage).getPosition().x, southY = northY + (this->roadImage).getSize().y;

	Obstacle* obstacle = nullptr;

	this->clearAllObstacles();

	for (int i = 0; i < numberOfObstacles; ++i) {
		obstacle = new Obstacle;
		obstacle->setVelocity(0, speed);
		if (speed > 0)
			obstacle->setPosition(westX, northY - (obstacle->getHeight()));
		else
			obstacle->setPosition(westX, southY);
		(this->waitingObstacles).push_back(obstacle);
	}

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