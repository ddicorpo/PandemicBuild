#pragma once
#include <string>

class GameManager {
public:
	GameManager();
	~GameManager();
	void increseInfectionRate();
	void setInfectionRate(int i);
	void increaseOutbreakTracker();
	void setOutbreakTracker(int i);
	void updateCubes(std::string, int n);
	void setCubes(int red, int blue, int black, int yellow);
	void useStation();
	int getInfectionRate();
	int getOutbreakTracker();
private:
	int redCubes;
	int blueCubes;
	int yellowCubes;
	int blackCubes;
	int infectionRate[7];
	int infectionRateIndex = 0;
	int outbreakTracker = 0;
	int researchStations = 6;
};