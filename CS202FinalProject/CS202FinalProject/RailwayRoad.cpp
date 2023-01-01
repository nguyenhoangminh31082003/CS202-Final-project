#include "RailwayRoad.h"

RailwayRoad::RailwayRoad() {
	if ((this->texture).loadFromFile("Data/images/Roads/RailwayRoads/railway_road.png"))
		std::cerr << "Texture is loaded successfully\n";
	(this->roadImage).setTexture(this->texture, true);
};

void RailwayRoad::movePositionVertically(const double dy) {
	(this->roadImage).move(sf::Vector2f(0, dy));
};

RailwayRoad::~RailwayRoad() {
	//this->clearAllObstacles();
}

void RailwayRoad::render(sf::RenderTarget* const target) {
	target->draw(this->roadImage);
	/*
	std::sort((this->obstacles).begin(), (this->obstacles).end(), [&](const auto& L, const auto& R) -> bool {
		const sf::Vector2f l(L->getSouthWestCornerPosition()), r(R->getSouthWestCornerPosition());
		return std::make_pair(l.y, l.x) < std::make_pair(r.y, r.x);
		});
	for (Obstacle* const& obstacle : (this->obstacles))
		obstacle->render(target);
	(this->trafficLight).render(target);
	*/
};

void RailwayRoad::update(float dTime) {
	
};

bool RailwayRoad::checkCollision(const Player& player) const {
	return false;
};

void RailwayRoad::saveToTextFile(std::ofstream& outputFile) const {
	outputFile << "RailwayRoad\n" << (this->roadImage).getPosition().x << ' ' << (this->roadImage).getPosition().y << '\n';
	(this->train).saveToTextFile(outputFile);
};

void RailwayRoad::readFromTextFile(std::ifstream& inputFile) {
	sf::Vector2f position;
	inputFile >> position.x >> position.y;
	this->setRoadPosition(position);
	(this->train).readFromTextFile(inputFile);
};