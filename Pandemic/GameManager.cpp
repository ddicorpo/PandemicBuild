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
	isRedCured = false;
	isRedErradicated = false;
	isBlueCured = false;
	isBlueErradicated = false;
	isYellowCured = false;
	isYellowErradicated = false;
	isBlackCured = false;
	isBlackErradicated = false;
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

void GameManager::setStationCount(int s){
	researchStations = s;
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

bool GameManager::getIsRedCured(){
	return isRedCured;
}
bool GameManager::getIsRedErradicated(){
	return isRedErradicated;
}
bool GameManager::getIsBlueCured(){
	return isBlueCured;
}
bool GameManager::getIsBlueErradicated(){
	return isBlueErradicated;
}
bool GameManager::getIsYellowCured(){
	return isYellowCured;
}
bool GameManager::getIsYellowErradicated(){
	return isYellowErradicated;
}
bool GameManager::getIsBlackCured(){
	return isBlackCured;
}
bool GameManager::getIsBlackErradicated(){
	return isBlackErradicated;
}

void GameManager::setIsRedCured(bool redCured){
	isRedCured = redCured;
}
void GameManager::setIsRedErradicated(bool redErradicated){
	isRedErradicated = redErradicated;
}
void GameManager::setIsBlueCured(bool blueCured){
	isBlueCured = blueCured;
}
void GameManager::setIsBlueErradicated(bool blueErradicated){
	isBlueErradicated = blueErradicated;
}
void GameManager::setIsYellowCured(bool yellowCured){
	isYellowCured = yellowCured;
}
void GameManager::setIsYellowErradicated(bool yellowErradicated){
	isYellowErradicated = yellowErradicated;
}
void GameManager::setIsBlackCured(bool blackCured){
	isBlackCured = blackCured;
}
void GameManager::setIsBlackErradicated(bool blackErradicated){
	isBlackErradicated = blackErradicated;
}

void GameManager::setCures(bool redCured, bool blueCured, bool yellowCured, bool blackCured){
	isRedCured = redCured;
	isBlueCured = blueCured;
	isYellowCured = yellowCured;
	isBlackCured = blackCured;
}

void GameManager::setErradicated(bool redErradicated, bool blueErradicated, bool yellowErradicated, bool blackErradicated){
	isRedErradicated = redErradicated;
	isBlueErradicated = blueErradicated;
	isYellowErradicated = yellowErradicated;
	isBlackErradicated = blackErradicated;
}
