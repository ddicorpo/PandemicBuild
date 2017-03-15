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

int main() {
	std::srand((int)time(0));

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
	

	//creating event cards
	events.push_back(new Event("Airlift", "Move any one pawn to any city. Get permission before moving another player's pawn."));
	events.push_back(new Event("One Quiet Night", "The next player to begin the Playing The Infection phase of their turn may skip that phase entirely."));
	events.push_back(new Event("Forecast", "Examine the top 6 cards of the Infection Draw Pile, rearrange them in the order of your choice, then place them back on the pile."));
	events.push_back(new Event("Government Grant","Add a Research Station to any city for free."));
	events.push_back(new Event("Resilient Population", "Take a card from the Infection Discard Pile and remove it from the game."));
	
	//create a deck
	Deck *deck(new Deck());
	deck->createDeck(cities, events, epidemics);
	//output deck
	//deck->displayDeck();


	
	
	
	std::cout << "Welcome to Pandemic: Build 1." << std::endl;
	std::cout << "===============================================" << std::endl;
	std::cout << "What is the name of player 1: ";
	std::string player1;
	std::cin >> player1;
	std::cout << "What is the name of player 2: ";
	std::string player2;
	std::cin >> player2;

	//initialize 2 players
	Player *p1(new Player(player1));
	Player *p2(new Player(player2));

	//p1->getReferenceCard();
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

		std::cout << p1->getName() << "'s turn." << std::endl;
		std::cout << "These are your cards." << std::endl;
		std::cout << std::endl;
		p1->displayHand();
		std::cout << std::endl;
		o = 1;
		std::cout << "Below are your options. Enter an option number to make a decision." << std::endl;
		std::cout << o << " : do nothing because city card are useless in this version." << std::endl;
		for (int i = 0; i < p1->getHand().size(); i++) {
			if (p1->getHand()[i]->getType() != "city") {
				p1HasEvent = true;
			}
		}

		if (p1HasEvent == true) {
			o = 2;
			std::cout << o << " : use 1 event card." << std::endl;
		}
		std::cout << o + 1 << " : check actions on reference card" << std::endl;
		std::cout << o + 2 << " : end the game." << std::endl;
		std::cin >> option;

		options: {
			if (option == "1") {
				std::cout << "Next players turn" << std::endl;
				goto proceed;
			}
			else if (option == "2" && p1HasEvent == true) {
				std::cout << "Turns out events are useless too. Next players turn.";
				goto proceed;
			}


			else if (option == std::to_string(o + 1)) {
				p1->getReferenceCard();
				std::cout << "You have up to 4 actions to do, you can either pick a number to perform the action, or skip your actions by pressing 0. What would you like to do?" << std::endl;
				int playerTurns = 4;
				int playerInput;
				std::cin >> playerInput;
				while (playerTurns <= 0 || playerInput != 0)
				{
					if (playerInput == 1 || playerInput == 2 || playerInput == 3 || playerInput == 4)
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
				}
				

			}

			else if (option == std::to_string(o + 2)) {
				std::cout << "Game ended!" << std::endl;
				goto endgame;
			}
			else {
				std::cout << "Wrong input. Try again!" << std::endl;
				goto options;
			}
		}

		std::cout << "Drawing 2 Infection Cards from infection deck . . . . " << std::endl;
		srand(time(0));    
		int card1 = rand() % infectionCardDeck.size();

		infectionCardDeck[card1]->infect();
		infectionCardDeck.erase(infectionCardDeck.begin() + card1);
		infectionCardDiscard.push_back(infectionCardDeck.at(card1)); 
		
		int card2 = rand() % infectionCardDeck.size();

		infectionCardDeck[card2]->infect();
		infectionCardDeck.erase(infectionCardDeck.begin() + card2);
		infectionCardDiscard.push_back(infectionCardDeck.at(card2));

		 proceed:
		//next players turn
		std::cout << p2->getName() << "'s turn." << std::endl;
		std::cout << "These are your cards." << std::endl;
		std::cout << std::endl;
		p2->displayHand();
		o = 1;
		std::cout << std::endl;
		std::cout << "Below are your options. Enter an option number to make a decision." << std::endl;
		std::cout << o << " : do nothing because city card are useless in this version." << std::endl;
		for (int i = 0; i < p2->getHand().size(); i++) {
			if (p2->getHand()[i]->getType() != "city") {
				p2HasEvent = true;
			}
		}

		if (p2HasEvent == true) {
			o = 2;
			std::cout << o << " : use 1 event card." << std::endl;
		}
		std::cout << o + 1 << " : check actions on reference card" << std::endl;
		std::cout << o + 2 << " : end the game." << std::endl;
		std::cin >> option;

		options2: {
			if (option == "1") {
				std::cout << "Next players turn." << std::endl;
				goto proceed2;
			}
			else if (option == "2" && p2HasEvent == true) {
				std::cout << "Turns out events are useless too. Next players turn." << std::endl;
				goto proceed2;
			}
			else if (option == std::to_string(o + 1)) {
				p2->getReferenceCard();
				std::cout << "You have up to 4 actions to do, you can either pick a number to perform the action, or skip your actions by pressing 0. What would you like to do?" << std::endl;
				int playerTurns = 4;
				int playerInput;
				std::cin >> playerInput;
				while (playerTurns != 0 || playerInput != 0)
				{
					if (playerInput > 0 && playerInput << 9)
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
				}


			}

			else if (option == std::to_string(o + 2)) {
				std::cout << "Game ended!" << std::endl;
				goto endgame;
			}
			else {
				std::cout << "Wrong input. Try again!" << std::endl;
				goto options2;
			}
		}
		int card3 = rand() % infectionCardDeck.size();

		infectionCardDeck[card3]->infect();
		infectionCardDeck.erase(infectionCardDeck.begin() + card3);
		infectionCardDiscard.push_back(infectionCardDeck.at(card3));

		int card4 = rand() % infectionCardDeck.size();

		infectionCardDeck[card4]->infect();
		infectionCardDeck.erase(infectionCardDeck.begin() + card4);
		infectionCardDiscard.push_back(infectionCardDeck.at(card4));
			  proceed2:
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
