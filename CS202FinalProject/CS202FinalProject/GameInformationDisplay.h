#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class GameInformationDislay {
private:

	sf::Text text;
	sf::Font font;

public:

	GameInformationDislay();
	void setContent(const double time, const int levelID);
	void render(sf::RenderTarget * const target) const;
	void setPosition(const double x, const double y);

};