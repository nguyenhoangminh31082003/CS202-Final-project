#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class BoxBorder {
private:

	double left, top, right, bottom;
	sf::Color color;

public:

	BoxBorder();
	BoxBorder(double length);
	BoxBorder(const double left, const double top, const double right, const double bottom);

	~BoxBorder();

	void setColor(const sf::Color &newColor);
	sf::Color getColor() const;
	void setSize(const double length);
	
	double getLeft() const;
	double getTop() const;
	double getBottom() const;
	double getRight() const;
	
	void setLeft(const double length);
	void setTop(const double length);
	void setRight(const double length);
	void setBottom(const double length);

	friend std::ostream& operator << (std::ostream &outputStream, const BoxBorder &boxBorder);

};