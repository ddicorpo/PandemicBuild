#pragma once
#include <iostream>
#include <string>

class PlayerCard {
public:
	PlayerCard();
	~PlayerCard();
	virtual void getAttributes();
	virtual std::string getType();
};