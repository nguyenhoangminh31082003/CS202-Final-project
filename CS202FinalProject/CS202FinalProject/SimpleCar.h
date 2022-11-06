#pragma once

#include "Box.h"

class SimpleCar {
private:

	sf::RectangleShape carImage;
	double dx, dy;

public:

	SimpleCar();

	void render(sf::RenderTarget * const window);
	

};