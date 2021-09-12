#pragma once
#pragma once
/*
Matthew Nelli
Professor Jonathan S.Weissman
CIS 554 - M401 Object Oriented Programming in C++
Syracuse University

9// 21

*/

#include <string>
#include <sstream>
#include <iostream>
#include <array>
#include <vector> 
#include "Character.h"

using std::string;
using std::array;
using std::vector;

class Combat
{

	static int totalCombat;
	int roundsOfCombat;
	Character* charOne;
	Character* charTwo;

	
	
public:
	//Provie constructor
	explicit Combat(Character* charOne, Character* charTwo);

	//Start combat 
	void initiateCombat(); 
	int getTotalCombat();
	int getRounds();
	
};
