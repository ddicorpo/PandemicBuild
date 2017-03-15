#include <string>
#include <iostream>
#include "GameManager.h"

GameManager::GameManager(){
	redCubes = 24;
	blueCubes = 24;
	yellowCubes = 24;
	blackCubes = 24;
	int infectionRate[7] = { 2, 2, 2, 3, 3, 4, 4 };
}

void GameManager::increseInfectionRate(){
	infectionRateIndex = infectionRateIndex + 1;
}

void GameManager::setInfectionRate(int i){
	infectionRateIndex = i;
}

void GameManager::increaseOutbreakTracker(){
	outbreakTracker = outbreakTracker + 1;
}

void GameManager::setOutbreakTracker(int i){
	outbreakTracker = i;
}

void GameManager::updateCubes(std::string color, int d){
	if (color == "red")
		redCubes = redCubes - d;
	if (color == "blue")
		blueCubes = blueCubes - d;
	if (color == "black")
		blackCubes = blackCubes - d;
	if (color == "yellow")
		yellowCubes = yellowCubes - d;
}

void GameManager::setCubes(int red, int blue, int black, int yellow){
	redCubes = red;
	blueCubes = blue;
	blackCubes = black;
	yellowCubes = yellow;
}

void GameManager::useStation(){
	if (researchStations = 0)
		std::cout << "No research statioons left" << std::endl;
	else
		researchStations = researchStations - 1;
}

int GameManager::getInfectionRate(){
	return infectionRate[infectionRateIndex];
}

int GameManager::getOutbreakTracker(){
	return outbreakTracker;
}