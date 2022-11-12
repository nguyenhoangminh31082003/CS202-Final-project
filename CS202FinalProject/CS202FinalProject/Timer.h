#pragma once


#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>


class Timer
{
	sf::Clock clock; // the running clock
	sf::Time time; // the recorded time
	sf::RenderTarget* rdTarget;
public:

	//---------Constructor-----------------------------//

	//Constructor
	//Create a timer who will be rendered to a RenderTarget
	Timer(sf::RenderTarget* const rdTarget);

	//---------Destructor------------------------------//

	//Destructor
	~Timer() = default;

	//---------Member Functions------------------------//

	// Start the timer
	void start();
	// Update the recorded time, 
	void update();
	// Stops the timer, returns time elapsed as seconds
	float stop();
	// Draw the timer
	void render();
};