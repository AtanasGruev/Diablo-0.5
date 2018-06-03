#include "Skeleton.h"
#include "Character.h"
#include <iostream>

Skeleton::Skeleton(const String& name) : Enemy(name, 32, 3, 0)
{}

double Skeleton::attackEnemy(Character* hero)
{
	double damageSkeleton = getStrength() + 0.1*hero->getIntelligence();
	return damageSkeleton;
}

double Skeleton::defendEnemy(double damageHero)
{
	damageHero -= (getStrength() / 100)*damageHero;
	setHealth(getHealth() - damageHero);
	return damageHero;
}

void Skeleton::printOnMap(char(*map)[10])
{
	int skeletonX = getXEnemy();
	int skeletonY = getYEnemy();
	map[skeletonX][skeletonY] = 'S';
}