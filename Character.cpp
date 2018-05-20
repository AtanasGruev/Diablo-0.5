#include "Character.h"
#include "Enemy.h"
#include <iostream>

/*
CLASS CHARACTER INTERFACE
*/

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
	healthPointsHero = 1.1*originalHealthPointsHero;
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
	std::cout << enemy->getName() << " was hit with " << totalDamageHero << " points damage" << std::endl;
	std::cout << enemy->getName() << "'s remaining health is:" << enemy->getHealth() << " health points" << std::endl;	
	std::cout << std::endl;
	std::cout << getName() << " was hit with " << totalDamageEnemy << " points damage." << std::endl;
	std::cout << getName() << "'s remaining health is:" << getHealth() << " health points" << std::endl;
	std::cout << std::endl;
}

/*
CLASS BARBARIAN INTERFACE
*/

Barbarian::Barbarian(const String& name) : Character(name, 1, 100, 10, 3), rageBarbarian(0), rageForNextBattle(0), rageFlag(true)
{}

double Barbarian::getSpecialAbility() const
{
	return rageBarbarian;
}

double Barbarian::getMinimumAbility() const
{
	double minAbility = Character::getMinimumAbility();
	if (minAbility < rageBarbarian) return minAbility;
	else return rageBarbarian;
}

bool Barbarian::isRageAllowed(int rage) const
{
	return (rage < 100);
}

double Barbarian::attackHero()
{
	if (rageFlag == true)
	{
		rageBarbarian = rageForNextBattle;
		rageForNextBattle = 0;
		rageFlag = false;
	}
	double rageMultiplier = (0.2*rageBarbarian);
	double damageBarbarian = ((100 + rageMultiplier) / 100)*(getStrength() + 0.2*getIntelligence());
	if (isRageAllowed(rageForNextBattle))
	{
		rageForNextBattle += 2;
	}
	else
	{
		rageForNextBattle = 100;
	}
	return damageBarbarian;
}

double Barbarian::defendHerî(double damageEnemy)
{
	if (isRageAllowed(rageForNextBattle))
	{
		rageForNextBattle += 3;
	}
	else
	{
		rageForNextBattle = 100;
	}

	return Character::defendHerî(damageEnemy);
}

void Barbarian::levelUpHero()
{
	Character::levelUpHero();
}

void Barbarian::battleWithEnemy(Enemy* enemy)
{
	while (getHealth() > 0 && enemy->getHealth() > 0)
	{
		double damageBarbarian = attackHero();
		double totalDamageBarbarian = enemy->defendEnemy(damageBarbarian);
		setCounterRounds(getCounterRounds() + 1);

		double damageEnemy = 0;
		double totalDamageEnemy = 0;
		if (enemy->getHealth() > 0)
		{
			damageEnemy = enemy->attackEnemy(this);
			totalDamageEnemy = defendHerî(damageEnemy);
			setHealth(getHealth() - totalDamageEnemy);
			enemy->incrementCounterRounds();
		}

		printBattleWithEnemy(enemy, totalDamageBarbarian, totalDamageEnemy);
	}

	if (getHealth() <= 0)
	{
		std::cout << "GAME OVER!";
		std::cout << std::endl;
	}
	else
	{
		std::cout << "VICTORY!";
		std::cout << std::endl;
		rageFlag = true;
		setCounterLevelUp(getCounterLevelUp() + 1);
	}
}

/*
CLASS SORCERER INTERFACE
*/

Sorcerer::Sorcerer(const String& name) : Character(name, 1, 70, 4, 12), manaSorcerer(100), manaCapacity(100)
{}

double Sorcerer::getSpecialAbility() const
{
	return manaSorcerer;
}

double Sorcerer::getMinimumAbility() const
{
	double minAbility = Character::getMinimumAbility();
	if (minAbility < manaSorcerer) return minAbility;
	else return manaSorcerer;
}

double Sorcerer::attackHero()
{
	double damageSorcerer = (0.5 + (manaSorcerer / manaCapacity)*0.75)*getIntelligence();
	manaSorcerer -= 0.1*manaCapacity;
	return damageSorcerer;
}

double Sorcerer::defendHerî(double damageEnemy)
{
	return Character::defendHerî(damageEnemy);
}

void Sorcerer::levelUpHero()
{
	Character::levelUpHero();
	manaCapacity += (10 / 100)*manaCapacity;
}

void Sorcerer::battleWithEnemy(Enemy* enemy)
{
	while (getHealth() > 0 && enemy->getHealth() > 0)
	{
		double damageSorcerer = attackHero();
		double totalDamageSorcerer = enemy->defendEnemy(damageSorcerer);
		setCounterRounds(getCounterRounds() + 1);

		double damageEnemy = 0;
		double totalDamageEnemy = 0;
		if (enemy->getHealth() > 0)
		{
			damageEnemy = enemy->attackEnemy(this);
			totalDamageEnemy = defendHerî(damageEnemy);
			setHealth(getHealth() - totalDamageEnemy);
			enemy->incrementCounterRounds();
		}

		printBattleWithEnemy(enemy, totalDamageSorcerer, totalDamageEnemy);
	}

	if (getHealth() <= 0) std::cout << "GAME OVER!";
	else
	{
		std::cout << "VICTORY!";
		manaSorcerer = manaCapacity;
		setCounterLevelUp(getCounterLevelUp() + 1);
	}
}

/*
CLASS BOUNTYHUNTER INTERFACE
*/

BountyHunter::BountyHunter(const String& name) : Character(name, 1, 80, 9, 6), agilityBountyHunter(10)
{}

double BountyHunter::getSpecialAbility() const
{
	return agilityBountyHunter;
}

double BountyHunter::getMinimumAbility() const
{
	double minAbility = Character::getMinimumAbility();
	if (minAbility < agilityBountyHunter) return minAbility;
	else return agilityBountyHunter;
}

double BountyHunter::attackHero()
{
	double damageBountyHunter;
	if (getCounterRounds() % 3 == 0)
	{
		damageBountyHunter = agilityBountyHunter + 0.4*getIntelligence() + 0.6*getStrength();
	}
	else
	{
		damageBountyHunter = 0.8*agilityBountyHunter;
	}
	return damageBountyHunter;
}

double BountyHunter::defendHerî(double damageEnemy)
{
	return Character::defendHerî(damageEnemy);
}

void BountyHunter::levelUpHero()
{
	Character::levelUpHero();
	agilityBountyHunter += 4;
}

void BountyHunter::battleWithEnemy(Enemy* enemy)
{
	while (getHealth() > 0 && enemy->getHealth() > 0)
	{
		double damageBountyHunter = attackHero();
		double totalDamageBountyHunter = enemy->defendEnemy(damageBountyHunter);
		setCounterRounds(getCounterRounds() + 1);

		double damageEnemy = 0;
		double totalDamageEnemy = 0;
		if (enemy->getHealth() > 0)
		{
			damageEnemy = enemy->attackEnemy(this);
			totalDamageEnemy = defendHerî(damageEnemy);
			setHealth(getHealth() - totalDamageEnemy);
			enemy->incrementCounterRounds();
		}

		printBattleWithEnemy(enemy, totalDamageBountyHunter, totalDamageEnemy);
	}

	if (getHealth() <= 0) std::cout << "GAME OVER!";
	else
	{
		std::cout << "VICTORY!";
		setCounterLevelUp(getCounterLevelUp() + 1);
	}
}

