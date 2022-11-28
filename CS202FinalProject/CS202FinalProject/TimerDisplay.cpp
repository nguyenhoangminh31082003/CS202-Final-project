#include <sstream>
#include <iomanip>

#include "TimerDisplay.h"

TimerDisplay::TimerDisplay() {
	(this->font).loadFromFile("Data/Fonts/Roboto/Roboto-Black.ttf");
	(this->text).setFont(this -> font);
	(this->text).setCharacterSize(30);
	(this->text).setFillColor(sf::Color::White);
};

void TimerDisplay::render(sf::RenderTarget* const target) const {
	target -> draw(this -> text);
};

void TimerDisplay::setContent(const double time) {
	std::stringstream ss;
	ss.setf(std::ios::fixed, std::ios::floatfield);
	ss.precision(3);
	ss << "Time:\n" << time << " seconds";
	(this->text).setString(ss.str());
};

void TimerDisplay::setPosition(const double x, const double y) {
	(this->text).setPosition(x, y);
};