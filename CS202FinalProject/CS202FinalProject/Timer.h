#pragma once


#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>


class Timer
{
	sf::Clock clock; // the running clock
	sf::Time time; // the recorded time
public:
	// Start the timer
	void start();
	// 
	void update();
	// Stops the timer, returns time elapsed as seconds
	float stop();
	// Draw the timer
	void display();
};