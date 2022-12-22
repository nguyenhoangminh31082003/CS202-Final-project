#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>

using namespace std;

class Scoreboard
{
public:
	vector<vector<double> > loadScoreboard();
	vector<double> loadScoreboard(int level);
	void saveScoreboard(vector<vector<double> >& score);
	void saveScoreboard(vector<double>& score, int level);
	void saveScore(int level, double time);
};