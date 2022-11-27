#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include <fstream>
#include <vector>

#include "Player.h"
#include "Obstacle.h"

class Road {
private:

	const static int MAXIMUM_NUMBER_OF_OBSTACLES = 4;

	sf::RectangleShape roadImage;
	std::vector<Obstacle*> obstacles;

	bool checkValid() const;
	void clearAllObstacles();

public:

	Road();
	Road(const sf::Vector2f &position);
	~Road();

	void setRoadPosition(const sf::Vector2f &position);
	void render(sf::RenderTarget * const window);
	void update();
	bool appendObstaclesWithSpeed(const double speed, const int numberOfObstacles);
	bool checkCollision(const Player &player) const;
	void saveToTextFile(std::ofstream &outputFile) const;
	void readFromTextFile(std::ifstream& inputFile);

};