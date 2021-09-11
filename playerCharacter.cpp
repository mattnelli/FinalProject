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
playerCharacter::playerCharacter(string* cNamePTR, int hlth, int armr, int strngth, int chrsm) {
	setCharacterName(*cNamePTR);
	setHealth(hlth);
	setArmor(armr);
	setStrength(strngth);
	setCharasma(chrsm); 
}

void playerCharacter::recieveAttack(vector<int> attack) {

	//Check if attack hits
	if (attack[0] > getArmor()) {
		cout << "That hits!!\n";
		cout << "The attack hits for " << attack[1] << " damage\n";
		

		//check health after attack
		if (attack[1] > getHealth()) {
			cout << "I regret to inform you that you have died\n";
			setHealth(getHealth() - attack[1]);
		}
		else {

			//reduce health
			setHealth(getHealth() - attack[1]);
			cout << "Your health is: " << getHealth() << "\n\n";

		}

	}
	else {
		//Attack missed
		cout << "That attack missed you!\n\n";
		
	}



}


vector<int> playerCharacter::attack() {

	//Vector here gives me room for expandiblity. Such as persistant posion damage
	vector<int> attack(2);

	//Roll a D20, first roll is attack against AC.
	std::default_random_engine engine{ static_cast<unsigned int>(time(0)) };
	std::uniform_int_distribution<unsigned int> AttackRoll{ 1,20 };
	std::uniform_int_distribution<unsigned int> DamageRoll{ 1,4 };

	//Save attack roll
	attack[0] = AttackRoll(engine);

	std::cout << "Your attack Roll is " << attack[0] << "\n";

	//Roll Damage base on character level
	int damage = 0;

	//half the strength to get the level of the player
	for (int i = 0; (getStrength()/2) > i; i++) {

		damage += DamageRoll(engine);

	}

	//Second location is for the damage dealt by the attack
	attack[1] = damage;

	//return attack vector
	return attack;

}


//Getter for player name 
string playerCharacter::getCharacterName() {
	return characterName;
}

//Getter for health 
int playerCharacter::getHealth() {
	return health;
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

//set player name
void playerCharacter::setCharacterName(string cName) {
	characterName = cName;
}

//set armor
void playerCharacter::setArmor(int armr) {
	armor = armr;
}

//set health
void playerCharacter::setHealth(int hlth) {
	health = hlth;
}

//set strength
void playerCharacter::setStrength(int strngth) {
	strength = strngth;
}

//set charasma
void playerCharacter::setCharasma(int chrsm) {
	charasma = chrsm;
}