#pragma once
#include <iostream>
#include "Strategy.h"
#include "Player.h"
#include "MapCity.h"
#include <vector>

class OptionFour_FlyResearch : public Strategy
{
private:
	Player* player;
	std::vector<MapCity*> map;
public:
	OptionFour_FlyResearch(Player*, std::vector<MapCity*>);
	void execute();
};

