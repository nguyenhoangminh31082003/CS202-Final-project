#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include <vector>

#include "SimpleCar.h"

class SimpleRoad {
private:

	sf::RectangleShape roadImage;
	std::vector<SimpleCar> cars;

public:

	SimpleRoad();
	SimpleRoad(const sf::Vector2f &position);

	void setRoadPosition(const sf::Vector2f &position);
	void render(sf::RenderTarget * const window);
	void update();
	void appendCar(const SimpleCar &car);
	void appendCarWithSpeed(const double speed);

};