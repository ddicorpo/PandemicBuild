#include <iostream>
#include <string>
#include <vector>
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
		std::vector<MapCity*> neighs;
		int wordNum = 1;
		for (wordNum; ss >> word; wordNum++)
		{
			if (wordNum == 1)
				name = word;
			else
				neighs.push_back(new MapCity(word));
		}
		map.push_back(new MapCity(name, neighs));
	}

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

	//////////////DETERMINE IF NEW GAME OR LOAD GAME

	Serialize access = Serialize();

	std::cout << "Welcome to Pandemic: Build 1." << std::endl;
	std::cout << "===============================================" << std::endl;
neworload:
	int input;
	std::cout << "Would you like to: \n 1) Start a new game? \n 2) Load an existing game?" << std::endl;
	std::cin >> input;
	if (input == 2){

		players = {};
		pDeck = {};
		playerCount = players.size();


		players = access.loadPlayers();

		system("pause");
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
		players.push_back(new Player(name));
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


start:
	int turnCounter = 0;
	int playerIndex = turnCounter % playerCount;
	std::cout << players[playerIndex]->getName() << "' turn" << std::endl;
	std::cout << "You are stationed in "<< players[playerIndex]->getCurrentCity() << std::endl;
	std::cout << "Below are your cards" << std::endl;
	players[playerIndex]->displayHand();

	////OPTIONS 4 of 8 actions, draw 2 cards, infect 
	int actioncounter = 0;
performactions:
	std::cout << "Choose an action from the list below - " << 4 - actioncounter << "actions remain" << std::endl;
	if (actioncounter >= 3)
		goto proceed;

	//////////////////////////////////////////
	//////////////dans work here//////////////
	//////////////////////////////////////////

	//save game option
	access.saveDeck(pDeck);
	access.saveManager();
	access.savePlayers(players);

	actioncounter++;
	goto performactions;

proceed:
	if (pDeck.at(0)->getType() == "epidemic") {
		//if epidemic, increase infection rate and add 1 card to your hand
		GameManager::Instance().increseInfectionRate();
		pDeck.erase(pDeck.begin());
		players[playerIndex]->addCard(pDeck.at(0));
		pDeck.erase(pDeck.begin());
	}
	else if (pDeck.at(1)->getType() == "epidemic") {
		//if 2nd card is epidemic, increase infection rate and add first card to your hand
		players[playerIndex]->addCard(pDeck.at(0));
		pDeck.erase(pDeck.begin());
		GameManager::Instance().increseInfectionRate();
		pDeck.erase(pDeck.begin());
	}
	else {
		//if not, add 2 cards to your hand
		players[playerIndex]->addCard(pDeck.at(0));
		pDeck.erase(pDeck.begin());
		players[playerIndex]->addCard(pDeck.at(0));
		pDeck.erase(pDeck.begin());
	}

	//infect cities - done automatiacally by the game - will check if cubes are available and update avaialble cube counts
	if (GameManager::Instance().checkCubes()) {
		std::cout << "------------------------------------------------------" << std::endl;
		std::cout << "Drawing 2 Infection Cards from infection deck . . . . " << std::endl;

		int card1 = rand() % infectionCardDeck.size();

		infectionCardDeck[card1]->infect();
		infectionCardDeck.erase(infectionCardDeck.begin() + card1);
		infectionCardDiscard.push_back(infectionCardDeck.at(card1));

		int card2 = rand() % infectionCardDeck.size();

		infectionCardDeck[card2]->infect();
		infectionCardDeck.erase(infectionCardDeck.begin() + card2);
		infectionCardDiscard.push_back(infectionCardDeck.at(card2));
		std::cout << "------------------------------------------------------" << std::endl;
	}
	else {
		MessageBox(NULL, L"You ran out of infection cubes", L"Game Over", NULL);
		goto endgame;
	}

	system("pause");

	turnCounter++;
	goto start;
	
	/*





	//decisions decisions - hard coded atm. will be possibly implemetned as a functon of class game.
	bool p1HasEvent = false;
	bool p2HasEvent = false;
	int o;
	std::string option;
	start: {
		
		std::cout << "Players are now stationed in " << p1->getCurrentCity() << " !" << std::endl;

		std::cout << p1->getName() << "'s turn." << std::endl;
		std::cout << p1->getRole()->getSkill() << std::endl;
		std::cout << "These are your cards." << std::endl;
		std::cout << std::endl;
		p1->displayHand();
		std::cout << std::endl;

		//perform the 4 or less actions available to the player
		o = 0;
		std::cout << "Below are your options. Enter an option number to make a decision." << std::endl;
		for (int i = 0; i < p1->getHand().size(); i++) {
			if (p1->getHand()[i]->getType() != "city") {
				p1HasEvent = true;
			}
		}

		if (p1HasEvent == true) {
			o = 1;
			std::cout << o << " : use 1 event card." << std::endl;
		}
		std::cout << o + 1 << " : check actions on reference card" << std::endl;
		std::cout << o + 2 << " : end the game." << std::endl;
		std::cin >> option;

		options: {
			if (option == "1" && p1HasEvent == true) {
				std::cout << "Turns out events are useless. Next players turn." << std::endl;
				goto proceed;
			}

			else if (option == std::to_string(o + 1)) {
				p1->getReferenceCard();
				std::cout << "You have up to 4 actions to do, you can either pick a number to perform the action, or skip your actions by pressing 0. What would you like to do?" << std::endl;
				int playerTurns = 4;
				int playerInput;
				retry:
				std::cin >> playerInput;
				while (playerTurns <= 0 || playerInput != 0)
				{
					if (playerInput == 1)
					{
						p1->move();
						std::cout << std::endl;
						p1->getReferenceCard();
						std::cout << "Would you like to perform another action? Press 0 to skip" << std::endl;
						std::cin >> playerInput;
					}
					else if (playerInput > 1 && playerInput < 10)
					{
						std::cout << "Doing " << playerInput << "'s actions. We have not yet implemented the actions" << std::endl;
						playerTurns--;
						if (playerTurns <= 0)
						{
							std::cout << "No more actions to do!" << std::endl;
							break;
						}
						std::cout << "Would you like to perform another action? Press 0 to skip." << std::endl;
						std::cin >> playerInput;
					}

					else if (playerInput == 0)
					{
						std::cout << "Confirmed! Exiting now . . . " << std::endl;
						break;
					}
					else {
						std::cout << "Wrong input, try again." << std::endl;
						goto retry;
					}
				}
				

			}

			else if (option == std::to_string(o + 2)) {
				MessageBox(NULL, L"You ended the game.", L"Game Over", NULL);
				goto endgame;
			}
			else {
				std::cout << "Wrong input. Try again!" << std::endl;
				goto options;
			}
		}
			 proceed:
				 //draw 2 cards from player deck, add to player hand. If epidemic, discard it and update infection rate
				 if (pDeck.at(0)->getType() == "epidemic") {
					 //if epidemic, increase infection rate and add 1 card to your hand
					 GameManager::Instance().increseInfectionRate();
					 pDeck.erase(pDeck.begin());
					 p1->addCard(pDeck.at(0));
					 pDeck.erase(pDeck.begin());
				 }
				 else if(pDeck.at(1)->getType() == "epidemic") {
					 //if 2nd card is epidemic, increase infection rate and add first card to your hand
					 p1->addCard(pDeck.at(0));
					 pDeck.erase(pDeck.begin());
					 GameManager::Instance().increseInfectionRate();
					 pDeck.erase(pDeck.begin());
				 }
				 else {
					 //if not, add 2 cards to your hand
					 p1->addCard(pDeck.at(0));
					 pDeck.erase(pDeck.begin());
					 p1->addCard(pDeck.at(0));
					 pDeck.erase(pDeck.begin());
				 }

				 //infect cities - done automatiacally by the game - will check if cubes are available and update avaialble cube counts
				 if (GameManager::Instance().checkCubes()) {
					 std::cout << "------------------------------------------------------" << std::endl;
					 std::cout << "Drawing 2 Infection Cards from infection deck . . . . " << std::endl;

					 int card1 = rand() % infectionCardDeck.size();

					 infectionCardDeck[card1]->infect();
					 infectionCardDeck.erase(infectionCardDeck.begin() + card1);
					 infectionCardDiscard.push_back(infectionCardDeck.at(card1));

					 int card2 = rand() % infectionCardDeck.size();

					 infectionCardDeck[card2]->infect();
					 infectionCardDeck.erase(infectionCardDeck.begin() + card2);
					 infectionCardDiscard.push_back(infectionCardDeck.at(card2));
					 std::cout << "------------------------------------------------------" << std::endl;
				 }
				 else {
					 MessageBox(NULL, L"You ran out of infection cubes", L"Game Over", NULL);
					 goto endgame;
				 }

				 //check if outbreak limit was reached
				 if (GameManager::Instance().checkOutbreak()) {
					 MessageBox(NULL, L"Outbreak tracker is at 8. You lose.", L"Game Over", NULL);
					 goto endgame;
				 }

		
		//next players turn
		std::cout << p2->getName() << "'s turn." << std::endl;
		std::cout << p2->getRole()->getSkill() << std::endl;
		std::cout << "These are your cards." << std::endl;
		std::cout << std::endl;
		p2->displayHand();
		o = 0;
		std::cout << std::endl;

		//perform the 4 or less actions available to the player
		std::cout << "Below are your options. Enter an option number to make a decision." << std::endl;
		for (int i = 0; i < p2->getHand().size(); i++) {
			if (p2->getHand()[i]->getType() != "city") {
				p2HasEvent = true;
			}
		}

		if (p2HasEvent == true) {
			o = 1;
			std::cout << o << " : use 1 event card." << std::endl;
		}
		std::cout << o + 1 << " : check actions on reference card" << std::endl;
		std::cout << o + 2 << " : end the game." << std::endl;
		std::cin >> option;

		options2: {
			if (option == "1" && p2HasEvent == true) {
				std::cout << "Turns out events are useless. Next players turn." << std::endl;
				goto proceed2;
			}
			else if (option == std::to_string(o + 1)) {
				p2->getReferenceCard();
				std::cout << "You have up to 4 actions to do, you can either pick a number to perform the action, or skip your actions by pressing 0. What would you like to do?" << std::endl;
				int playerTurns = 4;
				int playerInput;
				retry2:
				std::cin >> playerInput;
				while (playerTurns != 0 || playerInput != 0)
				{
					if (playerInput == 1)
					{
						p1->move();
						std::cout << std::endl;
						p1->getReferenceCard();
						std::cout << "Would you like to perform another action? Press 0 to skip" << std::endl;
						std::cin >> playerInput;
					}

					else if (playerInput > 0 && playerInput < 10)
					{
						std::cout << "Doing " << playerInput << "'s actions. We have not yet implemented the actions" << std::endl;
						playerTurns--;
						if (playerTurns <= 0)
						{
							std::cout << "No more actions to do!" << std::endl;
							break;
						}
						std::cout << "Would you like to perform another action? Press 0 to skip.";
						std::cin >> playerInput;
					}

					else if (playerInput == 0)
					{
						std::cout << "Confirmed! Exiting now . . . " << std::endl;
						break;
					}
					else {
						std::cout << "Wrong input, try again." << std::endl;
						goto retry2;
					}
				}


			}

			else if (option == std::to_string(o + 2)) {
				MessageBox(NULL, L"You ended the game.", L"Game Over", NULL);
				goto endgame;
			}
			else {
				std::cout << "Wrong input. Try again!" << std::endl;
				goto options2;
			}
		}
			  proceed2:
				  //draw 2 cards from player deck, add to player hand. If epidemic, discard it and update infection rate
				  if (pDeck.at(0)->getType() == "epidemic") {
					  //if epidemic, increase infection rate and add one card tou your hand
					  GameManager::Instance().increseInfectionRate();
					  pDeck.erase(pDeck.begin());
					  p2->addCard(pDeck.at(0));
					  pDeck.erase(pDeck.begin());
				  }
				  else if (pDeck.at(1)->getType() == "epidemic") {
					  //if 2nd card is epidemic, increase infection rate and add first card to your hand
					  p1->addCard(pDeck.at(0));
					  pDeck.erase(pDeck.begin());
					  GameManager::Instance().increseInfectionRate();
					  pDeck.erase(pDeck.begin());
				  }
				  else {
					  //if not, add 2 cards to your hand
					  p1->addCard(pDeck.at(0));
					  pDeck.erase(pDeck.begin());
					  p1->addCard(pDeck.at(0));
					  pDeck.erase(pDeck.begin());
				  }

				  //infect cities - done automatiacally by the game - will check if cubes are available and update avaialble cube counts
				  if (GameManager::Instance().checkCubes()) {
					  std::cout << "------------------------------------------------------" << std::endl;
					  std::cout << "Drawing 2 Infection Cards from infection deck . . . . " << std::endl;

					  int card3 = rand() % infectionCardDeck.size();

					  infectionCardDeck[card3]->infect();
					  infectionCardDeck.erase(infectionCardDeck.begin() + card3);
					  infectionCardDiscard.push_back(infectionCardDeck.at(card3));

					  int card4 = rand() % infectionCardDeck.size();

					  infectionCardDeck[card4]->infect();
					  infectionCardDeck.erase(infectionCardDeck.begin() + card4);
					  infectionCardDiscard.push_back(infectionCardDeck.at(card4));
					  std::cout << "------------------------------------------------------" << std::endl;
				  }
				  else {
					  MessageBox(NULL, L"You ran out of infection cubes", L"Game Over", NULL);
					  goto endgame;
				  }

				  //check if outbreak limit was reached
				  if (GameManager::Instance().checkOutbreak()) {
					  MessageBox(NULL, L"Outbreak tracker is at 8. You lose.", L"Game Over", NULL);
					  goto endgame;
				  }
			 
				  goto start;
	}

	

	*/
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
