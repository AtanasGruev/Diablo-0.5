#include "Character.h"
#include <iostream>

using namespace std;

void readMap(char(*map)[10], Enemy& en)
{
	for (int i = 0; i < 10; i++)
	{
		map[i][0] = i + '0';
	}
	for (int i = 0; i < 10; i++)
	{
		map[0][i] = i + '0';
	}

	for (int i = 1; i < 10; i++)
	{
		for (int j = 1; j < 10; j++)
		{
			map[i][j] = '_';
		}
	}

	int enemyX = en.getXEnemy();
	int enemyY = en.getYEnemy();
	map[enemyX][enemyY] = 'E';
}

void printMap(char (*map)[10])
{
	cout << endl;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void updateMap(char(*map)[10], Character& ch, Enemy& en)
{
	for (int i = 1; i < 10; i++)
	{
		for (int j = 1; j < 10; j++)
		{
			if (map[i][j] == 'P') map[i][j] = '_';
		}
	}
	int characterX = ch.getXCharacter();
	int characterY = ch.getYCharacter();

	int enemyX = en.getXEnemy();
	int enemyY = en.getYEnemy();

	if (characterX == enemyX && characterY == enemyY)
	{
		//Battle occurs
		return;
	}

	map[characterX][characterY] = 'P';

}



int main()
{
	Character ch("Hero", 1, 15, 20, 30);
	Enemy en("Opponent", 50, 5, 5);
	en.placeEnemy(3, 7);

	char Map[10][10];
	readMap(Map, en);
	printMap(Map);

	ch.moveCharacter();
	updateMap(Map, ch, en);
	printMap(Map);

	ch.moveCharacter();
	updateMap(Map, ch, en);
	printMap(Map);

	system("pause");
}