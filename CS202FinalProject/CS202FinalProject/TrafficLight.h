#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

enum TRAFFIC_LIGHT_COLOR {
	RED = 0,
	GREEN = 1
};

class TrafficLight {
private:

	TRAFFIC_LIGHT_COLOR color;
	sf::Texture redLight, greenLight;
	sf::Sprite image;

public:

	TrafficLight();

	void setPosition(const sf::Vector2f &position);
	void movePosition(const sf::Vector2f& d);

	void render(sf::RenderTarget * const target);

};