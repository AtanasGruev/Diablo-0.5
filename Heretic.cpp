#include "Heretic.h"
#include "Character.h"
#include <iostream>

Heretic::Heretic(const String& name) : Enemy(name, 20, 1, 4)
{}

double Heretic::attackEnemy(Character* hero)
{
	double damageHeretic = hero->getMinimumAbility() + getIntelligence();
	return damageHeretic;
}

double Heretic::defendEnemy(double damageHero)
{
	damageHero -= (getStrength() / 100)*damageHero;
	setHealth(getHealth() - damageHero);
	return damageHero;
}

void Heretic::printOnMap(char(*map)[10])
{
	int hereticX = getXEnemy();
	int hereticY = getYEnemy();
	map[hereticX][hereticY] = 'H';
}