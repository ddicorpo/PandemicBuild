#include "reference_cards.h"
#include <string>
#include <iostream>

reference_cards* reference_cards::s_instance = NULL;

reference_cards::reference_cards()
{

}

void reference_cards::output()
{
	std::cout << "Please choose from one of the actions below." << std::endl
		<< "1. Move to an adjacent city" << std::endl
		<< "2. Fly to a city by discarding the player card of that city" << std::endl
		<< "3. Fly to any city by discarding the player card of the city that the player is currently on" << std::endl
		<< "4. If currently on a research center move to another city with a research center" << std::endl
		<< "5. Research a cure if the player is at a city with a research center" << std::endl
		<< "6. Trade a player card of a city if and only if both parties are at the same city" << std::endl
		<< "7. Remove one infection cube from the current city" << std::endl
		<< "8. Construct a research station by discarding the player card of that city. Required to also be located at the city" << std::endl
		<< "9. End Turn" << std::endl
		<< "10. Save/Exit" << std::endl << std::endl;
}

reference_cards* reference_cards::instance()
{
	if (!s_instance)
		s_instance = new reference_cards;
	return s_instance;
}