#include "ScoreBoardState.h".h"
#include <sstream>
#include <cstdio>

ScoreBoardState::ScoreBoardState(std::map<std::string, Numbox*>* numboxes, Font* font)
{
	this->numboxes = numboxes;
	(*this->numboxes)["TOP 1"] = new Numbox(30, 100, 40, Color(15, 255, 80), Color(0, 0, 0, 0));
	this->numboxes->at("TOP 1")->setFont(*font);
	this->numboxes->at("TOP 1")->setPosition(Vector2f(210.f, 315.f));
	this->numboxes->at("TOP 1")->lockBox();

	(*this->numboxes)["TOP 2"] = new Numbox(30, 100, 40, Color(204, 48, 255), Color(0, 0, 0, 0));
	this->numboxes->at("TOP 2")->setFont(*font);
	this->numboxes->at("TOP 2")->setPosition(Vector2f(210.f, 378.f));
	this->numboxes->at("TOP 2")->lockBox();

	(*this->numboxes)["TOP 3"] = new Numbox(30, 100, 40, Color(254, 27, 23), Color(0, 0, 0, 0));
	this->numboxes->at("TOP 3")->setFont(*font);
	this->numboxes->at("TOP 3")->setPosition(Vector2f(210.f, 445.f));
	this->numboxes->at("TOP 3")->lockBox();

	this->updateData();
}

ScoreBoardState::~ScoreBoardState()
{
}

void ScoreBoardState::updateData()
{
	std::ifstream ifs("Data/highScore.txt");
	int dummy;
	ifs >> dummy;
	this->numboxes->at("TOP 1")->setInitText(std::to_string(dummy) + " pt" + ((dummy == 1) ? "" : "s"));
	ifs >> dummy;
	this->numboxes->at("TOP 2")->setInitText(std::to_string(dummy) + " pt" + ((dummy == 1) ? "" : "s"));
	ifs >> dummy;
	this->numboxes->at("TOP 3")->setInitText(std::to_string(dummy) + " pt" + ((dummy == 1) ? "" : "s"));

}
