#include <iostream>

#include "SimpleRoad.h"
#include "Helper.h"

SimpleRoad::SimpleRoad() {
	(this -> roadImage).setSize(sf::Vector2f(100, 1000));
	(this -> roadImage).setFillColor(sf::Color(159, 159, 159));
};

SimpleRoad::SimpleRoad(const sf::Vector2f& position) {
	(this->roadImage).setSize(sf::Vector2f(100, 1000));
	(this->roadImage).setPosition(position);

	const int color = ((int)position.x) % 255;

	(this->roadImage).setFillColor(sf::Color(color, color, color));
};

void SimpleRoad::setRoadPosition(const sf::Vector2f &position) {
	(this->roadImage).setPosition(position);

	const int color = ((int)position.x) % 255;

	(this->roadImage).setFillColor(sf::Color(color, color, color));

};

void SimpleRoad::render(sf::RenderTarget* const window) {
	window -> draw(this -> roadImage);
	for (const SimpleCar& car : (this->cars))
		car.render(window);
};

void SimpleRoad::update() {

	const double northY = (this->roadImage).getPosition().y, 
				 southY = northY + (this->roadImage).getSize().y,
				 westX = (this->roadImage).getPosition().x;

	for (SimpleCar& car : (this->cars)) {
		car.movePosition();
		if (car.getYofNorthBound() > southY)
			car.setPosition(westX, northY - car.getHeight());
		else if (car.getYofSouthBound() < northY)
			car.setPosition(westX, southY);
	}
};

void SimpleRoad::appendCar(const SimpleCar& car) {

	const double northY = (this->roadImage).getPosition().y,
			  	 westX = (this->roadImage).getPosition().x;

	(this->cars).push_back(car);
	(this->cars).back().setPosition(westX, northY - car.getHeight());
};

void SimpleRoad::appendCarWithSpeed(const double speed) {

	SimpleCar car;

	car.setVelocity(0, speed);

	this->appendCar(car);

};