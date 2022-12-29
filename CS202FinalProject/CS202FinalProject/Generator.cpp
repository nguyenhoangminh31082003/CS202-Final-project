#include "Generator.h"

bool Generator::generateLevelTxt(std::string location, int numLevels, int firstLevelNumRoads,int init_minSpeed, int init_maxSpeed, int speedScale)
{
	if (firstLevelNumRoads > RoadCrossingGame::MAX_NUM_ROADS)
	{
		std::cerr << "generateLevelTxt FAILED, reason: firstLevelNumRoads exceeds MAX_NUM_ROADS\n";
		return false;
	}
	int nRoads = firstLevelNumRoads;
	int minSpeed = init_minSpeed;
	int maxSpeed = init_maxSpeed;

	for (int lvID = 0; lvID < numLevels; lvID++)
	{
		std::string path = location + "/level_" + Helper::convertIntToString(lvID) + ".txt";
		std::ofstream file(path);
		if (!file.is_open())
		{
			std::cerr << "generateLevelTxt FAILED, reason: could not create file \"" << path << "\"\n";
			return false;
		}
		file << nRoads << "\n\n";
		int n_obstacles = 0;
		int speed = 0;
		int direction = 0;
		float velocity = 0;
		for (int i = 0; i < nRoads; i++)
		{
			int roadType = Helper::getRandomInteger(0, 3);
			switch (roadType)
			{
			case 0:
				file << "SidewalkRoad\n\n";
				break;
			case 1:
				file << "VehicleRoad\n";
				n_obstacles = Helper::getRandomInteger(1, RoadCrossingGame::MAX_NUM_CAR_MODELS + 1);
				speed = Helper::getRandomInteger(minSpeed, maxSpeed + 1);
				direction = Helper::getRandomIntegerFromList(std::vector<int>({ -1, 1 }));
				velocity = 1.0f * speed / 1000 * direction;
				file << n_obstacles << " " << velocity << "\n\n";
				break;
			case 2:
				file << "GrassRoad\n";
				n_obstacles = Helper::getRandomInteger(1, RoadCrossingGame::MAX_NUM_CAR_MODELS + 1);
				speed = Helper::getRandomInteger(minSpeed, maxSpeed + 1);
				direction = Helper::getRandomIntegerFromList(std::vector<int>({ -1, 1 }));
				velocity = 1.0f * speed / 1000 * direction;
				file << n_obstacles << " " << velocity << "\n\n";
				break;
			default:
				std::cerr << "generateLevelTxt FAILED, reason : error roadType\n";
				return false;
				break;
			}
		}

		if (nRoads + 1 <= RoadCrossingGame::MAX_NUM_ROADS)
			nRoads += 1;
		minSpeed += speedScale;
		maxSpeed += speedScale;
	}

	return true;
}