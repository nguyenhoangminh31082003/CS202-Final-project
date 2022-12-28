#pragma once

#include <iostream>
#include <cstring>
#include <string>
#include <map>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class RobotoFonts {
private:

	std::map<std::string, sf::Font> fonts;

	RobotoFonts();

	~RobotoFonts();

public:

	RobotoFonts(const RobotoFonts &fonts) = delete;
	RobotoFonts operator=(const RobotoFonts& robotoFonts) = delete;

	static RobotoFonts& getInstance();
	sf::Font const& getFont(const std::string& fontName) const;

};