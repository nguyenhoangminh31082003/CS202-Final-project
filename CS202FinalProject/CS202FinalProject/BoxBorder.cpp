#include <cmath>

#include "BoxBorder.h"

BoxBorder::BoxBorder(): length(0) {
	(this->color) = sf::Color(0, 0, 0, 0);
};

BoxBorder::~BoxBorder() {};

void BoxBorder::setColor(const sf::Color& newColor) {
	(this->color) = newColor;
};

sf::Color BoxBorder::getColor() const {
	return this->color;
};
void BoxBorder::setSize(const double length) {
	(this->length) = std::max(0.0, length);
};

double BoxBorder::getSize() const {
	return this->length;
};

std::ostream& operator << (std::ostream& outputStream, const BoxBorder& boxBorder) {
	return outputStream << "BoxBorder({length :" << boxBorder.length << 
		                             ", color : Color(r :" << boxBorder.color.r <<
													 "b :" << boxBorder.color.b << 
													 "g :" << boxBorder.color.g <<
													 "a :" << boxBorder.color.a << ')'
						<< "})";
};