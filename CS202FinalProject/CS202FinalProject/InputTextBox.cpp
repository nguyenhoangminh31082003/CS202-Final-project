#include <iostream>

#include "inputTextBox.h"
#include "RobotoFonts.h"

InputTextBox::InputTextBox() {
	this->limit = 0;
	this->choose = false;
	this->maximumNumberOfShownCharacters = 0;
}

void InputTextBox::setPosition(const double x, const double y) {
	(this->box).setPosition(sf::Vector2f(x, y));
	(this->text).setPosition(sf::Vector2f(x, y));
}

void InputTextBox::clearString() {
	(this->inputString).clear();
}

void InputTextBox::setBoxColor(const sf::Color normal, const sf::Color hover) {
	(this->normal) = normal;
	(this->hover) = hover;
	if (this->choose)
		(this->box).setFillColor(hover);
	else
		(this->box).setFillColor(normal);
};

void InputTextBox::setText(const sf::Font& font, const double textSize, const sf::Color color) {
	(this->text).setFont(font);
	(this->text).setCharacterSize(textSize);
	(this->text).setFillColor(color);
}

void InputTextBox::setLimit(const int limit) {
	(this->limit) = limit;
};

void InputTextBox::update(sf::Event& event) {
	switch (event.type) {
	case sf::Event::MouseButtonReleased:
		if (event.mouseButton.button == sf::Mouse::Left) {
			if ((this->box).getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y))) {
				(this->choose) = true;
				(this->box).setFillColor(this->hover);
			}
			else {
				(this->choose) = false;
				(this->box).setFillColor(this->normal);
			}
		}
	case sf::Event::TextEntered:
		if (this->choose) {
			const auto& t = event.text.unicode;
			if (t == '\b') {
				if (!(this->inputString).empty())
					(this->inputString).pop_back();
			} else if (0 < t && t < 128) {
				if ((this->inputString).size() < (this->limit))
					(this->inputString) += t;
			}
		}
		break;
	};
	(this->text).setString(this->inputString);
};

void InputTextBox::setBoxSize(const double width, const double height) {
	(this->box).setSize(sf::Vector2f(width, height));
}

std::string InputTextBox::getString() const {
	return this->inputString;
};

void InputTextBox::display(sf::RenderWindow& window) {
	window.draw(this->box);
	window.draw(this->text);
};

void InputTextBox::render(sf::RenderTarget* target) {
	target->draw(this -> box);

	const int length = (this -> inputString).size();

	if (length > (this->maximumNumberOfShownCharacters))
		(this->text).setString((this -> inputString).substr(length - (this -> maximumNumberOfShownCharacters), this -> maximumNumberOfShownCharacters));

	target->draw(this -> text);

	(this->text).setString(this->inputString);
};

bool InputTextBox::empty() const {
	return (this->inputString).empty();
}

std::ostream& operator << (std::ostream& outputStream, const InputTextBox& inputTextBox) {
	return outputStream << "InputTextBox";
};

void InputTextBox::setMaximumNumberOfShownCharacter(const int number) {
	this->maximumNumberOfShownCharacters = number;
};