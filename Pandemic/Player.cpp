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
		hand[i]->getAttributes();
		std::cout << "----------------------" << std::endl;
	}
}

void Player::getReferenceCard(){
	reference_card->output();
}