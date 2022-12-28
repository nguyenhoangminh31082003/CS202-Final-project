#include "Scoreboard.h"

vector<vector<double> > Scoreboard::loadScoreboard() {
	vector<vector<double> > score;
	for (int i = 0; ; i++) {
		ifstream fin;
		fin.open("Data/Scoreboard/level" + std::to_string(i) + ".txt");
		if (fin.is_open())
		{
			double x;
			vector<double> tmp;
			while (fin >> x)
			{
				tmp.push_back(x);
			}
			fin.close();
			score.push_back(tmp);
		} else {
			//std::cout << "Can't open file in loadScore()" << std::endl;
			break;
		}
	}
	return score;
}

vector<double> Scoreboard::loadScoreboard(int level) {
	level--;
	vector<double> score;
	ifstream fin;
	fin.open("Data/Scoreboard/level" + std::to_string(level) + ".txt");
	if (fin.is_open()) {
		double x;
		while (fin >> x) {
			score.push_back(x);
		}
		fin.close();
	} else {
		cout << "Can't open file in loadScoreboard(" + std::to_string(level) + ")" << endl;
		//exit(0);
	}
	return score;
}

void Scoreboard::saveScoreboard(vector<vector<double> >& score) {
	for (int i = 0; i < score.size(); i++) {
		ofstream fout;
		fout.open("Data/Scoreboard/level" + std::to_string(i) + ".txt");
		if (fout.is_open()) {
			for (int j = 0; j < min(3, (int)score[i].size()); j++)
			{
				fout << setprecision(6) << fixed << score[i][j] << '\n';
			}
			fout.close();
		} else {
			cout << "Can't open file in saveScoreboard(" + std::to_string(i) + ")" << endl;
			//exit(0);
		}
	}
}

void Scoreboard::saveScoreboard(vector<double>& score, int level) {
	ofstream fout;
	fout.open("Data/Scoreboard/level" + std::to_string(level) + ".txt");
	if (fout.is_open()) {
		for (int i = 0; i < min(3, (int)score.size()); i++) {
			fout << setprecision(6) << fixed << score[i] << '\n';
		}
		fout.close();
	} else {
		cout << "Can't open file in saveScoreboard(" + std::to_string(level) + ")" << endl;
		//exit(0);
	}
}

void Scoreboard::saveScore(int level, double time) {
	vector<double> score = loadScoreboard(level);
	score.push_back(time);
	sort(score.begin(), score.end());
	saveScoreboard(score, level);
}