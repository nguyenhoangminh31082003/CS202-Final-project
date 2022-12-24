#include <algorithm>

#include "Effects.h"

Effects::Effects() {};

Effects::~Effects() {
	this->clearAllEffects();
};


void Effects::addNewEffect(Effect* const effect) {
	(this->effects).push_back(effect);
};

void Effects::clearAllEffects() {
	while (!(this->effects).empty()) {
		delete (this->effects).back();
		(this->effects).pop_back();
	}
}

void Effects::render(sf::RenderTarget* const target) const {
	for (Effect* const& effect : (this->effects))
		effect->render(target);
};

int Effects::getNumberOfEffects() const {
	return (this->effects).size();
};

void Effects::update() {
	for (int i = (this->getNumberOfEffects()) - 1; i >= 0; --i) {
		(this->effects)[i]->update();
		if ((this->effects)[i]->checkFinished()) {
			std::swap((this -> effects)[i], (this -> effects).back());
			delete (this->effects).back();
			(this->effects).pop_back();
		}
	}
};


bool Effects::checkEmpty() const {
	return (this->effects).empty();
};

std::ostream& operator << (std::ostream& outputStream, const Effects& effects) {
	return outputStream << "Effects({size = " << effects.getNumberOfEffects() << "})";
};