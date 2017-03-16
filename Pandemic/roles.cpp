#include "roles.h"
#include <cstdlib>
#include <iostream>
#include <string>

roles::roles()
{

}

roles::roles(int type)
{
	switch (type)
	{
	case 0:
		roleID = 0;
		name = "Scientist";
		color = "White";
		skill = "Scientist Skill: Requires only 4 player cards to research a cure";
		role_scientist();
		break;
	case 1:
		roleID = 1;
		name = "Contingency Planner";
		color = "Light Blue";
		skill = "Contingency Planner Skill: Can take and store event cards in discard pile for a second use";
		role_contingency_planner();
		break;
	case 2:
		roleID = 2;
		name = "Operations Expert";
		color = "Light Green";
		skill = "Operations Expert Skill: Can plant a research station without player card, and can move to any research station as action";
		role_operations_expert();
		break;
	case 3:
		roleID = 3;
		name = "Medic";
		color = "Orange";
		skill = "Medic Skill: Remove all cubes of 1 color with one action, once cure is found, remove all cubes of cured disease on entrance to city";
		role_medic();
		break;
	case 4:
		roleID = 4;
		name = "Dispatcher";
		color = "Pink";
		skill = "Dispatcher Skill: Can move other pawns, and move a pawn to another pawns location";
		role_dispatcher();
		break;
	case 5:
		roleID = 5;
		name = "Researcher";
		color = "Brown";
		skill = "Researcher Skill: Can give any player card to any player as long as located in the same city";
		role_researcher();
		break;
	case 6:
		roleID = 6;
		name = "Quarantine Specialist";
		color = "Dark Green";
		skill = "Quarantine Specialist Skill: Current city and adjacent cities cannot be infected";
		role_quarantine_specialist();
		break;
	};
}

void roles::output()
{
	std::cout << "Role ID: " << roleID << std::endl;
	std::cout << "Role Name: " << name << std::endl;

	if (roleID == 0)
	{
		std::cout << "Scientist Skill: Requires only 4 player cards to research a cure" << std::endl;
	}
	else if (roleID == 1)
	{
		std::cout << "Contingency Planner Skill: Can take and store event cards in discard pile for a second use" << std::endl;
	}
	else if (roleID == 2)
	{
		std::cout << "Operations Expert Skill: Can plant a research station without player card, and can move to any research station as action" << std::endl;
	}
	else if (roleID == 3)
	{
		std::cout << "Medic Skill: Remove all cubes of 1 color with one action, once cure is found, remove all cubes of cured disease on entrance to city" << std::endl;
	}
	else if (roleID == 4)
	{
		std::cout << "Dispatcher Skill: Can move other pawns, and move a pawn to another pawns location" << std::endl;
	}
	else if (roleID == 5)
	{
		std::cout << "Researcher Skill: Can give any player card to any player as long as located in the same city" << std::endl;
	}
	else if (roleID == 6)
	{
		std::cout << "Quarantine Specialist Skill: Current city and adjacent cities cannot be infected" << std::endl;
	}

	std::cout << std::endl;
}

void roles::role_scientist()
{
	skill_scientist = true;
}

void roles::role_contingency_planner()
{
	skill_contingency_planner = true;
}

void roles::role_operations_expert()
{
	skill_operations_expert = true;
}

void roles::role_medic()
{
	skill_medic = true;
}

void roles::role_dispatcher()
{
	skill_dispatcher = true;
}

void roles::role_researcher()
{
	skill_researcher = true;
}

void roles::role_quarantine_specialist()
{
	skill_quarantine_specialist = true;
}

std::string roles::getColor()
{
	return color;
}

std::string roles::getName() {
	return name;
}

std::string roles::getSkill() {
	return skill;
}