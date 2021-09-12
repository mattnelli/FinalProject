/*
Matthew Nelli
Professor Jonathan S.Weissman
CIS 554 - M401 Object Oriented Programming in C++
Syracuse University

9 / / 21

*/

#include "Character.h"
#include <iostream>
#include <string>
#include <array>
#include <random>
#include <ctime>
#include <vector>
using std::string;
using std::array;
using std::vector;
using std::cout;
using std::cin;

//Player character constructor
Character::Character(string cNamePTR, int hlth) {
	setCharacterName(cNamePTR);
	setHealth(hlth);
}

//Getter for player name 
string Character::getCharacterName() {
	return characterName;
}

//Getter for health 
int Character::getHealth() {
	return health;
}

//set player name
void Character::setCharacterName(string cName) {
	characterName = cName;
}

//set health
void Character::setHealth(int hlth) {
	health = hlth;
}

