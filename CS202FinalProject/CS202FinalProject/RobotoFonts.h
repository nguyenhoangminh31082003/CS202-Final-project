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

	RobotoFonts() {
		std::cerr << "Constructor of class RobotoFonts is running\n";
		(this -> fonts)["black"].loadFromFile("Fonts/Roboto-Black.ttf");
		(this -> fonts)["blackItalic"].loadFromFile("Fonts/Roboto-BlackItalic.ttf");
		(this->fonts)["bold"].loadFromFile("Fonts / Roboto - Bold.ttf");
		(this->fonts)["boldItalic"].loadFromFile("Fonts/Roboto-BoldItalic.ttf");
		(this->fonts)["italic"].loadFromFile("Fonts/Roboto-Italic.ttf");
		(this->fonts)["light"].loadFromFile("Fonts/Roboto-Light.ttf");
		(this->fonts)["lightItalic"].loadFromFile("Fonts/Roboto-LightItalic.ttf");
		(this->fonts)["medium"].loadFromFile("Fonts/Roboto-Medium.ttf");
		(this->fonts)["mediumItalic"].loadFromFile("Fonts/Roboto-MediumItalic.ttf");
		(this->fonts)["regular"].loadFromFile("Fonts/Roboto-Regular.ttf");
		(this->fonts)["thin"].loadFromFile("Fonts/Roboto-Thin.ttf");
		(this->fonts)["thinItalic"].loadFromFile("Fonts/Roboto-ThinItalic.ttf");
	};

	~RobotoFonts() {
		std::cerr << "Destructor of class RobotoFonts is running\n";
	}

public:

	RobotoFonts(const RobotoFonts &fonts) = delete;
	RobotoFonts operator=(const RobotoFonts& robotoFonts) = delete;

	static RobotoFonts& getInstance() {
		static RobotoFonts fonts;
		return fonts;
	}

	sf::Font const& getFont(const std::string &fontName) const {
		const std::map<std::string, sf::Font>::const_iterator font = (this -> fonts).find(fontName);
		if (font == (this->fonts).end())
			return (this->fonts).begin()->second;
		return font->second;
	}

};