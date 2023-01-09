#include <algorithm>

#include "DesertRoad.h"
#include "Cactus.h"

DesertRoad::DesertRoad() {
	if ((this->texture).loadFromFile("Data/images/Roads/DesertRoads/DesertRoad.png"))
		std::cerr << "Texture is loaded successfully\n";
	(this->roadImage).setTexture(this->texture, true);
};

DesertRoad::DesertRoad(const int numberOfObstacles) {
	if ((this->texture).loadFromFile("Data/images/Roads/DesertRoads/DesertRoad.png"))
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
		obstacle = new Cactus();
		//obstacle->setVelocity(speed, 0);
		obstacle->setPosition(positions[i], northY);
		(this->obstacles).push_back(obstacle);
	}
};

void DesertRoad::movePositionVertically(const double dy) {
	(this->roadImage).move(sf::Vector2f(0, dy));
	for (Obstacle*& obstacle : (this->obstacles))
		obstacle->movePositionVertically(dy);
};

void DesertRoad::clearAllObstacles() {
	while (!((this->obstacles).empty())) {
		delete obstacles.back();
		obstacles.pop_back();
	}
};

DesertRoad::~DesertRoad() {
	this->clearAllObstacles();
}

void DesertRoad::render(sf::RenderTarget* const target) {
	target->draw(this->roadImage);
	std::sort((this->obstacles).begin(), (this->obstacles).end(), [&](const auto& L, const auto& R) -> bool {
		const sf::Vector2f l(L->getSouthWestCornerPosition()), r(R->getSouthWestCornerPosition());
		return std::make_pair(l.y, l.x) < std::make_pair(r.y, r.x);
		});
	for (Obstacle* const& obstacle : (this->obstacles))
		obstacle->render(target);
};

void DesertRoad::update(float dTime) {
};

bool DesertRoad::checkCollision(const Player& player) const {
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


bool DesertRoad::checkValid() const {
	const int numberOfObstacles = (this->obstacles).size();
	for (int i = 0, j; i < numberOfObstacles; ++i)
		for (j = 0; j < i; ++j)
			if (((this->obstacles)[j]->getSpeedY()) * ((this->obstacles)[i]->getSpeedY()) < 0)
				return false;
	return true;
};

void DesertRoad::saveToTextFile(std::ofstream& outputFile) const {
	outputFile << "VehicleRoad\n" << (this->roadImage).getPosition().x << ' ' << (this->roadImage).getPosition().y << '\n' << (this->obstacles).size() << '\n';
	for (Obstacle* const& obstacle : (this->obstacles))
		obstacle->saveToTextFile(outputFile);
};

void DesertRoad::readFromTextFile(std::ifstream& inputFile) {
	int numberOfObstacles;
	sf::Vector2f position;
	inputFile >> position.x >> position.y >> numberOfObstacles;
	std::cerr << "Number of obtascels: " << numberOfObstacles << '\n';
	this->setRoadPosition(position);
	this->clearAllObstacles();
	(this->obstacles).resize(numberOfObstacles, nullptr);
	for (Obstacle*& obstacle : (this->obstacles)) {
		obstacle = new Cactus();
		obstacle->readFromTextFile(inputFile);
	}
};

void DesertRoad::startSound() {};

void DesertRoad::endSound() {};