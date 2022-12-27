#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include "Obstacle.h"

enum TRAFFIC_LIGHT_COLOR {
	RED = 0,
	GREEN = 1
};

class TrafficLight {
private:

	TRAFFIC_LIGHT_COLOR color;
	sf::Texture redLight, greenLight;
	sf::Sprite image;
	sf::RectangleShape light;
	double delta, remainingTime;

	bool checkCollision(const std::vector<Obstacle*> &obstacles) const;

public:

	TrafficLight();

	void setPosition(const sf::Vector2f &position);
	void movePosition(const sf::Vector2f& d);

	void update(const std::vector<Obstacle*>& obstacles);

	void render(sf::RenderTarget * const target);

	TRAFFIC_LIGHT_COLOR getColor() const;

	bool checkCollision(sf::FloatRect bounds) const;

};