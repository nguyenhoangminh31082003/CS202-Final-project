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
	std::vector<Obstacle*> obstacles;

public:

	Road();
	Road(const sf::Vector2f &position);
	~Road();

	void setRoadPosition(const sf::Vector2f &position);
	void render(sf::RenderTarget * const window);
	void update();
	void appendObstacle(Obstacle * const obstacle);
	void appendCarWithSpeed(const double speed);
	bool checkCollision(const Player &player) const;

};