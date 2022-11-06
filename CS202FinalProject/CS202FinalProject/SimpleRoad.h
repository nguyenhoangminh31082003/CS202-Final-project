#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class SimpleRoad {
private:

	sf::RectangleShape roadImage;

public:

	SimpleRoad();
	SimpleRoad(const sf::Vector2f &position);

	void render(sf::RenderTarget * const window);

};