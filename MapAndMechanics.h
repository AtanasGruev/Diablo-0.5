#ifndef MAP_MAP_MAP_H
#define MAP_MAP_MAP_H

class Character;
class Enemy;
class String;

//initializes the array of enemies on the map
//plays vital role in the visualisation process
void readMap(char(*map)[10], Enemy** enemy, int numEnemies);

//displays map
//acknowledges the ocation of the player and of the enemies
void printMap(char(*map)[10]);

//updates the map according to the result of the last battle
//used to supple actual visual information
void updateMap(char(*map)[10], Character* player, Enemy** enemy, int numEnemies);

Character* createPlayer(String&, String&); //creates a player based on user input
Enemy** setDifficulty(String&, int&); //sets chosen difficulty by generating an array of enemies

bool victoryConditions(int numEnemies, Character* player); //informs the user whether the game has been won

#endif // !MAP_MAP_MAP_H
