#include <iostream>

#include "TrafficLight.h"

TrafficLight::TrafficLight(): color(TRAFFIC_LIGHT_COLOR::GREEN) {
	if ((this->redLight).loadFromFile("Data/Images/Roads/VehicleRoads/TrafficLight/RedLight.png"))
		std::cerr << "Red light is successfully loaded" << '\n';
	if ((this->greenLight).loadFromFile("Data/Images/Roads/VehicleRoads/TrafficLight/GreenLight.png"))
		std::cerr << "Green light is successfully loaded" << '\n';
};

void TrafficLight::render(sf::RenderTarget* const target) {
	if ((this->color) == TRAFFIC_LIGHT_COLOR::RED)
		(this->image).setTexture(this->redLight, true);
	else if ((this->color) == TRAFFIC_LIGHT_COLOR::GREEN)
		(this->image).setTexture(this->greenLight, true);
	//std::cerr << (this -> image).getPosition().x << ' ' << (this->image).getPosition().y << '\n';;
	target->draw(this -> image);
};

void TrafficLight::setPosition(const sf::Vector2f& position) {
	(this->image).setPosition(position);
};

void TrafficLight::movePosition(const sf::Vector2f& d) {
	(this->image).move(d);
};