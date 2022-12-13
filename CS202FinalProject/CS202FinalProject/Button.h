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

enum BUTTON_STATE {NORMAL = 0, HOVER = 1, LEFT_PRESSED = 2};

class Button {
private:
	sf::Sprite buttonModel;
	std::vector<sf::Texture> buttonTexture;
	//sf::Font buttonFont;
	//sf::Color onColor;
	//sf::Color offColor;
	//sf::Color hoverColor;
	BUTTON_STATE buttonState;

	void updateByMouse(const sf::Vector2f &mousePosition);

public:
	/* Constructors */
	Button(const double scale, const double positionX, const double positionY, const std::string &model_folder_path);
	Button(const double width, const double height, const double posX, const double posY, const std::string &model_folder_path);
	/* Member methods */
	
	/* set position for button */
	void setPosition(const sf::Vector2f &position);
	/* return button's position */
	sf::Vector2f getPosition() const;
	// draw button to a RenderTarget
	void render(sf::RenderWindow* const rdTarget);
	// update button state according to mouse position
	void updateStateByMouse(const sf::RenderWindow &window);
	/* return button's state */
	BUTTON_STATE getButtonState() const;

	void update(const sf::Vector2f &mousePosition);
	void render(sf::RenderTarget * const target);

	bool checkPressedLeft() const;
};

