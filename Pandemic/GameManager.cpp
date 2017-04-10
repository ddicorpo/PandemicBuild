#include <string>
#include <iostream>
#include "GameManager.h"

GameManager::GameManager(){
	redCubes = 24;
	blueCubes = 24;
	yellowCubes = 24;
	blackCubes = 24;
	infectionRate[0] = 2;
	infectionRate[1] = 2;
	infectionRate[2] = 2;
	infectionRate[3] = 3;
	infectionRate[4] = 3;
	infectionRate[5] = 4;
	infectionRate[6] = 4;
	infectionRateIndex = 0;
	outbreakTracker = 1;
	researchStations = 6;
}

void GameManager::increseInfectionRate(){
	infectionRateIndex = infectionRateIndex + 1;
}
int GameManager::getInfectionRateIndex(){
	return infectionRateIndex;
}
void GameManager::setInfectionRateIndex(int i){
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

int GameManager::getAvailableStations() {
	return researchStations;
}

void GameManager::displayCubeCount() {
	std::cout << "Red Cubes: " << redCubes << std::endl;
	std::cout << "Blue Cubes: " << blueCubes << std::endl;
	std::cout << "Black Cubes: " << blackCubes << std::endl;
	std::cout << "Yellow Cubes: " << yellowCubes << std::endl;
}

bool GameManager::checkCubes(){
	if (redCubes > 0 && blueCubes > 0 && yellowCubes > 0 && blackCubes > 0)
		return true;
	else
		return false;
}

bool GameManager::checkOutbreak()
{
	if (outbreakTracker == 8)
		return true;
	else
		return false;
}
int GameManager::getRed(){
	return redCubes;
}
int GameManager::getBlue(){
	return blueCubes;
}
int GameManager::getYellow(){
	return yellowCubes;
}
int GameManager::getBlack(){
	return blackCubes;
}

void GameManager::setRed(int r){
	redCubes = r;
}
void GameManager::setBlue(int b){
	blueCubes = b;
}
void GameManager::setYellow(int y){
	yellowCubes = y;
}
void GameManager::setBlack(int bl){
	blackCubes = bl;
}

