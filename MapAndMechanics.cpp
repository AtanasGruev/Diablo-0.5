#include "MapAndMechanics.h"
#include <iostream>

BootGame::BootGame() : validation(true)
{
		createPlayer();
		setDifficulty();
	
	if(!validation)
	{
		std::cout << std::endl;
		std::cout << "INVALID INPUT HAS BEEN DETECTED!" << std::endl;
		std::cout << "PLEASE RESTRART THE GAME!" << std::endl;
	}
}

BootGame::~BootGame()
{
	delete player;
	for (int i = 0; i < numEnemies; i++)
	{
		delete arrEnemies[i];
	}
	delete[] arrEnemies;
}

void BootGame::setNumEnemies(int numDifficultyEnemies)
{
	numEnemies = numDifficultyEnemies;
}

int BootGame::getNumEnemies() const
{
	return numEnemies;
}

void BootGame::readMap()
{
	for (int i = 0; i < 10; i++)
	{
		Map[i][0] = i + '0';
	}
	for (int i = 0; i < 10; i++)
	{
		Map[0][i] = i + '0';
	}

	for (int i = 1; i < 10; i++)
	{
		for (int j = 1; j < 10; j++)
		{
			Map[i][j] = '_';
		}
	}

	int* enemiesX = new int[numEnemies];
	int* enemiesY = new int[numEnemies];

	for (int i = 0; i < numEnemies; i++)
	{
		arrEnemies[i]->printOnMap(Map);
	}
}

