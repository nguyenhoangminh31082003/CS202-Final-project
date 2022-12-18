#pragma once

#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

struct InputTextBox {
private:
	int limit;
	bool choose;
	sf::Text text;
	std::string inputString;
	sf::RectangleShape box;
	sf::Color normal, hover;
public:
	InputTextBox();
	bool empty() const;
	std::string getString() const;
	void clearString();
	void setPosition(const double x, const double y);
	void setBoxColor(const sf::Color normal, const sf::Color hover);
	void setText(const sf::Font& font, const double textSize, const sf::Color color);
	void setBoxSize(const double width, const double height);
	void setLimit(const int limit);
	void update(sf::Event& event);
	void display(sf::RenderWindow& window);
	void render(sf::RenderTarget * target);

	friend std::ostream& operator << (std::ostream &outputStream, const InputTextBox &inputTextBox);
};