#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include <iostream>

class Effect {
private:
public:

	Effect();
	virtual ~Effect();

	virtual bool checkFinished() const;
	virtual void update();
	virtual void render(sf::RenderTarget* const target) = 0;

	friend std::ostream& operator << (std::ostream &outputStream, const Effect &effect);

};