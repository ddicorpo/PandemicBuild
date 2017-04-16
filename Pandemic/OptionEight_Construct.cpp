#include <iostream>
#include "OptionEight_Construct.h"
#include "GameManager.h"

OptionEight_Construct::OptionEight_Construct(Player* player, std::vector<MapCity*> map)
{
	this->player = player;
	this->map = map;
}

void OptionEight_Construct::execute()
{
	for (int i = 0; i < player->getHand().size(); i++)
	{
		if (player->getHand()[i]->getName() == player->getCurrentCity()->getName())
		{
			for (int a = 0; a < map.size(); a++)
			{
				if (map[a]->getName() == player->getCurrentCity()->getName() && map[a]->getResearchStation() == false)
				{
					map[a]->setResearchStation();
					player->getHand().erase(player->getHand().begin() + i);
				}
			}

			break;
		}
	}
}