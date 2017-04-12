#include "Serialize.h"
#include <fstream>
#include <sstream>
#include <algorithm>

Serialize::Serialize() {}
Serialize::~Serialize() {}

void Serialize::savePlayers(std::vector<Player*> players) {
	std::ofstream thefile;
	thefile.open("_playerssave");
	for (int k = 0; k < players.size(); k++) {
		thefile << players.at(k)->getName() << "|" << players.at(k)->getRoleId() << "|" << players.at(k)->getCurrentCity() << "|";
		for (int i = 0; i < players.at(k)->getHand().size(); i++) {
			thefile << players.at(k)->getHand().at(i)->getAttributes() << "|";
		}
		thefile << std::endl;
	}
	thefile.close();
	std::cout << "Players Saved" << std::endl;
}
void Serialize::saveDeck(std::vector<PlayerCard*> deck) {
	std::ofstream thefile;
	thefile.open("_decksave");
	for (int i = 0; i < deck.size(); i++) {
		thefile << deck.at(i)->getAttributes() << "\n";
	}
	thefile.close();
	std::cout << "Deck Saved" << std::endl;
}

void Serialize::saveManager() {
	std::ofstream thefile;
	thefile.open("_gamemanager");
	thefile << &GameManager::getRed << " "
		<< &GameManager::getBlue << " "
		<< &GameManager::getYellow << " "
		<< &GameManager::getBlack << " "
		<< &GameManager::getInfectionRateIndex << " "
		<< &GameManager::getOutbreakTracker << " "
		<< &GameManager::getAvailableStations;
	thefile.close();
	std::cout << "Game Manager Saved" << std::endl;
}

void Serialize::loadPlayers() {
	std::ifstream thefile;
	thefile.open("_playerssave");
	
	std::vector<std::string> temp;
	std::string name;
	std::string roleId;
	std::string city;

	std::string line;
	
	for (int lineNum = 1; getline(thefile, line, '|'); lineNum++)
	{
		for (int p = line.find('\n'); p != (int)std::string::npos; p = line.find('\n'))
			line.erase(p, 1);
		
		temp.push_back(line);
		//std::cout << line << std::endl;
	}


	name = temp[0];
	roleId = temp[1];
	city = temp[2];
	std::cout << name << "|" << roleId << "|" << city << std::endl;
	for (int i = 3; i < temp.size(); i++) {
		std::cout << temp[i] << std::endl;
	}

	
}
//
//Deck Serialize::loadDeck(){
//
//}
//
//void Serialize::loadManager(){
//
//}