#include "Timer.h"

#include <iostream>

Timer::Timer() {}

void Timer::start() {
	time = sf::Time::Zero;
	clock.restart();
}

float Timer::stop() {
	sf::Time result(time);
	time = sf::Time::Zero;
	return result.asSeconds();
}

void Timer::update() {
	if (clock.getElapsedTime().asSeconds() >= 1.00) {
		time += clock.getElapsedTime();
		clock.restart();
		//render();
	}
}

void Timer::render(sf::RenderTarget * const renderTarget) {
	float amount = time.asSeconds();
	int min = 0 + amount / 60;
	int sec = 0 + amount - min*60;
	std::cout << min << ":" << sec << "\n";
}
