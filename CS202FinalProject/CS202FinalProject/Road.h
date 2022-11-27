#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include <vector>

#include "Player.h"
#include "Obstacle.h"

class Road {
private:

	sf::RectangleShape roadImage;
	std::vector<Obstacle*> obstacles, waitingObstacles;

	bool checkValid() const;
	void clearAllActiveObstacles();
	void clearAllWaitingObstacles();
	void clearAllObstacles();
	bool startObstacleFromWaitingList();

public:

	Road();
	Road(const sf::Vector2f &position);
	~Road();

	void setRoadPosition(const sf::Vector2f &position);
	void render(sf::RenderTarget * const window);
	void update();
	void appendObstaclesWithSpeed(const double speed, const int numberOfObstacles);
	bool checkCollision(const Player &player) const;

};