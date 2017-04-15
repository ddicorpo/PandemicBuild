#include <iostream>
#include <string>
#include <vector>
#include "Player.h"

Player::Player(std::string n){
	name = n;
	reference_card = reference_cards::instance();
};

Player::~Player(){};

void Player::addCard(PlayerCard *card){
	hand.push_back(card);
}


std::vector<PlayerCard*> Player::getHand(){
	return hand;
}

std::string Player::getName(){
	return name;
}

void Player::displayHand()
{
	for (int i = 0; i < hand.size(); i++) {
		std::cout << hand[i]->getAttributes() << std::endl;
		std::cout << "----------------------" << std::endl;
	}
}

void Player::getReferenceCard(){
	reference_card->output();
}

void Player::setRole(roles* r){
	role = r;
}

roles* Player::getRole(){
	return role;
}

void Player::setRoleId(int i){
	roleId = i;
}

int Player::getRoleId(){
	return roleId;
}

void Player::setPawn(Pawn * p){
	pawn = p;
}

Pawn* Player::getPawn()
{
	return pawn;
}

void Player::move()
{
	int playerChoice;
	std::cout << "Here is the list of " << currentCity->getName() << "'s neighbours: " << std::endl;
	currentCity->getListOfNeighbours();
	std::cout << "Where would you like to move? (pick a number): " << std::endl;
	std::cin >> playerChoice;

	while ((!std::cin >> playerChoice) && (playerChoice < 1 || playerChoice > currentCity->getNeighbours().size()))
	{
	}

	switch (playerChoice)
	{
	case 1:
		std::cout << name << " is moving to  " << currentCity->getNeighbours().at(0)->getName() << " . . " << std::endl;

		setCurrentCity(currentCity->getNeighbours().at(0));
		std::cout << "You are now in: " << currentCity->getName() << std::endl;
		/*std::cout << currentCity->getName() << "'s neighbours are: " << std::endl;
		currentCity->getListOfNeighbours();*/
		break;

	case 2:
		std::cout << name << " is moving to " << currentCity->getNeighbours().at(1)->getName() << " . . " << std::endl;
		setCurrentCity(currentCity->getNeighbours().at(1));
		std::cout << "You are now in: " << currentCity->getName() << std::endl;
		/*std::cout << currentCity->getName() << "'s neighbours are: " << std::endl;
		currentCity->getListOfNeighbours();*/
		break;

	case 3:
		std::cout << name << " is moving to " << currentCity->getNeighbours().at(2)->getName() << " . . " << std::endl;
		setCurrentCity(currentCity->getNeighbours().at(2));
		std::cout << "You are now in: " << currentCity->getName() << std::endl;
		//std::cout << currentCity_h->getName() << "'s neighbours are: " << std::endl;
		//currentCity_h->getListOfNeighbours();
		break;
	case 4:
		std::cout << name << " is moving to " << currentCity->getNeighbours().at(3)->getName() << " . . " << std::endl;
		setCurrentCity(currentCity->getNeighbours().at(3));
		std::cout << "You are now in: " << currentCity->getName() << std::endl;
		//std::cout << currentCity_h->getName() << "'s neighbours are: " << std::endl;
		//currentCity_h->getListOfNeighbours();
		break;

	//case 5:
	//	std::cout << name_h << " is moving to " << currentCity_h->getNeighbours().at(4)->getName() << " . . " << std::endl;
	//	currentCity_h = currentCity_h->getNeighbours().at(4);
	//	std::cout << "You are now in: " << currentCity_h->getName() << std::endl;
	//	//std::cout << currentCity_h->getName() << "'s neighbours are: " << std::endl;
	//	//currentCity_h->getListOfNeighbours();
	//	break;
	//case 6:
	//	std::cout << name_h << " is moving to " << currentCity_h->getNeighbours().at(5)->getName() << " . . " << std::endl;
	//	currentCity_h = currentCity_h->getNeighbours().at(5);
	//	std::cout << "You are now in: " << currentCity_h->getName() << std::endl;
	//	//std::cout << currentCity_h->getName() << "'s neighbours are: " << std::endl;
	//	//currentCity_h->getListOfNeighbours();
	//	break;

	case 0:

		break;

	}
}
void Player::removeCube()
{
	if (currentCity->getInfected() != true)
	{
		std::cout << "City isn't infected. Try another choice!" << std::endl;
	}
    else
	{
		int playerChoice;
		std::cout << "Here is the list of cubes for this city. " << std::endl;
		currentCity->displayCubes();
		std::cout << "What cube would you like to remove?" << std::endl;
		std::cin >> playerChoice;
		
			switch (playerChoice)
			{
			case 1:
				if (currentCity->getBlackCubes() == 0)
				{
					std::cout << "No more black cubes! No need to remove." << std::endl;
				}
				
				else
				{
					currentCity->removeBlackCube();
				}
				
			case 2:
				if (currentCity->getBlueCubes() == 0)
				{
					std::cout << "No more blue cubes! No need to remove." << std::endl;
				}
						
				else
				{
					currentCity->removeBlueCube();
				}
						
			case 3:
				if (currentCity->getRedCubes() == 0)
		     	{
					std::cout << "No more red cubes! No need to remove." << std::endl;
				}
								
				else
				{
					currentCity->removeRedCube();
				}
								
			case 4:
				if (currentCity->getYellowCubes() == 0)
				{
					std::cout << "No more yellow cubes! No need to remove." << std::endl;
				}
										
				else
				{
					currentCity->removeYellowCube();
				}
			}
	}
}


void Player::setCurrentCity(MapCity* currentCity)
{
	this->currentCity = currentCity;
}

std::string Player::getCurrentCity()
{
	return currentCity->getName();
}