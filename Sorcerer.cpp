#include "Sorcerer.h"
#include "Enemy.h"
#include <iostream>

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
	manaCapacity = 1.1*manaCapacity;
	manaSorcerer = manaCapacity;
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

	if (getHealth() <= 0) std::cout << "GAME OVER!" << std::endl;
	else
	{
		std::cout << "VICTORY!" << std::endl;
		manaSorcerer = manaCapacity;
		setCounterLevelUp(getCounterLevelUp() + 1);
	}
}