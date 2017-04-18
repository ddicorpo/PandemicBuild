#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "PlayerCard.h"
#include "reference_cards.h"
#include "MapCity.h"
#include "roles.h"
#include "Pawn.h"
#include "Strategy.h"
#include "Player.h"
#include "MapCity.h"
#include <vector>

class Player{
public:
	Player(std::string name, Strategy *initStrategy);
	~Player();

	void setHand(std::vector<PlayerCard> h);
	std::vector<PlayerCard*> getHand();
	std::string getName();
	
	void addCard(PlayerCard *card);
	void displayHand();
	void setHand(std::vector<PlayerCard*> hand);
	void handcheck();
	void getReferenceCard();
	
	void setRole(roles* role);
	roles* getRole();
	int getRoleId();
	void setRoleId(int i);
	
	void setPawn(Pawn* p);
	Pawn* getPawn();

	void move();
	void setCurrentCity(MapCity* currentCity);
	MapCity* getCurrentCity();

	//called to set player object with new strategy
	void setStrategy(Strategy *newStrategy)
	{
		this->strategy = newStrategy;
	}

	//Executed current strategy's execute function
	void executeStrategy()
	{
		return this->strategy->execute();
	}
private:
	std::string name;
	std::vector<PlayerCard*> hand;
	reference_cards* reference_card;
	roles *role;
	int roleId;
	Pawn *pawn;
	MapCity* currentCity;
	Strategy *strategy;
};