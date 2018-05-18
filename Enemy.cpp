#include "Enemy.h"
#include "Character.h"
#include <iostream>
#include <cassert>

/*
CLASS ENEMY INTERFACE
*/

Enemy::Enemy(const String& name, double health, double strength, double intelligence) : nameEnemy(name), healthPointsEnemy(health),
strengthEnemy(strength), intelligenceEnemy(intelligence), counterRounds(1)
{}

void Enemy::setHealth(double health)
{
	healthPointsEnemy = health;
}

double Enemy::getHealth() const
{
	return healthPointsEnemy;
}

double Enemy::getStrength() const
{
	return strengthEnemy;
}

double Enemy::getIntelligence() const
{
	return intelligenceEnemy;
}

void Enemy::incrementCounterRounds()
{
	counterRounds++;
}

unsigned int Enemy::getCounterRounds() const
{
	return counterRounds;
}

double Enemy::defendEnemy(double damageHero)
{
	damageHero -= (strengthEnemy / 100)*damageHero;
	return damageHero;
}

void Enemy::setXEnemy(int xPos)
{
	xCoord = xPos;
}

void Enemy::setYEnemy(int yPos)
{
	yCoord = yPos;
}

int Enemy::getXEnemy() const
{
	return xCoord;
}

int Enemy::getYEnemy() const
{
	return yCoord;
}

void Enemy::placeEnemy(int newX, int newY)
{
	Enemy::setXEnemy(newX);
	Enemy::setYEnemy(newY);
}

/*
CLASS SKELETON INTERFACE
*/

Skeleton::Skeleton(const String& name) : Enemy(name, 32, 3, 0)
{}

double Skeleton::attackEnemy(Character* hero)
{
	double damageSkeleton = getStrength() + 0.1*hero->getIntelligence();
	return damageSkeleton;
}

double Skeleton::defendEnemy(double damageHero)
{
	return Enemy::defendEnemy(damageHero);
}

/*
CLASS HERETIC INTERFACE
*/

Heretic::Heretic(const String& name) : Enemy(name, 20, 1, 4)
{}

double Heretic::attackEnemy(Character* hero)
{
	double damageHeretic = hero->getMinimumAbility() + getIntelligence();
	return damageHeretic;
}

double Heretic::defendEnemy(double damageHero)
{
	return Enemy::defendEnemy(damageHero);
}

/*
CLASS NECROMANCER INTERFACE
*/

Necromancer::Necromancer(const String& name) : Enemy(name, 65, 2, 7)
{}

double Necromancer::attackEnemy(Character* hero)
{
	double damageNecromancer;

	if (getCounterRounds() % 3 == 1)
	{
		Enemy* skeletonServant = new Skeleton("Skeleton Servant");
		assert(skeletonServant);
		skeletonIsAlive = true;
	}

	//IMPORTANT CHECK WHETHER SKELETON IS ALIVE, CHANGE FLAG = false ELSE

	if (skeletonIsAlive == true)
	{
		damageNecromancer = skeletonServant->getHealth() + getIntelligence();
	}
	else
	{
		damageNecromancer = getIntelligence();
	}

	return damageNecromancer;
}

double Necromancer::defendEnemy(double damageHero)
{
	if (skeletonIsAlive == true) return skeletonServant->defendEnemy(damageHero);
	else return damageHero;
}

Necromancer::~Necromancer()
{
	delete[] skeletonServant;
}

/*
CLASS DIABLO INTERFACE
*/

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
	return Enemy::defendEnemy(damageHero);
}