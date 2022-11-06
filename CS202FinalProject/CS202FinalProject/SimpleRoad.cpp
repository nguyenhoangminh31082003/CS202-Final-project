#include "SimpleRoad.h"
#include "Helper.h"

SimpleRoad::SimpleRoad() {
	(this -> roadImage).setSize(sf::Vector2f(100, 800));
	(this -> roadImage).setFillColor(sf::Color(159, 159, 159));
};

SimpleRoad::SimpleRoad(const sf::Vector2f& position) {
	(this->roadImage).setSize(sf::Vector2f(100, 800));
	(this->roadImage).setPosition(position);

	const int color = ((int)position.x) % 255;

	(this->roadImage).setFillColor(sf::Color(color, color, color));
};


void SimpleRoad::render(sf::RenderTarget* const window) {
	window -> draw(this -> roadImage);
};