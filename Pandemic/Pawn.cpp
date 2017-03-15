#include "Pawn.h"


Pawn::Pawn(){};

Pawn::Pawn(std::string color) : color(color){};

void Pawn::setColor(std::string color)
{
	this->color = color;
}

std::string Pawn::getColor()
{
	return color;
}