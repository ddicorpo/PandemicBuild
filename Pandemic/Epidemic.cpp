#include <iostream>
#include <string>
#include "Epidemic.h"

Epidemic::Epidemic(){
	type = "epidemic";
}

Epidemic::~Epidemic(){}

void Epidemic::getAttributes()
{
	std::cout << "Epidemic!" << std::endl;
	std::cout << "1 - Increase" << std::endl;
	std::cout << "Move Infection rate marker forward 1 space." << std::endl;
	std::cout << "2 - Infect" << std::endl;
	std::cout << "Draw the bottom card from the Ingection Deck nd put 3 cubes on that city. Discard that card." << std::endl;
	std::cout << "3 - Intensify" << std::endl;
	std::cout << "Shuffle the cards in the Infection Discard Pile and put them on top of the Infection Deck." << std::endl;
}

std::string Epidemic::getType()
{
	return type;
}
