#include <algorithm>

#include "GardenRoad.h"
#include "PoisoningApple.h"

GardenRoad::GardenRoad() {
	if ((this->texture).loadFromFile("Data/images/Roads/GardenRoads/GardenRoad.png"))
		std::cerr << "Texture is loaded successfully\n";
	(this->roadImage).setTexture(this->texture, true);
};

GardenRoad::GardenRoad(const int numberOfObstacles) {
	if ((this->texture).loadFromFile("Data/images/Roads/GardenRoads/GardenRoad.png"))
		std::cerr << "Texture is loaded successfully\n";
	(this->roadImage).setTexture(this->texture, true);

	if (numberOfObstacles > MAXIMUM_NUMBER_OF_OBSTACLES)
		return;

	const double northY = (this->roadImage).getPosition().y, westX = (this->roadImage).getPosition().x;

	std::vector<double> positions(7);

	Obstacle* obstacle = nullptr;

	this->clearAllObstacles();

	for (int i = 0; i < positions.size(); ++i)
		positions[i] = westX + i * 200;

	std::random_shuffle(positions.begin(), positions.end());

	for (int i = 0; i < numberOfObstacles; ++i) {
		obstacle = new PoisoningApple();
		//obstacle->setVelocity(speed, 0);
		obstacle->setPosition(positions[i], northY);
		(this->obstacles).push_back(obstacle);
	}
};

void GardenRoad::movePositionVertically(const double dy) {
	(this->roadImage).move(sf::Vector2f(0, dy));
	for (Obstacle*& obstacle : (this->obstacles))
		obstacle->movePositionVertically(dy);
};

void GardenRoad::clearAllObstacles() {
	while (!((this->obstacles).empty())) {
		delete obstacles.back();
		obstacles.pop_back();
	}
};

GardenRoad::~GardenRoad() {
	this->clearAllObstacles();
}

void GardenRoad::render(sf::RenderTarget* const target) {
	target->draw(this->roadImage);
	std::sort((this->obstacles).begin(), (this->obstacles).end(), [&](const auto& L, const auto& R) -> bool {
		const sf::Vector2f l(L->getSouthWestCornerPosition()), r(R->getSouthWestCornerPosition());
		return std::make_pair(l.y, l.x) < std::make_pair(r.y, r.x);
		});
	for (Obstacle* const& obstacle : (this->obstacles))
		obstacle->render(target);
};

void GardenRoad::update(float dTime) {
};

bool GardenRoad::checkCollision(const Player& player) {
	for (int i = 0; i < (this->obstacles).size(); ++i) {
		if (player.checkCollision(*(this -> obstacles)[i])) {
			std::swap((this -> obstacles)[i], (this -> obstacles).back());
			delete (this->obstacles).back();
			(this->obstacles).pop_back();
			return true;
		}
	}
	return false;
};


bool GardenRoad::checkValid() const {
	const int numberOfObstacles = (this->obstacles).size();
	for (int i = 0, j; i < numberOfObstacles; ++i)
		for (j = 0; j < i; ++j)
			if (((this->obstacles)[j]->getSpeedY()) * ((this->obstacles)[i]->getSpeedY()) < 0)
				return false;
	return true;
};

void GardenRoad::saveToTextFile(std::ofstream& outputFile) const {
	outputFile << "GardenRoad\n" << (this->roadImage).getPosition().x << ' ' << (this->roadImage).getPosition().y << '\n' << (this->obstacles).size() << '\n';
	for (Obstacle* const& obstacle : (this->obstacles))
		obstacle->saveToTextFile(outputFile);
};

void GardenRoad::readFromTextFile(std::ifstream& inputFile) {
	int numberOfObstacles;
	sf::Vector2f position;
	inputFile >> position.x >> position.y >> numberOfObstacles;
	std::cerr << "Number of obtascels: " << numberOfObstacles << '\n';
	this->setRoadPosition(position);
	this->clearAllObstacles();
	(this->obstacles).resize(numberOfObstacles, nullptr);
	for (Obstacle*& obstacle : (this->obstacles)) {
		obstacle = new PoisoningApple();
		obstacle->readFromTextFile(inputFile);
	}
};

void GardenRoad::startSound() {};

void GardenRoad::endSound() {};

std::string GardenRoad::getRoadType() const {
	return "GardenRoad";
};