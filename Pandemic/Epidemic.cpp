#include <iostream>
#include <string>
#include "Epidemic.h"

Epidemic::Epidemic(std::string name){
	this->name = name;
	type = "epidemic";
	atr ="1 - Increase\n"
		"Move Infection rate marker forward 1 space.\n"
		"2 - Infect\n"
		"Draw the bottom card from the Ingection Deck nd put 3 cubes on that city. Discard that card.\n"
		"3 - Intensify\n"
		"Shuffle the cards in the Infection Discard Pile and put them on top of the Infection Deck.";
}

Epidemic::~Epidemic(){}

std::string Epidemic::getAttributes()
{
	return name + ":" + type;
}

std::string Epidemic::getType()
{
	return type;
}
