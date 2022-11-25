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

Road::~Road() {
	while (!((this->obstacles).empty())) {
		delete obstacles.back();
		obstacles.pop_back();
	}
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

void Road::appendObstacle(Obstacle* const obstacle) {

	const double northY = (this->roadImage).getPosition().y,
			  	 westX = (this->roadImage).getPosition().x;

	(this -> obstacles).push_back(obstacle);
	(this -> obstacles).back() -> setPosition(westX, northY - (obstacle -> getHeight()));
};

void Road::appendCarWithSpeed(const double speed) {

	Obstacle * obstacle = new Obstacle;

	obstacle -> setVelocity(0, speed);

	this-> appendObstacle(obstacle);

};