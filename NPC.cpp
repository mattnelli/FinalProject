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
using std::string;
using std::array;
using std::cout;



//create npc with just level and random name
NPC::NPC(int level) {

	//random number generator for name selection
	std::default_random_engine engine{ static_cast<unsigned int>(time(0)) };
	std::uniform_int_distribution<unsigned int> RandomName{ 0,4 };

	//Provide random name
	setNPCName(names[RandomName(engine)]);

	//Set level
	setLevel(level);

	//Set health
	setHealth(level * 3);

}

//NPC constructor with givin name
NPC::NPC(int level, string name) {

	//set name level and health
	setNPCName(name);
	setLevel(level);
	setHealth(level * 3);

}


//Provide getters for all variables
string NPC::getNPCName() {

	return Name;

}

int NPC::getLevel() {

	return level;

}
int NPC::getHealth() {

	return health; 

}
//Provide setters for all variables
void NPC::setNPCName(string characterName) {

	Name = characterName;

}

void NPC::setLevel(int lev) {

	level = lev;

}

void NPC::setHealth(int hlth) {

	health = hlth;

}

//Create attack class
vector<int> NPC::attack() {

	//Vector here gives me room for expandiblity. Such as persistant posion damage
	vector<int> attack(2); 

	//Roll a D20, first roll is attack against AC.
	std::default_random_engine engine{ static_cast<unsigned int>(time(0)) };
	std::uniform_int_distribution<unsigned int> AttackRoll{ 1,20 };
	std::uniform_int_distribution<unsigned int> DamageRoll{ 1,4 };

	//Save attack roll
	attack[0] = AttackRoll(engine);

	std::cout << getNPCName() << "'s attack Roll is " << attack[0] << "\n";

	//Roll Damage base on character level
	int damage = 0;
	for (int i = 0; getLevel() > i; i++) {

		damage += DamageRoll(engine);

	}

	//Second location is for the damage dealt by the attack
	attack[1] = damage;

	//return attack vector
	return attack;
	
}

//Recoeve attack from player
void NPC::recieveAttack(vector<int> attack) {

	//See if attack hits
	if (attack[0] > level*3) {
		//if hits inform of the damage
		cout <<"You attack on " << getNPCName() <<" hits!!\n";
		cout << "The hits for " << attack[1] << " damage\n";

		//if damage is greater than health he dies
		if (attack[1] > getHealth()) {
			cout << "I am please to inform you " << getNPCName() << " is dead!\n\n" ;
			setHealth(0);
		}

		else {
			//remove attacj from health
			setHealth(getHealth() - attack[1]);
			//return NPC health
			cout << getNPCName() <<" health is: " << getHealth() << "\n\n";

		}

	}
	else {
		//Attack missed
		cout << "Attack misses!\n\n";

	}



}