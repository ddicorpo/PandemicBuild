#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "PlayerCard.h"
#include "reference_cards.h"

class Player{
public:
	Player(std::string name);
	~Player();
	void addCard(PlayerCard *card);
	std::vector<PlayerCard*> getHand();
	std::string getName();
	void displayHand();
	void getReferenceCard();
private:
	std::string name;
	std::vector<PlayerCard*> hand;
	reference_cards* reference_card;
};