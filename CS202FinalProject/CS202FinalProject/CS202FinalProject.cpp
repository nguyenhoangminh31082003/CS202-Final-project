#include <iostream>

#include "MainProgram.h"

int randomIntegers(int l, int r) {
	int h = r - l + 1;
	long long result = 0;
	for (int i = 0; i < 3; ++i)
		result = (result * (RAND_MAX + 1) + rand()) % h;
	result += l;
	return result;
}

int main() {

	/*
	MainProgram mainProgram;

	mainProgram.test();
	//mainProgram.run();
	*/

	const int n = 20;
	const double speed_radius = 2, speed = 1e-12;
	sf::RenderWindow window(sf::VideoMode(1500, 1000), "Expanding circle", sf::Style::Close);
	sf::Event event;
	sf::CircleShape circles[n];
	sf::Vector2f positions[n];
	srand(time(NULL));
	for (int i = 0; i < n; ++i) {
		positions[i] = sf::Vector2f(randomIntegers(0, 1500), randomIntegers(0, 1000));
		circles[i].setFillColor(sf::Color::Transparent);
		circles[i].setOutlineThickness(10);
		//circles[i].setOutlineColor(sf::Color(randomIntegers(0, 255), randomIntegers(0, 255), randomIntegers(0, 255)));
		circles[i].setOutlineColor(sf::Color::Red);
		circles[i].setPointCount(50);
	}
	double radius = 0;
	while (window.isOpen()) {
		while (window.pollEvent(event)) {
			switch (event.type) {
			case sf::Event::Closed:
				window.close();
				break;
			}
		}
		if (radius < 1000) {
			radius += speed_radius;
			for (int i = 0; i < n; ++i) {
				circles[i].setRadius(radius);
				circles[i].setPosition(positions[i].x - radius, positions[i].y - radius);
				sf::Color color = circles[i].getOutlineColor();
				color.a -= speed;
				circles[i].setOutlineColor(color);
			}
		}
		window.clear();
		for (int i = 0; i < n; ++i)
			window.draw(circles[i]);
		window.display();
	}

	return 0;
}
