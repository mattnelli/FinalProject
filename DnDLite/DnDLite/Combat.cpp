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
#include "playerCharacter.h"
#include <string>
#include <array>
#include <random>
#include <ctime>
#include <iomanip>
#include <vector>
using namespace std;
using std::string;
using std::array;
using std::cout;
using std::ostream;

int Combat::totalCombat = 0;

Combat::Combat(playerCharacter* chrOneptr, Character* chrTwoptr){
	charOne = chrOneptr;
	charTwo = chrTwoptr;
	totalCombat = totalCombat + 1;
	roundsOfCombat = 0;
}


void Combat::initiateCombat() {
	

	bool cont = true;
	cout << "You have ecountered " << charTwo->getCharacterName() << " they have " << charTwo->getHealth() << "\n";

	cout << "Would you like to fight them? They will attack first \n";

	while (charOne->getHealth() > 0 && charTwo->getHealth() > 0 && cont) {

		//check wth user
		string answer;
		
		cin >> answer;
		if (answer == "yes" || answer == "Yes") {
			roundsOfCombat++;
			cont = true;
			
			if (charTwo->rollInitiative() > charOne->getArmor()) {
				cout << charTwo->getCharacterName() << "attack hit!\n";
				int attackValue = charTwo->rollDamage();
				cout << "You take " << attackValue << " points of damage\n"; 

				charOne->setHealth(charOne->getHealth() - attackValue);
				cout << "You health is now " << charOne->getHealth() << "\n";
			}
			else {
				cout << charTwo->getCharacterName() << "attack missed!\n";
			}



		}
		else {
			cont = false; 
		}

		cout << "Say yes if you would like to attack back! No to run: ";
	}




}

int Combat::getRounds() {
	return roundsOfCombat;
}

int Combat::getTotalCombat() {
	return totalCombat;
}

ostream &operator<<(ostream &output,  const Combat &fight) {
	output << "The current fight is "  << fight.roundsOfCombat << "rounds long\n"<< "Your campaign has been " << fight.totalCombat << "rounds long\n";
	return output;
}

