#pragma once
#include <string>

class GameManager {
public:
	static GameManager &Instance() {
		static GameManager *instance = new GameManager;
		return *instance;
	}

	//getters
	int getInfectionRate(); 
	int getInfectionRateIndex();	//save
	int getOutbreakTracker();		//save
	int getAvailableStations();		//save
	int getRed();					//save
	int getBlue();					//save
	int getYellow();				//save
	int getBlack();					//save
	
	void displayCubeCount();
	
	//setters
	void increseInfectionRate();								//occurs when an epidemic card is drawn from the player deck
	void setInfectionRateIndex(int i);
	void increaseOutbreakTracker();								//occurs when there is an outbreak in a city
	void setOutbreakTracker(int i);								//to use with load
	void updateCubes(std::string color, int n);
	void setCubes(int red, int blue, int black, int yellow);	//to use when loading i guess
	void useStation();											//used to fullfill an option of building a research station
	void setRed(int r);
	void setBlue(int b);
	void setYellow(int y);
	void setBlack(int bl);
	
	//checkers
	bool checkCubes();			//check if cubes are available
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