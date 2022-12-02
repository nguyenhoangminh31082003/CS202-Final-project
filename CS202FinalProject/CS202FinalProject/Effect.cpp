#include "Effect.h"

Effect::Effect() {};

Effect::~Effect() {};

bool Effect::checkFinished() const {
	return true;
}

void Effect::update() {};

std::ostream& operator << (std::ostream& outputStream, const Effect& effect) {
	return outputStream << "Effect({})";
};