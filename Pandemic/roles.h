#include <string>

#pragma once
class roles
{
public:
	roles();
	roles(int);
	void output();
	std::string getColor();
	std::string getName();
	std::string getSkill();
private:
	int roleID;
	std::string name;
	std::string color;
	std::string skill;
	bool skill_dispatcher = false;
	bool skill_medic = false;
	bool skill_scientist = false;
	bool skill_researcher = false;
	bool skill_quarantine_specialist = false;
	bool skill_operations_expert = false;
	bool skill_contingency_planner = false;
	void role_scientist();
	void role_contingency_planner();
	void role_operations_expert();
	void role_medic();
	void role_dispatcher();
	void role_researcher();
	void role_quarantine_specialist();
};