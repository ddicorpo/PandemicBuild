#ifndef PAWN_H
#define PAWN_H

#include <string>
class Pawn
{
public:
	Pawn();
	Pawn(std::string color);

	// setters
	void setColor(std::string color);

	std::string getColor();
private:
	std::string color;
};






#endif