#pragma once


#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>


class Timer {
private:
	bool running;
	sf::Clock clock;
	double recordTime;

	bool record();

public:
	
	Timer();
	~Timer();

	double getRecordTime();
	void stopTemporarily();
	void run();
	void stop();
	void setRecordTime(const double recordTime);

};