#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class BoxBorder {
private:

	double length;
	sf::Color color;

public:

	BoxBorder();
	~BoxBorder();

	void setColor(const sf::Color &newColor);
	sf::Color getColor() const;
	void setSize(const double length);
	double getSize() const;

	friend std::ostream& operator << (std::ostream &outputStream, const BoxBorder &boxBorder);

};