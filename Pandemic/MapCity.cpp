#include "MapCity.h"
#include "GameManager.h"
#include "InfectionCard.h"

MapCity::MapCity(std::string name, std::vector <MapCity*> neighbours) :name(name), neighbours(neighbours){};
MapCity::MapCity(){};

MapCity::MapCity(std::string name)
{
	this->name = name;
}

std::string MapCity::getName()
{
	return name;
	std::cout << std::endl;
}

std::vector<MapCity*> MapCity::getNeighbours()
{
	return neighbours;
}


void MapCity::getListOfNeighbours()
{
	for (int i = 0; i < neighbours.size(); i++)
	{
		std::cout << i + 1 << ") " << neighbours[i]->getName() << std::endl;
	}
};


void MapCity::setNeighbours(std::vector<MapCity*> neighbours)
{
	this->neighbours = neighbours;
}

void MapCity::addBlackCube()
{
	GameManager::Instance().updateCubes("black", 1);
	blackCubes += 1;
	if (blackCubes >= 4)
		outbreak("black");

	isInfected = true;
}

void MapCity::addBlueCube()
{
	GameManager::Instance().updateCubes("blue", 1);
	blueCubes += 1;
	if (blueCubes >= 4)
		outbreak("blue");

	isInfected = true;
}

void MapCity::addRedCube()
{
	GameManager::Instance().updateCubes("red", 1);
	redCubes += 1;
	if (yellowCubes >= 4)
		outbreak("red");

	isInfected = true;
}
void MapCity::addYellowCube()
{
	GameManager::Instance().updateCubes("yellow", 1);
	yellowCubes += 1;
	if (yellowCubes >= 4)
		outbreak("yellow");

	isInfected = true; 
}

void MapCity::outbreak(std::string color)
{
	if (color == "black")
	{
		for (int i = 0; i < neighbours.size(); i++)
		{
			neighbours[i]->addBlackCube();
		}
	}


	else if (color == "blue")
	{
		for (int i = 0; i < neighbours.size(); i++)
		{
			neighbours[i]->addBlueCube();
		}
	}


	if (color == "red")
	{
		for (int i = 0; i < neighbours.size(); i++)
		{
			neighbours[i]->addRedCube();
		}
	}


	if (color == "yellow")
	{
		for (int i = 0; i < neighbours.size(); i++)
		{
			neighbours[i]->addYellowCube();
		}
	}
}

void MapCity::epidemic(std::string color){

}

void MapCity::removeBlackCube()
{
	blackCubes -= 1;
	GameManager::Instance().updateCubes("black", -1);
	
		if (blackCubes == 0)
		{
			isInfected = false;
			/*isInfectedBlack = false;*/
		}
}

void MapCity::removeBlueCube()
{
	blueCubes -= 1;
	GameManager::Instance().updateCubes("blue", -1);
	
		if (blueCubes == 0)
		{
			isInfected = false;
			//isInfectedBlue = false;
		}
	
}

void MapCity::removeRedCube()
{
	redCubes -= 1;
	GameManager::Instance().updateCubes("red", -1);
	
		if (redCubes == 0)
		{
			isInfected = false;
			/*isInfectedBlack = false;*/
		}
	
}

void MapCity::removeYellowCube()
{
	yellowCubes -= 1;
	GameManager::Instance().updateCubes("yellow", -1);
	
		if (yellowCubes == 0)
		{
			isInfected = false;
			/*isInfectedYellow = false;*/
		}
	
}

bool MapCity::getInfected()
{
	return isInfected;
}

int MapCity::getBlackCubes()
{
	return blackCubes;
}

int MapCity::getBlueCubes()
{
	return blueCubes;
}

int MapCity::getYellowCubes()
{
	return yellowCubes;
}

int MapCity::getRedCubes()
{
	return redCubes;
}

void MapCity::displayCubes()
{
	
	std::cout << "Here are the list of cubes: " << std::endl;
	std::cout << "Black: " << blackCubes << std::endl;
	std::cout << "Blue: " << blueCubes << std::endl;
	std::cout << "Red: " << redCubes << std::endl;
	std::cout << "Yellow:  " << yellowCubes << std::endl;
}
