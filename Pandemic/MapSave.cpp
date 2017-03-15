// MapSave.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Map.h"
#include <fstream>



int _tmain(int argc, _TCHAR* argv[])
{
	Player player1("Memo");
	Player player2("Eric");
	Player player3("Tom");

	std::vector<MapCity*> mapCities;
	std::vector<MapCity*> neighbours;


	std::vector<MapCity*> dubaiNeighbours;
	std::vector<MapCity*> dublinNeighbours;
	std::vector<MapCity*> parisNeighbours;


	MapCity *Dublin(new MapCity("Dublin"));
	MapCity *Paris(new MapCity("Paris"));
	MapCity *Dubai(new MapCity("Dubai"));


	dubaiNeighbours.push_back(Paris);
	dubaiNeighbours.push_back(Dublin);


	dublinNeighbours.push_back(Dubai);
	dublinNeighbours.push_back(Paris);

	parisNeighbours.push_back(Dubai);
	parisNeighbours.push_back(Dublin);


	Dublin->setNeighbours(dublinNeighbours);
	Dubai->setNeighbours(dubaiNeighbours);
	Paris->setNeighbours(parisNeighbours);

	int playerInput;

	std::cout << "Welcome player! Do you want to: 1) Start a new game? " << std::endl;
	std::cout << "2) load your last saved game?" << std::endl;
	std::cin >> playerInput;

	if (playerInput == 1)
	{
		player1.setCity(Dublin);
		player2.setCity(Dublin);
		player3.setCity(Dublin);
		std::cout << "Hello players and welcome to the map save/load function! First we shall move the characters." << std::endl;

		player1.move();
		player2.move();
		player3.move();

		std::ofstream saveFile("LoadLastLocation.txt");
		if (saveFile.is_open())
		{
			saveFile << player1.getCurrentCity()->getName() << std::endl;
			saveFile << player2.getCurrentCity()->getName() << std::endl;
			saveFile << player3.getCurrentCity()->getName();
		}

		else
		{
			std::cout << "cannot open file " << std::endl;
		}

	}

	else if (playerInput == 2)
	{
		std::string line;
		std::ifstream infile("LoadLastLocation.txt");
		if (infile.is_open())
		{
			while (!infile.eof())
			{
				std::string player1City, player2City, player3City;

				getline(infile, player1City, '\n');
				getline(infile, player2City, '\n');
				getline(infile, player3City, '\n');
				
				MapCity* playerOne(new MapCity(player1City));
				MapCity* playerTwo(new MapCity(player2City));
				MapCity* playerThree(new MapCity(player3City));

				player1.setCity(playerOne);
				player2.setCity(playerTwo);
				player3.setCity(playerThree);

				std::cout << "Player 1 is currently at: " << player1.getCurrentCity()->getName() << std::endl;
				std::cout << "Player 2 is currently at: " << player2.getCurrentCity()->getName() << std::endl;
				std::cout << "Player 3 is currently at: " << player3.getCurrentCity()->getName() << std::endl;
			}
		}
	


		
	}
	

	
	void addCities()
	{

	}

	//std::string mapCity;
	//int pop;
	/*
	while (!infile.eof())
	{
		std::string name;
		std::string neighbourName;
		infile >> name;
		infile >> neighbourName;
		//mapCities.push_back(new MapCity(name));
		MapCity *neighbour(new MapCity(neighbourName));
		neighbours.push_back(new MapCity(neighbourName));
		mapCities.push_back(new MapCity(name, neighbours));
		
	}
	*/
	
//	Player player2("Eric", mapCities.at(40));

	

	std::cout << "Now that the players have moved, we should save the file. The program will exit after and we will open it again with last known locations!";
	

	//player1.move();
	//player2.move();
	//player1.move();

	 system("pause");
	return 0;
}

