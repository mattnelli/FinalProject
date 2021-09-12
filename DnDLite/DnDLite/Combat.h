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
#include <iomanip>
#include <array>
#include <vector> 
#include "Character.h"
#include "playerCharacter.h"

using std::string;
using std::array;
using std::vector;
using std::ostream;

class Combat
{

	static int totalCombat;
	int roundsOfCombat;
	playerCharacter* charOne;
	Character* charTwo;

	friend ostream &operator<<(ostream&, const Combat &);
	
	
public:
	//Provie constructor
	explicit Combat(playerCharacter* charOne, Character* charTwo);
	
	
	//Start combat 
	void initiateCombat(); 
	int getTotalCombat();
	int getRounds();
	
};
