#include "Barbarian.h"
#include "Enemy.h"
#include <iostream>

Barbarian::Barbarian(const String& name) : Character(name, 1, 100, 10, 3), rageBarbarian(0), rageForNextBattle(0)
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

void Barbarian::convertRage()
{
	rageBarbarian = rageForNextBattle;
	rageForNextBattle = 0;
}

bool Barbarian::isRageAllowed(int rage) const
{
	return (rage < 100);
}

double Barbarian::attackHero()
{
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
		std::cout << "GAME OVER!"<< std::endl;
	}
	else
	{
		std::cout << "VICTORY!" << std::endl;
		convertRage();

		setCounterLevelUp(getCounterLevelUp() + 1);
	}
}