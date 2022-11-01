#include <cmath>

#include "Box.h"

Box::Box(): height(0), width(0) {};

Box::Box(const double height, const double width) : height(std::max(0.0, height)), width(std::max(0.0, width)) {};

Box::Box(const double height, const double width, const std::string &content) : height(std::max(0.0, height)), width(std::max(0.0, width)), content(content) {};

Box::~Box() {};

void Box::setHeight(const double newHeight) {
	(this->height) = std::max(0.0, newHeight);
};

void Box::setWidth(const double newWidth) {
	(this->width) = std::max(0.0, newWidth);
};

double Box::getHeight() const {
	return this->height;
};

double Box::getWidth() const {
	return this->width;
};

void Box::render(sf::RenderTarget* const window) const {

};