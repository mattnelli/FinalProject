/*
    Introduction to Object Orient Programming project main class
    Author: Matthew Nelli

    Header file for character classes 

    Week two: Creating a class for a character 

*/
#include <string>
using std::string;

class Character
{
	//Strings for names and desription
	string characterName;

	//Character stats
	int health = 0;
	int armor = 0;
	int strength = 0; 
	int charasma = 0;

	//value for the total cost of all items
	int total = 10;


public:
	//Provie constructor
	explicit Character(string characterName, int health, int armor, int strength, int charasma);








	//Provide getters for all variables
	string getCharacterName();
	int getHealth();
	int getArmor();
	int getStrength();
	int getCharasma();

	//Provide setters for all variables
	void setCharacterName(string characterName);
	void setArmor(int armor);
	void setHealth(int health);
	void setStrength(int strength);
	void setCharasma(int charasma);

};
