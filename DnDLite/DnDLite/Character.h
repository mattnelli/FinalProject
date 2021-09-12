#pragma once

/*
Matthew Nelli
Professor Jonathan S.Weissman
CIS 554 - M401 Object Oriented Programming in C++
Syracuse University

9 /  / 21
*/

#include <string>
#include <vector>
using std::string;
using std::vector;

class Character
{
	//Strings for names and desription
	string characterName;

	//Character stats
	int health;
	
public:
	//Provie constructor
	explicit Character(string characterName, int health);

	//Provide getters for all variables
	string getCharacterName();
	int getHealth();

	//Provide setters for all variables
	void setCharacterName(string characterName);
	void setHealth(int health);


	void recieveAttack(vector<int> attack, string characterName);
	vector<int> attack();

	int rollDamage();
	int rollInitiative();
	
};