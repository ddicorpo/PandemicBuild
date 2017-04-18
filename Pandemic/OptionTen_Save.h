#pragma once
#include <iostream>
#include "Strategy.h"
#include "Player.h"
#include "MapCity.h"
#include <vector>

class OptionTen_Save : public Strategy
{
private:
	Player* player;
	std::vector<MapCity*> map;
public:
	OptionTen_Save(Player*, std::vector<MapCity*>);
	void execute();
};