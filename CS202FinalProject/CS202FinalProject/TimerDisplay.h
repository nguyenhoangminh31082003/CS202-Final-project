#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class TimerDisplay {
private:

	sf::Text text;
	sf::Font font;

public:

	TimerDisplay();
	void setContent(const double time);
	void render(sf::RenderTarget * const window);
	void setPosition(const double x, const double y);

};