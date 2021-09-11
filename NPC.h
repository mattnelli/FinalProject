#pragma once
/*
Matthew Nelli
Professor Jonathan S.Weissman
CIS 554 - M401 Object Oriented Programming in C++
Syracuse University
HW #5 - Any program
8 / 23 / 21
header file for NPC. Has all required NPC functions. Creation, combat, and health management
*/

#include <string>
#include <array>
#include <vector> 

using std::string;
using std::array; 
using std::vector;

class NPC
{
	//Strings for names and desription
	string Name;
	array<string, 5> names{ "Barry Bluejeans", "Ron", "Lup", "Glenn Close", "Duck" };


	//Character stats
	int level;
	int health;

	
public:
	//Provie constructor
	explicit NPC(int level);
	explicit NPC(int level, string name);
	int getHealth();
	//Provide getters for all variables
	string getNPCName();
	int getLevel();


	//Provide setters for all variables
	void setNPCName(string characterName);
	void setLevel(int lev);
	void setHealth(int health);
	vector<int> attack();
	void recieveAttack(vector<int> attack);
};
