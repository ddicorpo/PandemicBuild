#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <time.h>
#include "City.h"
#include "Event.h"
#include "Epidemic.h"
#include "Deck.h"
#include "Player.h"
#include "InfectionCard.h"
#include "GameManager.h"
#include <windows.h>
#include <sstream>
#include "Serialize.h"
#include "OptionOne_Move.h"
#include "OptionTwo_Fly.h"
#include "OptionThree_FlyAny.h"
#include "OptionFour_FlyResearch.h"
#include "OptionFive_Cure.h"
#include "OptionSix_Trade.h"
#include "OptionSeven_Remove.h"
#include "OptionEight_Construct.h"
#include "OptionDefault.h"
#include "OptionTen_Save.h"


int main() {
	std::srand((int)time(0));
	//accessing the game manager
	//GameManager::Instance().displayCubeCount();

	//locals
	std::vector<Player*> players;
	std::vector<PlayerCard*> pDeck;
	int playerCount;

	//////////////CRAETE THE MAP CITY OBJECTS

	std::ifstream mcities("..\\PandemicMap.txt");
	std::vector<MapCity*> map;
	

	std::string line;

	for (int lineNum = 1; getline(mcities, line); lineNum++)
	{
		std::stringstream ss(line);
		std::string word;

		std::string name;
		std::string region;
		std::vector<MapCity*> neighs;
		int wordNum = 1;
		for (wordNum; ss >> word; wordNum++)
		{
			if (wordNum == 1)
				name = word;
			else if (wordNum == 2)
				region = word;
			else
				neighs.push_back(new MapCity(word));
		}
		map.push_back(new MapCity(name, region, neighs));
	}

	/*for (int i = 0; i < map.size(); i++){
		for (int j = 0; j < map[i]->getNeighbours().size(); j++){
			for (int k = 0; k < map.size(); k++){
				if (map[i]->getNeighbours()[j]->getName() == map[k]->getName()){
					map[i]->getNeighbours()[j] = map[k];
					break;
				}
			}
		}
	}*/



	map[0]->setResearchStation();


	//////////////CREATE THE INFECTION DECK

	std::vector<InfectionCard*> infectionCardDeck;
	std::vector<InfectionCard*> infectionCardDiscard;
	std::ifstream infectionDeck("..\\cities.txt");
	std::string cityName, cityColor;
	int null;
	while (infectionDeck >> cityName >> cityColor >> null)
	{
		infectionCardDeck.push_back(new InfectionCard(cityName, cityColor));
	}

	for (int i = 0; i < 9; i++){
			if (i % 3 == 0){
				std::cout << infectionCardDeck[i]->getCity() << std::endl;
				for (int m = 0; m < map.size(); m++){
					if (infectionCardDeck[i]->getCity() == map[m]->getName()){
						if (infectionCardDeck[i]->getColor() == "red"){
							map[m]->addRedCube();
							map[m]->addRedCube();
							map[m]->addRedCube();
							break;
						}
						if (infectionCardDeck[i]->getColor() == "blue"){
							map[m]->addBlueCube();
							map[m]->addBlueCube();
							map[m]->addBlueCube();
							break;
						}
						if (infectionCardDeck[i]->getColor() == "yellow"){
							map[m]->addYellowCube();
							map[m]->addYellowCube();
							map[m]->addYellowCube();
							break;
						}
						if (infectionCardDeck[i]->getColor() == "black"){
							map[m]->addBlackCube();
							map[m]->addBlackCube();
							map[m]->addBlackCube();
							break;
						}
					}
				}
						
			}
			else if (i % 3 == 1) {
				std::cout << infectionCardDeck[i]->getCity() << std::endl;
				for (int m = 0; m < map.size(); m++){
					if (infectionCardDeck[i]->getCity() == map[m]->getName()){
						if (infectionCardDeck[i]->getColor() == "red"){
							map[m]->addRedCube();
							map[m]->addRedCube();
							break;
						}
						if (infectionCardDeck[i]->getColor() == "blue"){
							map[m]->addBlueCube();
							map[m]->addBlueCube();
							break;
						}
						if (infectionCardDeck[i]->getColor() == "yellow"){
							map[m]->addYellowCube();
							map[m]->addYellowCube();
							break;
						}
						if (infectionCardDeck[i]->getColor() == "black"){
							map[m]->addBlackCube();
							map[m]->addBlackCube();
							break;
						}
					}
				}

			}
			else if (i % 3 == 2){
				std::cout << infectionCardDeck[i]->getCity() << std::endl;
				for (int m = 0; m < map.size(); m++){
					if (infectionCardDeck[i]->getCity() == map[m]->getName()){
						if (infectionCardDeck[i]->getColor() == "red"){
							map[m]->addRedCube();
							break;
						}
						if (infectionCardDeck[i]->getColor() == "blue"){
							map[m]->addBlueCube();
							break;
						}
						if (infectionCardDeck[i]->getColor() == "yellow"){
							map[m]->addYellowCube();
							break;
						}
						if (infectionCardDeck[i]->getColor() == "black"){
							map[m]->addBlackCube();
							break;
						}
					}
				}
			}
		
	}
	

	//////////////DETERMINE IF NEW GAME OR LOAD GAME

	Serialize access = Serialize();

	std::cout << "Welcome to Pandemic: Build 1." << std::endl;
	std::cout << "===============================================" << std::endl;
neworload:
	int input;
	std::cout << "Would you like to: \n 1) Start a new game? \n 2) Load an existing game?" << std::endl;
	std::cin >> input;
	if (input == 2){
		//loading operations
		players = access.loadPlayers();
		playerCount = players.size();

		pDeck = access.loadDeck();
		access.loadManager();
	}
	else if (input == 1){
		//set up a new game
		
	//////////////CRAETE THE PLAYER CARD OBJECTS

	//vectors to hold card objects
	std::vector<PlayerCard*> cities;
	std::vector<PlayerCard*> events;
	std::vector<PlayerCard*> epidemics;

	//creating city 
	std::ifstream cityFile("..\\cities.txt");
	std::string name, color;
	int pop;
	while (cityFile >> name >> color >> pop){
		cities.push_back(new City(name, color, pop));
	}

	//create epidmics
	for (int i = 0; i < 6; i++){
		epidemics.push_back(new Epidemic());
	}

	//creating event cards
	events.push_back(new Event("Airlift", "Move any one pawn to any city. Get permission before moving another player's pawn."));
	events.push_back(new Event("One Quiet Night", "The next player to begin the Playing The Infection phase of their turn may skip that phase entirely."));
	events.push_back(new Event("Forecast", "Examine the top 6 cards of the Infection Draw Pile, rearrange them in the order of your choice, then place them back on the pile."));
	events.push_back(new Event("Government Grant", "Add a Research Station to any city for free."));
	events.push_back(new Event("Resilient Population", "Take a card from the Infection Discard Pile and remove it from the game."));


	//////////////INITIALIZE NEW GAME PLAYERS

	std::cout << "How many players?" << std::endl;
	
	while (!(std::cin >> playerCount) || playerCount < 2 || playerCount > 4) {
		std::cout << "2-4 PLayers only" << std::endl;
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
	}

	for (int i = 0; i < playerCount; i++){
		std::string name;
		std::cout << "What is player " << i + 1 << "'s name?" << std::endl;
		std::cin >> name;
		players.push_back(new Player(name,new OptionDefault()));
	}

	//create a deck
	Deck *deck(new Deck(playerCount));
	deck->createDeck(cities, events, epidemics);
	//hold the deck for game manipulation
	pDeck = deck->getDeck();

	//give roles to players and pawns
	std::vector<int> rolesvec = { 0, 1, 2, 3, 4, 5, 6 };
	std::vector<PlayerCard*> playerHands = deck->getPlayerHand();
	int handindex = 0;
	std::cout << "-------------------- Roles --------------------" << std::endl;
	for (int i = 0; i < players.size(); i++){
		int role = rand() % (7 - i);
		players[i]->setRole(new roles(rolesvec[role]));
		players[i]->setRoleId(rolesvec[role]);
		rolesvec.erase(rolesvec.begin() + role);
		players[i]->setPawn(new Pawn(players[i]->getRole()->getColor()));
		std::cout << players[i]->getName() << " is a " << players[i]->getRole()->getName() << std::endl;
		for (int c = 0; c < playerHands.size() / playerCount; c++) {
			//std::cout << playerHands[handindex]->getAttributes() << std::endl;
			players[i]->addCard(playerHands[handindex]);
			handindex++;
		}
		players[i]->setCurrentCity(map[0]);
	}
	std::cout << "-----------------------------------------------" << std::endl;

	//delete pointers
	delete deck;
	deck = NULL;

	}
	else {
		std::cout << "Must make a selection" << std::endl;
		goto neworload;
	}

	int turnCounter = playerCount;
start:
	int playerChoice = 0;
	int playerIndex = turnCounter % playerCount;
	std::cout << players[playerIndex]->getName() << "' turn" << std::endl;
	std::cout << "You are stationed in "<< players[playerIndex]->getCurrentCity()->getName() << std::endl;
	std::cout << "Below are your cards" << std::endl;
	std::cout << "======================== HAND ========================" << std::endl;
	players[playerIndex]->displayHand();
	std::cout << "======================================================" << std::endl;


	////OPTIONS 4 of 8 actions, draw 2 cards, infect 
	int actioncounter = 0;
performactions:
	std::cout << "*************** INFECTED CITIES ***************" << std::endl;
	std::cout << "Name: \t   Number of cubes: " << std::endl;
	for (int i = 0; i < map.size(); i++)
	{
		if (map[i]->getInfected() == true)
			std::cout << map[i]->getName() << "\t   " << map[i]->getAllCubes() << std::endl;
	}
	std::cout << "***********************************************" << std::endl;


	std::cout << 4 - actioncounter << " actions remain" << std::endl;
	if (actioncounter > 3)
		goto proceed;

	players[playerIndex]->getReferenceCard();
	std::cin >> playerChoice;

	switch (playerChoice)
	{
		case 1: players[playerIndex]->setStrategy(new OptionOne_Move(players[playerIndex], map));
				players[playerIndex]->executeStrategy();
				break;
		case 2: players[playerIndex]->setStrategy(new OptionTwo_Fly(players[playerIndex], map));
				players[playerIndex]->executeStrategy();
				break;
		case 3: players[playerIndex]->setStrategy(new OptionThree_FlyAny(players[playerIndex], map));
				players[playerIndex]->executeStrategy();
				break;
		case 4: players[playerIndex]->setStrategy(new OptionFour_FlyResearch(players[playerIndex], map));
				players[playerIndex]->executeStrategy();
				break;
		case 5: players[playerIndex]->setStrategy(new OptionFive_Cure(players[playerIndex], map));
				//players[playerIndex]->executeStrategy();
				break;
		case 6: players[playerIndex]->setStrategy(new OptionSix_Trade(players[playerIndex], map));
				players[playerIndex]->executeStrategy();
				break;
		case 7: players[playerIndex]->setStrategy(new OptionSeven_Remove(players[playerIndex], map));
				players[playerIndex]->executeStrategy();
				break;
		case 8: players[playerIndex]->setStrategy(new OptionEight_Construct(players[playerIndex], map));
				players[playerIndex]->executeStrategy();
				break;
		case 9: actioncounter = 4;
				break;
		case 10:/*players[playerIndex]->setStrategy(new OptionTen_Save(players[playerIndex], map));
				players[playerIndex]->executeStrategy();*/
				int option;
				std::cout << "Options" << std::endl;
				std::cout << "1 : Save" << std::endl;
				std::cout << "2 : Exit with save" << std::endl;
				std::cout << "3 : Exit without save" << std::endl;
				std::cout << "4 : Exit without save" << std::endl;
				std::cin >> option;
				switch (option) {
					case 1: access.saveDeck(pDeck);
							access.saveManager();
							access.savePlayers(players);
							break;
					case 2:	access.saveDeck(pDeck);
							access.saveManager();
							access.savePlayers(players);
							goto endgame;
							break;
					case 3: goto endgame;
							break;
					case 4: break;
				}
				break;
	}

	if (playerChoice > 9 || playerChoice < 1)
	{
		std::cout << "You made an invalid choice. Please select again!" << std::endl << std::endl;
		goto performactions;
	}

	actioncounter++;
	goto performactions;

proceed:
	if (pDeck.at(0)->getType() == "epidemic") {
		//increase
		GameManager::Instance().increseInfectionRate();	//if epidemic, increase infection rate and add 1 card to your hand
		pDeck.erase(pDeck.begin());
		players[playerIndex]->addCard(pDeck.at(0));
		pDeck.erase(pDeck.begin());
		
		//infect
		std::string epicity = infectionCardDeck.back()->getCity();
		std::string epicolor = infectionCardDeck.back()->getColor();
		for (int i = 0; i < map.size(); i++) {
			if (map[i]->getName() == epicity) {
				map[i]->epidemic(epicolor);
			}
		}

		//intensify
		infectionCardDeck = GameManager::Instance().epishuffle(infectionCardDeck, infectionCardDiscard);
		infectionCardDiscard.clear();

		//check player has <= 7 cards
		players[playerIndex]->handcheck();
	}
	else if (pDeck.at(1)->getType() == "epidemic") {
		//increase
		players[playerIndex]->addCard(pDeck.at(0));
		pDeck.erase(pDeck.begin());
		GameManager::Instance().increseInfectionRate();	//if 2nd card is epidemic, increase infection rate and add first card to your hand
		pDeck.erase(pDeck.begin());

		//infect
		std::string epicity = infectionCardDeck.back()->getCity();
		std::string epicolor = infectionCardDeck.back()->getColor();
		for (int i = 0; i < map.size(); i++) {
			if (map[i]->getName() == epicity) {
				map[i]->epidemic(epicolor);
			}
		}

		//intensify
		infectionCardDeck = GameManager::Instance().epishuffle(infectionCardDeck, infectionCardDiscard);
		infectionCardDiscard.clear();

		//check player has <= 7 cards
		players[playerIndex]->handcheck();
	}
	else {
		//if not, add 2 cards to your hand
		players[playerIndex]->addCard(pDeck.at(0));
		pDeck.erase(pDeck.begin());
		players[playerIndex]->addCard(pDeck.at(0));
		pDeck.erase(pDeck.begin());

		//check player has <= 7 cards
		players[playerIndex]->handcheck();
	}

	//infect cities - done automatiacally by the game - will check if cubes are available and update avaialble cube counts
	if (GameManager::Instance().checkCubes()) {
		std::cout << "------------------------------------------------------" << std::endl;
		std::cout << "Drawing 2 Infection Cards from infection deck . . . . " << std::endl;

		int card1 = rand() % infectionCardDeck.size();
		for (int i = 0; i < map.size(); i++){
			if (map[i]->getName() == infectionCardDeck.at(card1)->getCity()){
				if (infectionCardDeck.at(card1)->getColor() == "red"){
					map[i]->addRedCube();
				}
				else if (infectionCardDeck.at(card1)->getColor() == "blue"){
					map[i]->addBlueCube();
				}
				else if (infectionCardDeck.at(card1)->getColor() == "yellow"){
					map[i]->addYellowCube();
				}
				else if (infectionCardDeck.at(card1)->getColor() == "black"){
					map[i]->addBlackCube();
				}
			}
		}
		
		infectionCardDeck[card1]->infect();
		infectionCardDiscard.push_back(infectionCardDeck.at(card1));
		infectionCardDeck.erase(infectionCardDeck.begin() + card1);
		

		int card2 = rand() % infectionCardDeck.size();
		for (int i = 0; i < map.size(); i++){
			if (map[i]->getName() == infectionCardDeck.at(card2)->getCity()){
				if (infectionCardDeck.at(card2)->getColor() == "red"){
					map[i]->addRedCube();
				}
				else if (infectionCardDeck.at(card2)->getColor() == "blue"){
					map[i]->addBlueCube();
				}
				else if (infectionCardDeck.at(card2)->getColor() == "yellow"){
					map[i]->addYellowCube();
				}
				else if (infectionCardDeck.at(card2)->getColor() == "black"){
					map[i]->addBlackCube();
				}

			}
		}

		/*infectionCardDeck[card2]->infect();*/
		infectionCardDiscard.push_back(infectionCardDeck.at(card2));
		infectionCardDeck.erase(infectionCardDeck.begin() + card2);
		std::cout << "------------------------------------------------------" << std::endl;
	}
	else {
		MessageBox(NULL, L"You ran out of infection cubes", L"Game Over", NULL);
		goto endgame;
	}

	system("pause");

	turnCounter++;
	goto start;
	
	
	endgame:

	//delete rest of pointers
	for (auto it = players.begin(); it != players.end(); it++)
		delete *it;
	players.clear();

	for (auto it = pDeck.begin(); it != pDeck.end(); it++)
		delete *it;
	pDeck.clear();

	return 0;
}
