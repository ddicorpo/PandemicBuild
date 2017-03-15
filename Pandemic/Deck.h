#pragma once
#include <iostream>
#include <vector>
#include "PlayerCard.h"

class Deck {
public:
	Deck();
	~Deck();
	void getAttributes();
	void createDeck(std::vector<PlayerCard*> cities, std::vector<PlayerCard*> events, std::vector<PlayerCard*> epidemics);
	std::vector<PlayerCard*> getDeck();
	std::vector<PlayerCard*> getPlayerHand();
	void displayDeck();
private:
	std::vector<PlayerCard*> preDeck;
	std::vector<PlayerCard*> deck;
	std::vector<PlayerCard*> playerHand;
};