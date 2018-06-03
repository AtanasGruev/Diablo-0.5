#include "Necromancer.h"
#include "Character.h"
#include <iostream>
#include <cassert>

Necromancer::Necromancer(const String& name) : Enemy(name, 65, 2, 7)
{}

double Necromancer::attackEnemy(Character* hero)
{
	double damageNecromancer;

	if (getCounterRounds() % 3 == 1)
	{
		skeletonServant = new Skeleton("Skeleton Servant");
		assert(skeletonServant);
		skeletonIsAlive = true;
	}

	if (skeletonIsAlive == true)
	{
		damageNecromancer = (skeletonServant->getHealth()) / 10 + getIntelligence();
	}
	else
	{
		damageNecromancer = getIntelligence();
	}

	return damageNecromancer;
}

double Necromancer::defendEnemy(double damageHero)
{
	if (skeletonIsAlive == true)
	{
		skeletonServant->setHealth(skeletonServant->getHealth() - damageHero);
		if (skeletonServant->getHealth() <= 0)
		{
			skeletonIsAlive = false;
			double damageLeft = fabs(skeletonServant->getHealth());
			setHealth(getHealth() - damageLeft);
		}
	}
	else
	{
		setHealth(getHealth() - damageHero);
	}
	return damageHero;
}

double Necromancer::necromancerSkeleton()
{
	return skeletonServant->getHealth();
}

Necromancer::~Necromancer()
{
	delete skeletonServant;
}

void Necromancer::printOnMap(char(*map)[10])
{
	int necromancerX = getXEnemy();
	int necromancerY = getYEnemy();
	map[necromancerX][necromancerY] = 'N';
}