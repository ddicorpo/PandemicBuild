#pragma once
#include <iostream>
#include "Strategy.h"
#include "Player.h"
#include "MapCity.h"
#include <vector>

class OptionTwo_Fly : public Strategy
{
private:
	Player* player;
	std::vector<MapCity*> map;
public:
	OptionTwo_Fly(Player*, std::vector<MapCity*>);
	void execute();
};

