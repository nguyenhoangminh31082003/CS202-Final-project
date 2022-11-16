#pragma once
#include "State.h"
#include "Numbox.h"
#include <fstream>

class ScoreBoardState: public State
{
private:
	std::map<std::string, Numbox*>* numboxes;
public:
	ScoreBoardState(std::map<std::string, Numbox*>* numboxes, Font* font);
	virtual ~ScoreBoardState();

	void updateData();
};

