#pragma once

#include "Animal.h"
#include "Road.h"

class GrassRoad : public Road {
private:

	const static int MAXIMUM_NUMBER_OF_OBSTACLES = 4;

	std::vector<Obstacle*> obstacles;
	const std::vector<sf::Texture>* AnimalModels;

	bool checkValid() const;
	void clearAllObstacles();
public:

	GrassRoad();
	GrassRoad(const int numberOfObstacles, const double speed, const std::vector<sf::Texture>& Models);
	~GrassRoad();

	bool checkCollision(const Player& player) const;
	void update(float dTime);
	void render(sf::RenderTarget* const window);
	void movePositionVertically(const double dy);
	void saveToTextFile(std::ofstream& outputFile) const;
	void readFromTextFile(std::ifstream& inputFile);

};