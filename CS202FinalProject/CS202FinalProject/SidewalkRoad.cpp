#include "SidewalkRoad.h"

SidewalkRoad::SidewalkRoad() {
	if ((this->texture).loadFromFile("Data/images/Roads/SidewalkRoads/SidewalkRoad0.png"))
		std::cerr << "Texture is loaded successfully\n";
	(this->roadImage).setTexture(this->texture, true);
};

SidewalkRoad::~SidewalkRoad() {};

void SidewalkRoad::saveToTextFile(std::ofstream& outputFile) const {
	outputFile << "GrassRoad\n" << (this->roadImage).getPosition().x << ' ' << (this->roadImage).getPosition().y << '\n';
};

void SidewalkRoad::readFromTextFile(std::ifstream& inputFile) {
	sf::Vector2f position;
	inputFile >> position.x >> position.y;
	this->Road::setRoadPosition(position);
};

bool SidewalkRoad::checkCollision(const Player& player) const {
	return false;
};

void SidewalkRoad::update() {
};