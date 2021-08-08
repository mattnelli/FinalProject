/*
    Introduction to Object Orient Programming project main class
    Author: Matthew Nelli


    Premise: The game is a texted based aventure coded throughout the 10 week course. Each Part is what was learned in class 
    that week.

    Week one: Introductions. Simple text IO of user input and output. Still in Command Prompt. 
    (Ideas to advance interface as it progess so the player and I can feel it advancing)

    Week two:

*/

#include <iostream>
#include <string>
using namespace std; 

int main()
{
    //Keep dialog up here to allow easy modification
    string openingdialog = "Oh my... Hello there stranger.\nMy name is C2 + , I am an AI of this ships mainframe\nWhat is you name? ";
    string playerintro = " we have no need for names in the Guild... Lets find out more about you";

    //Save player name and value givin to the player
    string PlayerName;
    int PlayerNumber = 56432;

    //Ask player forthere name
    std::cout << openingdialog; 

    //Get players name save for later use
    getline(cin, PlayerName);

    //If name is carmine alter path
    if (PlayerName.compare("Carmine") == 0) {
        std::cout << "Anomally detected... Name is unaccessible in our data base \n";
        return 0;
    }
    
    //Initate next phase last line of week 1
    std::cout << "Welcome " << PlayerNumber << playerintro << std::endl;
}
