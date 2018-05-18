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

double Character::getHealth() const
{
	return healthPointsHero;
}

double Character::getLevel() const
{
	return levelHero;
}

double Character::getCounterLevelUp() const
{
	return counterLevelUp;
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
	healthPointsHero = (110 / 100)*originalHealthPointsHero;
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
		std::cin >> newX >> newY;
	} while (newX < 1 || newX > 9 || newY < 1 || newY > 9);

	Character::setXCharacter(newX);
	Character::setYCharacter(newY);
}

void Character::printBattleWithSkeletonOrHeretic(Enemy* enemy, double totalDamageHero, double totalDamageEnemy)
{

	std::cout << "---------- NEW ROUND " << " ---------" << std::endl;
	std::cout << std::endl;
	std::cout << "Enemy was hit with " << totalDamageHero << std::endl;
	std::cout << "Enemy's remaining health is:" << enemy->getHealth() << std::endl;
	std::cout << std::endl;
	std::cout << "Player was hit with " << totalDamageEnemy << std::endl;
	std::cout << "Player's remaining health is:" << getHealth() << std::endl;
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
	double rageMultiplier = (rageBarbarian / 5) / 100;
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

	//NOT TO FORGET - ACCUMULATED RAGE_FOR_NEXT_BATTLE TO BE SIGNALLED BY CHANGING RAGEFLAG = true
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

void Barbarian::battleWithSkeletonOrHeretic(Enemy* enemy)
{
	while (getHealth() > 0 && enemy->getHealth() > 0)
	{
		double damageBarbarian = attackHero();
		double totalDamageBarbarian = enemy->defendEnemy(damageBarbarian);

		enemy->setHealth(enemy->getHealth() - totalDamageBarbarian);
		counterRounds++;

		double damageSkeleton = enemy->attackEnemy(this);
		double totalDamageSkeleton = defendHerî(damageSkeleton);
		setHealth(getHealth() - totalDamageSkeleton);
		enemy->incrementCounterRounds();

		printBattleWithSkeletonOrHeretic(enemy, totalDamageBarbarian, totalDamageSkeleton);
	}

	if (getHealth() <= 0)
	{
		std::cout << "GAME OVER!";
	}
	else
	{
		std::cout << "VICTORY!";
		rageFlag = true;
		counterLevelUp++;
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

void Sorcerer::battleWithSkeletonOrHeretic(Enemy* skeleton)
{
	while (getHealth() > 0 && skeleton->getHealth() > 0)
	{
		double damageSorcerer = attackHero();
		double totalDamageSorcerer = skeleton->defendEnemy(damageSorcerer);

		skeleton->setHealth(skeleton->getHealth() - totalDamageSorcerer);
		counterRounds++;

		double damageSkeleton = skeleton->attackEnemy(this);
		double totalDamageSkeleton = defendHerî(damageSkeleton);
		setHealth(getHealth() - totalDamageSkeleton);
		skeleton->incrementCounterRounds();

		printBattleWithSkeletonOrHeretic(skeleton, totalDamageSorcerer, totalDamageSkeleton);
	}

	if (getHealth() <= 0) std::cout << "GAME OVER!";
	else
	{
		std::cout << "VICTORY!";
		manaSorcerer = manaCapacity;
		counterLevelUp++;
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
	if (counterRounds % 3 == 0)
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

void BountyHunter::battleWithSkeletonOrHeretic(Enemy* skeleton)
{
	while (getHealth() > 0 && skeleton->getHealth() > 0)
	{
		double damageBountyHunter = attackHero();
		double totalDamageBountyHunter = skeleton->defendEnemy(damageBountyHunter);

		skeleton->setHealth(skeleton->getHealth() - totalDamageBountyHunter);
		counterRounds++;

		double damageSkeleton = skeleton->attackEnemy(this);
		double totalDamageSkeleton = defendHerî(damageSkeleton);
		setHealth(getHealth() - totalDamageSkeleton);
		skeleton->incrementCounterRounds();

		printBattleWithSkeletonOrHeretic(skeleton, totalDamageBountyHunter, totalDamageSkeleton);
	}

	if (getHealth() <= 0) std::cout << "GAME OVER!";
	else
	{
		std::cout << "VICTORY!";
		counterLevelUp++;
	}
}

