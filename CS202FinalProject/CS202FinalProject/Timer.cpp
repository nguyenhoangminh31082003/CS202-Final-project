#include "Timer.h"

#include <iostream>

Timer::Timer() {
	this->recordTime = 0;
	this->running = false;
	(this->clock).restart();
}

Timer::~Timer() {}

bool Timer::record() {
	if (this->running) {
		(this->recordTime) += (this->clock).getElapsedTime().asSeconds();
		(this->clock).restart();
	}
	return this->running;
}

double Timer::getRecordTime() {
	this->record();
	return this->recordTime;
}

void Timer::stopTemporarily() {
	(this->recordTime) += (this->clock).getElapsedTime().asSeconds();
	(this->running) = false;
};

void Timer::run() {
	if (!(this->running)) {
		this->running = true;
		(this->clock).restart();
	}
};

void Timer::stop() {
	this->running = false;
	this->recordTime = 0;
};

void Timer::setRecordTime(const double recordTime) {
	(this->clock).restart();
	(this->recordTime) = recordTime;
};