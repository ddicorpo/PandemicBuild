#pragma once
#include <string>

class GameManager {
public:
	static GameManager &Instance() {
		static GameManager *instance = new GameManager;
		return *instance;
	}
	void increseInfectionRate(); //occurs when an epidemic card is drawn from the player deck
	void increaseOutbreakTracker(); //occurs when there is an outbreak in a city
	void setOutbreakTracker(int i);
	void updateCubes(std::string color, int n);
	void setCubes(int red, int blue, int black, int yellow); //to use when loading i guess
	void useStation();	//used to fullfill an option of building a research station
	int getInfectionRate();
	int getOutbreakTracker(); 
	int getAvailableStations();
	void displayCubeCount();
	bool checkCubes();	//check if cubes are available
	bool checkOutbreak();
private:
	GameManager();
	~GameManager();
	GameManager(const GameManager &old);
	const GameManager &operator=(const GameManager &old);

	int redCubes;
	int blueCubes;
	int yellowCubes;
	int blackCubes;
	int infectionRate[7];
	int infectionRateIndex;
	int outbreakTracker;
	int researchStations;
};