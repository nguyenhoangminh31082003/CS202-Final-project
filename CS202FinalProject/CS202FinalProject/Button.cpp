#include "Button.h"

Button::Button(const double scale, const double positionX, const double positionY, const std::string &model_folder_path) :
	buttonState(0), buttonTexture(3, sf::Texture())
{
	for (int i = 0; i < 3; i++) {
		if (!buttonTexture[i].loadFromFile(model_folder_path + (const char)(i + 48) + ".png"))
			buttonTexture[i] = buttonTexture[0];
		std::cerr << "Path " << (model_folder_path + (const char)(i + 48) + ".png") << '\n';
	}
	buttonModel.setTexture(buttonTexture[0], true);
	buttonModel.setScale(scale, scale);
	this->setPosition(sf::Vector2f(positionX, positionY));
}

Button::Button(const double width, const double height, const double posX, const double posY, const std::string &model_folder_path) :
	buttonState(0), buttonTexture(3, sf::Texture())
{
	for (int i = 0; i < 3; i++) {
		if (!buttonTexture[i].loadFromFile(model_folder_path + (const char)(i + 48) + ".png"))
			buttonTexture[i] = buttonTexture[0];
	}
	buttonModel.setTexture(buttonTexture[0], true);
	buttonModel.setScale(width / buttonModel.getGlobalBounds().width, height / buttonModel.getGlobalBounds().width);
	this->setPosition(sf::Vector2f(posX, posY));
}

void Button::setPosition(const sf::Vector2f &position) {
	(this -> buttonModel).setPosition(position);
}

sf::Vector2f Button::getPosition() const {
	return (this -> buttonModel).getPosition();
}

void Button::render(sf::RenderWindow* const rdTarget) {
	updateStateByMouse(*rdTarget);
	buttonModel.setTexture(buttonTexture[buttonState], true);
	rdTarget->draw(buttonModel);
}

void Button::updateStateByMouse(const sf::RenderWindow &window) {
	sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
	if (buttonModel.getGlobalBounds().contains(mouse_pos.x, mouse_pos.y)) {
		buttonState = 1;
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			buttonState = 2;
	} else 
		buttonState = 0;
	if (buttonModel.getGlobalBounds().contains(mouse_pos.x, mouse_pos.y)) {
		buttonState = 1;//HOVER
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			buttonState = 2;//PRESSED LEFT
	} else {
		buttonState = 0;//UNTOUCHED
	}
}

int Button::getButtonState() const {
	return this -> buttonState;
}

void Button::update(const sf::Vector2f& mousePosition) {
	this->updateByMouse(mousePosition);
	(this -> buttonModel).setTexture(buttonTexture[buttonState], true);
};

void Button::render(sf::RenderTarget* const target) {
	target->draw(this -> buttonModel);
};

void Button::updateByMouse(const sf::Vector2f mousePosition) {
	if ((this -> buttonModel).getGlobalBounds().contains(mousePosition.x, mousePosition.y)) {
		this -> buttonState = 1;
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			this -> buttonState = 2;
	} else
		this -> buttonState = 0;
	if ((this -> buttonModel).getGlobalBounds().contains(mousePosition.x, mousePosition.y)) {
		this -> buttonState = 1;//HOVER
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			this -> buttonState = 2;//PRESSED LEFT
	} else {
		this -> buttonState = 0;//UNTOUCHED
	}
};