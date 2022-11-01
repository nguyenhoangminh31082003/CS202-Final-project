#include <cmath>

#include "BoxBorder.h"

BoxBorder::BoxBorder(): left(0), top(0), right(0), bottom(0) {
	(this->color) = sf::Color(0, 0, 0, 0);
};

BoxBorder::BoxBorder(double length) {
	(this->top) = (this->bottom) = (this->left) = (this->right) = std::max(0.0, length);
	(this->color) = sf::Color(0, 0, 0, 0);
};

BoxBorder::BoxBorder(const double left, const double top, const double right, const double bottom) : left(left), top(top), right(right), bottom(bottom) {
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
	(this->top) = (this->bottom) = (this->left) = (this->right) = std::max(0.0, length);
};

double BoxBorder::getTop() const {
	return this->top;
};

double BoxBorder::getBottom() const {
	return this->bottom;
};

double BoxBorder::getLeft() const {
	return this->left;
};

double BoxBorder::getRight() const {
	return this->right;
};

void BoxBorder::setLeft(const double length) {
	(this->left) = std::max(length, 0.0);
};

void BoxBorder::setTop(const double length) {
	(this->top) = std::max(length, 0.0);
};

void BoxBorder::setRight(const double length) {
	(this->right) = std::max(length, 0.0);
};

void BoxBorder::setBottom(const double length) {
	(this->bottom) = std::max(length, 0.0);
};

std::ostream& operator << (std::ostream& outputStream, const BoxBorder& boxBorder) {
	return outputStream << "BoxBorder({top :" << boxBorder.top <<
									 ", right: " << boxBorder.right << 
									 ", bottom: " << boxBorder.bottom <<
									 ", left: " << boxBorder.left <<
		                             ", color : Color(r :" << boxBorder.color.r <<
													 "b :" << boxBorder.color.b << 
													 "g :" << boxBorder.color.g <<
													 "a :" << boxBorder.color.a << ')'
						<< "})";
};