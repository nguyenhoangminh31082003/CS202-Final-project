#include "Scoreboard.h"

void loadScoreboardToVector(vector<pair<int, int> >& v)
{
	ifstream fin;
	fin.open("Data/Scoreboard/Scoreboard.txt");
	if (fin.is_open())
	{
		pair<int, int> x;
		while (fin >> x.first >> x.second)
		{
			v.push_back(x);
		}
		fin.close();
	}
	else
	{
		cout << "Can not open Data/Scoreboard/Scoreboard.txt" << endl;
	}
}

void saveVectorToScoreboard(vector<pair<int, int> >& v)
{
	ofstream fout;
	fout.open("Data/Scoreboard/Scoreboard.txt");
	if (fout.is_open())
	{
		for (int i = 0; i < min(10, (int)v.size()); i++)
		{
			fout << v[i].first << ' ' << v[i].second << '\n';
		}
		fout.close();
	}
	else
	{
		cout << "Can not open Data/Scoreboard/Scoreboard.txt" << endl;
	}

}

void saveScore(int level, int time)
{ 
	vector<std::pair<int, int> > score;
	loadScoreboardToVector(score);
	score.push_back(pair<int, int>(level, time));
	sort(score.begin(), score.end(), [&](const pair<int, int>& a, const pair<int, int>& b)
		{
			if (a.first == b.first) return a.second < b.second;
			return a.first > b.first;
		});
	saveVectorToScoreboard(score);
}

void showScoreboard(sf::RenderWindow* window)
{
	vector<std::pair<int, int> > score;
	loadScoreboardToVector(score);
	//Box levelTitleBox()

	while (window->isOpen())
	{
		sf::Event event;
		while (window->pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				window->close();
		}

		window->clear(sf::Color::White);

	}
}