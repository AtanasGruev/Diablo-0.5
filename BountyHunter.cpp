#include "BountyHunter.h"
#include "Enemy.h"
#include <iostream>

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

	if (getHealth() <= 0) std::cout << "GAME OVER!" << std::endl;
	else
	{
		std::cout << "VICTORY!" << std::endl;
		setCounterLevelUp(getCounterLevelUp() + 1);
	}
}
