#pragma once

#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

using namespace std;

struct InputTextBox {
private:
	int limit;
	bool choose;
	sf::Text text;
	string inputString;
	sf::RectangleShape box;
	sf::Color normal, hover;
public:
	InputTextBox();
	bool empty() const;
	string getString() const;
	void clearString();
	void setPosition(const double x, const double y);
	void setBoxColor(const sf::Color normal, const sf::Color hover);
	void setText(const sf::Font& font, const double textSize, const sf::Color color);
	void setBoxSize(const double width, const double height);
	void setLimit(const int limit);
	void update(sf::Event& event);
	void display(sf::RenderWindow& window);
};