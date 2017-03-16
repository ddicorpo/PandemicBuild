#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "PlayerCard.h"
#include "reference_cards.h"
#include "MapCity.h"
#include "roles.h"
#include "Pawn.h"

class Player{
public:
	Player(std::string name);
	~Player();
	void addCard(PlayerCard *card);
	std::vector<PlayerCard*> getHand();
	std::string getName();
	void displayHand();
	void getReferenceCard();
	void setRole(roles* role);
	roles* getRole();
	void setPawn(Pawn* p);
	Pawn* getPawn();

	void move();
	void setCurrentCity(MapCity* currentCity);
	std::string getCurrentCity();


private:
	std::string name;
	std::vector<PlayerCard*> hand;
	reference_cards* reference_card;
	roles *role;
	Pawn *pawn;
	MapCity* currentCity;
};