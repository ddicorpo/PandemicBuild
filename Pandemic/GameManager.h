#pragma once
#include "InfectionCard.h"
#include <vector>


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

	bool getIsRedCured();			//save
	bool getIsRedErradicated();		//save
	bool getIsBlueCured();			//save
	bool getIsBlueErradicated();	//save
	bool getIsYellowCured();		//save
	bool getIsYellowErradicated();	//save
	bool getIsBlackCured();			//save
	bool getIsBlackErradicated();	//save
	
	bool isWin();

	void displayCubeCount();
	
	//setters
	void increseInfectionRate();								//occurs when an epidemic card is drawn from the player deck
	void setInfectionRateIndex(int i);
	void increaseOutbreakTracker();								//occurs when there is an outbreak in a city
	void setOutbreakTracker(int i);								//to use with load
	void updateCubes(std::string color, int n);
	void setCubes(int red, int blue, int black, int yellow);	//to use when loading i guess
	void useStation();											//used to fullfill an option of building a research station
	void setStationCount(int stations);
	void setRed(int r);
	void setBlue(int b);
	void setYellow(int y);
	void setBlack(int bl);
	void setIsRedCured(bool redCured);
	void setIsRedErradicated(bool redErradicated);
	void setIsBlueCured(bool blueCured);
	void setIsBlueErradicated(bool blueErradicated);
	void setIsYellowCured(bool yellowCured);
	void setIsYellowErradicated(bool yellowErradicated);
	void setIsBlackCured(bool blackCured);
	void setIsBlackErradicated(bool blackErradicated);
	void setCures(bool redCured, bool blueCured, bool yellowCured, bool blackCured);
	void setErradicated(bool redErradicated, bool blueErradicated, bool yellowErradicated, bool blackErradicated);

	std::vector<InfectionCard*> epishuffle(std::vector<InfectionCard*> draw, std::vector<InfectionCard*> discard);

	//checkers
	bool checkCubes();			//check if cubes are available
	bool checkOutbreak();

	void setvalidaction(bool tf);
	bool getvalidaction();
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

	bool isRedCured;
	bool isRedErradicated;
	bool isBlueCured;
	bool isBlueErradicated;
	bool isYellowCured;
	bool isYellowErradicated;
	bool isBlackCured;
	bool isBlackErradicated;

	bool isvalidaction;
};