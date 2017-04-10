#include "Serialize.h"
#include <fstream>

Serialize::Serialize(){}
Serialize::~Serialize(){}

void Serialize::savePlayers(std::vector<Player*> players){
	std::ofstream thefile;
	thefile.open("_playerssave");
	for (int k = 0; k < players.size(); k++){
		thefile << players.at(k)->getName() << " " << players.at(k)->getRoleId() << " " << players.at(k)->getCurrentCity() << "|";
		for (int i = 0; i < players.at(k)->getHand().size(); i++){
			thefile << players.at(k)->getHand().at(i)->getAttributes() << " ";
		}
		thefile << "\n";
	}
	thefile.close();
	std::cout << "Players Saved" << std::endl;
}
void Serialize::saveDeck(std::vector<PlayerCard*> deck){
	std::ofstream thefile;
	thefile.open("_decksave");
	for (int i = 0; i < deck.size(); i++){
		thefile << deck.at(i)->getAttributes() << "\n";
	}
}

void Serialize::saveManager(){

}

//Player Serialize::loadPlayers(){
//
//}
//
//Deck Serialize::loadDeck(){
//
//}
//
//GameManager Serialize::loadManager(){
//
//}