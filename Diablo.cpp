#include "Diablo.h"
#include "Character.h"
#include <iostream>

Diablo::Diablo(const String& name) : Enemy(name, 350, 8, 4), Skeleton(name), Heretic(name)
{}

double Diablo::attackEnemy(Character* hero)
{
	if (getCounterRounds() % 2 == 1)
	{
		return Skeleton::attackEnemy(hero);
	}
	else
	{
		return Heretic::attackEnemy(hero);
	}
}

double Diablo::defendEnemy(double damageHero)
{
	damageHero -= (getStrength() / 100)*damageHero;
	setHealth(getHealth() - damageHero);
	return damageHero;
}

void Diablo::printOnMap(char(*map)[10])
{
	int diabloX = getXEnemy();
	int diabloY = getYEnemy();
	map[diabloX][diabloY] = 'D';
}