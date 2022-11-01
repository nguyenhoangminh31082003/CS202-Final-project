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

	~Box();

	void setHeight(const double newHeight);
	void setWidth(const double newWidth);
	double getHeight() const;
	double getWidth() const;

	void render(sf::RenderTarget * const window) const;

};