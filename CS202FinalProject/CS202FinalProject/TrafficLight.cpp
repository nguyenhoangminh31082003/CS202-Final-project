#include <iostream>

#include "TrafficLight.h"
#include "Helper.h"

TrafficLight::TrafficLight(): color(TRAFFIC_LIGHT_COLOR::GREEN) {
	if ((this->redLight).loadFromFile("Data/Images/Roads/VehicleRoads/TrafficLight/RedLight.png"))
		std::cerr << "Red light is successfully loaded" << '\n';
	if ((this->greenLight).loadFromFile("Data/Images/Roads/VehicleRoads/TrafficLight/GreenLight.png"))
		std::cerr << "Green light is successfully loaded" << '\n';
	(this -> light).setSize(sf::Vector2f(50, 100));
	(this->light).setFillColor(sf::Color(0, 0, 0, 100));
	(this->delta) = -1;
	(this->remainingTime) = 500 + Helper::getRandomInteger(0, 1000);
};

void TrafficLight::render(sf::RenderTarget* const target) {
	const double alpha = (this -> light).getFillColor().a;
	sf::Color color(0, 0, 0);
	if ((this->color) == TRAFFIC_LIGHT_COLOR::RED) {
		(this->image).setTexture(this->redLight, true);
		color = sf::Color::Red;
	} else if ((this->color) == TRAFFIC_LIGHT_COLOR::GREEN) {
		(this->image).setTexture(this->greenLight, true);
		color = sf::Color::Green;
	}
	color.a = alpha;
	(this->light).setFillColor(color);
	target->draw(this -> image);
	target->draw(this -> light);
};

void TrafficLight::setPosition(const sf::Vector2f& position) {
	(this->image).setPosition(position);
	(this->light).setPosition(position);
};

void TrafficLight::movePosition(const sf::Vector2f& d) {
	(this->image).move(d);
	(this->light).move(d);
};

void TrafficLight::update(const std::vector<Obstacle*>& obstacles) {
	sf::Color color((this -> light).getFillColor());
	color.a += (this -> delta);
	if (color.a < 10) {
		color.a = 10;
		delta = 1;
	} else if (color.a > 100) {
		color.a = 100;
		delta = -1;
	}
	(this->light).setFillColor(color);

	(this->remainingTime) -= 1;

	if ((this->color) == TRAFFIC_LIGHT_COLOR::GREEN && (this -> remainingTime < 0) && !(this->checkCollision(obstacles))) {
		(this->color) = TRAFFIC_LIGHT_COLOR::RED;
		(this->remainingTime) = 200 + Helper::getRandomInteger(0, 100);
	}

	if ((this->color) == TRAFFIC_LIGHT_COLOR::RED) {
		if ((this->remainingTime) < 0) {
			this->color = TRAFFIC_LIGHT_COLOR::GREEN;
			this->remainingTime = 750 + Helper::getRandomInteger(0, 250);
		}
	}
	//std::cerr << (this->remainingTime) << ' ' << (this->checkCollision(obstacles)) << ' ' << (this->color) << '\n';
}

bool TrafficLight::checkCollision(const std::vector<Obstacle*>& obstacles) const {
	for (Obstacle* const& obstacle : obstacles)
		if ((this->light).getGlobalBounds().intersects(obstacle->getBounds()))
			return true;
	return false;
};

TRAFFIC_LIGHT_COLOR TrafficLight::getColor() const {
	return this->color;
};

bool TrafficLight::checkCollision(sf::FloatRect bounds) const {
	return (this->light).getGlobalBounds().intersects(bounds);
};

void TrafficLight::saveToTextFile(std::ofstream& outputFile) const {
	const sf::Color colorOfLight((this -> light).getFillColor());
	const sf::Vector2f position((this -> light).getPosition());
	outputFile << (this->color) << '\n'
			   << (int)colorOfLight.r << ' ' << (int)colorOfLight.g << ' ' << (int)colorOfLight.b << ' ' << (int)colorOfLight.a << '\n'
			   << position.x << ' ' << position.y << '\n'
			   << (this -> delta) << ' ' << (this -> remainingTime) << '\n';
};


sf::Vector2f TrafficLight::getPosition() const {
	return (this->light).getPosition();
};

void TrafficLight::readFromTextFile(std::ifstream& inputFile) {
	int red, blue, green, alpha;
	sf::Vector2f position;
	int color;
	inputFile >> color >> red >> blue >> green >> alpha >> position.x >> position.y >> (this -> delta) >> (this -> remainingTime);
	(this->light).setFillColor(sf::Color(red, green, blue, alpha));
	this->setPosition(position);
	this->color = (TRAFFIC_LIGHT_COLOR)(color);
};

std::ostream& operator << (std::ostream& outputStream, const TrafficLight& trafficLight) {
	outputStream << "TrafficLight({color = " << trafficLight.color;
	return outputStream << "})";
};