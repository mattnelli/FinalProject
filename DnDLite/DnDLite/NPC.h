#pragma once
/*
Matthew Nelli
Professor Jonathan S.Weissman
CIS 554 - M401 Object Oriented Programming in C++
Syracuse University

9// 21

*/

#include <string>
#include <array>
#include <vector> 
#include "Character.h"

using std::string;
using std::array; 
using std::vector;

class NPC: public Character
{
	//Strings for names and desription
	string Name;
	array<string, 5> names{ "Barry Bluejeans", "Ron", "Lup", "Glenn Close", "Duck" };


	//Character stats
	int level;
	int health;

	
public:
	//Provie constructor
	explicit NPC(int level, string name);
	//Provide getters for all variables
	int getLevel();

	//Provide setters for all variables
	void setLevel(int lev);
};
