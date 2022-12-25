#include "GrassRoad.h"

GrassRoad::GrassRoad() {
	if ((this->texture).loadFromFile("Data/images/Roads/GrassRoads/GrassRoad1.png"))
		std::cerr << "Texture is loaded successfully\n";
	(this->roadImage).setTexture(this->texture, true);
};

GrassRoad::~GrassRoad() {};

void GrassRoad::saveToTextFile(std::ofstream& outputFile) const {
	outputFile << "GrassRoad\n" << (this->roadImage).getPosition().x << ' ' << (this->roadImage).getPosition().y << '\n';
};

void GrassRoad::readFromTextFile(std::ifstream& inputFile) {
	sf::Vector2f position;
	inputFile >> position.x >> position.y;
	this->Road::setRoadPosition(position);
};

bool GrassRoad::checkCollision(const Player& player) const {
	return false;
};

void GrassRoad::update() {
};