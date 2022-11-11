#pragma once

#include <string>

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Window/Mouse.hpp>
#include <SFML/Window/Window.hpp>

class Button
{
private:
	sf::Sprite buttonModel;
	sf::Texture buttonTexture;
	sf::Font buttonFont;
	sf::Color onColor;
	sf::Color offColor;
	sf::Color hoverColor;
	int buttonState;
public:
	// Constructor_________________________
	Button(std::string model_file_path);
	// Member functions____________________
	
	// set position for button
	void setPosition(sf::Vector2f pos);
	// return button's position
	sf::Vector2f getPosition();
	// draw button to a RenderTarget
	void render(sf::RenderTarget* const rdTarget);
	// update button state according to mouse position
	void updateStateByMouse(const sf::Window &window);

	// set hover color
	void setHoverColor(sf::Color color);
	// return button's state
	int getButtonState();
};

