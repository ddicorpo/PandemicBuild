#include "Serialize.h"
#include <fstream>
#include <sstream>

Serialize::Serialize() {}
Serialize::~Serialize() {}

void Serialize::savePlayers(std::vector<Player*> players) {
	std::ofstream thefile;
	thefile.open("_playerssave");
	for (int k = 0; k < players.size(); k++) {
		thefile << players.at(k)->getName() << " " << players.at(k)->getRoleId() << " " << players.at(k)->getCurrentCity() << " ";
		for (int i = 0; i < players.at(k)->getHand().size(); i++) {
			thefile << players.at(k)->getHand().at(i)->getAttributes() << " ";
		}
		thefile << "\n";
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

	std::string line;
	for (int lineNum = 1; getline(thefile, line); lineNum++)
	{
		std::cout << line << std::endl;
		std::stringstream ss(line);
		std::string word;

		std::string name;
		std::string roleId;
		std::string city;
		std::string cards;

		int wordNum = 1;
		for (wordNum; ss >> word; wordNum++)
		{
			if (wordNum == 1)
				name = word;
			else if (wordNum == 2)
				roleId = word;
			else if (wordNum == 3)
				city = word;
			else
				cards += word;
		}

		std::cout << name << std::endl;
		std::cout << roleId << std::endl;
		std::cout << city << std::endl;
		std::cout << cards << std::endl;

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