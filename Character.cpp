#include "Character.h"
#include "Enemy.h"
#include <iostream>

Character::Character(const String& name, unsigned int level, double health, double strength, double intelligence) : nameHero(name), levelHero(level),
healthPointsHero(health), originalHealthPointsHero(health),
strengthHero(strength), originalStrengthHero(strength),
intelligenceHero(intelligence), originalIntelligenceHero(intelligence),
counterLevelUp(0), counterRounds(1)
{}

void Character::setHealth(double health)
{
	healthPointsHero = health;
}

void Character::setCounterRounds(unsigned int currentRound)
{
	counterRounds = currentRound;
}

void Character::setCounterLevelUp(unsigned int levelUp)
{
	counterLevelUp = levelUp;
}

String Character::getName() const
{
	return nameHero;
}

double Character::getHealth() const
{
	return healthPointsHero;
}

double Character::getLevel() const
{
	return levelHero;
}

unsigned int Character::getCounterLevelUp() const
{
	return counterLevelUp;
}

unsigned int Character::getCounterRounds() const
{
	return counterRounds;
}

double Character::getStrength() const
{
	return strengthHero;
}

double Character::getIntelligence() const
{
	return intelligenceHero;
}

double Character::getMinimumAbility() const
{
	if (strengthHero < intelligenceHero) return strengthHero;
	else return intelligenceHero;
}


double Character::defendHerî(double damageEnemy)
{
	damageEnemy -= (strengthHero / 100)*damageEnemy;
	return damageEnemy;
}

void Character::levelUpHero()
{
	levelHero++;
	//CONSIDER OPTIMIZATION
	healthPointsHero = 1.1*originalHealthPointsHero;
	originalHealthPointsHero = healthPointsHero;
	strengthHero += (originalStrengthHero / (originalStrengthHero + originalIntelligenceHero)) * 5;
	intelligenceHero += (originalIntelligenceHero / (originalStrengthHero + originalIntelligenceHero)) * 5;
}

void Character::setXCharacter(int xPos)
{
	xCoord = xPos;
}

void Character::setYCharacter(int yPos)
{
	yCoord = yPos;
}

int Character::getXCharacter() const
{
	return xCoord;
}

int Character::getYCharacter() const
{
	return yCoord;
}

void Character::moveCharacter()
{
	int newX, newY;
	do
	{
		std::cout << "MAKE YOUR NEXT MOVE: ";
		std::cin >> newX >> newY;
		if (newX < 1 || newX > 9 || newY < 1 || newY > 9)
		{
			std::cout << "INVALID COORDINATES - PLEASE ENTER VALID MAP COORDINATES!" << std::endl;
		}
	} while (newX < 1 || newX > 9 || newY < 1 || newY > 9);

	Character::setXCharacter(newX);
	Character::setYCharacter(newY);
}

void Character::printBattleWithEnemy(Enemy* enemy, double totalDamageHero, double totalDamageEnemy)
{

	std::cout << "---------- NEW ROUND " << " ---------" << std::endl;
	std::cout << std::endl;

	if (enemy->necromancerSkeleton() >= 0 && enemy->getCounterRounds() != 2)
	{
		std::cout << "Skeleton Servant has been summoned!" << std::endl;
		std::cout << getName() << "'s attacks affect the Skeleton Servant!" << std::endl;
	}
	std::cout << enemy->getName() << " was hit with " << totalDamageHero << " points damage" << std::endl;
	std::cout << enemy->getName() << "'s remaining health is:" << enemy->getHealth() << " health points" << std::endl;
	std::cout << std::endl;
	std::cout << getName() << " was hit with " << totalDamageEnemy << " points damage." << std::endl;
	std::cout << getName() << "'s remaining health is:" << getHealth() << " health points" << std::endl;
	std::cout << std::endl;
}