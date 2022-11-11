#include "Button.h"

Button::Button(std::string model_file_path):buttonState(0)
{
	buttonTexture.loadFromFile(model_file_path);
	printf("Texture Size: %d %d", buttonTexture.getSize().x, buttonTexture.getSize().y);
	buttonModel.setTexture(buttonTexture, true);
}

void Button::setPosition(sf::Vector2f pos)
{
	buttonModel.setPosition(pos);
}

sf::Vector2f Button::getPosition()
{
	return buttonModel.getPosition();
}

void Button::render(sf::RenderTarget* const rdTarget)
{
	rdTarget->draw(buttonModel);
}

void Button::updateStateByMouse(const sf::Window &window)
{
	sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
	if (buttonModel.getGlobalBounds().contains(mouse_pos.x, mouse_pos.y))
	{
		setHoverColor(sf::Color::Cyan);
	}
}

void Button::setHoverColor(sf::Color color)
{
	hoverColor = color;
}

int Button::getButtonState()
{
	return buttonState;
}