#include "Serialize.h"
#include "City.h"
#include "Event.h"
#include "Epidemic.h"
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
		thefile << deck.at(i)->getAttributes() << std::endl;
	}
	thefile.close();
	std::cout << "Deck Saved" << std::endl;
}

void Serialize::saveManager() {
	std::ofstream thefile;
	thefile.open("_gamemanager");
	thefile << GameManager::Instance().getRed() << " "
		<< GameManager::Instance().getBlue() << " "
		<< GameManager::Instance().getYellow() << " "
		<< GameManager::Instance().getBlack() << " "
		<< GameManager::Instance().getInfectionRateIndex() << " "
		<< GameManager::Instance().getOutbreakTracker() << " "
		<< GameManager::Instance().getAvailableStations();
	thefile.close();
	std::cout << "Game Manager Saved" << std::endl;
}

std::vector<Player*> Serialize::loadPlayers() {
	std::ifstream thefile;
	thefile.open("_playerssave");
	
	std::vector<Player*> players;
	std::string name;
	std::string roleId;
	std::string city;

	std::string line;
	
	for (int lineNum = 1; getline(thefile, line); lineNum++)
	{
		for (int p = line.find('\n'); p != (int)std::string::npos; p = line.find('\n'))
			line.erase(p, 1);
		
		std::string item;
		std::istringstream ss;
		ss.str(line);
		std::vector<std::string> temp;
		for (int k = 0; getline(ss, item, '|'); k++) {
			//std::cout << item << std::endl;
			temp.push_back(item);
		}

		std::string name = temp[0];
		int roleid = std::stoi(temp[1]);
		std::string city = temp[2];
		Player* pl = new Player(name);
		pl->setCurrentCity(new MapCity(city));
		pl->setRoleId(roleid);
		for (int i = 3; i < temp.size(); i++) {
			std::string item;
			std::istringstream ss;
			std::vector<std::string> tempy;
			ss.str(temp[i]);
			for (int k = 0; getline(ss, item, ':'); k++) {
				tempy.push_back(item);
			}

			if (tempy[1] == "city") {
				pl->addCard(new City(tempy[0], tempy[2], std::stoi(tempy[3])));
			}
			else if (tempy[1] == "event") {
				pl->addCard(new Event(tempy[0], tempy[2]));
			}	
		}

		players.push_back(pl);
		std::cout << "player loaded: " << lineNum << std::endl;

	}


	return players;
}

std::vector<PlayerCard*> Serialize::loadDeck(){
	std::ifstream thefile;
	thefile.open("_decksave");
	std::string line;
	std::vector<PlayerCard*> deck;

	for (int lineNum = 1; getline(thefile, line); lineNum++)
	{
		for (int p = line.find('\n'); p != (int)std::string::npos; p = line.find('\n'))
			line.erase(p, 1);

		std::string item;
		std::istringstream ss;
		ss.str(line);
		std::vector<std::string> temp;
		for (int k = 0; getline(ss, item, ':'); k++) {
			temp.push_back(item);
		}

		if (temp[1] == "city"){
			deck.push_back(new City(temp[0], temp[2], std::stoi(temp[3])));
		}
		else if (temp[1] == "event"){
			deck.push_back(new Event(temp[0], temp[2]));
		}
		else if (temp[1] == "epidemic"){
			deck.push_back(new Epidemic());
		}

	}
	return deck;
}

void Serialize::loadManager(){
	std::ifstream thefile;
	thefile.open("_gamemanager");
	int red, blue, yellow, black, infectionrateindex, outbreaktracker, stations;

	while (thefile >> red >> blue >> yellow >> black >> infectionrateindex >> outbreaktracker >> stations)
	{
		GameManager::Instance().setCubes(red, blue, yellow, black);
		GameManager::Instance().setInfectionRateIndex(infectionrateindex);
		GameManager::Instance().setOutbreakTracker(outbreaktracker);
		GameManager::Instance().setStationCount(stations);
	}
}