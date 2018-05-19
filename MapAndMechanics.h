#ifndef MAP_MAP_MAP_H
#define MAP_MAP_MAP_H

class Character;
class Enemy;
class String;

void readMap(char(*map)[10], Enemy** enemy, int numEnemies);
void printMap(char(*map)[10]);
void updateMap(char(*map)[10], Character* player, Enemy** enemy, int numEnemies);

Character* createPlayer(String&, String&);
Enemy** setDifficulty(String&, int&);

#endif // !MAP_MAP_MAP_H
