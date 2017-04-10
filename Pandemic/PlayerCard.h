#pragma once
#include <iostream>
#include <string>

class PlayerCard {
public:
	PlayerCard();
	~PlayerCard();
	virtual std::string getAttributes();
	virtual std::string getType();
	virtual std::string getName();
};