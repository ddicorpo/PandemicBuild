#pragma once
#include <iostream>
#include "Strategy.h"
#include "Player.h"
#include "MapCity.h"
#include <vector>

class OptionFive_Cure : public Strategy
{
private:
	Player* player;
	std::vector<MapCity*> map;
public:
	OptionFive_Cure(Player*, std::vector<MapCity*>);
	void execute();
};