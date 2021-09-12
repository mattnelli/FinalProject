/*
Matthew Nelli
Professor Jonathan S.Weissman
CIS 554 - M401 Object Oriented Programming in C++
Syracuse University
HW #5 - Any program
8 / 23 / 21
This is the NPC class. It creates an NPC and handles health and combat
*/

#include <iostream>
#include <sstream>
#include "Combat.h"
#include "Character.h"
#include <string>
#include <array>
#include <random>
#include <ctime>
#include <vector>
using namespace std;
using std::string;
using std::array;
using std::cout;


Combat::Combat(Character* chrOneptr, Character* chrTwoptr){
	charOne = chrOneptr;
	charTwo = chrTwoptr;
	totalCombat++;
	roundsOfCombat = 0;
}


void Combat::initiateCombat() {
	std::default_random_engine engine{ static_cast<unsigned int>(time(0)) };
	std::uniform_int_distribution<unsigned int> AttackRoll{ 1,20 };
	std::uniform_int_distribution<unsigned int> DamageRoll{ 1,4 };

	bool cont = true;
	cout << "You have ecountered " << charTwo->getCharacterName() << " they have " << charTwo->getHealth() << "/n";

	while (charOne->getHealth() > 0 && charTwo->getHealth() > 0 && cont) {

		//check wth user
		string answer;
		cout << "Say yes if you would like to attack back! No to run: ";
		cin >> answer;

		if (answer == "yes" || answer == "Yes") {
			//firstAttacker.recieveAttack(playerOne.attack());
			cont = true;
		}
		else {
			cont = false; 
		}


	}




}

int Combat::getRounds() {
	return roundsOfCombat;
}

int Combat::getTotalCombat() {
	return totalCombat;
}

ostream& operator<<(ostream& output,  Combat& fight) {
	output << "The current fight is " << fight.getRounds() << "rounds long\n"
		<< "Your campaign has been " << fight.getTotalCombat() << "rounds long\n";
	return output;
}

