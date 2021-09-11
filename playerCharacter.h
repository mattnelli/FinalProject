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
using std::string;
using std::vector;

class playerCharacter
{
	//Strings for names and desription
	string characterName;

	//Character stats
	int health;
	int armor;
	int strength;
	int charasma;

	//value for the total cost of all items
	int total = 10;


public:
	//Provie constructor
	explicit playerCharacter(string* characterName, int health, int armor, int strength, int charasma);

	//Provide getters for all variables
	string getCharacterName();
	int getHealth();
	int getArmor();
	int getStrength();
	int getCharasma();

	//Provide setters for all variables
	void setCharacterName(string characterName);
	void setArmor(int armor);
	void setHealth(int health);
	void setStrength(int strength);
	void setCharasma(int charasma);

	void recieveAttack(vector<int> attack);
	vector<int> attack();
};


