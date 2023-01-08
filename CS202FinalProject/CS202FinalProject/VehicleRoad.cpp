#include <algorithm>

#include "VehicleRoad.h"
#include "Vehicle.h"

VehicleRoad::VehicleRoad(const std::vector<sf::Texture>& carModels): carModels(&carModels) {
	if ((this->texture).loadFromFile("Data/images/Roads/VehicleRoads/VehicleRoad0.png"))
		std::cerr << "Texture is loaded successfully\n";
	(this->roadImage).setTexture(this -> texture, true);
};

VehicleRoad::VehicleRoad(const int numberOfObstacles, const double speed, const std::vector<sf::Texture> &carModels): carModels(&carModels) {
	if ((this->texture).loadFromFile("Data/images/Roads/VehicleRoads/VehicleRoad0.png"))
		std::cerr << "Texture is loaded successfully\n";
	(this->roadImage).setTexture(this->texture, true);
	
	if (numberOfObstacles > MAXIMUM_NUMBER_OF_OBSTACLES)
		return;

	if (speed > 0)
		(this->trafficLight).movePosition(sf::Vector2f(1450, 0));

	const double northY = (this->roadImage).getPosition().y, westX = (this->roadImage).getPosition().x;

	std::vector<double> positions(7);

	Obstacle* obstacle = nullptr;

	this->clearAllObstacles();

	for (int i = 0; i < positions.size(); ++i)
		positions[i] = westX + i * 200;

	std::random_shuffle(positions.begin(), positions.end());

	for (int i = 0; i < numberOfObstacles; ++i) {
		obstacle = new Vehicle(speed, 0, carModels);
		//obstacle->setVelocity(speed, 0);
		obstacle->setPosition(positions[i], northY);
		(this->obstacles).push_back(obstacle);
	}
};

void VehicleRoad::movePositionVertically(const double dy) {
	(this->roadImage).move(sf::Vector2f(0, dy));
	(this->trafficLight).movePosition(sf::Vector2f(0, dy));
	for (Obstacle*& obstacle : (this->obstacles))
		obstacle->movePositionVertically(dy);
};

void VehicleRoad::clearAllObstacles() {
	while (!((this->obstacles).empty())) {
		delete obstacles.back();
		obstacles.pop_back();
	}
};

VehicleRoad::~VehicleRoad() {
	this->clearAllObstacles();
}

void VehicleRoad::render(sf::RenderTarget* const target) {
	target->draw(this->roadImage);
	std::sort((this->obstacles).begin(), (this->obstacles).end(), [&](const auto& L, const auto& R) -> bool {
		const sf::Vector2f l(L->getSouthWestCornerPosition()), r(R->getSouthWestCornerPosition());
		return std::make_pair(l.y, l.x) < std::make_pair(r.y, r.x);
	});
	for (Obstacle* const& obstacle : (this->obstacles))
		obstacle->render(target);
	(this->trafficLight).render(target);
};

void VehicleRoad::update(float dTime) {

	const double northY = (this->roadImage).getPosition().y,
				 southY = northY + (this->texture).getSize().y,
				 westX = (this->roadImage).getPosition().x,
				 eastX = (this->texture).getSize().x;

	(this->trafficLight).update(this -> obstacles);

	if ((this->trafficLight).getColor() == TRAFFIC_LIGHT_COLOR::GREEN) {
		for (Obstacle* const& obstacle : (this->obstacles)) {
			obstacle->movePosition();

			/*
			if (obstacle -> getYofNorthBound() > southY)
				obstacle -> setPosition(westX, northY - (obstacle -> getHeight()));
			else if (obstacle -> getYofSouthBound() < northY)
				obstacle -> setPosition(westX, southY);
			*/

			if (obstacle->getXofWestBound() > eastX && obstacle->getSpeedX() > 0) // right-to-left and passed EastX
			{
				obstacle->setPosition(westX - obstacle->getWidth(), northY);
			}
			else if (obstacle->getXofWestBound() < westX && obstacle->getSpeedX() < 0) // left-to-right and passed the WestX
				obstacle->setPosition(eastX + obstacle->getWidth(), northY);
		}
	}
};

bool VehicleRoad::checkCollision(const Player& player) const {
	for (Obstacle* const& obstacle : (this->obstacles))
		if (player.checkCollision(*obstacle)) {
			/*
			auto bounds = obstacle -> getBounds();
			std::cerr << bounds.left << ' ' << bounds.top << ' ' << bounds.height << ' ' << bounds.width << '\n';
			bounds = player.getBounds();
			std::cerr << bounds.left << ' ' << bounds.top << ' ' << bounds.height << ' ' << bounds.width << '\n';
			*/
			return true;
		}
	return false;
};


bool VehicleRoad::checkValid() const {
	const int numberOfObstacles = (this->obstacles).size();
	for (int i = 0, j; i < numberOfObstacles; ++i)
		for (j = 0; j < i; ++j)
			if (((this->obstacles)[j]->getSpeedY()) * ((this->obstacles)[i]->getSpeedY()) < 0)
				return false;
	return true;
};

void VehicleRoad::saveToTextFile(std::ofstream& outputFile) const {
	outputFile << "VehicleRoad\n" << (this->roadImage).getPosition().x << ' ' << (this->roadImage).getPosition().y << '\n' << (this->obstacles).size() << '\n';
	for (Obstacle* const& obstacle : (this->obstacles))
		obstacle->saveToTextFile(outputFile);
	(this->trafficLight).saveToTextFile(outputFile);
};

void VehicleRoad::readFromTextFile(std::ifstream& inputFile) {
	int numberOfObstacles;
	sf::Vector2f position;
	inputFile >> position.x >> position.y >> numberOfObstacles;
	std::cerr << "Number of obtascels: " << numberOfObstacles << '\n';
	this->setRoadPosition(position);
	this->clearAllObstacles();
	(this->obstacles).resize(numberOfObstacles, nullptr);
	for (Obstacle*& obstacle : (this->obstacles)) {
		std::cerr << "SIZE = " << (this -> carModels);
		obstacle = new Vehicle(*(this -> carModels));
		obstacle -> readFromTextFile(inputFile);
	}
	(this->trafficLight).readFromTextFile(inputFile);
};

void VehicleRoad::startSound() {};

void VehicleRoad::endSound() {};

std::ostream& operator << (std::ostream& outputStream, const VehicleRoad& vehicleRoad) {
	outputStream << "VehicleRoad({numberOfObstacles = " << vehicleRoad.obstacles.size();
	return outputStream << "})";
};