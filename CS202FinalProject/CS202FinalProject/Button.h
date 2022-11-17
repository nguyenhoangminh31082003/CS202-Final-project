#pragma once

#include <string>
#include <vector>
#include <iostream>

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Window/Mouse.hpp>
#include <SFML/Window/Window.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class Button
{
private:
	sf::Sprite buttonModel;
	std::vector<sf::Texture> buttonTexture;
	//sf::Font buttonFont;
	//sf::Color onColor;
	//sf::Color offColor;
	//sf::Color hoverColor;
	int buttonState;
public:
	// Constructor_________________________
	Button(float scale, float posX, float posY, std::string model_folder_path);
	Button(float width, float height, float posX, float posY, std::string model_folder_path);
	// Member functions____________________
	
	// set position for button
	void setPosition(sf::Vector2f pos);
	// return button's position
	sf::Vector2f getPosition() const;
	// draw button to a RenderTarget
	void render(sf::RenderWindow* const rdTarget);
	// update button state according to mouse position
	void updateStateByMouse(const sf::RenderWindow &window);
	// return button's state
	int getButtonState();
};

