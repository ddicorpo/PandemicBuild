#pragma once
#include <vector>
#include <iostream>
#include "Player.h"
#include "PlayerCard.h"
#include "GameManager.h"

class Serialize {
public:
	Serialize();
	~Serialize();

	void savePlayers(std::vector<Player*> p);
	void saveDeck(std::vector<PlayerCard*> d);
	void saveManager();

	void loadPlayers();
	void loadDeck();
	void loadManager();
};