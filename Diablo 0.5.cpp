#include "Character.h"
#include "Enemy.h"
#include <iostream>
#include <cassert>

using namespace std;

void readMap(char(*map)[10], Enemy* sk, Enemy* he)
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

	int skeletonX = sk->getXEnemy();
	int skeletonY = sk->getYEnemy();

	int hereticX = he->getXEnemy();
	int hereticY = he->getYEnemy();
	map[skeletonX][skeletonY] = 'S';
	map[hereticX][hereticY] = 'H';
}

void printMap(char(*map)[10])
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

void updateMap(char(*map)[10], Character* ch, Enemy* sk, Enemy* he)
{
	for (int i = 1; i < 10; i++)
	{
		for (int j = 1; j < 10; j++)
		{
			if (map[i][j] == 'P') map[i][j] = '_';
		}
	}
	int characterX = ch->getXCharacter();
	int characterY = ch->getYCharacter();

	int skeletonX = sk->getXEnemy();
	int skeletonY = sk->getYEnemy();

	int hereticX = he->getXEnemy();
	int hereticY = he->getYEnemy();

	if (characterX == skeletonX && characterY == skeletonY)
	{
		ch->battleWithSkeletonOrHeretic(sk);
		if (ch->getHealth() <= 0) map[characterX][characterY] = '$';
		else
		{
			map[characterX][characterY] = 'P';
			if (ch->getCounterLevelUp() == pow(2, ch->getLevel())) ch->levelUpHero();
		}
	}
	else if ((characterX == hereticX && characterY == hereticY))
	{

		ch->battleWithSkeletonOrHeretic(he);
		if (ch->getHealth() <= 0) map[characterX][characterY] = '$';
		else
		{
			map[characterX][characterY] = 'P';
			if (ch->getCounterLevelUp() == pow(2, ch->getLevel())) ch->levelUpHero();
		}
	}
	else
	{
		map[characterX][characterY] = 'P';
	}
}

int main()
{
	Character* Player = new BountyHunter("Hero");
	assert(Player);

	Enemy* Skeleton1 = new Skeleton("Skeleton1");
	assert(Skeleton1);
	Skeleton1->setXEnemy(3);
	Skeleton1->setYEnemy(7);

	Enemy* Heretic1 = new Heretic("Heretic1");
	assert(Heretic1);
	Heretic1->setXEnemy(7);
	Heretic1->setYEnemy(8);

	Enemy* Diablo1 = new Diablo("Diablo");
	Diablo1->setXEnemy(9);
	Diablo1->setYEnemy(9);

	char Map[10][10];

	readMap(Map, Skeleton1, Heretic1);
	printMap(Map);

	while (Player->getHealth() > 0)
	{
		Player->moveCharacter();
		updateMap(Map, Player, Skeleton1, Heretic1);
		printMap(Map);
	}

	system("pause");
}