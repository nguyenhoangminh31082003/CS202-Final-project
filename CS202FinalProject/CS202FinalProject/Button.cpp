#include "Button.h"

Button::Button(float scale, float posX, float posY, std::string model_folder_path) :
	buttonState(0), buttonTexture(3, sf::Texture())
{
	for (int i = 0; i < 3; i++)
	{
		if (!buttonTexture[i].loadFromFile(model_folder_path + (const char)(i + 48) + ".png"))
			buttonTexture[i] = buttonTexture[0];
	}
	buttonModel.setTexture(buttonTexture[0], true);
	buttonModel.setScale(scale, scale);
	this->setPosition(sf::Vector2f(posX, posY));
}

Button::Button(float width, float height, float posX, float posY, std::string model_folder_path) :
	buttonState(0), buttonTexture(3, sf::Texture())
{
	for (int i = 0; i < 3; i++)
	{
		if (!buttonTexture[i].loadFromFile(model_folder_path + (const char)(i + 48) + ".png"))
			buttonTexture[i] = buttonTexture[0];
	}
	buttonModel.setTexture(buttonTexture[0], true);
	buttonModel.setScale(width / buttonModel.getGlobalBounds().width, height / buttonModel.getGlobalBounds().width);
	this->setPosition(sf::Vector2f(posX, posY));
}

void Button::setPosition(sf::Vector2f pos) {
	buttonModel.setPosition(pos);
}

sf::Vector2f Button::getPosition() const {
	return buttonModel.getPosition();
}

void Button::render(sf::RenderWindow* const rdTarget) {
	updateStateByMouse(*rdTarget);
	buttonModel.setTexture(buttonTexture[buttonState], true);
	rdTarget->draw(buttonModel);
}

void Button::updateStateByMouse(const sf::RenderWindow &window) {
	sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
//<<<<<<< Updated upstream
	if (buttonModel.getGlobalBounds().contains(mouse_pos.x, mouse_pos.y)) {
		buttonState = 1;
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			buttonState = 2;
	} else 
		buttonState = 0;
//=======
	if (buttonModel.getGlobalBounds().contains(mouse_pos.x, mouse_pos.y))
	{
		buttonState = 1;//HOVER
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			buttonState = 2;//PRESSED LEFT
	}
	else
	{
		buttonState = 0;//UNTOUCHED
//>>>>>>> Stashed changes
	}
}

int Button::getButtonState() {
	return buttonState;
}