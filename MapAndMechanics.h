#ifndef MAP_MAP_MAP_H
#define MAP_MAP_MAP_H

#include "Barbarian.h"
#include "Sorcerer.h"
#include "BountyHunter.h"
#include "Skeleton.h"
#include "Heretic.h"
#include "Necromancer.h"
#include "Diablo.h"
#include "String.h"

class BootGame
{
private:
	char Map[10][10]; //10-by-10 grid which acts as a map
	Character* player; //pointer to Character, refering to the player
	Enemy** arrEnemies; //pointer to an array of Enemy, refering to the monsters
	int numEnemies; //number of enemies on current level
	bool validation; //tracks whether input is correct
public:
	BootGame(); //default constructor, initiaztes game 
	~BootGame(); //dynamically allocated memory is released

	//setter and getter accordingly to manipulate the number of enemies on a given level
	void setNumEnemies(int);
	int getNumEnemies() const;

	void readMap(); //initializes the array of enemies on the map
	void printMap(); //displays map, acknowledges the location of the player and the enemies
	void updateMap(); //updates the map according to the result of the last battle, supplies actual visual information

	void createPlayer(); //creates a player based on user input
	void setDifficulty(); //sets chosen difficulty by generating an array of enemies
	bool victoryConditions(); //informs the user whether the game has been won

	void printPlayerInfo(); //displays player stats and serves as actual information
	void playGame(); //encompasses all other functions to conduct game process
};

#endif // !MAP_MAP_MAP_H
