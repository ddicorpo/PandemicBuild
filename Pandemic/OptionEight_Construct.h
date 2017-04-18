#pragma once
#include <iostream>
#include "Strategy.h"
#include "Player.h"
#include "MapCity.h"
#include <vector>

class OptionEight_Construct : public Strategy
{
private:
	Player* player;
	std::vector<MapCity*> map;
public:
	OptionEight_Construct(Player*, std::vector<MapCity*>);
	void execute();
};

