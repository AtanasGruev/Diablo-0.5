#include "Character.h"
#include "Enemy.h"
#include "String.h"
#include "MapAndMechanics.h"
#include <iostream>
#include <cassert>

using namespace std;

int main()
{
	String PlayerCharacter, PlayerName;
	cout << "CHOOSE YOUR HERO: " << endl;
	cin >> PlayerCharacter;
	cout << "CHOOSE YOUR NAME: " << endl;
	cin >> PlayerName;

	Character* Player = createPlayer(PlayerCharacter, PlayerName);

	String difficultyLevel;
	cout << "CHOOSE DIFFICULTY: " << endl;
	cin >> difficultyLevel;

	int numEnemies;
	Enemy** gameEnemies = setDifficulty(difficultyLevel, numEnemies);

	char Map[10][10];

	readMap(Map, gameEnemies, numEnemies);
	printMap(Map);

	while (Player->getHealth() > 0)
	{
		Player->moveCharacter();
		updateMap(Map, Player, gameEnemies, numEnemies);
		printMap(Map);
	}

	system("pause");
}