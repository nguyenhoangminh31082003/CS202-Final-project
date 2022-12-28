#include "RobotoFonts.h"

RobotoFonts::RobotoFonts() {
	std::cerr << "Constructor of class RobotoFonts is running\n";
	(this->fonts)["black"].loadFromFile("Data/Fonts/Roboto/Roboto-Black.ttf");
	(this->fonts)["blackItalic"].loadFromFile("Data/Fonts/Roboto/Roboto-BlackItalic.ttf");
	(this->fonts)["bold"].loadFromFile("Data/Fonts/Roboto/Roboto-Bold.ttf");
	(this->fonts)["boldItalic"].loadFromFile("Data/Fonts/Roboto/Roboto-BoldItalic.ttf");
	(this->fonts)["italic"].loadFromFile("Data/Fonts/Roboto/Roboto-Italic.ttf");
	(this->fonts)["light"].loadFromFile("Data/Fonts/Roboto/Roboto-Light.ttf");
	(this->fonts)["lightItalic"].loadFromFile("Data/Fonts/Roboto/Roboto-LightItalic.ttf");
	(this->fonts)["medium"].loadFromFile("Data/Fonts/Roboto/Roboto-Medium.ttf");
	(this->fonts)["mediumItalic"].loadFromFile("Data/Fonts/Roboto/Roboto-MediumItalic.ttf");
	(this->fonts)["regular"].loadFromFile("Data/Fonts/Roboto/Roboto-Regular.ttf");
	(this->fonts)["thin"].loadFromFile("Data/Fonts/Roboto/Roboto-Thin.ttf");
	(this->fonts)["thinItalic"].loadFromFile("Data/Fonts/Roboto/Roboto-ThinItalic.ttf");
};

RobotoFonts::~RobotoFonts() {
	std::cerr << "Destructor of class RobotoFonts is running\n";
}

RobotoFonts& RobotoFonts::getInstance() {
	static RobotoFonts fonts;
	return fonts;
}

sf::Font const& RobotoFonts::getFont(const std::string& fontName) const {
	const std::map<std::string, sf::Font>::const_iterator font = (this->fonts).find(fontName);
	if (font == (this->fonts).end())
		return (this->fonts).begin()->second;
	return font->second;
}