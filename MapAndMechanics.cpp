#include "MapAndMechanics.h"
#include "Character.h"
#include "Enemy.h"
#include "String.h"
#include <iostream>

void readMap(char(*map)[10], Enemy ** enemy, int numEnemies)
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

	int* enemiesX = new int[numEnemies];
	int* enemiesY = new int[numEnemies];

	for (int i = 0; i < numEnemies; i++)
	{

		enemy[i]->printOnMap(map);
	}
}

void printMap(char(*map)[10])
{
	std::cout << std::endl;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			std::cout << map[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void updateMap(char(*map)[10], Character* player, Enemy** enemy, int numEnemies)
{
	for (int i = 1; i < 10; i++)
	{
		for (int j = 1; j < 10; j++)
		{
			if (map[i][j] == 'P') map[i][j] = '_';
		}
	}
	int characterX = player->getXCharacter();
	int characterY = player->getYCharacter();

	int* enemiesX = new int[numEnemies];
	int* enemiesY = new int[numEnemies];

	for (int i = 0; i < numEnemies; i++)
	{
		enemiesX[i] = enemy[i]->getXEnemy();
		enemiesY[i] = enemy[i]->getYEnemy();
		if (characterX == enemiesX[i] && characterY == enemiesY[i])
		{
			player->battleWithEnemy(enemy[i]);
			if (player->getHealth() <= 0) map[characterX][characterY] = '$';
			else
			{
				map[characterX][characterY] = 'P';
				if (player->getCounterLevelUp() == pow(2,player->getLevel())) player->levelUpHero();
			}
		}
		else
		{
			map[characterX][characterY] = 'P';
		}
	}
}

Character* createPlayer(String& heroCharacter, String& heroName)
{
	if (heroCharacter == "Barbarian")
	{
		Character* Player = new Barbarian(heroName);
		std::cout << "Your special ability is RAGE!" << std::endl;
		return Player;
	}
	else if (heroCharacter == "Sorcerer")
	{
		Character* Player = new Sorcerer(heroName);
		std::cout << "Your special ability is MANA!" << std::endl;
		return Player;
	}
	else if (heroCharacter == "BountyHunter")
	{
		Character* Player = new BountyHunter(heroName);
		std::cout << "Your special ability is AGILITY!" << std::endl;
		return Player;
	}
	else
	{
		std::cout << "INVALID CHARACTER!" << std::endl;
		std::cout << "GAME WILL CLOSE SHORTLY!" << std::endl;
		return NULL;
	}
}

Enemy** setDifficulty(String& difficulty, int& numEnemies)
{
	if (difficulty == "Easy")
	{
		int numEasyEnemies = 3;
		Enemy** easyEnemies = new Enemy*[numEasyEnemies];
		easyEnemies[0] = new Skeleton("Skeleton1");
		easyEnemies[0]->setXEnemy(8); easyEnemies[0]->setYEnemy(2);
		easyEnemies[1] = new Heretic("Heretic1");
		easyEnemies[1]->setXEnemy(3); easyEnemies[1]->setYEnemy(7);
		easyEnemies[2] = new Necromancer("Necromancer1");
		easyEnemies[2]->setXEnemy(7); easyEnemies[2]->setYEnemy(9);
		numEnemies = numEasyEnemies;
		return easyEnemies;
	}
	else if (difficulty == "Medium")
	{
		int numMediumEnemies = 5;
		Enemy** mediumEnemies = new Enemy*[numMediumEnemies];
		mediumEnemies[0] = new Skeleton("Skeleton1");
		mediumEnemies[0]->setXEnemy(2); mediumEnemies[0]->setYEnemy(3);
		mediumEnemies[1] = new Skeleton("Skeleton2");
		mediumEnemies[1]->setXEnemy(5); mediumEnemies[1]->setYEnemy(5);
		mediumEnemies[2] = new Heretic("Heretic1");
		mediumEnemies[2]->setXEnemy(6); mediumEnemies[2]->setYEnemy(8);
		mediumEnemies[3] = new Heretic("Heretic2");
		mediumEnemies[3]->setXEnemy(4); mediumEnemies[3]->setYEnemy(7);
		mediumEnemies[4] = new Necromancer("Necromancer1");
		mediumEnemies[4]->setXEnemy(8); mediumEnemies[4]->setYEnemy(4);
		numEnemies = numMediumEnemies;
		return mediumEnemies;
	}
	else if (difficulty == "Hard")
	{
		int numHardEnemies = 9;
		Enemy** hardEnemies = new Enemy*[numHardEnemies];
		hardEnemies[0] = new Skeleton("Skeleton1");
		hardEnemies[0]->setXEnemy(1); hardEnemies[0]->setYEnemy(5);
		hardEnemies[1] = new Skeleton("Skeleton2");
		hardEnemies[1]->setXEnemy(4); hardEnemies[1]->setYEnemy(2);
		hardEnemies[2] = new Skeleton("Skeleton3");
		hardEnemies[2]->setXEnemy(7); hardEnemies[2]->setYEnemy(8);
		hardEnemies[3] = new Heretic("Heretic1");
		hardEnemies[3]->setXEnemy(9); hardEnemies[3]->setYEnemy(2);
		hardEnemies[4] = new Heretic("Heretic2");
		hardEnemies[4]->setXEnemy(9); hardEnemies[4]->setYEnemy(3);
		hardEnemies[5] = new Heretic("Heretic3");
		hardEnemies[5]->setXEnemy(2); hardEnemies[5]->setYEnemy(6);
		hardEnemies[6] = new Necromancer("Necromancer1");
		hardEnemies[6]->setXEnemy(3); hardEnemies[6]->setYEnemy(6);
		hardEnemies[7] = new Necromancer("Necromancer2");
		hardEnemies[7]->setXEnemy(5); hardEnemies[7]->setYEnemy(8);
		hardEnemies[8] = new Diablo("Diablo");
		hardEnemies[8]->setXEnemy(9); hardEnemies[8]->setYEnemy(9);
		numEnemies = numHardEnemies;
		return hardEnemies;
	}
	else
	{
		std::cout << "INVALID DIFFICULTY!" << std::endl;
		std::cout << "GAME WILL CLOSE SHORTLY!" << std::endl;
		return NULL;
	}
}

bool victoryConditions(int numEnemies, Character* player)
{
	if (player->getCounterLevelUp() == numEnemies)
	{
		std::cout << player->getName() << " EMERGED VICTORIOUS!" << std::endl;
		return true;
	}
	else
	{
		return false;
	}
}