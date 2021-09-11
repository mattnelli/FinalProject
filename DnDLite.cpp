/*
Matthew Nelli
Professor Jonathan S.Weissman
CIS 554 - M401 Object Oriented Programming in C++
Syracuse University
HW #5 - Any program
8 / 23 / 21
This program is a DnD combat simulator. It creates a player then has the user fight 4 different NPC of varying difficulty.
*/
#include <iostream>
#include <iostream>
#include <string>
#include "playerCharacter.h"
#include "NPC.h"
using std::cout;
using std::cin;
using std::string;

//Function to print banner 
void printbanner() {

    //Provide the sring name of the program
    std::string bannertitle = " DnD Lite ";

    //Get the length of astrix need (banner plus 2 1 astrix each side
    int bannerlength = bannertitle.length() + 2;

    //Print top row
    for (int i = 0; i < bannerlength; i++) {
        std::cout << "*";
        //Slow down for effect
        //Sleep(50);
    }

    //print name
    std::cout << "\n" << bannertitle << "\n";

    //Print bottom row
    for (int i = 0; i < bannerlength; i++) {
        std::cout << "*";
        //Slow down for effect
       // Sleep(50);
    }

    //indent for spacing
    std::cout << "\n\n";
}

//function for combat
void intiateCombat(NPC& firstAttacker, playerCharacter& playerOne) {

    //check if the user wants to keep fightingh
    bool cont = true;

    //check both players health and if the player wants to attack 
    while (firstAttacker.getHealth() > 0 && playerOne.getHealth() > 0 && cont) {

        //NPC attacks
        playerOne.recieveAttack(firstAttacker.attack());

        //check with user
        string answer;
        cout << "Say yes if you would like to attack back! No to run: ";
        cin >> answer;

        //if yes continue to attack
        if (answer == "yes" || answer == "Yes") {
            firstAttacker.recieveAttack(playerOne.attack());
            cont = true;
        }
        //else exit loop
        else {
            cont = false;
        }
    }
}



int main()
{
    //Print banner
    printbanner();

    //Keep dialog up here to allow easy modification
    string openingdialog = "Oh my... Hello there stranger.\nMy name is C2 + , I am an AI of this ships mainframe\nWhat is you name? ";
    string playerintro = " we have no need for names in the Guild... Lets find out more about you";
    int armor;
    int health; 
    int charasma; 
    int strength; 

    //Save player name and value givin to the player
    string PlayerName;
    int PlayerNumber = 56432;

    //Ask player forthere name
    std::cout << openingdialog;

    //Get players name save for later use
    getline(cin, PlayerName);


    //Get player intro
    std::cout << "Welcome " << PlayerNumber << playerintro << std::endl;

    string* PlayerNameptr = &PlayerName;
    //get player armor stat
    cout << "Well now that introductions are over lets see how much armor you have\nInput an armor class between 10-15: ";
    cin >> armor; 

    //get player armor health
    cout << "and... how much health do you have\nInput a health class between 10-15: ";
    cin >> health;

    //get player armor charasma
    cout << "not to be annoying but... how charismatic are you\nInput a charasma class between 10-15: ";
    cin >> charasma;

    //get player armor strength
    cout << "last and maybe you least.. how strong are you\nInput a strength class between 10-15: ";
    cin >> strength;
    cout << "\n\n";


    //test yo might
    cout << "TEST YOUR MIGHT!\n";



    

    //create player character
    playerCharacter playerOne = playerCharacter(PlayerNameptr, health, armor, strength, charasma);

    //Create 4 NPCs of varing level
    NPC firstAttacker = NPC(1);
    NPC secondAttacker = NPC(2,"Jodie Foster");
    NPC thirdAttacker = NPC(3,"The green machine");
    NPC fourthAttacker = NPC(4, "Full Medal Alcemist");

    //Group them in a vector
    vector<NPC> figher = {firstAttacker ,secondAttacker, thirdAttacker,fourthAttacker};

    //range for loop through each encounter
    for (NPC fight : figher) {

        //Tell them who they are fighting
        cout << "You have encountered " << fight.getNPCName() << "\n";

        //intiate combat
        intiateCombat(fight, playerOne);

    }

    if (playerOne.getHealth() > 0) {
        cout << "Congrats " << playerOne.getCharacterName() << " you have won.\n\n";
    }


}

