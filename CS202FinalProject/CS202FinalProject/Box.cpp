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

	sf::RectangleShape marginRectangle, borderRectangle, paddingRectangle, rectangle;
	sf::Vector2f v(0, 0);

	/* Set Color */
	marginRectangle.setFillColor((this -> margin).getColor());
	borderRectangle.setFillColor((this -> border).getColor());
	paddingRectangle.setFillColor((this -> padding).getColor());
	rectangle.setFillColor(this -> color);

	/* Set position */
	marginRectangle.setPosition(v);
	v.x += (this -> margin).getSize();
	v.y += (this -> margin).getSize();
	borderRectangle.setPosition(v);
	v.x += (this->border).getSize();
	v.y += (this->border).getSize();
	paddingRectangle.setPosition(v);
	v.x += (this->padding).getSize();
	v.y += (this->padding).getSize();
	rectangle.setPosition(v);

	/* Set size */
	v.x = height;
	v.y = width;
	rectangle.setSize(v);
	v.x += (this->padding).getSize();
	v.y += (this->padding).getSize();
	paddingRectangle.setSize(v);
	v.x += (this->border).getSize();
	v.y += (this->border).getSize();
	borderRectangle.setSize(v);
	v.x += (this->margin).getSize();
	v.y += (this->margin).getSize();
	marginRectangle.setSize(v);

	/* Draw rectangles */
	window->draw(marginRectangle);
	window->draw(borderRectangle);
	window->draw(paddingRectangle);
	window->draw(rectangle);

};