void BootGame::printMap()
{
	std::cout << std::endl;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			std::cout << Map[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void BootGame::updateMap()
{
	for (int i = 1; i < 10; i++)
	{
		for (int j = 1; j < 10; j++)
		{
			if (Map[i][j] == 'P') Map[i][j] = '_';
		}
	}
	int characterX = player->getXCharacter();
	int characterY = player->getYCharacter();

	int* enemiesX = new int[numEnemies];
	int* enemiesY = new int[numEnemies];

	for (int i = 0; i < numEnemies; i++)
	{
		enemiesX[i] = arrEnemies[i]->getXEnemy();
		enemiesY[i] = arrEnemies[i]->getYEnemy();
		if (characterX == enemiesX[i] && characterY == enemiesY[i])
		{
			player->battleWithEnemy(arrEnemies[i]);
			if (player->getHealth() <= 0) Map[characterX][characterY] = '$';
			else
			{
				Map[characterX][characterY] = 'P';
				if (player->getCounterLevelUp() == pow(2, player->getLevel())) player->levelUpHero();
			}
		}
		else
		{
			Map[characterX][characterY] = 'P';
		}
	}
}

void BootGame::createPlayer()
{
	String playerCharacter, playerName;
	std::cout << "CHOOSE YOUR HERO - Barbarian, Sorcerer or BountyHunter: " << std::endl;
	std::cin >> playerCharacter;
	if (!(playerCharacter == "Barbarian" || playerCharacter == "Sorcerer" || playerCharacter == "BountyHunter")) validation = false;
	std::cout << "CHOOSE YOUR NAME: " << std::endl;
	std::cin >> playerName;

	if (playerCharacter == "Barbarian")
	{
		player = new Barbarian(playerName);
		std::cout << std::endl;
		std::cout << "Your special ability is RAGE!" << std::endl;
		std::cout << std::endl;

	}
	else if (playerCharacter == "Sorcerer")
	{
		player = new Sorcerer(playerName);
		std::cout << std::endl;
		std::cout << "Your special ability is MANA!" << std::endl;
		std::cout << std::endl;
	}
	else if (playerCharacter == "BountyHunter")
	{
		player = new BountyHunter(playerName);
		std::cout << std::endl;
		std::cout << "Your special ability is AGILITY!" << std::endl;
		std::cout << std::endl;
	}
}

void BootGame::setDifficulty()
{
	String difficultyLevel;
	std::cout << "CHOOSE DIFFICULTY - Easy, Medium, Hard:  " << std::endl;
	std::cin >> difficultyLevel;
	if (!(difficultyLevel == "Easy" || difficultyLevel == "Medium" || difficultyLevel == "Hard")) validation = false;

	else if (difficultyLevel == "Easy")
	{
		int numEasyEnemies = 3;
		arrEnemies = new Enemy*[numEasyEnemies];
		arrEnemies[0] = new Skeleton("Skeleton1");
		arrEnemies[0]->setXEnemy(8); arrEnemies[0]->setYEnemy(2);
		arrEnemies[1] = new Heretic("Heretic1");
		arrEnemies[1]->setXEnemy(3); arrEnemies[1]->setYEnemy(7);
		arrEnemies[2] = new Necromancer("Necromancer1");
		arrEnemies[2]->setXEnemy(7); arrEnemies[2]->setYEnemy(9);
		numEnemies = numEasyEnemies;
	}
	else if (difficultyLevel == "Medium")
	{
		int numMediumEnemies = 5;
		arrEnemies = new Enemy*[numMediumEnemies];
		arrEnemies[0] = new Skeleton("Skeleton1");
		arrEnemies[0]->setXEnemy(2); arrEnemies[0]->setYEnemy(3);
		arrEnemies[1] = new Skeleton("Skeleton2");
		arrEnemies[1]->setXEnemy(5); arrEnemies[1]->setYEnemy(5);
		arrEnemies[2] = new Heretic("Heretic1");
		arrEnemies[2]->setXEnemy(6); arrEnemies[2]->setYEnemy(8);
		arrEnemies[3] = new Heretic("Heretic2");
		arrEnemies[3]->setXEnemy(4); arrEnemies[3]->setYEnemy(7);
		arrEnemies[4] = new Necromancer("Necromancer1");
		arrEnemies[4]->setXEnemy(8); arrEnemies[4]->setYEnemy(4);
		numEnemies = numMediumEnemies;
	}
	else if (difficultyLevel == "Hard")
	{
		int numHardEnemies = 9;
		arrEnemies = new Enemy*[numHardEnemies];
		arrEnemies[0] = new Skeleton("Skeleton1");
		arrEnemies[0]->setXEnemy(1); arrEnemies[0]->setYEnemy(5);
		arrEnemies[1] = new Skeleton("Skeleton2");
		arrEnemies[1]->setXEnemy(4); arrEnemies[1]->setYEnemy(2);
		arrEnemies[2] = new Skeleton("Skeleton3");
		arrEnemies[2]->setXEnemy(7); arrEnemies[2]->setYEnemy(8);
		arrEnemies[3] = new Heretic("Heretic1");
		arrEnemies[3]->setXEnemy(9); arrEnemies[3]->setYEnemy(2);
		arrEnemies[4] = new Heretic("Heretic2");
		arrEnemies[4]->setXEnemy(9); arrEnemies[4]->setYEnemy(3);
		arrEnemies[5] = new Heretic("Heretic3");
		arrEnemies[5]->setXEnemy(2); arrEnemies[5]->setYEnemy(6);
		arrEnemies[6] = new Necromancer("Necromancer1");
		arrEnemies[6]->setXEnemy(3); arrEnemies[6]->setYEnemy(6);
		arrEnemies[7] = new Necromancer("Necromancer2");
		arrEnemies[7]->setXEnemy(5); arrEnemies[7]->setYEnemy(8);
		arrEnemies[8] = new Diablo("Diablo");
		arrEnemies[8]->setXEnemy(9); arrEnemies[8]->setYEnemy(9);
		numEnemies = numHardEnemies;
	}
}

bool BootGame::victoryConditions()
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

void BootGame::playGame()
{
	if (validation)
	{
		readMap();
		printMap();

		while (player->getHealth() > 0 && !(victoryConditions()))
		{
			player->moveCharacter();
			updateMap();
			printMap();

			if (player->getHealth() > 0)
			{
				printPlayerInfo();
			}
		}
	}
}

void BootGame::printPlayerInfo()
{
	std::cout << "Current stats: " << std::endl;
	std::cout << "Health: " << player->getHealth() << std::endl;
	std::cout << "Strength: " << player->getStrength() << std::endl;
	std::cout << "Intelligence: " << player->getIntelligence() << std::endl;
	std::cout << "Special ability:" << player->getSpecialAbility() << std::endl;
	std::cout << "Level: " << player->getLevel() << std::endl;
	std::cout << std::endl;
}