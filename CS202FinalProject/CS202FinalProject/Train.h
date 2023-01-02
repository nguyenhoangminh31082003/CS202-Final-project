#pragma once

#include <vector>

#include "RailRoadCar.h"

class Train : public Obstacle {
private:
public:

	Train();
	Train(const double dx, const double dy);

	void render(sf::RenderTarget* const target) const;

	double getWidth() const;
	sf::FloatRect getBounds() const;

	void saveToTextFile(std::ofstream& outputFile) const;
	void readFromTextFile(std::ifstream& inputFile);

	~Train();

	friend std::ostream& operator << (std::ostream& outputStream, const Train &train);

};