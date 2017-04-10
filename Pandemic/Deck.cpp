#include <iostream>
#include <random>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include "Deck.h"

Deck::Deck(int playercount) {
	pcount = playercount;
}
Deck::~Deck() {}

void Deck::getAttributes(){
	std::cout << "This is a player deck" << std::endl;
}

void Deck::createDeck(std::vector<PlayerCard*> cities, std::vector<PlayerCard*> events, std::vector<PlayerCard*> epidemics) {
	int randIndex;

	//populate preDeck
	for (size_t i = 0; i < cities.size(); i++) {
		preDeck.push_back(cities.at(i));
	}

	for (size_t i = 0; i < events.size(); i++) {
		preDeck.push_back(events.at(i));
	}

	//populate playerHand with cards for players
	int bound;
	if (pcount == 2)
		bound = 8;
	else if (pcount == 3)
		bound = 9;
	else if (pcount == 4)
		bound = 8;

	for (int a = 0; a < bound; a++){
		randIndex = rand() % preDeck.size();

		playerHand.push_back(preDeck.at(randIndex));
		preDeck.erase(preDeck.begin() + randIndex);
	}

	int psize = preDeck.size();

	//create final playerdeck
	for (int i = 0; i < psize; i++) {
		if (i == psize)
			break;

		if (preDeck.size() != 0){
			randIndex = rand() % preDeck.size();

			if (i % 12 == 11){
				deck.push_back(epidemics.at(0));
			}

			deck.push_back(preDeck.at(randIndex));
			preDeck.erase(preDeck.begin() + randIndex);
		}
	}
}

std::vector<PlayerCard*> Deck::getDeck() {
	return deck;
}

std::vector<PlayerCard*> Deck::getPlayerHand() {
	return playerHand;
}

void Deck::displayDeck(){
	//for debugging
	std::cout << "Deck Size = " << deck.size() << std::endl;
	for (int i = 0; i < deck.size(); i++) {
		deck[i]->getAttributes();
		std::cout << "Card: " << i << std::endl;
		std::cout << std::endl;
	}
}
