/*
Matthew Nelli
Professor Jonathan S.Weissman
CIS 554 - M401 Object Oriented Programming in C++
Syracuse University
HW #5 - Any program
8 / 23 / 21
This is the player character class. It creates a player character and handles health and combat
*/

#include "playerCharacter.h"
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
playerCharacter::playerCharacter(string cNamePTR, int hlth, int armr, int strngth, int chrsm) :Character(cNamePTR, hlth) {
	setArmor(armr);
	setStrength(strngth);
	setCharasma(chrsm); 
}


//return armor class
int playerCharacter::getArmor() {
	return armor;
}

//return player strength 
int playerCharacter::getStrength() {
	return strength;
}

//return charasma
int playerCharacter::getCharasma() {
	return charasma;
}


//set armor
void playerCharacter::setArmor(int armr) {
	armor = armr;
}

//set strength
void playerCharacter::setStrength(int strngth) {
	strength = strngth;
}

//set charasma
void playerCharacter::setCharasma(int chrsm) {
	charasma = chrsm;
}

void playerCharacter::copy(playerCharacter test) {
	setCharacterName(test.getCharacterName());

}