#pragma once 
#include <vector>
#include <iostream>
#include <string>

class MapCity
{
private:
	std::string name;
	std::string region;
	std::vector<MapCity*> neighbours;
	bool isInfected; 
 
	int blueCubes; 
	int redCubes; 
	int blackCubes;
	int yellowCubes; 

	bool hasResearchStation = false;

public:
	MapCity::MapCity(std::string name, std::string region, std::vector <MapCity*> neighbours);
	MapCity::MapCity(std::string name);
	MapCity::MapCity();

	std::string getName();
	std::string getRegion();
	std::vector<MapCity*> getNeighbours();

	void setNeighbours(std::vector <MapCity*> neighbours);
	void getListOfNeighbours();
	void addBlackCube(); 
	void addBlueCube();
	void addRedCube();
	void addYellowCube();

	void displayCubes();

	void removeBlackCube();
	void removeBlueCube();
	void removeRedCube();
	void removeYellowCube();
	
	bool getInfected();

	int getBlackCubes();
	int getBlueCubes();
	int getYellowCubes();
	int getRedCubes();

	int getAllCubes();

	void outbreak(std::string cubeColor);
	void epidemic(std::string cubeColor);

	void setResearchStation();
	void load(int red, int blue, int yellow, int black, bool ii, bool tf);
	bool getResearchStation();
	bool checkResearchStation();
};
