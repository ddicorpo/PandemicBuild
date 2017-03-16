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
#include "reference_cards.h"
#include "InfectionCard.h"
#include "GameManager.h"
#include "roles.h"
#include "MapCity.h"
#include <windows.h>
#include <sstream>


int main() {
	std::srand((int)time(0));
	//accessing the game manager
	//GameManager::Instance().displayCubeCount();


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

	std::vector<InfectionCard*> infectionCardDeck;
	std::vector<InfectionCard*> infectionCardDiscard;
	std::ifstream infectionDeck("..\\cities.txt");
	std::string cityName, cityColor; 
	int null;
	while (infectionDeck >> name >> color >> null)
	{
		infectionCardDeck.push_back(new InfectionCard(name, color));
	}

	for (int i = 0; i < 6; i++){
		epidemics.push_back(new Epidemic());
	}

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

	//std::ifstream mapCities("..\\PandemicMap.txt"); 
	//std::vector<MapCity*> map;
	//std::string city, neighbourOne, neighbourTwo, neighbourThree, neighbourFour;
	//
	//while (mapCities >> city >> neighbourOne >> neighbourTwo >> neighbourThree >> neighbourFour)
	//{
	//	std::vector<MapCity*> neighbours;
	//	neighbours.push_back(new MapCity(neighbourOne));
	//	neighbours.push_back(new MapCity(neighbourTwo));
	//	neighbours.push_back(new MapCity(neighbourThree));
	//	neighbours.push_back(new MapCity(neighbourFour));

	//	map.push_back(new MapCity(city, neighbours));
	//}

	//std::cout << map.size();
	//for (int i = 0; i < map.size(); i++)
	//{
	//	std::cout << map[i]->getName() << " has neighbours: " << std::endl;
	//	map[i]->getListOfNeighbours();
	//	std::cout << std::endl;
	//}

	//for (int i = 0; i < map.size(); i++)
	//{
	//	std::cout << map[i]->getName() << std::endl;
	//	map[i]->getListOfNeighbours();
	//	std::cout << std::endl;
	//}

	//creating event cards
	events.push_back(new Event("Airlift", "Move any one pawn to any city. Get permission before moving another player's pawn."));
	events.push_back(new Event("One Quiet Night", "The next player to begin the Playing The Infection phase of their turn may skip that phase entirely."));
	events.push_back(new Event("Forecast", "Examine the top 6 cards of the Infection Draw Pile, rearrange them in the order of your choice, then place them back on the pile."));
	events.push_back(new Event("Government Grant","Add a Research Station to any city for free."));
	events.push_back(new Event("Resilient Population", "Take a card from the Infection Discard Pile and remove it from the game."));
	
	//create a deck
	Deck *deck(new Deck());
	deck->createDeck(cities, events, epidemics);
	//hold the deck for game manipulation
	std::vector<PlayerCard*> pDeck = deck->getDeck();
	//output deck
	//deck->displayDeck();


	
	
	int input;
	std::cout << "Welcome to Pandemic: Build 1." << std::endl;
	std::cout << "===============================================" << std::endl;
	/*std::cout << "Would you like to: \n 1) Start a new game? \n 2) Load an existing game?";
	std::cin >> input;*/

	std::cout << "What is the name of player 1: ";
	std::string player1;
	std::cin >> player1;
	std::cout << "What is the name of player 2: ";
	std::string player2;
	std::cin >> player2;

	//initialize 2 players
	Player *p1(new Player(player1));
	Player *p2(new Player(player2));

	//give roles to players
	int role1 = rand() % 7;
	int role2 = rand() % 7;
	while (role1 == role2)
	{
		role2 = rand() % 7;
	}
	p1->setRole(new roles(role1));
	p2->setRole(new roles(role2));

	//set pawns of player (to do: set start location of pawn)
	p1->setPawn(new Pawn(p1->getRole()->getColor()));
	p2->setPawn(new Pawn(p2->getRole()->getColor()));

	std::cout << std::endl;
	std::cout << "-------------------- Roles --------------------" << std::endl;
	std::cout << p1->getName() << " is a " << p1->getRole()->getName() << std::endl;
	std::cout << p2->getName() << " is a " << p2->getRole()->getName() << std::endl;
	std::cout << "-----------------------------------------------" << std::endl;
	std::cout << std::endl;

	//populate individual player hands
	for (int i = 0; i < deck->getPlayerHand().size(); i++){
		p1->addCard(deck->getPlayerHand().at(i));
		p2->addCard(deck->getPlayerHand().at(i + 1));
		i = i + 1;
	}

	//decisions decisions - hard coded atm. will be possibly implemetned as a functon of class game.
	bool p1HasEvent = false;
	bool p2HasEvent = false;
	int o;
	std::string option;
	start: {

		//start of players turn
		p1->setCurrentCity(map[0]);
		p2->setCurrentCity(map[0]);
		
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

	


	endgame:

	//delete all pointers
	for (auto it = cities.begin(); it != cities.end(); it++)
		delete *it;
	cities.clear();

	for (auto it = events.begin(); it != events.end(); it++)
		delete *it;
	events.clear();

	for (auto it = epidemics.begin(); it != epidemics.end(); it++)
		delete *it;
	epidemics.clear();

	delete deck, p1, p2;
	deck, p1, p2 = NULL;
	
	return 0;
}
