#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <SFML/Graphics.hpp>
#include "Box.h"
using namespace std;

void loadScoreboardToVector(vector<pair<int, int> >& v);
void saveVectorToScoreboard(vector<pair<int, int> >& v);
void saveScore(int level, int time);
void showScoreboard(sf::RenderWindow* window);