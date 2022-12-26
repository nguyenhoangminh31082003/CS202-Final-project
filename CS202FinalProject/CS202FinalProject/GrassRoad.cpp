#include "GrassRoad.h"

GrassRoad::GrassRoad() {
	if ((this->texture).loadFromFile("Data/images/Roads/GrassRoads/GrassRoad.png"))
		std::cerr << "Texture is loaded successfully\n";
	(this->roadImage).setTexture(this->texture, true);
};

GrassRoad::GrassRoad(const int numberOfObstacles, const double speed, const std::vector<sf::Texture>& Models): AnimalModels(&Models)
{
	if ((this->texture).loadFromFile("Data/images/Roads/GrassRoads/GrassRoad.png"))
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
		obstacle = new Animal(speed, 0, Models, 4, 4.0f, 1);
		//obstacle->setVelocity(speed, 0);
		obstacle->setPosition(positions[i], northY);
		(this->obstacles).push_back(obstacle);
	}
};

bool GrassRoad::checkValid() const {
	const int numberOfObstacles = (this->obstacles).size();
	for (int i = 0, j; i < numberOfObstacles; ++i)
		for (j = 0; j < i; ++j)
			if (((this->obstacles)[j]->getSpeedY()) * ((this->obstacles)[i]->getSpeedY()) < 0)
				return false;
	return true;
};

void GrassRoad::clearAllObstacles() {
	while (!((this->obstacles).empty())) {
		delete obstacles.back();
		obstacles.pop_back();
	}
};

GrassRoad::~GrassRoad()
{
	this->clearAllObstacles();
};

void GrassRoad::saveToTextFile(std::ofstream& outputFile) const {
	outputFile << "GrassRoad\n" << (this->roadImage).getPosition().x << ' ' << (this->roadImage).getPosition().y << '\n';
};

void GrassRoad::readFromTextFile(std::ifstream& inputFile) {
	sf::Vector2f position;
	inputFile >> position.x >> position.y;
	this->Road::setRoadPosition(position);
};

bool GrassRoad::checkCollision(const Player& player) const {
	for (Obstacle* const& obstacle : (this->obstacles))
		if (player.checkCollision(*obstacle))
			return true;
	return false;
};

void GrassRoad::update(float dTime) {

	const double northY = (this->roadImage).getPosition().y,
		southY = northY + (this->texture).getSize().y,
		westX = (this->roadImage).getPosition().x,
		eastX = (this->texture).getSize().x;

	for (Obstacle* const& obstacle : (this->obstacles)) {
		obstacle->movePosition_wAnim(dTime);

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
		else
			if (obstacle->getXofWestBound() < westX && obstacle->getSpeedX() < 0) // left-to-right and passed the WestX
				obstacle->setPosition(eastX + obstacle->getWidth(), northY);
	}
};

void GrassRoad::render(sf::RenderTarget* const window) {
	window->draw(this->roadImage);
	for (Obstacle* const& obstacle : (this->obstacles))
		obstacle->render(window);
};

void GrassRoad::movePositionVertically(const double dy) {
	(this->roadImage).move(sf::Vector2f(0, dy));
	for (Obstacle*& obstacle : (this->obstacles))
	{
		obstacle->movePositionVertically(dy);
		std::cerr << obstacle->getPosition().x << " " << obstacle->getPosition().y << "\n";
	}

};