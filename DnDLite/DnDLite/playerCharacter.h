#pragma once

/*
Matthew Nelli
Professor Jonathan S.Weissman
CIS 554 - M401 Object Oriented Programming in C++
Syracuse University
HW #5 - Any program
8 / 23 / 21
header file for player character. Has all required player character  functions. Creation, combat, and health management
*/

#include <string>
#include <vector>
#include "Character.h"

using std::string;
using std::vector;

class playerCharacter : public Character
{

	//value for the total cost of all items
	int total = 10;
	int charasma;
	int armor;
	int strength; 

public:
	//Provie constructor
	explicit playerCharacter(string characterName, int health, int armor, int strength, int charasma);

	//Provide getters for all variables
	
	int getArmor();
	int getStrength();
	int getCharasma();

	//Provide setters for all variables
	void setArmor(int armor);
	void setStrength(int strength);
	void setCharasma(int charasma);
	void copy(playerCharacter test);
};


