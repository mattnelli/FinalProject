/*
Matthew Nelli
Professor Jonathan S.Weissman
CIS 554 - M401 Object Oriented Programming in C++
Syracuse University
HW #5 - Any program
8 / 23 / 21
This is the NPC class. It creates an NPC and handles health and combat
*/

#include "NPC.h"
#include <iostream>
#include <string>
#include <array>
#include <random>
#include <ctime>
#include <vector>
#include "Character.h"
using std::string;
using std::array;
using std::cout;




//NPC constructor with givin name
NPC::NPC(int level, string name) :Character(name, level * 3) 
{

}


int NPC::getLevel() {

	return level;

}

void NPC::setLevel(int lev) {

	level = lev;

}
