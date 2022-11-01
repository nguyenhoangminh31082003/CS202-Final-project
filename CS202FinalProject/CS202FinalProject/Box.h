#pragma once

#include <string>

#include "BoxBorder.h"

class Box {
private:

	double height, width;
	std::string content;
	sf::Color color;

public:

	BoxBorder padding, border, margin;

	Box();
	Box(const double height, const double width);
	Box(const double height, const double width, const std::string &content);
	Box(const double height, const double width, const std::string& content, const sf::Color &color);

	~Box();

	void setHeight(const double newHeight);
	void setWidth(const double newWidth);
	void setSize(const sf::Vector2f &size);
	double getHeight() const;
	double getWidth() const;

	void setColor(const sf::Color &color);

	void render(sf::RenderTarget * const window) const;

};