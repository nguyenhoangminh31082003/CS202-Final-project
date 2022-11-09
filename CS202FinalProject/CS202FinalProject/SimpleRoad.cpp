#include <iostream>

#include "SimpleRoad.h"
#include "Helper.h"

SimpleRoad::SimpleRoad() {
	(this -> roadImage).setSize(sf::Vector2f(100, 800));
	(this -> roadImage).setFillColor(sf::Color(159, 159, 159));
};

SimpleRoad::SimpleRoad(const sf::Vector2f& position) {
	(this->roadImage).setSize(sf::Vector2f(100, 800));
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
	auto position = (this->roadImage).getPosition();
	window -> draw(this -> roadImage);
};

void SimpleRoad::update() {

	const double northY = (this->roadImage).getPosition().y, 
				 southY = northY + (this->roadImage).getSize().y,
				 westX = (this->roadImage).getPosition().x;

	for (SimpleCar& car : (this->cars)) {
		car.movePosition();
		if (car.getYofSouthBound() > southY)
			car.setPosition(westX, northY - car.getHeight());
	}
};

void SimpleRoad::appendCar(const SimpleCar& car) {

	const double northY = (this->roadImage).getPosition().y,
			  	 westX = (this->roadImage).getPosition().x;

	(this->cars).push_back(car);
	(this->cars).back().setPosition(westX, northY - car.getHeight());
};